#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <string>
#include <vector>
#include <clocale>
#include <qstringlist>

#include <conio.h>



class Package{

private:
	std::vector<std::string> files;   // ����� ������ (-files)
	std:: string path;            // ���� (-path)   
	std:: string name;           // ��� ������ (-name)
	std::string real_bin_file;   // ��� ��������� �����-������( ������������ ��� ��������� )
	std::string hoff_bin_file;
	std::string unhoff_bin_file;
public:
	Package(std::vector<std::string> &vec, std::string p, std::string n);
	~Package();
	std::string getReal_bin_file();
	std::string getHoff_bin_file();
	std::string getUnhoff_bin_file();
	void getInfo();   // ����� ��� ��������� ���������� � ������ �� ����� ���������
	void packaging();   // �������� ������
	void unPacking(std::string binary);   // ���������� ������ ( binary - ���� �� ������ )
	int digs(double w);
	// ����������� ����� ��� ��������� ����� ����� �� ������� ����. 
	static std::string get_file_name(std::string fn);
	
};





#endif PACKAGE_H