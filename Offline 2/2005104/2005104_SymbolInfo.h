#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

class SymbolInfo{
    string name;
    string type;
    int chainID;
    SymbolInfo* next;

    public:
    SymbolInfo(){
        next=nullptr;
    }
    SymbolInfo(string name,string type,SymbolInfo * next=nullptr){
        this->name=name;
        this->type=type;
        this->next=next;

    }

    SymbolInfo(SymbolInfo &obj, SymbolInfo* next=nullptr){
        this->name=obj.name;
        this->type=obj.type;
        this->next=next;
    }
    void setName(string name){
        this->name=name;
    }
    string getName(){
        return name;
    }
    void setType(string type){
        this->type=type;
    }
    string getType(){
        return type;
    }
    void setNext(SymbolInfo * next){
        this->next=next;
    }
    SymbolInfo* getNext(){
        return next;
    }
};