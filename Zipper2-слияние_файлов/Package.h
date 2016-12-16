#ifndef PACKAGE_H
#define PACKAGE_H


#include <iostream>
#include <string>
#include <vector>
#include <clocale>

using namespace std;

class Package{

private:
	std::vector<std::string> files;   // набор файлов (-files)
	std:: string path;            // путь (-path)    
	
public:
	Package(std::vector<std::string> &vec, std::string p);
	std::string real_bin_file;   // имя выходного файла-архива( используется при архивации )
	std::string hoff_bin_file;
	std::string unhoff_bin_file;
	void getInfo();   // Метод для получения информации о файлах на этапе архивации
	void Packaging();   // Упаковка данных
	void Unpacking(std::string binary);   // Распаковка данных ( binary - путь до архива )
	int digs(double w);
	// Статический метод для выделения имени файла из полного пути. 
	// Используется для внутренних нужд.
	static std::string get_file_name(std::string fn){return fn.substr(fn.find_last_of("\\")+1,fn.size());}
	};





#endif PACKAGE_H