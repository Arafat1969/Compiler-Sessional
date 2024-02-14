%option noyywrap  yylineno

%x MULTICOMMENT
%x SINGLECOMMENT
%{
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string>

#include "2005104_SymbolTable.h"
using namespace std;

ofstream logout("2005104_log.txt"), tokenout("2005104_token.txt");
SymbolTable symbolTable(10);

int errorCount = 0;
int warningCount=0;
string multilineComment = "";
string singlelineComment = "";
int multilineCommentStart = 0;
int singlelineCommentStart=0;
bool new_line=true;
int tabrequired=0;
int spacecount=0;
int tabcount=0;

string convertUpper(string text){
	string newText="";
	for(auto i : text){
        if(i >= 'a' && i <= 'z')
            newText.push_back(i-'a'+'A');
        else newText.push_back(i);
	}
	return newText;
}



char convertEscape(char ch){
	int size=11;
	char match[]= {'\'', '\"', 'n', 't', '\\', 'a', 'f', 'r', 'b', 'v', '0'};
	char ret[]={'\'', '\"', '\n', '\t', '\\', '\a', '\f', '\r', '\b', '\v', '\0'};
	for(int i=0;i<size;i++){
		if(match[i]==ch){
			return ret[i];
		}
	}
	return ch;
}

string convertString(string str){
	string ans="";
	for(int i=0;i<str.length()-1;i++){
		if(str[i]=='\n' && str[i-1]=='\\'){
			ans.push_back(str[i]);
		}
		else{
			ans.push_back(str[i]);
		}
	}
	return ans;
}

string convertStringToken(string str){
	string ans="";
	for(int i=0;i<str.length();i++){
		if(str[i+1]=='\n' && str[i]=='\\'){
			ans.push_back(' ');
			i++;
		}else if(str[i]=='\\'){
			char ch= convertEscape(str[i+1]);
			ans.push_back(ch);
			i++;
		}else if(str[i]=='\"'){
			continue;
		}else{
			ans.push_back(str[i]);
		}
	}
	return ans;
}

void resetIndentation(){
	spacecount=0;
	tabcount=0;
	new_line=true;
}

void checkIndentation(){
	if(new_line){
		new_line=false;
		if(spacecount==0 && tabcount>tabrequired){
			warningCount++;
			logout<<"Line# "<<yylineno<<": warning, "<<tabrequired<<" of tabs needed but got "<<tabcount<<" tabs."<<endl;
		}else if(tabcount<tabrequired && (spacecount/4!=tabrequired || spacecount%4!=0)){
			warningCount++;
			logout<<"Line# "<<yylineno<<": warning, tab requrired but got space."<<endl;
		}else if(tabcount== tabrequired && spacecount!=0){
			warningCount++;
			logout<<"Line# "<<yylineno<<": warning, tab requrired but got space."<<endl;
		}else if(spacecount=!0 && tabcount>tabrequired){
			warningCount++;
			logout<<"Line# "<<yylineno<<": warning, tab requrired but got space."<<endl;
		}else{

		}				
	}
}

bool insertSymbol(string text){
	SymbolInfo symbol(text,"ID");
	return symbolTable.insert(symbol);
}

void printAll(){
	string str="";
	str+=symbolTable.printAllScopeTable();
	logout<<str;
}

%}

DELIM [ \t\f\r\v]
TAB [	]
WS [ ]

CHARS [ A-Za-z0-9]
CHAR [A-Za-z0-9]
DIGIT [0-9]
DIGITS ({DIGIT}+)
EXP (E[+-]?{DIGITS})
ESCAPES ['"nt\\afrbv0]  
%%
\n {
		resetIndentation();
	}
{WS} { 
		if(new_line){
			spacecount++;
		}
	}
{TAB} 	{
			if(new_line){
				tabcount++;
			}
		}
"if"  |
"do"  |
"int"  |
"for"  |
"else"  |
"case"  |
"char"  |
"void"  |
"while"  |
"break"  |	
"float"  |	
"double"  | 	
"switch"  |	
"return"  |		
"default"  |
"continue" {
				checkIndentation();
				string str=convertUpper(yytext); 
				tokenout<<"<"<<str<<", "<<yytext<<">"<<endl;
				logout<<"Line# "<<yylineno<<": Token <"<<str<<"> Lexeme "<<yytext<<" found"<<endl;
           } 
	
{DIGITS} {
			checkIndentation();
			tokenout<<"<CONST_INT, "<<yytext<<">"<<endl;
			logout<<"Line# "<<yylineno<<": Token <CONST_INT> Lexeme "<<yytext<<" found"<<endl;
		 }

({DIGITS}?\.{DIGITS}(E[+-]?{DIGITS})?)	|
{DIGITS}(E[+-]?{DIGITS}) {
				checkIndentation();
				tokenout<<"<CONST_FLOAT, "<<yytext<<">"<<endl;
				logout<<"Line# "<<yylineno<<": Token <CONST_FLOAT> Lexeme "<<yytext<<" found"<<endl;
			}

{DIGITS}(\.{DIGITS})?(E[+-]?{DIGITS}?(\.)[0-9(\.)]*) {
				checkIndentation();
				errorCount++;
				logout<<"Error at line# "<<yylineno<<": ILLFORMED_NUMBER "<<yytext<<endl;
			}

{DIGITS}?((\.)+{DIGITS})((\.)+{DIGITS})+{EXP}?	|
{DIGITS}?(\.)+{DIGITS}?	{
				checkIndentation();
				errorCount++;
				logout<<"Error at line# "<<yylineno<<": TOO_MANY_DECIMAL_POINTS "<<yytext<<endl;
			}

'{CHAR}*'    |
'{CHAR}+([ ]|{CHAR})*' {
			checkIndentation();
			string str=yytext;
			if(str.length() == 2){
				errorCount++;
				logout<<"Error at line# "<<yylineno<<": EMPTY_CONST_CHAR "<<str<<endl;
			}
			else if(str.length() == 3 && str[1]!=' '){
				tokenout<<"<CONST_CHAR, "<<str[1]<<">"<<endl;
				logout<<"Line# "<<yylineno<<": Token <CONST_CHAR> Lexeme "<<str[1]<<" found"<<endl;
			}
			else{
				errorCount++;
				logout<<"Error at line# "<<yylineno<<": MULTICHAR_CONST_CHAR "<<str<<endl;
			}
		}
		
'{ESCAPES}*' {
			checkIndentation();
			string str=yytext;
			if(str.length() == 2){
				errorCount++;
				logout<<"Error at line# "<<yylineno<<": EMPTY_CONST_CHAR "<<str<<endl;
			}
			else if(str.length() == 3 ){
				errorCount++;
				logout<<"Error at line# "<<yylineno<<": UNFINISHED_CONST_CHAR "<<str<<endl;
			}
			else if(str.length() == 4){
				tokenout<<"<CONST_CHAR, "<<convertEscape(str[2])<<">"<<endl;
				if(convertEscape(str[2])!='\n' && convertEscape(str[2])!='\r'){
					logout<<"Line# "<<yylineno<<": Token <CONST_CHAR> Lexeme "<<convertEscape(str[2])<<" found"<<endl;
				}
				else{
					logout<<"Line# "<<yylineno<<": Token <CONST_CHAR> Lexeme "<<convertEscape(str[2])<<"\t found"<<endl;
				}
			}
			else{
				logout<<"Error at line# "<<yylineno<<": MULTICHAR_CONST_CHAR "<<str<<endl;
			}
		}


'({CHAR}|{ESCAPES})* {
			checkIndentation();
			errorCount++;
			logout<<"Error at line# "<<yylineno<<": UNFINISHED_CONST_CHAR "<<yytext<<endl;
		}

"+" |
"-"  {
		checkIndentation();
		tokenout<<"<ADDOP, "<<yytext<<">"<<endl;
		logout<<"Line# "<<yylineno<<": Token <ADDOP> Lexeme "<<yytext<<" found"<<endl;
	 }

"*" | 
"/" | 
"%" {
		checkIndentation();
		tokenout<<"<MULOP, "<<yytext<<">"<<endl;
		logout<<"Line# "<<yylineno<<": Token <MULOP> Lexeme "<<yytext<<" found"<<endl;
	}

"++" |
"--" {
		checkIndentation();
		tokenout<<"<INCOP, "<<yytext<<">"<<endl;
		logout<<"Line# "<<yylineno<<": Token <INCOP> Lexeme "<<yytext<<" found"<<endl;
	} 

"<" | 
"<=" |
">" | 
">=" |
"==" | 
"!=" {
		checkIndentation();
		tokenout<<"<RELOP, "<<yytext<<">"<<endl;
		logout<<"Line# "<<yylineno<<": Token <RELOP> Lexeme "<<yytext<<" found"<<endl;
	 } 

"=" {
		checkIndentation();
		tokenout<<"<ASSIGNOP, "<<yytext<<">"<<endl;
		logout<<"Line# "<<yylineno<<": Token <ASSIGNOP> Lexeme "<<yytext<<" found"<<endl;
	}

"&&" | 
"||" {
		checkIndentation();
		tokenout<<"<LOGICOP, "<<yytext<<">"<<endl;
		logout<<"Line# "<<yylineno<<": Token <LOGICOP> Lexeme "<<yytext<<" found"<<endl;
	 }

"&" | 
"|" | 
"^" | 
"<<" | 
">>" {
		checkIndentation();
		tokenout<<"<BITOP, "<<yytext<<">"<<endl;
		logout<<"Line# "<<yylineno<<": Token <BITOP> Lexeme "<<yytext<<" found"<<endl;
	}

"!" {
		checkIndentation();
		tokenout<<"<NOT, "<<yytext<<">"<<endl;
		logout<<"Line# "<<yylineno<<": Token <NOT> Lexeme "<<yytext<<" found"<<endl;
	} 
"(" {
		checkIndentation();
		tokenout<<"<LPAREN, "<<yytext<<">"<<endl;
		logout<<"Line# "<<yylineno<<": Token <LPAREN> Lexeme "<<yytext<<" found"<<endl;
	} 
")" {
		checkIndentation();
		tokenout<<"<RPAREN, "<<yytext<<">"<<endl;
		logout<<"Line# "<<yylineno<<": Token <RPAREN> Lexeme "<<yytext<<" found"<<endl;
	}
"{" {
		checkIndentation();
		tabrequired++;
		symbolTable.enterScope();
		tokenout<<"<LCURL, "<<yytext<<">"<<endl;
		logout<<"Line# "<<yylineno<<": Token <LCURL> Lexeme "<<yytext<<" found"<<endl;
	} 
"}" {
		tabrequired--;
		checkIndentation();
		symbolTable.exitScope();
		tokenout<<"<RCURL, "<<yytext<<">"<<endl;
		logout<<"Line# "<<yylineno<<": Token <RCURL> Lexeme "<<yytext<<" found"<<endl;
	} 
"[" {
		checkIndentation();
		tokenout<<"<LSQUARE, "<<yytext<<">"<<endl;
		logout<<"Line# "<<yylineno<<": Token <LSQUARE> Lexeme "<<yytext<<" found"<<endl;
	} 
"]" {
		checkIndentation();
		tokenout<<"<RSQUARE, "<<yytext<<">"<<endl;
		logout<<"Line# "<<yylineno<<": Token <RSQUARE> Lexeme "<<yytext<<" found"<<endl;
	} 
"," {
		checkIndentation();
		tokenout<<"<COMMA, "<<yytext<<">"<<endl;
		logout<<"Line# "<<yylineno<<": Token <COMMA> Lexeme "<<yytext<<" found"<<endl;
	} 
";" {
		checkIndentation();
		tokenout<<"<SEMICOLON, "<<yytext<<">"<<endl;
		logout<<"Line# "<<yylineno<<": Token <SEMICOLON> Lexeme "<<yytext<<" found"<<endl;
	} 

[_a-zA-Z][_a-zA-Z0-9]* {
			checkIndentation();
			tokenout<<"<ID, "<<yytext<<">"<<endl;
			logout<<"Line# "<<yylineno<<": Token <ID> Lexeme "<<yytext<<" found"<<endl;
			if(insertSymbol(yytext)){
				printAll();
			}else{
				logout<<"\t"<<yytext<<" already exists in the current ScopeTable"<<endl;
			}
		}

[0-9][_a-zA-Z0-9]* {
			checkIndentation();
			errorCount++;
			logout<<"Error at line# "<<yylineno<<": INVALID_ID_SUFFIX_NUM_PREFIX "<<yytext<<endl;
		}

\"(([^"\\\n]|(\\{ESCAPES}))|("\\\n"))*\" {
			checkIndentation();
			string str=yytext;
			int newLine=0;
			for(auto i:str){
				if(i=='\n'){
					newLine++;
				}
			}
			string token=convertStringToken(str);
			string ans=convertString(str);
			ans.push_back('\"');
			if(newLine==0){
				logout<<"Line# "<<yylineno<<": Token <SINGLE LINE STRING> Lexeme "<<ans<<" found"<<endl;
				tokenout<<"<SINGLE LINE STRING, "<<token<<">"<<endl;
			}else{
				logout<<"Line# "<<yylineno-newLine<<": Token <MULTI LINE STRING> Lexeme "<<ans<<" found"<<endl;
				tokenout<<"<MULTI LINE STRING, "<<token<<">"<<endl;
			}
		}
\"(([^"\\\n]|(\\{ESCAPES}))|("\\\n"))*\n {
			checkIndentation();
			string str=yytext;
			errorCount++;
			string ans="";
			for(int i=0;i<str.length()-1;i++){
				ans.push_back(str[i]);
			}
			logout<<"Error at line# "<<(yylineno-1)<<": UNFINISHED_STRING "<<ans<<endl;
			resetIndentation();
		}

"//" {
		checkIndentation();
		BEGIN(SINGLECOMMENT);
		singlelineCommentStart=yylineno;
	}

<SINGLECOMMENT>(.|"\\\n")* {
		singlelineComment.append(yytext);
	}
<SINGLECOMMENT>\n {
		BEGIN(INITIAL);
		logout<<"Line# "<<singlelineCommentStart<<": Token <SINGLE LINE COMMENT> Lexeme "<<"//"+singlelineComment<<" found"<<endl;
		singlelineComment="";
		resetIndentation();
	}

"/*" {
		checkIndentation();
		BEGIN(MULTICOMMENT);
		multilineCommentStart=yylineno;
	}

<MULTICOMMENT>"*/" {
				BEGIN(INITIAL);
				string ans=multilineComment;
				logout<<"Line# "<<multilineCommentStart<<": Token <MULTI LINE COMMENT> Lexeme "<<"/*"+ans+"*/"<<" found"<<endl;
				multilineComment = "";
				checkIndentation();
			}
<MULTICOMMENT>([^*]|\n)+|. {
					multilineComment.append(yytext);
				}
<MULTICOMMENT><<EOF>> {
					if(multilineComment.back() == '\n') {
						multilineComment.pop_back();
					}
					errorCount++;
					logout<<"Error at line# "<<yylineno<<": UNFINISHED_COMMENT "<<"/*"+multilineComment<<endl;
					multilineComment = "";
					BEGIN(INITIAL);
				}
. 		{
		checkIndentation();
		errorCount++;
		logout<<"Error at line# "<<yylineno<<": UNRECOGNIZED_CHAR "<<yytext<<endl;
	}
%%
int main(int argc, char** argv) {
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	

	yyin= fin;
	yylex();
	
	printAll();
	logout<<"Total lines: "<<yylineno<<endl;
	logout<<"Total errors: "<<errorCount<<endl;
	logout<<"Total warnings: "<<warningCount<<endl;

	fclose(yyin);

	return 0;
}