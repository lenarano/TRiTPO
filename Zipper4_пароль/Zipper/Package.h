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
	std::vector<std::string> files;   // набор файлов (-files)
	std:: string path;            // путь (-path)   
	std:: string name;           // имя архива (-name)
	std::string real_bin_file;   // имя выходного файла-архива( используется при архивации )
	std::string hoff_bin_file;
	std::string unhoff_bin_file;
public:
	Package(std::vector<std::string> &vec, std::string p, std::string n);
	~Package();
	std::string getReal_bin_file();
	std::string getHoff_bin_file();
	std::string getUnhoff_bin_file();
	void getInfo();   // Метод для получения информации о файлах на этапе архивации
	void packaging();   // Упаковка данных
	void unPacking(std::string binary);   // Распаковка данных ( binary - путь до архива )
	int digs(double w);
	// Статический метод для выделения имени файла из полного пути. 
	static std::string get_file_name(std::string fn);
	
};





#endif PACKAGE_H