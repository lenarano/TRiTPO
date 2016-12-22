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
	else std::cout<<"In the file name does not meet the characters // \\";//В названии файла не встречаются символы // \\

	return rezultat;
}



int Package::digs(double w)
{
	int yield = 0;
	while(w>10) {yield++;w/=10;}
	return yield+1;
}

void Package::getInfo()//получение информации о всех файлах и сохранение в промежуточный текстовый файл 
{
	char byte[1];  // единичный буфер для считывания одного байта
	basic_string<char> s_info = "";
	remove((this->path+"info.txt").c_str());
	FILE *info;
	if((info = fopen((this->path+"info.txt").c_str(),"a+"))==NULL) // сохраняем информацию в наш текстовый файл
	{
		printf ("Cannot open file.\n");
		getch();
		exit(1);
	}
	int bytes_size=0;  // длина информационного блока в байтах
	for(vector<string>::iterator itr=this->files.begin();itr!=this->files.end();++itr)
	{
		FILE *f = fopen((*itr).c_str(),"rb");
		if(!f) break;
		// получаем размер архивируемого файла
		fseek(f,0,SEEK_END);
		int size = ftell(f);  
		string name = Package::get_file_name(*itr);  // получаем имя архивируемого файла
		char *m_size = new char[digs(size)+1];
		itoa(size,m_size,10);//char *itoa( int value, char * string, int radix );
		fclose(f);
		// все, что "нарыли", сохраняем в промежуточный буфер :
		s_info.append(m_size);
		s_info.append("||");
		s_info.append(name);
		s_info.append("||");
		delete [] m_size;
	}
	bytes_size = s_info.size()+2;
	char *b_buff = new char[digs(bytes_size)];
	itoa(bytes_size,b_buff,10);
	// форматируем до 5 байт
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
	char byte[1];  // единичный буфер для считывания одного байта
	getInfo();  // получаем необходимую информацию о том, что архивируем
	FILE *f;
	FILE *main=fopen((this->real_bin_file).c_str(),"wb");  // файл - архив
	FILE *info = fopen((this->path+"info.txt").c_str(),"rb");  // файл с информацией
	// переписываем информацию в архив
	while(!feof(info))
	{
		if(fread(byte,1,1,info)==1) fwrite(byte,1,1,main);
	}
	fclose(info);
	remove((this->path+"info.txt").c_str());  // прибираемся за собой
	// последовательная запись в архив архивируемых файлов побайтно :
	for(vector<string>::iterator itr=this->files.begin();itr!=this->files.end();++itr)
	{
		f = fopen((*itr).c_str(),"rb");
		if(!f){ cout<<*itr<<" не найден!"<<endl; break;}
		while(!feof(f))
		{
			if(fread(byte,1,1,f)==1) fwrite(byte,1,1,main);
		}
		std::cout<<*itr<<" добавлен в общий файл '"<<this->real_bin_file<<"'."<<std::endl;
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
	} // открываем архив в режиме чтения
	char info_block_size[5];   // размер информационного блока 
	fread(info_block_size,1,5,bin);  // получаем размер
	int _sz = atoi(info_block_size);  // преобразуем буфер в число
	char *info_block = new char[_sz];  // информационный блок 
	fread(info_block,1,_sz,bin);   // считываем его 
	// Парсинг информационного блока :
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
	if(toks%2==1) toks--;  // удаляем мусор
	int files=toks/2;  // количество обнаруженных файлов в архиве
	char byte[1];   // единичный буфер для считывания одного байта
	// Процесс распаковки всех файлов( по правилам полученным из блока с информацией ) :
	for(int i=0;i<files;i++)
	{
		const char* size = tokens[i*2].c_str();
		const char* name = tokens[i*2+1].c_str();
		char full_path[255];
		strcpy(full_path,this->path.c_str());
		strcat(full_path,name);
		int _sz = atoi(size);
		cout<<"--  '"<<name<<"' извлечен в '"<<this->path<<"' ."<<endl;
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
	remove((binary).c_str());//удаляем уже не нужный промежуточный файл
	delete [] info_block;
}


