#include "Hoffman.h"


Hoffman::Hoffman()
{
	count=0;
	buf=0;
}

struct Hoffman::NodeCompare
{
	bool operator()(const Node* l, const Node* r) const { return l->matches < r->matches; }
};

Node* Hoffman::pyramidNode(std::list<Node*> &package)
{
	while (package.size()!=1)
	{  
		package.sort(Hoffman::NodeCompare());//отсортировали по возрастанию
		Node *LeftSon = package.front();//указали на 2 самых первых элемента и удалили их
		package.pop_front();
		Node *RightSon = package.front(); 
		package.pop_front();
		Node *parent = new Node(LeftSon,RightSon); //создали новый узел, который является родителем
		package.push_back(parent);

	}
	return(package.front()) ;  //root - указатель на вершину дерева
}

void Hoffman::printPiramid(Node* root,unsigned k)
{
	if(root != NULL)
	{
		printPiramid(root->left,k+3);
		for(unsigned i=0;i<k;i++)
		{
			std::cout<<" ";
		}
		if(root->letter) std::cout<<root->matches<<"("<<root->letter<<")"<<std::endl;
		else std::cout<<root->matches<<std::endl;
		printPiramid(root->right,k+3);
	}
}

void Hoffman::buildTable(Node *root)//кодировка символа
{
	if (root->left!=NULL) 
	{
		encode.push_back(0);
		buildTable(root->left);
	}
	if (root->right!=NULL)
	{ 
		encode.push_back(1);
		buildTable(root->right);
	}
	if( root->letter) catalogue[root->letter]=encode;
	encode.pop_back();
}

void Hoffman::printCoding()
{
	for (std::map<char,std::vector<bool> >::iterator itr=catalogue.begin(); itr!=catalogue.end(); itr++)
	{
		std::cout <<std::endl<< itr->first << ": ";
		std::vector<bool>& vec = itr->second;
		for (std::vector<bool>::iterator it = vec.begin(); it != vec.end(); ++it)
		{
			std::cout << *it ;
		}
	}
	std::cout<<std::endl;
}

void Hoffman::archiving(std::ifstream &f,std::ofstream &g,std::map<char,int> &counting)
{
	int sz = counting.size();
	g.write(reinterpret_cast<char *>(&sz), sizeof(sz));
	for (std::map<char, int>::iterator i = counting.begin(); i != counting.end(); ++i)
	{
		char fr = i->first;
		int sc = i->second;
		g.write(reinterpret_cast<char *>(&fr), sizeof(char));
		g.write(reinterpret_cast<char *>(&sc), sizeof(int));
	}
	while((c1=f.get()) != EOF)//считали из файла букву,чтобы входили и пробелы
	{
		std::vector<bool>x=catalogue[c1];//используя ключ мы выводим код
		for(int n=0;n<x.size();n++)
		{
			if(DEBUG) std::cout <<x[n];//выведем на экран
			///////выведем в файл///////
			buf=buf | x[n]<<(7-count);//изначально buf 00000000
			count++;
			if(count==8){count=0;g.put(buf);buf=0;}
		}
		std::cout<<" ";
	}
	if( count > 0) g.put(buf);
	std::cout<<std::endl;
}

void Hoffman::buildingTheTree(std::map<char,int> &counting){
	for( std::map<char,int>::iterator itr=counting.begin(); itr!=counting.end(); ++itr)
	{
		Node *p = new Node;
		p->letter = itr->first;
		p->matches = itr->second;
		t.push_back(p);      }	
}


void Hoffman::unzipping(std::ifstream &F,std::map<char,int> &counting)
{
	int sz;
	F.read(reinterpret_cast<char *>(&sz), sizeof(sz));//считали размер

	for (int i = 0; i < sz; ++i)//считали символы и количество каждого встречающего символа
	{
		char fr;
		int sc;
		F.read(reinterpret_cast<char *>(&fr), sizeof(char));
		F.read(reinterpret_cast<char *>(&sc), sizeof(int));
		counting[fr] = sc;
	}

	buildingTheTree(counting);//разносим значения
	Node *root =pyramidNode(t);//строим дерево
	std::ofstream O("outText.txt", std::ios::out | std::ios::binary);
	Node *pp = root;
	count=0;
	char byte;
	byte = F.get();
	while(!F.eof())
	{
		bool b = byte & (1 << (7-count) ); //проверка, что впереди 0 или 1
		if (b) pp=pp->right; else pp=pp->left;
		if (pp->left==NULL && pp->right==NULL)
		{
			std::cout<<pp->letter;
			O<<(pp->letter);
			pp=root;
		}  
		count++;
		if (count==8) {count=0; byte = F.get();}
	}
	O.close();
}




