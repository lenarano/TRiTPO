#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>
#include "Node.h"
#include "Hoffman.h"

using namespace std;

int main()
{ Node Wood;Hoffman Нoff;
	/*Node Wood;
	ifstream f("text.txt", ios::in | ios::binary);
	Wood.calculation(f);//просчитали количество совпадающих символов
	Wood.buildingTheTree();// записываем начальные узлы в список list(этап, когда мы распологаем символ и количество его вхождений)
	Hoffman Нoff;
	Node *root = Нoff.pyramidNode(Wood.package);//создаем пирамиду из символов
	if(DEBUG) Нoff.printPiramid(root);//в режиме отладки нарисовать процесс построения дерева
	Нoff.buildTable(root);//кодировка символа
	if(DEBUG) Нoff.printCoding();//в режиме отладки нарисовать кодировку символов
	/////Перемещаем указатель вначало///////
	f.clear();
	f.seekg(0);//перемещаем указатель на 0
	ofstream g("output.bin", ios::out | ios::binary);
	Нoff.archiving(f,g,Wood.counting);//процесс архивации
	f.close();
	g.close();*/
	ifstream F("output.bin", ios::in | ios::binary);
	Нoff.unzipping(F,Wood.counting);//разархивация
	F.close();
	cout<<endl;
	system("pause");
	return 0;
}
