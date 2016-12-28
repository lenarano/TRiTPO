#ifndef GUIINTERACTION_H
#define GUIINTERACTION_H

#include <QtWidgets/QMainWindow>
#include <QApplication>
#include <QFileDialog>
#include <QTextStream>
#include <QTextEdit>
#include "Haffman.h"
#include "NameDialog.h" 


class GuiInteraction : public QMainWindow
{
	Q_OBJECT


private:
	NameDialog dialogNameFile;
	Node Wood;
	Package *zip;
	Haffman Íaff;
	std::vector<std::string> files;
	std::string path;
	bool ifFileArchive;
	bool ifFileUnarchive;
	bool ifFilePath;
	bool ifFileDirCleaning;
	bool ifWarning;
	QMessageBox msb;

	public:
	QTextEdit *textEdit;

	GuiInteraction(QWidget *parent = 0);
	~GuiInteraction();
	
	void cleaning();
	void  open();
	void save();
	void openFileArchive();
	void openFiles();
	void openFileUnarchive();
	void openDir();
	void nameFile();
	void archiveFile();
	void dearchiveFile();

};




#endif // GUIINTERACTION_H