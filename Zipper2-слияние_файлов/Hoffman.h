#ifndef NOFFMAN_H
#define NOFFMAN_H
#define DEBUG false //������ � ������ �������

#include <vector>
#include "Node.h"
#include "Package.h"

class Hoffman
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
Hoffman();

void buildingTheTree( std::map<char,int> &counting);// ���������� ��������� ���� � ������ list(����, ����� �� ����������� ������ � ���������� ��� ���������)
Node* pyramidNode(std::list<Node*> &package);//������� �������� �� ��������
void printPiramid(Node* root,unsigned k=0);//���� ���� ���������� ��� �������� ��������
void buildTable(Node *root);//��������� �������
void printCoding();//���� ���� ���������� ��������� �������
void archiving(std::ifstream &f,std::ofstream &g,std::map<char,int> &counting);//������� ���������
void unzipping(std::map<char,int> &counting,Package *zip);//������������
};


#endif NOFFMAN_H