#ifndef __AST_H__
#define __AST_H__


#include<vector>
#include"2005104_SymbolInfo.h"
#include<string>
using namespace std;
class Node{
public:
    Node() = default;
    virtual void addChild(Node *child) = 0;
    virtual void addChild(vector<Node *> childs){
		for(auto i: childs){
       		addChild(i);
    	}
	}
    virtual void removeAllChild() = 0;
    virtual int getBeginLine() = 0;
    virtual int getEndLine() = 0;
    virtual vector<Node *> getChilds() = 0;
    virtual string getTokenType() = 0;
    virtual ~Node(){}
};


class TokenNode : public Node{
	string nodeType;
    string info;
    int startLine;
    int endLine;
    vector<Node *> childs;
public:
    TokenNode(string nodeType,string info, int startLineNo, int endLineNo = -1){
		this.nodeType=nodeType;
		this.info=info;
		this.startLine= startLineNo;
		if(endLineNo=-1){
			endLineNo=startLineNo;
		}
		this.endLine=endLineNo;
	}
    void addChild(Node * child) override{
		if(childs.size() == 0){
			startLine = child->getBeginLine();
		}
		childs.push_back(child);
		endLine = child->getEndLine();
	}
    vector<Node *> getChilds() override {
		return childs;
	}
    void removeAllChild() override {
		childs = vector<Node*>();
	}
    int getBeginLine() override { 
		return startLine; 
	}
    int getEndLine() override { 
		return endLine;
	}
    string getTokenType() override {
		return nodeType;
	}

	string print(int space){
		string result="";
		result+= string(space,' ');
		result+=nodeType+" : "+info;
		result+="\t\t<Line: "+to_string(startLine);
		result+="-"+to_string(endLine)+">\n";
		for(auto i: childs){
			result+=i->print(space+1);
		}
		return result;
	}

    ~TokenNode(){
		for(auto i: childs){
			delete i;
		}
	}
};

class ExpressionNode : public TokenNode{
	string dataType;
public:
    ExpressionNode(TokenNode *token, string dataType)
        : TokenNode(*token), dataType(dataType)
    {}
    
    ExpressionNode(NodeType nodeType, string info, string dataType ,int startLineNo, int endLineNo = -1)
        : TokenNode(nodeType, info, startLineNo, endLineNo) , dataType(dataType)
    {}

    string getDataType(){ 
		return dataType; 
	}
};


class SymbolNode : public Node{
    SymbolInfo *symbolInfo;
    int lineNo;
public:
    SymbolNode(SymbolInfo *symbolInfo, int lineNo);

    void addChild(Node * child) override {}
    vector<Node *> getChilds() override { return vector<Node *> ();}
    void removeAllChild() override {}

    ostream& print(ostream &os, int tab=0) override;

    int getBeginLine() override{ return lineNo; }
    int getEndLine() override{ return lineNo; }
    string getTokenType() override {return "symbol";}

    SymbolInfo* getSymbol(){ return symbolInfo;}
    void setSymbol(SymbolInfo *symbolInfo){ this->symbolInfo = symbolInfo;}

    ~SymbolNode();
};
