%option noyywrap  yylineno

%x MULTICOMMENT
%x SINGLECOMMENT
%{
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "2005104_SymbolTable.h"
#include"2005104.tab.h"

//#include "2005104_SymbolTable.h"
using namespace std;

extern ofstream logout;
extern ofstream tokenout;
extern int error;
extern int line;
extern YYSTYPE yylval;
extern SymbolTable table;
void yyerror(char* c);

int errorCount = 0;
int warningCount=0;
string multilineComment = "";
string singlelineComment = "";
int multilineCommentStart = 0;
int singlelineCommentStart=0;

%}
TAB [	]
WS [ ]
DIGIT [0-9]
DIGITS ({DIGIT}+)
EXP (E[+-]?{DIGITS})  
%%
\n {
		line++;
 	}
{WS} {	}
{TAB} 	{}	

"if"	{
			SymbolInfo *sym= new  SymbolInfo(yytext,"IF");
			yylval.symbol =sym;
			sym->startLine=line;
			sym->endLine=line;
			sym->isLeaf=true;
			logout<<"Line# "<<line<<": Token <IF> Lexeme if found"<<endl;
			return IF;
		}
"int"	{
			SymbolInfo *sym= new  SymbolInfo(yytext,"INT");
			yylval.symbol =sym;
			sym->startLine=line;
			sym->endLine=line;
			sym->isLeaf=true;
			logout<<"Line# "<<line<<": Token <INT> Lexeme int found"<<endl;
			return INT;
		}
"for" 	{
			SymbolInfo *sym= new  SymbolInfo(yytext, "FOR");
			yylval.symbol =sym;
			sym->startLine=line;
			sym->endLine=line;
			sym->isLeaf=true; 
			logout<<"Line# "<<line<<": Token <FOR> Lexeme for found"<<endl;
			return FOR;
		}
"else"  {
			SymbolInfo *sym= new  SymbolInfo(yytext, "ELSE");
			yylval.symbol =sym;
			sym->startLine=line;
			sym->endLine=line;
			sym->isLeaf=true;
			logout<<"Line# "<<line<<": Token <ELSE> Lexeme else found"<<endl;
			return ELSE;
		}
"void"	{
			SymbolInfo *sym= new  SymbolInfo(yytext, "VOID");
			yylval.symbol =sym;
			sym->startLine=line;
			sym->endLine=line;
			sym->isLeaf=true;
			logout<<"Line# "<<line<<": Token <VOID> Lexeme void found"<<endl;
			return VOID;
		}
"while"	{
			SymbolInfo *sym= new  SymbolInfo(yytext, "WHILE");
			yylval.symbol =sym;
			sym->startLine=line;
			sym->endLine=line;
			sym->isLeaf=true;
			logout<<"Line# "<<line<<": Token <WHILE> Lexeme while found"<<endl;
			return WHILE;
		}	
"println"	{
			SymbolInfo *sym= new  SymbolInfo(yytext, "PRINTLN");
			yylval.symbol =sym;
			sym->startLine=line;
			sym->endLine=line;
			sym->isLeaf=true;
			logout<<"Line# "<<line<<": Token <PRINTLN> Lexeme println found"<<endl;
			return PRINTLN;
		}
"float"	{
			SymbolInfo *sym= new  SymbolInfo(yytext, "FLOAT");
			yylval.symbol =sym;
			sym->startLine=line;
			sym->endLine=line;
			sym->isLeaf=true;
			logout<<"Line# "<<line<<": Token <FLOAT> Lexeme float found"<<endl;
			return FLOAT;
		}		
"return" {
			SymbolInfo *sym= new  SymbolInfo(yytext, "RETURN");
			yylval.symbol =sym;
			sym->startLine=line;
			sym->endLine=line;
			sym->isLeaf=true;
			logout<<"Line# "<<line<<": Token <RETURN> Lexeme return found"<<endl;
			return RETURN;
		}		
	
{DIGITS} {
			SymbolInfo *sym= new  SymbolInfo(yytext, "CONST_INT");
			yylval.symbol =sym;
			sym->startLine=line;
			sym->endLine=line;
			sym->isLeaf=true;
			logout<<"Line# "<<line<<": Token <CONST_INT> Lexeme "<<yytext<<" found"<<endl;
			return CONST_INT;
		 }

({DIGITS}?\.{DIGITS}(E[+-]?{DIGITS})?)	|
{DIGITS}(E[+-]?{DIGITS}) {
				SymbolInfo *sym= new  SymbolInfo(yytext, "CONST_FLOAT");
				yylval.symbol =sym;
				sym->startLine=line;
				sym->endLine=line;
				sym->isLeaf=true;
				logout<<"Line# "<<line<<": Token <CONST_FLOAT> Lexeme "<<yytext<<" found"<<endl;
				return CONST_FLOAT;
			}

{DIGITS}(\.{DIGITS})?(E[+-]?{DIGITS}?(\.)[0-9(\.)]*) {
				
				logout<<"Error at line# "<<line<<": ILLFORMED_NUMBER "<<yytext<<endl;
			}

{DIGITS}?((\.)+{DIGITS})((\.)+{DIGITS})+{EXP}?	|
{DIGITS}?(\.)+{DIGITS}?	{
				
				logout<<"Error at line# "<<line<<": TOO_MANY_DECIMAL_POINTS "<<yytext<<endl;
			}

"+" |
"-"	{
		SymbolInfo *sym= new  SymbolInfo(yytext, "ADDOP");
		yylval.symbol =sym;
		sym->startLine=line;
		sym->endLine=line;
		sym->isLeaf=true;
		logout<<"Line# "<<line<<": Token <ADDOP> Lexeme "<<yytext<<" found"<<endl;
		return ADDOP;
	}

"*"	|
"/"	|
"%" {
		SymbolInfo *sym= new  SymbolInfo(yytext, "MULOP");
		yylval.symbol =sym;
		sym->startLine=line;
		sym->endLine=line;
		sym->isLeaf=true;
		logout<<"Line# "<<line<<": Token <MULOP> Lexeme "<<yytext<<" found"<<endl;
		return MULOP;
	}

"++" {
		SymbolInfo *sym= new  SymbolInfo(yytext, "INCOP");
		yylval.symbol =sym;
		sym->startLine=line;
		sym->endLine=line;
		sym->isLeaf=true;
		logout<<"Line# "<<line<<": Token <INCOP> Lexeme "<<yytext<<" found"<<endl;
		return INCOP;
	}
"--" {
		SymbolInfo *sym= new  SymbolInfo(yytext, "DECOP");
		yylval.symbol =sym;
		sym->startLine=line;
		sym->endLine=line;
		sym->isLeaf=true;
		logout<<"Line# "<<line<<": Token <DECOP> Lexeme "<<yytext<<" found"<<endl;
		return DECOP;
	} 

"<"	|
"<=" |
">"	|
">=" |
"==" | 
"!=" {
		SymbolInfo *sym= new  SymbolInfo(yytext, "RELOP");
		yylval.symbol =sym;
		sym->startLine=line;
		sym->endLine=line;
		sym->isLeaf=true;
		logout<<"Line# "<<line<<": Token <RELOP> Lexeme "<<yytext<<" found"<<endl;
		return RELOP;
	} 

"=" {
		SymbolInfo *sym= new  SymbolInfo(yytext, "ASSIGNOP");
		yylval.symbol =sym;
		sym->startLine=line;
		sym->endLine=line;
		sym->isLeaf=true;
		logout<<"Line# "<<line<<": Token <ASSIGNOP> Lexeme "<<yytext<<" found"<<endl;
		return ASSIGNOP;
	}

"&&" |
"||" {
		SymbolInfo *sym= new  SymbolInfo(yytext, "LOGICOP");
		yylval.symbol =sym;
		sym->startLine=line;
		sym->endLine=line;
		sym->isLeaf=true;
		logout<<"Line# "<<line<<": Token <LOGICOP> Lexeme "<<yytext<<" found"<<endl;
		return LOGICOP;
	}

"!" {
		SymbolInfo *sym= new  SymbolInfo(yytext, "NOT");
		yylval.symbol =sym;
		sym->startLine=line;
		sym->endLine=line;
		sym->isLeaf=true;
		logout<<"Line# "<<line<<": Token <NOT> Lexeme "<<yytext<<" found"<<endl;
		return NOT;
	} 
"(" {
		SymbolInfo *sym= new  SymbolInfo(yytext, "LPAREN");
		yylval.symbol =sym;
		sym->startLine=line;
		sym->endLine=line;
		sym->isLeaf=true;
		logout<<"Line# "<<line<<": Token <LPAREN> Lexeme "<<yytext<<" found"<<endl;
		return LPAREN;
	} 
")" {
		SymbolInfo *sym= new  SymbolInfo(yytext, "RPAREN");
		yylval.symbol =sym;
		sym->startLine=line;
		sym->endLine=line;
		sym->isLeaf=true;
		logout<<"Line# "<<line<<": Token <RPAREN> Lexeme "<<yytext<<" found"<<endl;
		return RPAREN;
	}
"{" {
		SymbolInfo *sym= new  SymbolInfo(yytext, "LCURL");
		yylval.symbol =sym;
		sym->startLine=line;
		sym->endLine=line;
		sym->isLeaf=true;
		logout<<"Line# "<<line<<": Token <LCURL> Lexeme "<<yytext<<" found"<<endl;
		return LCURL;
	} 
"}" {
		SymbolInfo *sym= new  SymbolInfo(yytext, "RCURL");
		yylval.symbol =sym;
		sym->startLine=line;
		sym->endLine=line;
		sym->isLeaf=true;
		logout<<"Line# "<<line<<": Token <RCURL> Lexeme "<<yytext<<" found"<<endl;
		return RCURL;
	} 
"[" {
		SymbolInfo *sym= new  SymbolInfo(yytext, "LSQUARE");
		yylval.symbol =sym;
		sym->startLine=line;
		sym->endLine=line;
		sym->isLeaf=true;
		logout<<"Line# "<<line<<": Token <LSQUARE> Lexeme "<<yytext<<" found"<<endl;
		return LTHIRD;
	} 
"]" {	
		SymbolInfo *sym= new  SymbolInfo(yytext, "RSQUARE");
		yylval.symbol =sym;
		sym->startLine=line;
		sym->endLine=line;
		sym->isLeaf=true;
		logout<<"Line# "<<line<<": Token <RSQUARE> Lexeme "<<yytext<<" found"<<endl;
		return RTHIRD;
	} 
"," {
		SymbolInfo *sym= new  SymbolInfo(yytext, "COMMA");
		yylval.symbol =sym;
		sym->startLine=line;
		sym->endLine=line;
		sym->isLeaf=true;
		logout<<"Line# "<<line<<": Token <COMMA> Lexeme "<<yytext<<" found"<<endl;
		return COMMA;
	} 
";" {
		SymbolInfo *sym= new  SymbolInfo(yytext, "SEMICOLON");
		yylval.symbol =sym;
		sym->startLine=line;
		sym->endLine=line;
		sym->isLeaf=true;
		logout<<"Line# "<<line<<": Token <SEMICOLON> Lexeme "<<yytext<<" found"<<endl;
		return SEMICOLON;
	} 

[_a-zA-Z][_a-zA-Z0-9]* {
			SymbolInfo *sym= new  SymbolInfo(yytext, "ID");
			yylval.symbol =sym;
			sym->startLine=line;
			// SymbolInfo *temp= table.lookUp(yytext);
			// sym->offset=temp->offset;
			sym->endLine=line;
			sym->isLeaf=true;
			logout<<"Line# "<<line<<": Token <ID> Lexeme "<<yytext<<" found"<<endl;
			return ID;
		}

[0-9][_a-zA-Z0-9]* {
			
			logout<<"Error at line# "<<line<<": INVALID_ID_SUFFIX_NUM_PREFIX "<<yytext<<endl;
		}

"//" {
		
		BEGIN(SINGLECOMMENT);
		singlelineCommentStart=line;
	}

<SINGLECOMMENT>(.|"\\\n")* {
		singlelineComment.append(yytext);
	}
<SINGLECOMMENT>\n {
		BEGIN(INITIAL);
		//logout<<"Line# "<<singlelineCommentStart<<": Token <SINGLE LINE COMMENT> Lexeme "<<"//"+singlelineComment<<" found"<<endl;
		singlelineComment="";
	}

"/*" {
		BEGIN(MULTICOMMENT);
		multilineCommentStart=line;
	}

<MULTICOMMENT>"*/" {
				BEGIN(INITIAL);
				string ans=multilineComment;
				//logout<<"Line# "<<multilineCommentStart<<": Token <MULTI LINE COMMENT> Lexeme "<<"/*"+ans+"*/"<<" found"<<endl;
				multilineComment = "";
			}
<MULTICOMMENT>([^*]|\n)+|. {
					multilineComment.append(yytext);
				}
<MULTICOMMENT><<EOF>> {
					if(multilineComment.back() == '\n') {
						multilineComment.pop_back();
					}
					
					//logout<<"Error at line# "<<line<<": UNFINISHED_COMMENT "<<"/*"+multilineComment<<endl;
					multilineComment = "";
					BEGIN(INITIAL);
				}
. 		{
		
		//logout<<"Error at line# "<<line<<": UNRECOGNIZED_CHAR "<<yytext<<endl;
	}
%%
/*
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
	logout<<"Total lines: "<<line<<endl;
	logout<<"Total errors: "<<errorCount<<endl;
	logout<<"Total warnings: "<<warningCount<<endl;

	fclose(yyin);

	return 0;
}
*/