#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include "2005104_Scopetable.h"
using namespace std;

class SymbolTable{
    ScopeTable* currentScope;
    int maxSize;
    
    public:
    SymbolTable(int maxSize){
        this->maxSize=maxSize;
        currentScope=nullptr;
        enterScope();
    }

    void enterScope(){
        if(currentScope==nullptr){
            currentScope=new ScopeTable(maxSize,"1",currentScope);;
        }else{
            int childScopeId=currentScope->getMaxChildId();
            currentScope->setMaxChildId(childScopeId+1);
            string id = currentScope->getScopeId()+"."+to_string(childScopeId+1);
            auto s=new ScopeTable(maxSize,id,currentScope);
            currentScope=s;
        }
        //myOutput<<"\t"<<"ScopeTable# "<<currentScope->getScopeId()<<" created"<<endl;
    }
    void exitScope(){
        auto t= currentScope->getParentScope();
        if(t==nullptr){
            //myOutput<<"\t";
            //myOutput<<"ScopeTable# 1 cannot be deleted"<<endl;
            return;
        }
        delete currentScope;
        currentScope=t;
    }
    bool insert(SymbolInfo symbol){
        return currentScope->Insert(symbol);
    }
    bool remove(string name){
        return currentScope->Delete(name);
    }
    SymbolInfo* lookUp(string name){
        for(auto scope=currentScope;scope!=nullptr;scope=scope->getParentScope()){
            auto symbol= scope->LookUp(name); 
            if(symbol!=nullptr){
                return symbol;
            }       
        }
        return nullptr;
    }

    string printCurrentScopeTable(){
        return currentScope->Print();
    }
    string printAllScopeTable(){
        string str="";
        for(auto curr=currentScope;curr!=nullptr;curr=curr->getParentScope()){
            str+=curr->Print();
        }
        return str;
    }
    ~SymbolTable(){
        for(auto curr = currentScope; curr != nullptr; ){
            auto t = curr->getParentScope();
            delete curr;
            curr = t;
        }
    }
};