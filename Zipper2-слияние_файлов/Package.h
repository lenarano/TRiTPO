#ifndef PACKAGE_H
#define PACKAGE_H


#include <iostream>
#include <string>
#include <vector>
#include <clocale>

using namespace std;

class Package{

private:
	std::vector<std::string> files;   // ����� ������ (-files)
	std:: string path;            // ���� (-path)    
	
public:
	Package(std::vector<std::string> &vec, std::string p);
	std::string real_bin_file;   // ��� ��������� �����-������( ������������ ��� ��������� )
	std::string hoff_bin_file;
	std::string unhoff_bin_file;
	void getInfo();   // ����� ��� ��������� ���������� � ������ �� ����� ���������
	void Packaging();   // �������� ������
	void Unpacking(std::string binary);   // ���������� ������ ( binary - ���� �� ������ )
	int digs(double w);
	// ����������� ����� ��� ��������� ����� ����� �� ������� ����. 
	// ������������ ��� ���������� ����.
	static std::string get_file_name(std::string fn){return fn.substr(fn.find_last_of("\\")+1,fn.size());}
	};





#endif PACKAGE_H