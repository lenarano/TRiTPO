#include "Node.h"


Node::Node(){left=right=NULL;}

Node::Node(Node *L, Node *R) 
{  
	left =  L;
	right = R;
	matches = L->matches + R->matches; 
	letter ='+';
}

void Node::setLetter(char s){letter=s;}

char Node::getLetter(){return letter;}

std::list<Node*> Node:: getPackage(){return package;}

Node * Node::getRight(){return right;}

Node * Node::getLeft(){return left;}

std::map<char,int> Node::getCounting( ){return counting;}

void Node::calculation(std::ifstream &f)
{
	counting.clear();
	while ((symbol=f.get()) != EOF)
	{
		counting[symbol]++;
	}
}

void Node::buildingTheTree()
{
	package.clear();
	for( itr=counting.begin(); itr!=counting.end(); ++itr)
	{  
		Node *pointer = new Node;
		pointer->letter = itr->first;//вписали символ-ключ в  char letter класса Node
		pointer->matches= itr->second;//вписали количество вхождений символа в  int matches класса Node 
		package.push_back(pointer);     
	}	
}


