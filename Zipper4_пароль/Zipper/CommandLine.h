#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include "Haffman.h"
#include <ctime>

class CommandLine
{
private:
	Node Wood;
	Haffman Íoff;
	std::vector<std::string> files;
	std::string path;
	std::string name;
	std::string password;
	bool flag_fs, flag_path, flag_name, flag_password;
	char type[7];

public:
	CommandLine();
	~CommandLine();

	void initialization(int &argv, char* argc[]);
	void command(int &argv, char* argc[]);

};


#endif COMMANDLINE_H