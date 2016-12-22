#include "Package.h"

using namespace std;
Package::Package(std::vector<std::string> &vec, std::string p,std::string n)
{
	if(vec.size()>0) files.assign(vec.begin(),vec.end());
	path = p+'\\';
	name = n+".";
	real_bin_file=path+"binary.bin";
	hoff_bin_file=path+name+"zipp";
	unhoff_bin_file=path+"unzipper.bin";
}

Package::~Package()
{

}

std::string Package::getReal_bin_file(){return real_bin_file;}

std::string Package::getHoff_bin_file(){return hoff_bin_file;}

std::string Package::getUnhoff_bin_file(){return unhoff_bin_file;}

std::string Package::get_file_name(std::string fn)
{
	std::string rezultat;
	std::string rezultat1=fn.substr(fn.find_last_of("\\")+1,fn.size());
	std::string rezultat2=fn.substr(fn.find_last_of("//")+1,fn.size());
	if(rezultat1!=fn){ rezultat= rezultat1;}
	else if(rezultat2!=fn) { rezultat= rezultat2;}
	else std::cout<<"In the file name does not meet the characters // \\";//� �������� ����� �� ����������� ������� // \\

	return rezultat;
}



int Package::digs(double w)
{
	int yield = 0;
	while(w>10) {yield++;w/=10;}
	return yield+1;
}

void Package::getInfo()//��������� ���������� � ���� ������ � ���������� � ������������� ��������� ���� 
{
	char byte[1];  // ��������� ����� ��� ���������� ������ �����
	basic_string<char> s_info = "";
	remove((this->path+"info.txt").c_str());
	FILE *info;
	if((info = fopen((this->path+"info.txt").c_str(),"a+"))==NULL) // ��������� ���������� � ��� ��������� ����
	{
		printf ("Cannot open file.\n");
		getch();
		exit(1);
	}
	int bytes_size=0;  // ����� ��������������� ����� � ������
	for(vector<string>::iterator itr=this->files.begin();itr!=this->files.end();++itr)
	{
		FILE *f = fopen((*itr).c_str(),"rb");
		if(!f) break;
		// �������� ������ ������������� �����
		fseek(f,0,SEEK_END);
		int size = ftell(f);  
		string name = Package::get_file_name(*itr);  // �������� ��� ������������� �����
		char *m_size = new char[digs(size)+1];
		itoa(size,m_size,10);//char *itoa( int value, char * string, int radix );
		fclose(f);
		// ���, ��� "������", ��������� � ������������� ����� :
		s_info.append(m_size);
		s_info.append("||");
		s_info.append(name);
		s_info.append("||");
		delete [] m_size;
	}
	bytes_size = s_info.size()+2;
	char *b_buff = new char[digs(bytes_size)];
	itoa(bytes_size,b_buff,10);
	// ����������� �� 5 ����
	if(digs(bytes_size)<5)
	{
		fputs(string(5-digs(bytes_size),'0').c_str(),info);
	}
	fputs(b_buff,info);
	fputs("||",info);
	fputs(s_info.c_str(),info);
	fclose(info);
	//delete [] b_buff;
}

void Package::packaging()
{
	char byte[1];  // ��������� ����� ��� ���������� ������ �����
	getInfo();  // �������� ����������� ���������� � ���, ��� ����������
	FILE *f;
	FILE *main=fopen((this->real_bin_file).c_str(),"wb");  // ���� - �����
	FILE *info = fopen((this->path+"info.txt").c_str(),"rb");  // ���� � �����������
	// ������������ ���������� � �����
	while(!feof(info))
	{
		if(fread(byte,1,1,info)==1) fwrite(byte,1,1,main);
	}
	fclose(info);
	remove((this->path+"info.txt").c_str());  // ����������� �� �����
	// ���������������� ������ � ����� ������������ ������ �������� :
	for(vector<string>::iterator itr=this->files.begin();itr!=this->files.end();++itr)
	{
		f = fopen((*itr).c_str(),"rb");
		if(!f){ cout<<*itr<<" �� ������!"<<endl; break;}
		while(!feof(f))
		{
			if(fread(byte,1,1,f)==1) fwrite(byte,1,1,main);
		}
		std::cout<<*itr<<" �������� � ����� ���� '"<<this->real_bin_file<<"'."<<std::endl;
		fclose(f);
	}
	fclose(main);
}


void Package::unPacking(string binary)
{
	FILE *bin;
	if ((bin = fopen(binary.c_str(),"rb"))==NULL)
	{
		printf("Cannot open file.\n");exit(1);
	} // ��������� ����� � ������ ������
	char info_block_size[5];   // ������ ��������������� ����� 
	fread(info_block_size,1,5,bin);  // �������� ������
	int _sz = atoi(info_block_size);  // ����������� ����� � �����
	char *info_block = new char[_sz];  // �������������� ���� 
	fread(info_block,1,_sz,bin);   // ��������� ��� 
	// ������� ��������������� ����� :
	vector<string> tokens;
	char *tok = strtok(info_block,"||");
	int toks = 0;
	while(tok)
	{
		if(strlen(tok)==0) break;
		tokens.push_back(tok);
		tok=strtok(NULL,"||");
		toks++;
	}
	if(toks%2==1) toks--;  // ������� �����
	int files=toks/2;  // ���������� ������������ ������ � ������
	char byte[1];   // ��������� ����� ��� ���������� ������ �����
	// ������� ���������� ���� ������( �� �������� ���������� �� ����� � ����������� ) :
	for(int i=0;i<files;i++)
	{
		const char* size = tokens[i*2].c_str();
		const char* name = tokens[i*2+1].c_str();
		char full_path[255];
		strcpy(full_path,this->path.c_str());
		strcat(full_path,name);
		int _sz = atoi(size);
		cout<<"--  '"<<name<<"' �������� � '"<<this->path<<"' ."<<endl;
		FILE *curr;
		if ((curr = fopen(full_path,"wb"))==NULL)
		{
			printf("Cannot open file.\n");
			getch();
			exit(1);

		}
		for(int r=1;r<=_sz;r++)
		{
			if(fread(byte,1,1,bin)==1) fwrite(byte,1,1,curr);
		}
		fclose(curr);
	}
	fclose(bin);
	remove((binary).c_str());//������� ��� �� ������ ������������� ����
	delete [] info_block;
}


