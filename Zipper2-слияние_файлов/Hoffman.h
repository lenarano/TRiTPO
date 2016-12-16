#ifndef NOFFMAN_H
#define NOFFMAN_H
#define DEBUG false //работа в режиме отладки

#include <vector>
#include "Node.h"
#include "Package.h"

class Hoffman
{
private:
struct NodeCompare;
std::vector <bool> encode;//код собираем в вектор
std::map<char,std::vector<bool> >catalogue;//ассоциация символа с кодом
int count;
char buf;
unsigned int c1;
std:: list<Node*> t;
public:
Hoffman();

void buildingTheTree( std::map<char,int> &counting);// записываем начальные узлы в список list(этап, когда мы распологаем символ и количество его вхождений)
Node* pyramidNode(std::list<Node*> &package);//создаем пирамиду из символов
void printPiramid(Node* root,unsigned k=0);//если надо нарисовать как строится пирамида
void buildTable(Node *root);//кодировка символа
void printCoding();//если надо нарисовать кодировку символа
void archiving(std::ifstream &f,std::ofstream &g,std::map<char,int> &counting);//процесс архивации
void unzipping(std::map<char,int> &counting,Package *zip);//разархивация
};


#endif NOFFMAN_H