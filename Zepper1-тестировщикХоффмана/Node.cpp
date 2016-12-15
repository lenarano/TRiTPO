#include "Node.h"


Node::Node(){left=right=NULL;}

Node::Node(Node *L, Node *R) 
{  
	left =  L;
	right = R;
	matches = L->matches + R->matches; 
	letter ='+';
}

void Node::calculation(std::ifstream &f)
	{
    	while ((symbol=f.get()) != EOF)
			{
				counting[symbol]++;
		     }
	}

 void Node::buildingTheTree()
{
for( itr=counting.begin(); itr!=counting.end(); ++itr)
	{  
		Node *pointer = new Node;
		pointer->letter = itr->first;//вписали символ-ключ в  char letter класса Node
		pointer->matches= itr->second;//вписали количество вхождений символа в  int matches класса Node 
		package.push_back(pointer);     
	}	
}



