#ifndef NODE_H
#define NODE_H


#include <iostream>
#include <fstream>
#include <map>
#include <list>



class Node
{
private:
	unsigned int symbol;
	std::map<char,int>::iterator itr;
	std::map<char,int> counting;//символ + кол-во совпадений
	std::list<Node*> package;//комплект(лист указателей на узлы)
	Node *left, *right;
	char letter;//буква
public:
	int matches;//совпадения
		
	Node();
	Node(Node *L, Node *R);
	
	void setLetter(char s);
	char getLetter();
	Node * getRight();
	Node * getLeft();
	std::list<Node*>  getPackage();
	std::map<char,int> getCounting();
	void calculation(std::ifstream &f);//просчитали количество совпадающих символов
	void buildingTheTree();// записываем начальные узлы в список list(этап, когда мы распологаем символ и количество его вхождений)

	
};





#endif NODE_H