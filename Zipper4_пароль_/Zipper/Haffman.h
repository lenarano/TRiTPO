#ifndef NAFFMAN_H
#define NAFFMAN_H
#define DEBUG true//������ � ������ �������

#include <vector>
#include "Node.h"
#include "Package.h"

class Haffman
{
private:
	struct NodeCompare;
	std::vector <bool> encode;//��� �������� � ������
	std::map<char,std::vector<bool> >catalogue;//���������� ������� � �����
	int count;
	char buf;
	unsigned int c1;
	std:: list<Node*> t;

public:
	Haffman();
	~Haffman();

	void buildingTheTree( std::map<char,int> &counting);// ���������� ��������� ���� � ������ list(����, ����� �� ����������� ������ � ���������� ��� ���������)
	Node* pyramidNode(std::list<Node*> &package);//������� �������� �� ��������
	void printPiramid(Node* root,unsigned k=0);//���� ���� ���������� ��� �������� ��������
	void buildTable(Node *root);//��������� �������
	void printCoding();//���� ���� ���������� ��������� �������
	void compression(std::ifstream &f,std::ofstream &g,std::map<char,int> &counting);//������� ���������
	void archiving(Package *zip,Node &Wood,Haffman &�off);
	void un�ompression(std::map<char,int> &counting,std::vector<std::string> &files,Package *zip);//������������
};


#endif NOFFMAN_H