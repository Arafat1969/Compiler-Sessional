%{
	#include<bits/stdc++.h> 
	#include<cstdio>
	#include<cstdlib>
	#include<iostream>
	#include<fstream>
	#include<string>
	#include "2005104_SymbolTable.h"
	using namespace std;

	ofstream logout("log.txt"), parseout("parsetree.txt"),errorout("error.txt");
	ofstream assemble("code.asm");
	int yyparse(void);
	int yylex(void);
	extern FILE *yyin;
	SymbolTable table(11);
	extern int errorCount;
	int arraySize=0;
	bool arrayInsertable;
	int line=1;
	int value;
	string type;
	string type_final;
	bool is_global=true;
	void yyerror(string s)
	{
		
	}

	struct variable{
		string name;
		int size;
	}var;

	struct param{
		string type;
		string name;
	};

	vector<variable> vList;
	vector<param> pList;
	vector<SymbolInfo*> argList;

	void unit(SymbolInfo* sym){
		if(sym->child[0]->getType()=="var_declaration"){
			//var_declaration(sym->child[0]);
		}else if(sym->child[0]->getType()=="func_declaration"){
			
		}else{

		}
	}

	void program(SymbolInfo* sym){
		if(sym->child.size()==2){
			program(sym->child[0]);
			unit(sym->child[1]);
		}else{
			unit(sym->child[0]);
		}
	}

	void start(SymbolInfo* sym){
		assemble<<".MODEL SMALL"<<endl;
		assemble<<".STACK 1000H"<<endl;
		assemble<<".DATA"<<endl;
		assemble<<"\tnumber DB \"00000$\""<<endl;
		program(sym->child[0]);
	}
	void printNewLine(){
		assemble<<"new_line proc\n\tpush ax\n\tpush dx\n\tmov ah,2\n\tmov dl,0Dh\n\tint 21h\n\tmov ah,2\n\tmov dl,0Ah\n\tint 21h\n\tpop dx\n\tpop ax\n\tret\nnew_line endp"<<endl;
	}
	void printOutput(){
		assemble<<"print_output proc  ;print what is in ax\n\tpush ax\n\tpush bx\n\tpush cx\n\tpush dx\n\tpush si\n\tlea si,number\n\tmov bx,10\n\tadd si,4\n\tcmp ax,0\n\tjnge negate\nprint:\n\txor dx,dx\n\tdiv bx\n\tmov [si],dl\n\tadd [si],'0'\n\tdec si\n\tcmp ax,0\n\tjne print\n\tinc si\n\tlea dx,si\n\tmov ah,9\n\tint 21h\n\tpop si\n\tpop dx\n\tpop cx\n\tpop bx\n\tpop ax\n\tret\nnegate:\n\tpush ax\n\tmov ah,2\n\tmov dl,'-'\n\tint 21h\n\tpop ax\n\tneg ax\n\tjmp print\nprint_output endp"<<endl;
	}
%}

%union{
	SymbolInfo *symbol;
}

%token<symbol> CONST_INT CONST_FLOAT ID SEMICOLON
%token<symbol> ASSIGNOP NOT INCOP DECOP LOGICOP RELOP ADDOP MULOP 
%token<symbol> INT FLOAT VOID IF ELSE FOR WHILE PRINTLN RETURN
%token<symbol> LPAREN RPAREN LTHIRD RTHIRD LCURL RCURL COMMA 

%type<symbol> start program unit var_declaration declaration_list
%type<symbol> func_declaration func_definition type_specifier compound_statement
%type<symbol> parameter_list statements statement variable expression_statement
%type<symbol> logic_expression arguments argument_list expression simple_expression
%type<symbol> unary_expression factor term rel_expression lcurl

%left ADDOP
%left MULOP

%left RELOP
%nonassoc RPAREN
%nonassoc  ELSE



%%

start : program {
	$$=new SymbolInfo("program","start");
	logout << "start : program" << endl;
	$$->startLine=$1->startLine;
	$$->endLine= $1->endLine;
	$$->child.push_back($1);
	parseout<<$$->printParseTree(1);
	start($$);
	printOutput();
	printNewLine();
	assemble<<"END main"<<endl;
	logout<<"Total Lines: "<<line<<endl;
	logout<<"Total Errors: "<<errorCount<<endl;
}
;


program : program unit {
	$$=new SymbolInfo("program unit","program");
	$$->startLine=$1->startLine;
	$$->endLine=$2->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);

	logout << "program  : program unit " << endl;
}
| unit {
	$$=new SymbolInfo("unit","program");
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);

	logout << "program  : unit " << endl;
}
;


unit : var_declaration {
	$$ = new SymbolInfo("var_declaration","unit");
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);

	logout<<"unit  : var_declaration "<<endl;
}
| func_declaration {
	$$ = new SymbolInfo("func_declaration","unit");
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);

	logout << "unit  : func_declaration " << endl;
}
| func_definition {
	$$ = new SymbolInfo("func_definition","unit");
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);

	logout << "unit  : func_definition " << endl;
}
;


func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON {
	$$= new SymbolInfo("type_specifier ID LPAREN parameter_list RPAREN SEMICOLON","func_declaration");
	$$->startLine=$1->startLine;
	$$->endLine=$6->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);
	$$->child.push_back($4);
	$$->child.push_back($5);
	$$->child.push_back($6);

	for(int i=0;i<$4->paraList.size();i++){
		$2->paraList.push_back($4->paraList[i]);
	}

	$2->isDeclared=true;
	SymbolInfo newSymbol($2->getName(),$2->getType());
	table.insert(newSymbol);
	SymbolInfo * temp=table.lookUp($2->getName());
	temp->isDeclared=true;
	temp->type_specifier="FUNCTION";
	temp->retType=$1->type_specifier;
	temp->setFunction();
	for(int i=0;i<$4->paraList.size();i++){
		temp->paraList.push_back($4->paraList[i]);
	}
	
	pList.clear();
	logout << "func_declaration  : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON " << endl;
}
| type_specifier ID LPAREN RPAREN SEMICOLON {
	$$=new SymbolInfo("type_specifier ID LPAREN RPAREN SEMICOLON","func_declaration");
	$$->startLine=$1->startLine;
	$$->endLine=$5->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);
	$$->child.push_back($4);
	$$->child.push_back($5);

	$2->isDeclared=true; 
	SymbolInfo  newSymbol($2->getName(),$2->getType());
	table.insert(newSymbol);
	SymbolInfo* temp=table.lookUp($2->getName());
	temp->isDeclared=true;
	temp->type_specifier="FUNCTION";
	temp->retType=$1->type_specifier;
	temp->varType=$1->varType;
	temp->setFunction();
	pList.clear();
	
	logout << "func_declaration  : type_specifier ID LPAREN RPAREN SEMICOLON " << endl;
}
;


func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement {
	$$=new SymbolInfo("type_specifier ID LPAREN parameter_list RPAREN compound_statement","func_definition");
	$$->startLine=$1->startLine;
	$$->endLine=$6->endLine;

	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);
	$$->child.push_back($4);
	$$->child.push_back($5);
	$$->child.push_back($6);

	SymbolInfo* temp1=table.lookUp($2->getName());

	if(!temp1){
		SymbolInfo* sym= new SymbolInfo($2->getName(),$1->getType());

		for(int i=0;i<$4->paraList.size();i++){
			$2->paraList.push_back($4->paraList[i]);
			SymbolInfo newSymbol($4->paraList[i]->getName(),$4->paraList[i]->getType());
			// table.insert(newSymbol);
		}
		SymbolInfo newSymbol3(sym->getName(),sym->getType());
		table.insert(newSymbol3);
		SymbolInfo* temp=table.lookUp(sym->getName());

		for(int i=0;i<$4->paraList.size();i++){
			temp->paraList.push_back($4->paraList[i]);
		}

		temp->type_specifier="FUNCTION";
		temp->retType=$1->type_specifier;
		temp->varType=$1->varType;
		temp->setFunction();
	}else{
		SymbolInfo* temp =table.lookUp($2->getName());

		if(temp->isDefined || temp->isDeclared){
			if($1->varType!=temp->varType){
				errorout<<"Line# "<<$2->endLine<<": Conflicting types for '"<<$2->getName()<<"' "<<endl;
				errorCount++;
			}else if(temp1->paraList.size()>$4->paraList.size()){
				errorout<<"Line# "<<line<<": Too few arguments to function '"<<$2->getName()<<"' "<<endl;
				errorCount++;
			}
			else if(temp1->paraList.size()<$4->paraList.size()){
				errorout<<"Line# "<<line<<": Too many arguments to function '"<<$2->getName()<<"' "<<endl;
				errorCount++;
			}else{
				bool misMatch=false;

				for(int i=0;i<pList.size();i++){
					if(($4->paraList[i]->varType!= temp1->paraList[i]->varType)){
						errorout<<"Line# "<< line<<": Type mismatch for argument "<<(i+1)<<" of '"<<$1->getName()<<"' "<<endl;
						errorCount++;
						misMatch=true;	
					}
				}

				if(!misMatch){
					$2->isDefined=true; 
				}
			}

		}else{
			errorout<<"Line# "<<$2->startLine<<": '"<<$2->getName()<<"' redeclared as different kind of symbol "<<endl;
			errorCount++;
		}
	}

	pList.clear();
	logout << "func_definition  : type_specifier ID LPAREN parameter_list RPAREN compound_statement " << endl;
}
| type_specifier ID LPAREN RPAREN compound_statement {
	$$=new SymbolInfo("type_specifier ID LPAREN RPAREN compound_statement","func_definition");
	$$->startLine=$1->startLine;
	$$->endLine=$5->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);
	$$->child.push_back($4);
	$$->child.push_back($5);

	SymbolInfo* temp=table.lookUp($2->getName());

	if(!temp){
		SymbolInfo newSymbol4($2->getName(),$1->getType());
		table.insert(newSymbol4);
		SymbolInfo* temp1=table.lookUp(newSymbol4.getName());
		temp1->isDefined=true;
		temp1->type_specifier="FUNCTION";
		temp1->retType=$1->type_specifier;
		temp1->setFunction();
	}

	logout << "func_definition  : type_specifier ID LPAREN RPAREN compound_statement " << endl;
}
;


parameter_list : parameter_list COMMA type_specifier ID {
	$$= new SymbolInfo("parameter_list COMMA type_specifier ID","parameter_list");
	param temp;
	temp.type=$3->varType;
	temp.name=$4->getName();

	pList.push_back(temp);

	for(int i=0;i<$1->paraList.size();i++){
		$$->paraList.push_back($1->paraList[i]);
	}

	$$->paraList.push_back($4);
	$4->varType=$3->varType;

	for(int i=0;i<$1->paraList.size();i++){
		for(int j=i+1;j<$1->paraList.size();j++){
			if($1->paraList[i]->getName()==$1->paraList[j]->getName())
			{
				errorout<<"Line# "<<line<<": Redefinition of parameter '"<<$1->paraList[i]->getName()<<"' "<<endl;
				errorCount++;
			}
		}
	}

	$$->startLine=$1->startLine;
	$$->endLine=$4->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);
	$$->child.push_back($4);

	logout << "parameter_list  : parameter_list COMMA type_specifier ID " << endl;
}
| parameter_list COMMA type_specifier {
	$$=new SymbolInfo("parameter_list COMMA type_specifier","parameter_list");
	param temp;
	temp.type=$3->varType;
	temp.name="";
	pList.push_back(temp);

	SymbolInfo* sym= new SymbolInfo("","ID");
	$$->paraList.push_back(sym);
	for(int i=0;i<$1->paraList.size();i++){
		$$->paraList.push_back($1->paraList[i]);
	}
	
	$$->startLine=$1->startLine;
	$$->endLine=$3->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);

	logout << "parameter_list  : parameter_list COMMA type_specifier " << endl;
}
| type_specifier ID {
	$$=new SymbolInfo("type_specifier ID","parameter_list");
	param temp;
	temp.type=$1->varType;
	temp.name=$2->getName();
	$2->type_specifier=$1->type_specifier;

	pList.push_back(temp);

	$$->paraList.push_back($2);

	$$->startLine=$1->startLine;
	$$->endLine=$2->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);

	logout << "parameter_list  : type_specifier ID " << endl;
}
| type_specifier {
	$$=new SymbolInfo("type_specifier","parameter_list");

	param temp;
	temp.type=$1->varType;
	temp.name="";

	pList.push_back(temp);
	SymbolInfo* sym=new SymbolInfo("","ID");
	sym->type_specifier=$1->type_specifier;
	$$->paraList.push_back(sym);

	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);

	logout << "parameter_list  : type_specifier " << endl;
}
;


compound_statement : lcurl statements RCURL {
	$$=new SymbolInfo("LCURL statements RCURL","compound_statement");
	$$->startLine=$1->startLine;
	$$->endLine=$3->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);

	logout << "compound_statement  : LCURL statements RCURL " << endl;
	logout << table.printAllScopeTable();
	table.exitScope();
}
| lcurl RCURL {
	$$=new SymbolInfo("LCURL RCURL","compound_statement");
	$$->startLine=$1->startLine;
	$$->endLine=$2->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);

	logout << "compound_statement  : LCURL RCURL " << endl;	
	logout << table.printAllScopeTable();
	table.exitScope();
}
;


var_declaration : type_specifier declaration_list SEMICOLON {
	$$=new SymbolInfo("type_specifier declaration_list SEMICOLON","var_declaration");

	SymbolInfo* sym;
	if($1->varType=="void"){
		errorCount++;
		for(int i=0;i<vList.size();i++){
			sym=new SymbolInfo(vList[i].name,"ID");
			SymbolInfo* temp=table.lookUp(sym->getName());
			if(temp->isInserted)
				temp->varType=$1->varType;
				temp->type_specifier=$1->type_specifier;
			errorout<<"Line# "<<line<<": Variable or field '"<<vList[i].name<<"' declared void "<<endl;
		}
	}else{
		for(int i=0;i<vList.size();i++){
			SymbolInfo* temp=table.lookUp(vList[i].name);
			if($1->varType!= type ){
				errorout<<"Line# "<<line<<": Conflicting types for '"<<vList[i].name<<"' "<<endl;
			}
			if(temp->isInserted){
				temp->varType=$1->varType;
				temp->type_specifier=$1->type_specifier;
			}
		}
	}
	

	for(int i=0;i<$2->decList.size();i++){
		$2->decList[i]->varType=$1->varType;
		$2->decList[i]->type_specifier=$1->type_specifier;
		if(table->getCurrScopeId()==1){	
			$$->isGlobal=true;
			temp->isGlobal=true;
			$2->dec_list[i]->isGlobal=true;
			global_vars.push_back(temp);
		}else{
			temp->isGlobal=false;
			$2->dec_list[i]->isGlobal=false;
		}
	}

	vList.clear();

	$$->startLine=$1->startLine;
	$$->endLine=$3->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);

	logout << "var_declaration  : type_specifier declaration_list SEMICOLON " << endl;
}
;


type_specifier : INT {
	$$=new SymbolInfo("INT","type_specifier");
	$$->varType="int";
	$$->type_specifier="INT";
	//type="int";
	type="int";
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);

	logout << "type_specifier : INT" << endl;
}
| FLOAT {
	$$=new SymbolInfo("FLOAT","type_specifier");
	$$->varType="float";
	$$->type_specifier="FLOAT";
	type="float";
	
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);

	logout << "type_specifier : FLOAT" << endl;
}
| VOID {
	$$=new SymbolInfo("VOID","type_specifier");
	$$->varType="void";
	$$->type_specifier="VOID";
	type="void";
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);

	logout << "type_specifier  : VOID " << endl;
}
;


declaration_list : declaration_list COMMA ID {
	string name=$3->getName();
	$$=new SymbolInfo("declaration_list COMMA ID","declaration_list");
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);
	$$->startLine=$1->startLine;
	$$->endLine=$3->endLine;
	for(int i=0;i<$1->decList.size();i++){
		$$->decList.push_back($1->decList[i]);
	}
	$$->decList.push_back($3);
	SymbolInfo newSymbol12($3->getName(),$3->getType());
	bool insertable=table.insert(newSymbol12);
	if(insertable){
		SymbolInfo* temp=table.lookUp($3->getName());
		temp->arraySize=var.size;
		temp->isInserted=true;
		temp->varType=$1->decList[0]->varType;
		temp->type_specifier=$1->decList[0]->type_specifier;
		var.name=(string)$3->getName();
		var.size=0;

		vList.push_back(var);
	}else{
		errorout<<"Line# "<<line<<": Redefinition of parameter '"<<$3->getName()<<"' "<<endl;
		errorCount++;
	}
	logout << "declaration_list  : declaration_list COMMA ID " << endl;
}
| declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
	$$=new SymbolInfo("declaration_list COMMA ID LTHIRD CONST_INT RTHIRD","declaration_list");

	var.name=(string)$3->getName();
	var.size=stoi($5->getName());
	$3->arraySize=var.size;
	for(int i=0;i<$1->decList.size();i++)
	{
		$$->decList.push_back($1->decList[i]);
	}
	$$->decList.push_back($3);
	SymbolInfo newSymbol($3->getName(),$3->getType());
	bool insertable=table.insert(newSymbol);
	arrayInsertable=insertable;

	if(insertable){
		SymbolInfo* temp=table.lookUp($3->getName());
		
		if($5->varType=="float")
		{
			errorout<<"Error at line# "<<line<<": array size cannot be float '"<<$3->getType()<<"' "<<endl;
		}
		else{
			$3->arraySize=stoi($5->getName());
		}

		vList.push_back(var);
		temp->arraySize=var.size;
		temp->varType=$1->varType;
		temp->type_specifier="ARRAY";
		temp->isInserted=true;
	}else{
		errorout<<"Line# "<<line<<": Conflicting types for'"<<$3->getName()<<"' "<<endl;
		errorCount++;
	}

	arraySize=var.size;
	$$->startLine=$1->startLine;
	$$->endLine=$6->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);
	$$->child.push_back($4);
	$$->child.push_back($5);
	$$->child.push_back($6);

	logout << "declaration_list  : declaration_list COMMA ID LSQUARE CONST_INT RSQUARE " << endl;
}
| ID {
	$$=new SymbolInfo("ID","declaration_list");
	$$->decList.push_back($1);
	SymbolInfo newSymbol($1->getName(),$1->getType());
	bool insertable=table.insert(newSymbol);
	
	if(insertable){
		SymbolInfo* temp=table.lookUp($1->getName());
		temp->arraySize=var.size;
		temp->isInserted=true;

		var.name=(string)$1->getName();
		var.size=0;

		vList.push_back(var);
	}
	else{
		errorout<<"Line# "<<line<<": Conflicting types for'"<<$1->getName()<<"' "<<endl;
		errorCount++;
	}

	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);

	logout << "declaration_list  : ID " << endl;
}
| ID LTHIRD CONST_INT RTHIRD {
	$$=new SymbolInfo("ID LTHIRD CONST_INT RTHIRD ","declaration_list");

	if($3->varType=="float"){
		errorout<<"Line# "<<line<<": array size cannot be float '"<<$3->getType()<<"' "<<endl;
		errorCount++;
	}

	$1->arraySize=stoi($3->getName());
	$$->decList.push_back($1);
	arraySize=var.size;
	SymbolInfo newSymbol15($1->getName(),$1->getType());
	bool insertable=table.insert(newSymbol15);
	arrayInsertable=insertable;
	if(insertable){
		SymbolInfo* temp=table.lookUp($1->getName());
		var.name=(string)$1->getName();
		var.size=stoi($3->getName());
		vList.push_back(var);
		temp->arraySize=var.size;
		temp->isInserted=true;
		temp->type_specifier="ARRAY";
	}else{
		errorout<<"Line# "<<line<<": Conflicting types for'"<<$1->getName()<<"' "<<endl;
		errorCount++;
	}
	arraySize=var.size;
	$$->startLine=$1->startLine;
	$$->endLine=$4->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);
	$$->child.push_back($4);
	logout << "declaration_list  : ID LSQUARE CONST_INT RSQUARE " << endl;
}
;


statements : statement {
	$$=new SymbolInfo("statement","statements");
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);
	logout << "statements : statement" << endl;
}
| statements statement {
	$$=new SymbolInfo("statements statement","statements");
	$$->startLine=$1->startLine;
	$$->endLine=$2->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	logout << "statements  : statements statement " << endl;
}
;


statement : var_declaration {
	$$=new SymbolInfo("var_declaration","statement");
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);
	logout << "statement  : var_declaration " << endl;
}
| expression_statement {
	$$=new SymbolInfo("expression_statement","statement");
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);
	logout << "statement  : expression_statement " << endl;
}
| compound_statement {
	$$=new SymbolInfo("compound_statement","statement");
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);
	logout << "statement  : compound_statement " << endl;
}
| FOR LPAREN expression_statement embedded_exp embedded_void expression_statement embedded_exp embedded_void expression embedded_exp embedded_void RPAREN statement {
	$$=new SymbolInfo("FOR LPAREN expression_statement expression RPAREN statement","statement");
	$$->startLine=$1->startLine;
	$$->endLine=$13->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);
	$$->child.push_back($9);
	$$->child.push_back($12);
	$$->child.push_back($6);
	$$->child.push_back($13);
	logout << "statement  : FOR LPAREN expression_statement expression_statement expression RPAREN statement " << endl;
}
| IF LPAREN expression embedded_exp RPAREN embedded_void statement  {
	$$=new SymbolInfo("IF LPAREN expression RPAREN statement","statement");
	$$->startLine=$1->startLine;
	$$->endLine=$7->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);
	$$->child.push_back($5);
	$$->child.push_back($7);
	logout << "statement  : IF LPAREN expression RPAREN statement " << endl;
}
| IF LPAREN expression embedded_exp RPAREN embedded_void statement ELSE statement {
	$$=new SymbolInfo("IF LPAREN expression RPAREN statement ELSE statement","statement");
	$$->startLine=$1->startLine;
	$$->endLine=$9->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);
	$$->child.push_back($9);
	$$->child.push_back($5);
	$$->child.push_back($8);
	$$->child.push_back($7);
		
	logout << "statement  : IF LPAREN expression RPAREN statement ELSE statement " << endl;
}
| WHILE LPAREN expression embedded_exp RPAREN embedded_void statement {
	$$=new SymbolInfo("WHILE LPAREN expression RPAREN statement","statement");
	$$->startLine=$1->startLine;
	$$->endLine=$7->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);
	$$->child.push_back($7);
	$$->child.push_back($5);
	logout << "statement  : WHILE LPAREN expression RPAREN statement " << endl;
}
| PRINTLN LPAREN ID RPAREN SEMICOLON {
	$$=new SymbolInfo("PRINTLN LPAREN ID RPAREN SEMICOLON","statement");
	$$->startLine=$1->startLine;
	$$->endLine=$5->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);
	$$->child.push_back($4);
	$$->child.push_back($5);
	logout << "statement  : PRINTLN LPAREN ID RPAREN SEMICOLON ";
}
| RETURN expression SEMICOLON {
	$$=new SymbolInfo("RETURN expression SEMICOLON","statement");
	$$->startLine=$1->startLine;
	$$->endLine=$3->endLine;	
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);
	logout << "statement  : RETURN expression SEMICOLON " << endl;
}
;

embedded_exp: {
	 type_final=type;
};

embedded_void: {
	if(type_final=="void"){
		errorout<<"Line# "<<line<<": void function called within expression "<<endl;
		errorCount++;
	}
};

expression_statement : SEMICOLON {
	$$=new SymbolInfo("SEMICOLON","expression_statement");
	$$->varType="int";
	type="int";
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;	
	$$->child.push_back($1);

	logout << "expression_statement  : SEMICOLON " << endl;
}
| expression SEMICOLON {
	$$=new SymbolInfo("expression SEMICOLON","expression_statement");
	$$->varType=$1->varType;//why?
	type=$1->varType;//why?
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	logout << "expression_statement  : expression SEMICOLON " << endl;
}
;


variable : ID {
	$$=new SymbolInfo("ID","variable");
	SymbolInfo* temp=table.lookUp($1->getName());
	if(!temp){
		errorout<<"Line# "<<line<<": Undeclared variable '"<<$1->getName()<<"' "<<endl;
		errorCount++;
		$$->varType="error";
	}else{
		$1->varType=temp->varType;
		if($1->varType!="void"){
			$$->varType=$1->varType;
		}else{
			$$->varType="float";
		}
	}

	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);
	logout << "variable  : ID " << endl;
}
| ID LTHIRD expression RTHIRD {
	$$=new SymbolInfo("ID LTHIRD expression RTHIRD","variable");
	SymbolInfo* temp=table.lookUp($1->getName());
	
	if(!temp){
		errorout<<"Line# "<<line<<": undeclared variable '"<<$1->getName()<<"' "<<endl;
		errorCount++;
		$$->varType="float";
	}else if(temp->arraySize==0){
		errorout<<"Line# "<<line<<": '"<<$1->getName()<<"' is not an array "<<endl;
		errorCount++;
	}else{
		$$->varType=temp->varType;
		$1->type_specifier="ARRAY";
		$$->arraySize=$3->arraySize;
		if($1->varType!="void"){
			$$->varType=$1->varType;
		}else{
			$$->varType="float";
		}	
	}

	if($3->varType!="int"){
		errorout<<"Line# "<<line<<": Array subscript is not an integer "<<endl;
		errorCount++;
	}
	$$->startLine=$1->startLine;
	$$->endLine=$4->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);
	$$->child.push_back($4);
	logout << "variable  : ID LSQUARE expression RSQUARE " << endl;
}
;


expression : logic_expression {
	$$=new SymbolInfo("logic_expression","expression");
	$$->varType=$1->varType;
	type=$1->varType;
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);
	logout << "expression  : logic_expression " << endl;
}
| variable ASSIGNOP logic_expression {
	$$=new SymbolInfo("variable ASSIGNOP logic_expression","expression");
	
	if($1->varType=="float" && type=="int"){
		$3->varType="float";
	}else if($1->varType=="void" || $3->varType=="void"){
		errorout<<"Line# "<<line<<": Void cannot be used in expression  "<<endl;
		errorCount++;
	}else if($3->varType=="float" && $1->varType=="int"){
		errorout<<"Line# "<<line<<": Warning: possible loss of data in assignment of FLOAT to INT "<<endl;
		errorCount++;
	}else if($1->varType!=$3->varType){
		//errorout<<"Line# "<<line<<": type mismatch(not array2) "<<endl;
		//cout<<"from assign: "<<$1->varType<<" : "<<$3->varType<<endl;
		errorCount++;
	}else {
		$$->varType=$1->varType;
		type=$1->varType;
	}
	$$->startLine=$1->startLine;
	$$->endLine=$3->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);

	logout << "expression  : variable ASSIGNOP logic_expression " << endl;
}
;


logic_expression : rel_expression {
	$$=new SymbolInfo("rel_expression","logic_expression");

	$$->varType=$1->varType;
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);
	$$->arraySize=$1->arraySize;

	logout << "logic_expression  : rel_expression " << endl;
}
| rel_expression LOGICOP rel_expression {
	$$=new SymbolInfo("rel_expression LOGICOP rel_expression","logic_expression");
	$$->varType="int";
	$$->startLine=$1->startLine;
	$$->endLine=$3->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);
	logout << "logic_expression  : rel_expression LOGICOP rel_expression " << endl;
}
;


rel_expression : simple_expression {
	$$=new SymbolInfo("simple_expression","rel_expression");	
	$$->varType=$1->varType;
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);
	$$->arraySize=$1->arraySize;
	logout << "rel_expression  : simple_expression " << endl;
}
| simple_expression RELOP simple_expression {
	$$=new SymbolInfo("simple_expression RELOP simple_expression","rel_expression");
	$$->varType="int";
	$$->startLine=$1->startLine;
	$$->endLine=$3->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);
	logout << "rel_expression  : simple_expression RELOP simple_expression " << endl;
}
;


simple_expression : term {
	$$=new SymbolInfo("term","simple_expression");
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);
	$$->varType=$1->varType;
	$$->arraySize=$1->arraySize;
	logout << "simple_expression  : term " << endl;
}
| simple_expression ADDOP term {
	$$=new SymbolInfo("simple_expression ADDOP term","simple_expression");

	if($1->varType=="void" || $3->varType=="void"){
		errorout<<"Line# "<<line<<": Void function cannot be called in argument of function  "<<endl;;
	}else if($1->varType=="float" || $3->varType=="float"){
		$$->varType="float";
	}else {
		$$->varType=$1->varType;
	}

	$$->startLine=$1->startLine;
	$$->endLine=$3->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);
					
	logout << "simple_expression  : simple_expression ADDOP term " << endl;
}
;


term : unary_expression {
	$$=new SymbolInfo("unary_expression","term");
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);
	$$->varType=$1->varType;
	$$->arraySize=$1->arraySize;
	logout << "term  : unary_expression " << endl;
}
| term MULOP unary_expression {
	$$=new SymbolInfo("term MULOP unary_expression","term");


	if($1->varType=="void" || $3->varType=="void"){
		errorout<<"Line# "<<line<<": Void cannot be used in expression "<<endl;
		errorCount++;
	}else if(($2->getName()=="%"|| $2->getName()=="/") && !value){
		errorout<<"Line# "<<line<<": Warning: division by zero i=0f=1Const=0 "<<endl;
		errorCount++;
		$$->varType="int";
	}else if($2->getName()=="%" && ($1->varType!="int" || $3->varType!="int")){
		errorout<<"Line# "<<line<<": Operands of modulus must be integers  "<<endl;
		errorCount++;
		$$->varType="int";
	}else if($2->getName()!="%" && ($1->varType=="float" || $3->varType=="float")) {
		$$->varType="float";
	}else{
		$$->varType=$1->varType;
	}

	$$->startLine=$1->startLine;
	$$->endLine=$3->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);

	logout << "term  : term MULOP unary_expression " << endl;
}
;


unary_expression : ADDOP unary_expression {
	$$=new SymbolInfo("ADDOP unary_expression","unary_expression");
	$$->startLine=$1->startLine;
	$$->endLine=$2->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	if($2->varType=="void"){
		errorout<<"Line# "<<line<<": Void cannot be used in expression "<<endl;
		errorCount++;
	}
	$$->varType="int";
	logout << "unary_expression  : ADDOP unary_expression " << endl;
}
| NOT unary_expression {
	$$=new SymbolInfo("NOT unary_expression","unary_expression");
	$$->startLine=$1->startLine;
	$$->endLine=$2->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->varType="int";
	logout << "unary_expression  : NOT unary_expression " << endl;
}
| factor {
	$$=new SymbolInfo("factor","unary_expression");
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);
	$$->varType=$1->varType;
	$$->arraySize=$1->arraySize;

	logout << "unary_expression  : factor " << endl;
}
;

factor : variable {
	$$=new SymbolInfo("variable","factor");
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);
	$$->varType=$1->varType;
	$$->arraySize=$1->arraySize;
	logout << "factor  : variable " << endl;
}
| ID LPAREN argument_list RPAREN {
	$$=new SymbolInfo("ID LPAREN argument_list RPAREN","factor");
	SymbolInfo* si=table.lookUp($1->getName());
	argList.clear();
	$$->startLine=$1->startLine;
	$$->endLine=$4->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);
	$$->child.push_back($4);

	SymbolInfo* temp=table.lookUp($1->getName());

	if(!temp){
		errorout<<"Line# "<<line<<": Undeclared function '"<<$1->getName()<<"' "<<endl;
		errorCount++;
		$$->varType="empty";
	}else{
		$$->varType=temp->varType;
		if(temp->varType=="void"){
			$$->varType="void";
		}else if($3->argList.size()<temp->paraList.size()){
			errorout<<"Line# "<<$2->startLine<<": Too few arguments to function '"<<$1->getName()<<"' "<<endl;
			errorCount++;
		}else if($3->argList.size()>temp->paraList.size()){
			errorout<<"Line# "<<$2->startLine<<": Too many arguments to function '"<<$1->getName()<<"' "<<endl;
			errorCount++;
		}else {
			for(int i=0;i<temp->paraList.size();i++){
				if(($3->argList[i]->varType!= temp->paraList[i]->varType) ){
					// errorout<<"Line# "<<$1->startLine<<": Type mismatch for argument "<<(i+1)<<" of '"<<$1->getName()<<"' "<<endl;
					// errorCount++;
				}
			}
		}
	}
	logout << "factor  : ID LPAREN argument_list RPAREN " << endl;
}
| LPAREN expression RPAREN {
	$$=new SymbolInfo("LPAREN expression RPAREN","factor");
	SymbolInfo* temp=table.lookUp($1->getName());
	$$->startLine=$1->startLine;
	$$->endLine=$3->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);

	//$2->varType="float";
	$$->varType=$2->varType;
	logout << "factor  : LPAREN expression RPAREN " << endl;
}
| CONST_INT {
	$$=new SymbolInfo("CONST_INT","factor");
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);
	$$->varType="int";
	value=stoi($1->getName());
	logout << "factor  : CONST_INT " << endl;
}
| CONST_FLOAT {
	$$=new SymbolInfo("CONST_FLOAT","factor");
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);
	$$->varType="float";
	logout << "factor  : CONST_FLOAT " << endl;
}
| variable INCOP {
	$$=new SymbolInfo("variable INCOP","factor");
	$$->varType=$1->varType;
	$$->startLine=$1->startLine;
	$$->endLine=$2->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	logout << "factor  : variable INCOP " << endl;
}
| variable DECOP {
	$$=new SymbolInfo("variable DECOP","factor");
	$$->varType=$1->varType;
	$$->startLine=$1->startLine;
	$$->endLine=$2->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	logout << "factor  : variable DECOP " << endl;
}
;

argument_list : arguments {
	$$=new SymbolInfo("arguments","argument_list");
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);

	for(int i=0;i<$1->argList.size();i++){
		$$->argList.push_back($1->argList[i]);		
	}
	logout << "argument_list  : arguments " << endl;
}
| {
	$$=new SymbolInfo("","argument_list");
	$$->startLine=line;
	$$->endLine=line;
	logout << "argument_list  :  " << endl;
}
;


arguments : arguments COMMA logic_expression {
	$$=new SymbolInfo("arguments COMMA logic_expression ","arguments");
	
	if($3->varType=="void"){
		errorout<<"Line# "<<line<<": Void function cannot be called in argument of function  "<<endl;;
		errorCount++;
		$3->varType="float";
	}

	$$->startLine=$1->startLine;
	$$->endLine=$3->endLine;
	$$->child.push_back($1);
	$$->child.push_back($2);
	$$->child.push_back($3);
	for(int i=0;i<$1->argList.size();i++){
		$$->argList.push_back($1->argList[i]);
	}
	$$->argList.push_back($3);

	logout << "arguments  : arguments COMMA logic_expression " << endl;
}
| logic_expression {
	$$=new SymbolInfo("logic_expression","arguments");
	if($1->varType=="void"){
		errorout<<"Line# "<<line<<": Void function cannot be called in argument of function "<<endl;
		errorCount++;
		$1->varType="float";
	}
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	$$->child.push_back($1);
	argList.push_back($1);
	$$->argList.push_back($1);
	logout << "arguments  : logic_expression " << endl;
}
;

lcurl : LCURL {
	$$ = $1;
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;
	table.enterScope();
	for(int i=0;i<pList.size();i++){
		if(pList[i].name!=""){
			if(pList[i].name=="void"){

			}else{
				SymbolInfo  newSymbol6(pList[i].name,pList[i].type);
				table.insert(newSymbol6);
				SymbolInfo* temp=table.lookUp(pList[i].name);
				temp->varType=pList[i].type;
			}
		}
	}
	pList.clear();
	// $$->child.push_back($1);
	$$->startLine=$1->startLine;
	$$->endLine=$1->endLine;		
}
;

%%
int main(int argc,char *argv[])
{
	
	auto fp = fopen(argv[1], "r");
	if(fp==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	yyin=fp;
	yyparse();
	
	fclose(fp);
	
	return 0;
}