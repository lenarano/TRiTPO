#include "CommandLine.h"



CommandLine::CommandLine()
{
	path = "";
	name ="";
	password ="";
	flag_fs = false;
	flag_path = false;
	flag_name= false;
	flag_password = false;
	memset(type,0,7);
}

CommandLine::~CommandLine()
{

}

void CommandLine::initialization(int &argv, char* argc[])
{
	for(int i=1;i<argv;i++)
	{
		if(strcmp(argc[i],"-pack")==0) { strcpy(type,"pack"); flag_fs=flag_path=flag_name=flag_password= false;}
		if(strcmp(argc[i],"-unpack")==0) { strcpy(type,"unpack"); flag_fs=flag_path=flag_name=flag_password=false;}
		if(strcmp(argc[i],"-path")==0) {flag_path=true; flag_fs=false; flag_name= false;  flag_password= false; continue; }
		if(strcmp(argc[i],"-files")==0) {flag_fs=true; flag_path=false; flag_name= false; flag_password= false; continue; }
		if(strcmp(argc[i],"-name")==0) {flag_name= true;flag_fs=false; flag_path=false; flag_password= false; continue; }
		if(strcmp(argc[i],"-password")==0) {flag_password= true;flag_fs=false; flag_path=false;flag_name= false;  continue; }

		if(flag_path) {path.assign(argc[i]); }
		if(flag_fs) files.push_back(std::string(argc[i]));
		if(flag_name) {name.assign(argc[i]); }
		if(flag_password) {password.assign(argc[i]); }
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
			zip->packaging();//�������� ������ � ����
			�off.archiving(zip,Wood,�off);
		}
		if(strcmp(type,"unpack")==0)
		{				
			�off.un�ompression(Wood.getCounting(),files,zip);//������������
			zip->unPacking1(zip->getUnhoff_bin_file());
			if(zip->getPassword()==password){zip->unPacking2(zip->getUnhoff_bin_file());}
			else 
			{
				fclose(zip->bin);
				remove((zip->getUnhoff_bin_file()).c_str());
				std::cout<<"�������� ������! ���������� ��� ���!"<<std::endl;
			}
		}
	}
	else std::cout<<"��������� -pack/-unpack , -files, -path, -password �����������!"<<std::endl;
	std::cout<<std::endl<<"########################################################"<<std::endl<<std::endl;
	std::cout << "����� ���������� = " << clock()/1000.0 << std::endl; // ����� ������ ���������

}

