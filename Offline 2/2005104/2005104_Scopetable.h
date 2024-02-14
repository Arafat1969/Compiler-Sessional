#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include "2005104_SymbolInfo.h"
using namespace std;

unsigned long long int SDBMHash(string str) {
	unsigned long long int  hash = 0;
	int  i = 0;
	int len = str.length();
    
	for (i = 0; i < len; i++){
        int a= str[i];
        
		hash =  a + (hash << 6) + (hash << 16) - hash;
	}
	return hash;
};

class ScopeTable{
    SymbolInfo** table;
    int maxBuckets;
    ScopeTable* parentScope;
    string scopeId;
    int maxChildId;
    public:
    ScopeTable(int maxBuckets,string scopeId,ScopeTable* parentScope=nullptr){
        
        this->maxBuckets=maxBuckets;
        this->scopeId=scopeId;
        this->parentScope=parentScope;
        maxChildId=0;
        table= new SymbolInfo*[this->maxBuckets];
        for(int i=0;i<this->maxBuckets;i++){
            table[i]=nullptr;
        }
    }

    void setMaxBuckets(int n){
        maxBuckets=n;
    }

    int getMaxBuckets(){
        return maxBuckets;
    }
    void setMaxChildId(int id){
        maxChildId=id;
    }

    int getMaxChildId(){
        return maxChildId;
    }

    string getScopeId(){
        return scopeId;
    }

    ScopeTable* getParentScope(){
        return parentScope;
    }

    unsigned long long int hashValue(string name){
        return SDBMHash(name)%maxBuckets;
    }

    bool Insert(SymbolInfo symbol){
        int index=hashValue(symbol.getName());
        if(table[index]==nullptr){
            table[index]=new SymbolInfo(symbol);
            //myOutput<<'\t'<<"Inserted  at position <"<<index+1<<", 1> of ScopeTable# "<<getScopeId()<<endl;
        }else{
            int i=1;
            auto curr=table[index];
            while(curr->getNext()!=nullptr){
                if(curr->getName()==symbol.getName() ){
                    //myOutput<<"\t";
                    //myOutput<<"'"<<symbol.getName()<<"' already exists in the current ScopeTable# "<<getScopeId()<<endl;
                    return false;
                }
                curr=curr->getNext();
                i++;
            }
            if(curr->getName()==symbol.getName() ){
                    //myOutput<<"\t";
                    //myOutput<<"'"<<symbol.getName()<<"' already exists in the current ScopeTable# "<<getScopeId()<<endl;
                    return false;
            }else{
                SymbolInfo* newSymbol=new SymbolInfo(symbol);
                curr->setNext(newSymbol);
                //myOutput<<'\t'<<"Inserted  at position <"<<index+1<<", "<<i+1<<"> of ScopeTable# "<<getScopeId()<<endl;
            }
            
        }
        return true;
    }

    SymbolInfo* LookUp(string name){
        auto index=hashValue(name);
        int i=1;
        for(auto curr=table[index];curr!=nullptr; curr=curr->getNext() ){//3 3
            if(curr->getName()==name){
                //myOutput<<"\t"<<"'"<<name<<"' found at position <"<<index+1<<","<<" "<<i<<"> of ScopeTable# "<<getScopeId()<<endl;
                return curr;
            }
            i++;//3
        }
        return nullptr;
    }
    bool Delete(string name){
        auto index=hashValue(name);
        auto curr=table[index];
        if(table[index]==nullptr){
            //myOutput<<"\t";
            //myOutput<<"Not found in the current ScopeTable# "<<getScopeId()<<endl;
            return false;
        }
        if(curr->getName()==name){
            table[index]=curr->getNext();
            delete curr;
            //myOutput<<"\t";
            //myOutput<<"Deleted '"<<name<<"' from position <"<<index+1<<", 1> of ScopeTable# "<<getScopeId()<<endl;
            return true;
        }else{
            auto prev=curr;
            int i=2;
            for(curr=curr->getNext();curr!=nullptr;curr=curr->getNext()){
                if(curr->getName()==name){
                    prev->setNext(curr->getNext());
                    delete curr;
                    //myOutput<<"\t";
                    //myOutput<<"Deleted '"<<name<<"' from position <"<<index+1<<", "<< i<<"> of ScopeTable# "<<getScopeId()<<endl;
                    return true;
                }
            }
        }
        //myOutput<<"\t";
        //myOutput<<"Not found in the current ScopeTable# "<<getScopeId()<<endl;
        return false;
    }

    string Print(){
        string str="";
        str+="\t";
        str+="ScopeTable# "+getScopeId()+"\n";
        for(int i=0;i<getMaxBuckets();i++){
            str+="\t";
            str+=to_string(i+1);
            if(table[i]!=nullptr){
                for(SymbolInfo* curr=table[i];curr!=nullptr;curr=curr->getNext()){
                    str+=" --> ";
                    str+="("+curr->getName()+","+curr->getType()+")";
                }
            }
            str+="\n";
        }
        return str;
    }
    ~ScopeTable(){
        for(int i = 0; i < maxBuckets; i++){
			auto curr=table[i];
            while(curr!=nullptr){
                auto t = curr->getNext();
                delete curr;
                curr = t;
            }
		}
		delete[] table;
        //myOutput<<"\t";
        //myOutput<<"ScopeTable# "<<getScopeId()<<" deleted"<<endl;
    }
};