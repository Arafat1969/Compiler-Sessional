#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

ifstream myInput;
ofstream myOutput;

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
    
    friend ostream& operator<<(ostream &os,SymbolInfo symbol){
        os << "("<<symbol.getName()<<","<<symbol.getType()<<")";
        return os;
    }

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
            myOutput<<'\t'<<"Inserted  at position <"<<index+1<<", 1> of ScopeTable# "<<getScopeId()<<endl;
        }else{
            int i=1;
            auto curr=table[index];
            while(curr->getNext()!=nullptr){
                if(curr->getName()==symbol.getName() ){
                    myOutput<<"\t";
                    myOutput<<"'"<<symbol.getName()<<"' already exists in the current ScopeTable# "<<getScopeId()<<endl;
                    return false;
                }
                curr=curr->getNext();
                i++;
            }
            if(curr->getName()==symbol.getName() ){
                    myOutput<<"\t";
                    myOutput<<"'"<<symbol.getName()<<"' already exists in the current ScopeTable# "<<getScopeId()<<endl;
                    return false;
            }else{
                SymbolInfo* newSymbol=new SymbolInfo(symbol);
                curr->setNext(newSymbol);
                myOutput<<'\t'<<"Inserted  at position <"<<index+1<<", "<<i+1<<"> of ScopeTable# "<<getScopeId()<<endl;
            }
            
        }
        return true;
    }

    SymbolInfo* LookUp(string name){
        auto index=hashValue(name);
        int i=1;
        for(auto curr=table[index];curr!=nullptr; curr=curr->getNext() ){//3 3
            if(curr->getName()==name){
                myOutput<<"\t"<<"'"<<name<<"' found at position <"<<index+1<<","<<" "<<i<<"> of ScopeTable# "<<getScopeId()<<endl;
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
            myOutput<<"\t";
            myOutput<<"Not found in the current ScopeTable# "<<getScopeId()<<endl;
            return false;
        }
        if(curr->getName()==name){
            table[index]=curr->getNext();
            delete curr;
            myOutput<<"\t";
            myOutput<<"Deleted '"<<name<<"' from position <"<<index+1<<", 1> of ScopeTable# "<<getScopeId()<<endl;
            return true;
        }else{
            auto prev=curr;
            int i=2;
            for(curr=curr->getNext();curr!=nullptr;curr=curr->getNext()){
                if(curr->getName()==name){
                    prev->setNext(curr->getNext());
                    delete curr;
                    myOutput<<"\t";
                    myOutput<<"Deleted '"<<name<<"' from position <"<<index+1<<", "<< i<<"> of ScopeTable# "<<getScopeId()<<endl;
                    return true;
                }
            }
        }
        myOutput<<"\t";
        myOutput<<"Not found in the current ScopeTable# "<<getScopeId()<<endl;
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
                    //myOutput<< *curr;
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
        myOutput<<"\t";
        myOutput<<"ScopeTable# "<<getScopeId()<<" deleted"<<endl;
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
            currentScope=new ScopeTable(maxSize,"1",currentScope);;
        }else{
            int childScopeId=currentScope->getMaxChildId();
            currentScope->setMaxChildId(childScopeId+1);
            string id = currentScope->getScopeId()+"."+to_string(childScopeId+1);
            auto s=new ScopeTable(maxSize,id,currentScope);
            currentScope=s;
        }
        myOutput<<"\t"<<"ScopeTable# "<<currentScope->getScopeId()<<" created"<<endl;
    }
    void exitScope(){
        auto t= currentScope->getParentScope();
        if(t==nullptr){
            myOutput<<"\t";
            myOutput<<"ScopeTable# 1 cannot be deleted"<<endl;
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
        string str=" ";
        for(auto curr=currentScope;curr!=nullptr;curr=curr->getParentScope()){
            str+= curr->Print();
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

int main(){
    myOutput.open("output.txt");
    myInput.open("input.txt");
    if(!myInput){

        cout<<"File not valid"<<endl;
    }
    string line;
    getline(myInput,line);
    istringstream s(line);
    int noOfBuckets;
    s>>noOfBuckets;
    SymbolTable s_table(noOfBuckets);
    for(int i=0; ;i++){
        string line2;
        getline(myInput,line2);
        istringstream s1(line2);
        string instruction;
        string param1,param2;
        s1>>instruction;
        s1>>param1;
        s1>>param2;
        myOutput<<"Cmd "<<i+1<<": "<<instruction<<(param1==""?"":" ")<<param1<<(param2==""?"":" ")<<param2<<endl;
        if(instruction=="I"){
            if( param1=="" || param2==""){
                myOutput<<"\t";
                myOutput<< "Wrong number of arugments for the command I"<<endl;
                continue;
            }
            SymbolInfo symbol(param1,param2);
            s_table.insert(symbol);
        }
        else if(instruction=="L"){
            if(param1=="" || param2!=""){
                myOutput<<"\t";
                myOutput<< "Wrong number of arugments for the command L"<<endl;
                continue;
            }
            SymbolInfo* s= s_table.lookUp(param1);
            if(s==nullptr){
                myOutput<<"\t";
                myOutput<< "'"<<param1<<"' not found in any of the ScopeTables"<<endl;
            }
        }
        else if(instruction=="D"){
            if(param1=="" || param2!=""){
                myOutput<<"\t";
                myOutput<< "Wrong number of arugments for the command D"<<endl;
                continue;
            }
            bool s= s_table.remove(param1);
        }
        else if(instruction=="P"){
            if((param1!="A" && param1!="C" )|| param2!=""){
                myOutput<<"\t";
                myOutput<< "Invalid argument for the command P"<<endl;
                continue;
            }
            if(param1=="A"){
                string str =s_table.printAllScopeTable();
                myOutput<<str;
                continue;
            }
            if(param1=="C"){
                string str= s_table.printCurrentScopeTable();
                myOutput<<str;
                continue;
            }
        }
        else if(instruction=="S"){
            if(param1!="" || param2!=""){
                myOutput<<"\t";
                
                myOutput<< "Invalid argument for the command S"<<endl;
                continue;
            }
            s_table.enterScope();
        }
        else if(instruction=="E"){
            if(param1!="" || param2!=""){
                myOutput<<"\t";
                myOutput<< "Invalid argument for the command E"<<endl;
                continue;
            }
            s_table.exitScope();
        }
        else if(instruction=="Q"){
            return 0;
        }
        else{
            myOutput<<"Invalid Command"<<endl;
        }
    }
    return 0;
}