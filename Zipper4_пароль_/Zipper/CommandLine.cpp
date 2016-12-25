#include "CommandLine.h"



CommandLine::CommandLine()
{
	path = "";
	name ="";
	password ="";
	flag_fs = false;
	flag_path = false;
	flag_name= false;
	memset(type,0,7);
}

CommandLine::~CommandLine()
{

}

void CommandLine::initialization(int &argv, char* argc[])
{
	for(int i=1;i<argv;i++)
	{
		if(strcmp(argc[i],"-pack")==0) { strcpy(type,"pack"); flag_fs=flag_path=flag_name=false;}
		if(strcmp(argc[i],"-unpack")==0) { strcpy(type,"unpack"); flag_fs=flag_path=flag_name=false;}
		if(strcmp(argc[i],"-path")==0) {flag_path=true; flag_fs=false; flag_name= false; continue; }
		if(strcmp(argc[i],"-files")==0) {flag_fs=true; flag_path=false; flag_name= false; continue; }
		if(strcmp(argc[i],"-name")==0) {flag_name= true;flag_fs=false; flag_path=false; continue; }

		if(flag_path) {path.assign(argc[i]); }
		if(flag_fs) files.push_back(std::string(argc[i]));
		if(flag_name) {name.assign(argc[i]); }
	}
}


void CommandLine::command(int &argv, char* argc[])
{

	std::cout<<std::endl<<"######################## ZIPPER ########################"<<std::endl<<std::endl;
	if(argv>1)
	{
		initialization(argv,argc);

		Package *zip = new Package(files,path,name,password);
		if(strcmp(type,"pack")==0)
		{
			zip->packaging();//упаковка файлов в один
			Нoff.archiving(zip,Wood,Нoff);
		}
		if(strcmp(type,"unpack")==0)
		{				
			Нoff.unСompression(Wood.getCounting(),files,zip);//разархивация
			zip->unPacking1(zip->getUnhoff_bin_file());//!!!
		}
	}
	else std::cout<<"Параметры -pack/-unpack , -files, -path обязательны!"<<std::endl;
	std::cout<<std::endl<<"########################################################"<<std::endl<<std::endl;
	std::cout << "Время выполнения = " << clock()/1000.0 << std::endl; // время работы программы

}

