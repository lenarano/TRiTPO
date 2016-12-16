#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>
#include "Node.h"
#include "Hoffman.h"
#include "Package.h"

using namespace std;

int main(int argv, char* argc[])
{ 
	Node Wood;
	Hoffman Нoff;
	/*/ Suppotred args:
	//
	// -pack, -unpack, -files, -path
	//
	/*/
	setlocale(LC_ALL,"Russian");
	cout<<endl<<"######################## ZIPPER ########################"<<endl<<endl;

	if(argv>1)
	{//-pack -files C:\test\text1.txt C:\test\text2.txt C:\test\text3.txt -path C:\test
		//	-unpack -files C:\test\zipper.bin -path C:\test\unpack
		vector<string> files;
		string path = "";
		bool flag_fs = false, flag_path = false;
		char type[7];
		memset(type,0,7);
		for(int i=1;i<argv;i++)
		{
			if(strcmp(argc[i],"-pack")==0) { strcpy(type,"pack"); flag_fs=flag_path=false;}
			if(strcmp(argc[i],"-unpack")==0) { strcpy(type,"unpack"); flag_fs=flag_path=false;}
			if(strcmp(argc[i],"-path")==0) {flag_path=true; flag_fs=false; continue; }
			if(strcmp(argc[i],"-files")==0) {flag_fs=true; flag_path=false; continue; }

			if(flag_path) {path.assign(argc[i]); }
			if(flag_fs) files.push_back(string(argc[i]));

		}
		Package *zip = new Package(files,path);
		if(strcmp(type,"pack")==0)
		{
			zip->Packaging();
			ifstream f(zip->real_bin_file, ios::in | ios::binary);
			Wood.calculation(f);//просчитали количество совпадающих символов
			Wood.buildingTheTree();// записываем начальные узлы в список list(этап, когда мы распологаем символ и количество его вхождений)
			Node *root = Нoff.pyramidNode(Wood.package);//создаем пирамиду из символов
			if(DEBUG) Нoff.printPiramid(root);//в режиме отладки нарисовать процесс построения дерева
			Нoff.buildTable(root);//кодировка символа
			if(DEBUG) Нoff.printCoding();//в режиме отладки нарисовать кодировку символов
			/////Перемещаем указатель вначало///////
			f.clear();
			f.seekg(0);//перемещаем указатель на 0
			ofstream g(zip->hoff_bin_file, ios::out | ios::binary);
			Нoff.archiving(f,g,Wood.counting);//процесс архивации
			f.close();
			g.close();
			remove((zip->real_bin_file).c_str());//удаляем уже не нужный промежуточный файл
		}
		if(strcmp(type,"unpack")==0)
			{				
			    Нoff.unzipping(Wood.counting,zip);//разархивация
			    zip->Unpacking(zip->unhoff_bin_file);
		    }
	}
	else cout<<"Параметры -pack/-unpack , -files, -path обязательны!"<<endl;
	cout<<endl<<"########################################################"<<endl<<endl;

	
	cout<<endl;
	system("pause");
	return 0;
}
