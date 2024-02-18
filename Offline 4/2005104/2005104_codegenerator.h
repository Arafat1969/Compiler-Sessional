//#ifndef codegenerator_h
// #define codegenerator_h


#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include "2005104_SymbolTable.h"

using namespace std;

ofstream assemble("optcode.asm");
//extern SymbolTable table;
extern int stack_decremented;
extern int levelCount;
extern int line;
extern vector<SymbolInfo*> globalVariables;


class codeGenerator{
	public:
	bool var_dec=false;
	int replace=0;
	int offset=0;
	//SymbolTable table1;

	codeGenerator(){

	}
	string newLevel(){
		string level="L";
		level+=to_string(levelCount);
		levelCount++;
		return level;
	}

	void arguments(SymbolInfo* sym){
		if(sym->getName()=="arguments COMMA logic_expression"){

		}else if(sym->getName()=="logic_expression"){

		}
	}

	void argument_list(SymbolInfo* sym){
		if(sym->getName()=="arguments"){

		}
	}

	void factor(SymbolInfo* sym){
		if(sym->getName()=="variable"){
			variable(sym->child[0]);
		}else if(sym->getName()=="ID LPAREN argument_list RPAREN"){

		}else if(sym->getName()=="LPAREN expression RPAREN"){

		}else if(sym->getName()=="CONST_INT"){
			assemble<<"\tMOV AX,"<<sym->child[0]->getName()<<"       ; Line "<<sym->startLine<<endl;

			if(sym->isCond){
				assemble<<"\tJCXZ "<<sym->isFalse<<endl;
				assemble<<"\tJMP "<<sym->isTrue<<endl;
			}
		}else if(sym->getName()=="CONST_FLOAT"){

		}else if(sym->getName()=="variable INCOP"){
			variable(sym->child[0]);
			assemble<<"\tPUSH AX"<<endl;
			assemble<<"\tINC AX"<<endl;
			if(sym->child[0]->isGlobal){
				assemble<<"\tMOV "<<sym->child[0]->child[0]->getName()<<", AX"<<endl;
			}else{
				assemble<<"\tMOV [BP-"<<sym->child[0]->offset<<"], AX"<<endl;
			}
			assemble<<"\tPOP AX"<<endl;
			if(sym->isCond){
				assemble<<"\tCMP AX, 0"<<endl;
				assemble<<"\tJNE "<<sym->isFalse<<endl;
				assemble<<"\tJMP "<<sym->isTrue<<endl;
			}

		}else if(sym->getName()=="variable DECOP"){
			variable(sym->child[0]);
			assemble<<"\tPUSH AX"<<endl;
			assemble<<"\tDEC AX"<<endl;
			if(sym->child[0]->isGlobal){
				assemble<<"\tMOV "<<sym->child[0]->child[0]->getName()<<", AX"<<endl;
			}else{
				assemble<<"\tMOV [BP-"<<sym->child[0]->offset<<"], AX"<<endl;
			}
			assemble<<"\tPOP AX"<<endl;
			if(sym->isCond){
				assemble<<"\tCMP AX, 0"<<endl;
				assemble<<"\tJNE "<<sym->isTrue<<endl;
				assemble<<"\tJMP "<<sym->isFalse<<endl;
			}
		}
	}

	void unary_expression(SymbolInfo* sym){
		if(sym->getName()=="ADDOP unary_expression"){
			if(sym->child[0]->getName()=="-"){
				unary_expression(sym->child[1]);
				assemble<<"\tNEG AX"<<endl;
				assemble<<"\tPUSH AX"<<endl;
				assemble<<"\tPOP AX       ; Line "<<sym->startLine<<endl;
			}
		}else if(sym->getName()=="NOT unary_expression"){

		}else if(sym->getName()=="factor"){
			sym->child[0]->isCond=sym->isCond;
			sym->child[0]->isTrue=sym->isTrue;
			sym->child[0]->isFalse=sym->isFalse;
			factor(sym->child[0]);
		}
	}

	void term(SymbolInfo* sym){
		if(sym->getName()=="unary_expression"){
			sym->child[0]->isCond=sym->isCond;
			sym->child[0]->isTrue=sym->isTrue;
			sym->child[0]->isFalse=sym->isFalse;
			unary_expression(sym->child[0]);
		}else if(sym->getName()=="term MULOP unary_expression"){
			unary_expression(sym->child[2]);
			assemble<<"\tMOV CX, AX"<<endl;
			term(sym->child[0]);
			assemble<<"\tCWD"<<endl;
			if(sym->child[1]->getName()=="*"){
				assemble<<"\tMUL CX"<<endl;
			}else{
				assemble<<"\tDIV CX"<<endl;
			}
			if(sym->child[1]->getName()=="*" || sym->child[1]->getName()=="/"){
				assemble<<"\tPUSH AX"<<endl;
			}else{
				assemble<<"\tPUSH DX"<<endl;
			}
			assemble<<"\tPOP AX       ; Line "<<sym->startLine<<endl;
		}
	}

	void simple_expression(SymbolInfo* sym){
		if(sym->getName()=="term"){
			sym->child[0]->isCond=sym->isCond;
			sym->child[0]->isTrue=sym->isTrue;
			sym->child[0]->isFalse=sym->isFalse;
			term(sym->child[0]);
		}else if(sym->getName()=="simple_expression ADDOP term"){
			term(sym->child[2]);
			assemble<<"\tMOV DX, AX"<<endl;
			simple_expression(sym->child[0]);
			if(sym->child[1]->getName()=="+"){
				assemble<<"\tADD AX, DX"<<endl;
			}else{
				assemble<<"\tSUB AX, DX"<<endl;
			}
			assemble<<"\tPUSH AX"<<endl;
			assemble<<"\tPOP AX       ; Line "<<sym->startLine<<endl;
		}
	}

	void rel_expression(SymbolInfo* sym){
		if(sym->getName()=="simple_expression"){
			sym->child[0]->isCond=sym->isCond;
			sym->child[0]->isTrue=sym->isTrue;
			sym->child[0]->isFalse=sym->isFalse;
			simple_expression(sym->child[0]);
		}else if(sym->getName()=="simple_expression RELOP simple_expression"){
			simple_expression(sym->child[2]);
			assemble<<"\tMOV DX, AX"<<endl;
			simple_expression(sym->child[0]);
			assemble<<"\tCMP AX, DX"<<endl;
			if(sym->isTrue==""){
				sym->isTrue=newLevel();
			}

			if(sym->isFalse==""){
				sym->isFalse=newLevel();
			}

			if(sym->child[1]->getName()=="<"){
				assemble<<"\tJL ";
			}else if(sym->child[1]->getName()=="<="){
				assemble<<"\tJLE ";
			}else if(sym->child[1]->getName()==">"){
				assemble<<"\tJG ";
			}else if(sym->child[1]->getName()=="=>"){
				assemble<<"\tJGE ";
			}else if(sym->child[1]->getName()=="=="){
				assemble<<"\tJE ";
			}else if(sym->child[1]->getName()=="!="){
				assemble<<"\tJNE ";
			}
			assemble<<sym->isTrue<<endl;
			assemble<<"\tJMP "<<sym->isFalse<<endl;
			if(!sym->isCond){
				assemble<<sym->isTrue<<":"<<endl;
				assemble<<"\tMOV AX, 1       ; Line "<<sym->startLine<<endl;
				string levelOut=newLevel();

				assemble<<"\tJMP "<<levelOut<<endl;
				assemble<<sym->isFalse<<":"<<endl;
				assemble<<"\tMOV AX,0"<<endl;
				assemble<<levelOut<<":"<<endl;
			}

		}
	}

	void logic_expression(SymbolInfo* sym){
		if(sym->getName()=="rel_expression"){
			sym->child[0]->isCond=sym->isCond;
			sym->child[0]->isTrue=sym->isTrue;
			sym->child[0]->isFalse=sym->isFalse;
			rel_expression(sym->child[0]);
		}else if(sym->getName()=="rel_expression LOGICOP rel_expression"){
			sym->child[0]->isCond=sym->isCond;
			sym->child[2]->isCond=sym->isCond;
			string midlevel=newLevel();
			if(sym->isTrue==""){
				sym->isTrue=newLevel();
			}
			string levelout=newLevel();
			if(sym->isFalse==""){
				sym->isFalse=newLevel();
			}
			rel_expression(sym->child[0]);
			assemble<<"\tCMP AX, 0"<<endl;
			if(sym->child[1]->getName()=="&&"){
				assemble<<"\tJNE "<<midlevel<<endl;
				assemble<<"\tJMP "<<sym->isFalse<<endl;
			}else{
				assemble<<"\tJNE "<<sym->isTrue<<endl;
				assemble<<"\tJMP "<<midlevel<<endl;
			}
			assemble<<midlevel<<":"<<endl;
			rel_expression(sym->child[2]);
			assemble<<"\tCMP AX, 0"<<endl;
			assemble<<"\tJNE "<<sym->isTrue<<endl;
			assemble<<"\tJMP "<<sym->isFalse<<endl;
			if(!sym->isCond){
				assemble<<sym->isTrue<<":"<<endl;
				assemble<<"\tMOV AX, 1       ; Line "<<sym->startLine<<endl;
				assemble<<"\tJMP "<<levelout<<endl;
				assemble<<sym->isFalse<<":"<<endl;
				assemble<<"\tMOV AX,0"<<endl;
				assemble<<levelout<<":"<<endl;
			}

		}
	}

	void variable(SymbolInfo* sym){
		if(sym->getName()=="ID"){
			if(sym->isGlobal){
				assemble<<"\tMOV AX, "<<sym->child[0]->getName()<<"       ; Line "<<sym->startLine<<endl;
			}else if(!sym->isParam){
				assemble<<"\tMOV AX, [BP-"<<sym->offset<<"]       ; Line "<<sym->startLine<<endl;
			}else{
				assemble<<"\tMOV AX, [BP+"<<sym->offset<<"]       ; Line "<<sym->startLine<<endl;
			}
		}else if(sym->getName()=="ID LTHIRD expression RTHIRD"){

		}

	}

	void expression(SymbolInfo* sym){
		if(sym->getName()=="logic_expression"){
			sym->child[0]->isCond=sym->isCond;
			sym->child[0]->isTrue=sym->isTrue;
			sym->child[0]->isFalse=sym->isFalse;
			logic_expression(sym->child[0]);
		}else if(sym->getName()=="variable ASSIGNOP logic_expression"){
			//variable(sym->child[0]);
			logic_expression(sym->child[2]);
			//assemble<<"\tMOV AX, "<<sym->child[2]->varVal<<"       ; Line "<<sym->startLine<<endl;       
			if(sym->child[0]->isGlobal){
				assemble<<"\tMOV "<<sym->child[0]->varName<<", AX"<<endl;
			}else if(!sym->child[0]->isParam){
				//SymbolInfo* temp =table.lookUp(sym->child[0]->varName);
				assemble<<"\tMOV [BP-"<<sym->child[0]->offset<<"], AX"<<endl;
			}else{
				assemble<<"\tMOV [BP+"<<sym->child[0]->offset<<"], AX"<<endl;
			}
		}
	}

	void expression_statement(SymbolInfo* sym){
		if(sym->getName()=="expression SEMICOLON"){
			sym->child[0]->isCond=sym->isCond;
			sym->child[0]->isTrue=sym->isTrue;
			sym->child[0]->isFalse=sym->isFalse;
			expression(sym->child[0]);
		}
	}

	void statement(SymbolInfo* sym){
		if(sym->getName()=="var_declaration"){
			var_dec=true;
			var_declaration(sym->child[0]);
		}else if(sym->getName()=="expression_statement"){
			sym->child[0]->isCond=sym->isCond;
			sym->child[0]->isTrue=sym->isTrue;
			sym->child[0]->isFalse=sym->isFalse;
			expression_statement(sym->child[0]);
		}else if(sym->getName()=="compound_statement"){
			sym->child[0]->isEnd=newLevel();
			compound_statement(sym->child[0]);
		}else if(sym->getName()=="FOR LPAREN expression_statement expression_statement expression RPAREN statement"){
			//Later
			expression_statement(sym->child[2]);
			string forLoop=newLevel();
			assemble<<forLoop<<":\n";

			sym->child[3]->isCond=true;
			sym->child[3]->isTrue=newLevel();
			sym->child[3]->isFalse=sym->isEnd;
			sym->child[6]->isEnd=newLevel();
		
			expression_statement(sym->child[3]);
			assemble<<sym->child[3]->isTrue<<":\n";
			
			statement(sym->child[6]);
		
			expression(sym->child[4]);
			assemble<<"\tJMP "<<forLoop<<endl;
		}else if(sym->getName()=="IF LPAREN expression RPAREN statement"){
			sym->child[2]->isCond=true;
			sym->child[2]->isTrue=newLevel();
			sym->child[2]->isFalse=sym->isEnd;
			sym->child[4]->isEnd=sym->isEnd;
			expression(sym->child[2]);
			assemble<<sym->child[2]->isTrue<<":\n";
			statement(sym->child[4]);
			//Later
		}else if(sym->getName()=="IF LPAREN expression RPAREN statement ELSE statement"){
			sym->child[2]->isCond=true;
			sym->child[2]->isTrue=newLevel();
			sym->child[2]->isFalse=newLevel();
			sym->child[4]->isEnd=sym->child[2]->isFalse;
			sym->child[6]->isEnd=sym->isEnd;
			expression(sym->child[2]);
			assemble<<sym->child[2]->isTrue<<":\n";
			statement(sym->child[4]);
			assemble<<"\tJMP "<<sym->isEnd<<endl;
			assemble<<sym->child[2]->isFalse<<":\n";
			statement(sym->child[6]);
		}else if(sym->getName()=="WHILE LPAREN expression RPAREN statement"){
			string whileLoop=newLevel();
			sym->child[2]->isCond=true;
			sym->child[2]->isTrue=newLevel();
			sym->child[2]->isFalse=sym->isEnd;
			sym->child[4]->isEnd=sym->isEnd;
			cout<<"expression "<<sym->child[2]->isCond<<endl;
			assemble<<whileLoop<<":\n";

			expression(sym->child[2]);
			assemble<<sym->child[2]->isTrue<<":\n";
				
			statement(sym->child[4]);

			assemble<<"\tJMP "<<whileLoop<<endl;
			//Later
		}else if(sym->getName()=="PRINTLN LPAREN ID RPAREN SEMICOLON"){
			//cout<<"abc"<<endl;
			bool global=false;
			for(auto i: globalVariables){
				if(i->getName()==sym->child[2]->getName()){
					//cout<<i->getName()<<" global "<<sym->child[2]->getName()<<endl;
					global=true;
				}
			}
			
			if(!global){
				//cout<<sym->child[2]->getName()<<sym->child[2]->offset<<endl;
				assemble<<"\tMOV AX, "<<"[BP-"<<sym->child[2]->offset<<"]       ; Line "<<sym->startLine<<endl;
			}else {
				assemble<<"\tMOV AX, "<<sym->child[2]->getName()<<"       ; Line "<<sym->startLine<<endl;
			}
			assemble<<"\tCALL print_output"<<endl;
			assemble<<"\tCALL new_line"<<endl;
		}else if(sym->getName()=="RETURN expression SEMICOLON"){
			expression(sym->child[1]);
			assemble<<"\tJMP "<<sym->isEnd<<endl;
		}
	}

	void statements(SymbolInfo* sym){
		if(sym->getName()=="statement"){
			sym->child[0]->isEnd=sym->isEnd;
			statement(sym->child[0]);
			assemble<<sym->child[0]->isEnd<<":"<<endl;
		}else if(sym->getName()=="statements statement"){
			sym->child[0]->isEnd=newLevel();
			sym->child[1]->isEnd=sym->isEnd;
			statements(sym->child[0]);
			statement(sym->child[1]);
			//assemble<<sym->child[0]->isEnd<<":"<<endl;
			assemble<<sym->child[1]->isEnd<<":"<<endl;
		}
		
	}

	void declaration_list(SymbolInfo* sym){
		if(sym->getName()=="declaration_list COMMA ID"){
			declaration_list(sym->child[0]);
		}else if(sym->getName()=="declaration_list COMMA ID LTHIRD CONST_INT RTHIRD"){
			declaration_list(sym->child[0]);
		}else if(sym->getName()=="ID"){
			
		}else if(sym->getName()=="ID LTHIRD CONST_INT RTHIRD"){

		}
	}

	void compound_statement(SymbolInfo* sym){
		if(sym->getName()=="LCURL statements RCURL"){
			if(sym->isEnd==""){
				sym->isEnd=newLevel();
			}
			sym->child[1]->isEnd=sym->isEnd;
			statements(sym->child[1]);
		}
	}

	void var_declaration(SymbolInfo* sym){
		declaration_list(sym->child[1]);
		for(int i=0;i<sym->child[1]->decList.size();i++){
			if(! sym->child[1]->decList[i]->isGlobal){
				assemble<<"\tSUB SP, 2"<<endl;
			}
		}	
	}

	void parameter_list(SymbolInfo* sym){
		if(sym->getName()=="parameter_list COMMA type_specifier ID" ){
			parameter_list(sym->child[0]);
			//cout<<sym->child[1]->getName()<<"= name ::"<<endl;
		}else if(sym->getType()=="parameter_list" && sym->getName()=="parameter_list COMMA type_specifier" ){
			parameter_list(sym->child[0]);	
		}else if(sym->getType()=="parameter_list" && sym->getName()=="type_specifier ID" ){
			return;
		}else if(sym->getType()=="parameter_list" && sym->getName()=="type_specifier" ){
			return;		
		}
	}

	// void func_declaration(SymbolInfo* sym){

	// }

	void func_definition(SymbolInfo* sym){
		string func_name=sym->child[1]->getName();
		assemble<<func_name<<" PROC"<<endl;
		if(func_name=="main"){
			assemble<<"\tMOV AX, @DATA"<<endl;
			assemble<<"\tMOV DS, AX"<<endl;
		}
		assemble<<"\tPUSH BP"<<endl;
		assemble<<"\tMOV BP, SP"<<endl;
		if(sym->getName()=="type_specifier ID LPAREN parameter_list RPAREN compound_statement"){
			parameter_list(sym->child[3]);
			compound_statement(sym->child[5]);
		}
		if(sym->getName()=="type_specifier ID LPAREN RPAREN compound_statement"){
			compound_statement(sym->child[4]);
		}
		//assemble<<"\tADD SP, "<<sym->child[4]->offset<<endl;
		if(var_dec){
			assemble<<"\tADD SP, "<<sym->offset<<endl;
			assemble<<"\tPOP BP"<<endl;	
			var_dec=false;
		}else{
			assemble<<"\tPOP BP"<<endl;	
		}
		
		if(func_name=="main"){
			assemble<<"\tMOV AX,4CH"<<endl;
			assemble<<"\tINT 21H"<<endl;
		}else{
			assemble<<"\tRET "<<sym->retVal<<endl;
		}
		assemble<<sym->child[1]->getName()<<" ENDP\n";
	}

	void unit(SymbolInfo* sym){
		if(sym->getName()=="var_declaration"){
			var_declaration(sym->child[0]);
		}else if(sym->getName()=="func_declaration"){
			//func_declaration(sym->child[0]);
		}else if(sym->getName()=="func_definition"){
			func_definition(sym->child[0]);
		}
	}

	void program(SymbolInfo* sym){
		if(sym->getName()=="program unit"){
			program(sym->child[0]);
			unit(sym->child[1]);
		}
		if(sym->getName()=="unit"){
			unit(sym->child[0]);
		}
	}

	void printNewLine(){
		assemble<<"new_line proc"<<endl;
		assemble<<"\tpush ax"<<endl;
		assemble<<"\tpush dx"<<endl;
		assemble<<"\tmov ah,2"<<endl;
		assemble<<"\tmov dl,0Dh"<<endl;
		assemble<<"\tint 21h"<<endl;
		assemble<<"\tmov ah,2"<<endl;
		assemble<<"\tmov dl,0Ah"<<endl;
		assemble<<"\tint 21h"<<endl;
		assemble<<"\tpop dx"<<endl;
		assemble<<"\tpop ax"<<endl;
		assemble<<"\tret"<<endl;
		assemble<<"new_line endp"<<endl;
	}

	void printOutput(){
		assemble<<"print_output proc  ;print what is in ax"<<endl;
		assemble<<"\tpush ax"<<endl;
		assemble<<"\tpush bx"<<endl;
		assemble<<"\tpush cx"<<endl;
		assemble<<"\tpush dx"<<endl;
		assemble<<"\tpush si"<<endl;
		assemble<<"\tlea si,number"<<endl;
		assemble<<"\tmov bx,10"<<endl;
		assemble<<"\tadd si,4"<<endl;
		assemble<<"\tcmp ax,0"<<endl;
		assemble<<"\tjnge negate"<<endl;
		assemble<<"print:"<<endl;
		assemble<<"\txor dx,dx"<<endl;
		assemble<<"\tdiv bx"<<endl;
		assemble<<"\tmov [si],dl"<<endl;
		assemble<<"\tadd [si],'0'"<<endl;
		assemble<<"\tdec si"<<endl;
		assemble<<"\tcmp ax,0"<<endl;
		assemble<<"\tjne print"<<endl;
		assemble<<"\tinc si"<<endl;
		assemble<<"\tlea dx,si"<<endl;
		assemble<<"\tmov ah,9"<<endl;
		assemble<<"\tint 21h"<<endl;
		assemble<<"\tpop si"<<endl;
		assemble<<"\tpop dx"<<endl;
		assemble<<"\tpop cx"<<endl;
		assemble<<"\tpop bx"<<endl;
		assemble<<"\tpop ax"<<endl;
		assemble<<"\tret"<<endl;
		assemble<<"negate:"<<endl;
		assemble<<"\tpush ax"<<endl;
		assemble<<"\tmov ah,2"<<endl;
		assemble<<"\tmov dl,'-'"<<endl;
		assemble<<"\tint 21h"<<endl;
		assemble<<"\tpop ax"<<endl;
		assemble<<"\tneg ax"<<endl;
		assemble<<"\tjmp print"<<endl;
		assemble<<"print_output endp"<<endl;
	}

	void start(SymbolInfo* sym){
		assemble<<".MODEL SMALL"<<endl;
		assemble<<".STACK 1000H"<<endl;
		assemble<<".Data"<<endl;
		assemble<<"\tnumber DB \"00000$\""<<endl;
		for(auto i: globalVariables){
			assemble<<"\t"<<i->getName()<<" DW "<<i->arraySize<<" DUP (0000H)"<<endl;
		}
		assemble<<".CODE"<<endl;
		program(sym->child[0]);
		printOutput();
		printNewLine();
		assemble<<"END main"<<endl;
	}

};




// #endif