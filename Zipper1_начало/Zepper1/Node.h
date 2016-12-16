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
	
public:
	char letter;//�����
	int matches;//����������
	std::map<char,int> counting;//������ + ���-�� ����������
	std::list<Node*> package;//��������(���� ���������� �� ����)
	Node *left, *right;
	
	Node();
	Node(Node *L, Node *R);

	void calculation(std::ifstream &f);//���������� ���������� ����������� ��������
	void buildingTheTree();// ���������� ��������� ���� � ������ list(����, ����� �� ����������� ������ � ���������� ��� ���������)

	
	



};





#endif NODE_H