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
	std::map<char,int> counting;//������ + ���-�� ����������
	std::list<Node*> package;//��������(���� ���������� �� ����)
	Node *left, *right;
	char letter;//�����
public:
	int matches;//����������
		
	Node();
	Node(Node *L, Node *R);
	
	void setLetter(char s);
	char getLetter();
	Node * getRight();
	Node * getLeft();
	std::list<Node*>  getPackage();
	std::map<char,int> getCounting();
	void calculation(std::ifstream &f);//���������� ���������� ����������� ��������
	void buildingTheTree();// ���������� ��������� ���� � ������ list(����, ����� �� ����������� ������ � ���������� ��� ���������)

	
};





#endif NODE_H