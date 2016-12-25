#include "GuiInterface.h"
#include "CommandLine.h"
#include <QtWidgets/QApplication>



QCoreApplication* createApplication(int &argv, char *argc[])
{
	for (int i = 1; i < argv; ++i)
		if (!qstrcmp(argc[i], "-no-gui"))
			return new QCoreApplication(argv, argc);
	return new QApplication(argv, argc);
}


int main(int argv, char* argc[])
{
	setlocale(LC_ALL,"Russian");
	QScopedPointer<QCoreApplication> app(createApplication(argv, argc));

	if (qobject_cast<QApplication *>(app.data()))// start GUI version...
	{		
		GuiInterface itf;
		itf.show();
		app->exec();
	} 
	else// start non-GUI version...
	{	
		//-no-gui -pack -files C:\test\text1.txt C:\test\text2.txt C:\test\text3.txt -path C:\test -name proba -password пароль
		//-no-gui -unpack -files C:\test\proba.zipp -path C:\test\unpack -password пароль
		CommandLine com;
		com.command(argv,argc);
		system("pause");
		return 0;
	}

}

