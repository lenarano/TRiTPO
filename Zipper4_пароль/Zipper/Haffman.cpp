#include "Haffman.h"



Haffman::Haffman()
{
	count=0;
	buf=0;

}

Haffman::~Haffman()
{

}

struct Haffman::NodeCompare
{
	bool operator()(const Node* l, const Node* r) const { return l->matches < r->matches; }
};

Node* Haffman::pyramidNode(std::list<Node*> &package)
{
	while (package.size()!=1)
	{  
		package.sort(Haffman::NodeCompare());//������������� �� �����������
		Node *LeftSon = package.front();//������� �� 2 ����� ������ �������� � ������� ��
		package.pop_front();
		Node *RightSon = package.front(); 
		package.pop_front();
		Node *parent = new Node(LeftSon,RightSon); //������� ����� ����, ������� �������� ���������
		package.push_back(parent);

	}
	return(package.front()) ;  //root - ��������� �� ������� ������
}

void Haffman::printPiramid(Node* root,unsigned k)
{
	if(root != NULL)
	{
		printPiramid(root->getLeft(),k+3);
		for(unsigned i=0;i<k;i++)
		{
			std::cout<<" ";
		}
		if(root->getLetter()) std::cout<<root->matches<<"("<<root->getLetter()<<")"<<std::endl;
		else std::cout<<root->matches<<std::endl;
		printPiramid(root->getRight(),k+3);
	}
}

void Haffman::buildTable(Node *root)//��������� �������
{
	if (root->getLeft()!=NULL) 
	{
		encode.push_back(0);
		buildTable(root->getLeft());
	}
	if (root->getRight()!=NULL)
	{ 
		encode.push_back(1);
		buildTable(root->getRight());
	}
	if( root->getLetter()) catalogue[root->getLetter()]=encode;
	encode.pop_back();
}

void Haffman::printCoding()
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

void Haffman::compression(std::ifstream &f,std::ofstream &g,std::map<char,int> &counting)
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
	while((c1=f.get()) != EOF)//������� �� ����� �����,����� ������� � �������
	{
		std::vector<bool>x=catalogue[c1];//��������� ���� �� ������� ���
		for(int n=0;n<x.size();n++)
		{
			if(DEBUG) std::cout <<x[n];//������� �� �����
			///////������� � ����///////
			buf=buf | x[n]<<(7-count);//���������� buf 00000000
			count++;
			if(count==8){count=0;g.put(buf);buf=0;}
		}
		std::cout<<" ";
	}
	if( count > 0)
	{ 
		count=0;
		g.put(buf);
		buf=0;
	}
	std::cout<<std::endl;
}

void Haffman::buildingTheTree(std::map<char,int> &counting){
	t.clear();
	for( std::map<char,int>::iterator itr=counting.begin(); itr!=counting.end(); ++itr)
	{
		Node *p = new Node;
		p->setLetter( itr->first);
		p->matches = itr->second;
		t.push_back(p);      }	

}

void Haffman::archiving(Package *zip,Node &Wood,Haffman &�off)
{
	std::ifstream f(zip->getReal_bin_file(), std::ios::in | std::ios::binary);
	Wood.calculation(f);//���������� ���������� ����������� ��������
	Wood.buildingTheTree();// ���������� ��������� ���� � ������ list(����, ����� �� ����������� ������ � ���������� ��� ���������)
	Node *root = �off.pyramidNode(Wood.getPackage());//������� �������� �� ��������
	if(DEBUG) �off.printPiramid(root);//� ������ ������� ���������� ������� ���������� ������
	�off.buildTable(root);//��������� �������
	if(DEBUG) �off.printCoding();//� ������ ������� ���������� ��������� ��������
	/////���������� ��������� �������///////
	f.clear();
	f.seekg(0);//���������� ��������� �� 0
	std::ofstream g(zip->getHoff_bin_file(), std::ios::out | std::ios::binary);
	�off.compression(f,g,Wood.getCounting());//������� ���������
	f.close();
	g.close();
	remove((zip->getReal_bin_file()).c_str());//������� ��� �� ������ ������������� ����
}


void Haffman::un�ompression(std::map<char,int> &counting,std::vector<std::string> &files,Package *zip)
{ 
	counting.clear();
	std::ifstream F(files[0], std::ios::in | std::ios::binary);
	int sz;
	F.read(reinterpret_cast<char *>(&sz), sizeof(sz));//������� ������
	for (int i = 0; i < sz; ++i)//������� ������� � ���������� ������� ������������ �������
	{
		char fr;
		int sc;
		F.read(reinterpret_cast<char *>(&fr), sizeof(char));
		F.read(reinterpret_cast<char *>(&sc), sizeof(int));
		counting[fr] = sc;
	}
	buildingTheTree(counting);//�������� ��������
	Node *root =pyramidNode(t);//������ ������
	std::ofstream O(zip->getUnhoff_bin_file(), std::ios::out | std::ios::binary);
	Node *pp = root;
	count=0;
	char byte;
	byte = F.get();
	while(!F.eof())
	{
		bool b = byte & (1 << (7-count) ); //��������, ��� ������� 0 ��� 1
		if (b) pp=pp->getRight(); else pp=pp->getLeft();
		if (pp->getLeft()==NULL && pp->getRight()==NULL)
		{
			if(DEBUG) std::cout<<pp->getLetter();
			O<<(pp->getLetter());
			pp=root;
		}  
		count++;
		if (count==8) {count=0; byte = F.get();}
	}
	O.close();
	F.close();
	std::cout<<std::endl;
	remove((files[0]).c_str());
}



