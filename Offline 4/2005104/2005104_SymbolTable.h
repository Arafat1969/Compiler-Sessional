#ifndef SymbolTable_h
#define SymbolTable_h


#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
extern ofstream assmble;

class SymbolInfo{
    string name;
    string type;
    int chainID;
    SymbolInfo* next;

    public:
    string varType;
    string type_specifier;
    string retType;
    bool isFunc=false;
    int arraySize=0;
    int startLine; 
    int endLine;    
    bool isInserted;
    string isEnd="";
    string isTrue="";
    string isFalse=""; 
    int offset=0; 
    string varName;
    int varVal;
    int retVal;
    bool isParam=false;
    vector<SymbolInfo*> child;
    bool isDeclared;
    bool isDefined;
    bool isGlobal=false;
    bool isCond;
    bool isLeaf;
    vector<SymbolInfo*> paraList;
    vector<SymbolInfo*> decList; 
    vector<SymbolInfo*> argList;

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

    string getTypeSpecifier(){
        return type_specifier;
    }
    string getType(){
        return type;
    }
    string getVarType(){
        return varType;
    }
    string getRetType(){
        return retType;
    }
    void setFunction(){
        isFunc=true;
    }

    bool isFunction(){
        return isFunc;
    }
    void setNext(SymbolInfo * next){
        this->next=next;
    }
    SymbolInfo* getNext(){
        return next;
    }

    string printParseTree(int space){
		string result="";
		result+= string(space,' ');
		result+=getType()+" : "+getName();
		result+=" \t<Line: "+to_string(startLine);
        if(!isLeaf){
            result+="-"+to_string(endLine);
        }
        result+=">\n";
		for(auto i: child){
			result+=i->printParseTree(space+1);
		}
		return result;
	}
};



class ScopeTable{
    SymbolInfo** table;
    int maxBuckets;
    ScopeTable* parentScope;
    int scopeId;
    int maxChildId;
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
    public:
    ScopeTable(int maxBuckets,int scopeId,ScopeTable* parentScope=nullptr){
        
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

    int getScopeId(){
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
        str+="ScopeTable# "+to_string(getScopeId())+"\n";
        for(int i=0;i<getMaxBuckets();i++){
            if(table[i]==nullptr){
                continue;
            }
            str+="\t";
            str+=to_string(i+1);
            str+="--> ";
            for(SymbolInfo* curr=table[i];curr!=nullptr;curr=curr->getNext()){
                str+="<"+curr->getName()+","+curr->getVarType();
                if(curr->isFunction()){
                    str+=","+curr->retType;
                }
                str+="> ";
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
            currentScope=new ScopeTable(maxSize,1,currentScope);;
        }else{
            int childScopeId=currentScope->getMaxChildId();
            currentScope->setMaxChildId(childScopeId+1);
            int numID=currentScope->getScopeId()+childScopeId+1;
            int id =numID;
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
    int getCurrScopeId(){
        return currentScope->getScopeId();
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

#endif