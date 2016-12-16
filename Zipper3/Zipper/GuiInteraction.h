#ifndef GUIINTERACTION_H
#define GUIINTERACTION_H

#include <QtWidgets/QMainWindow>
#include <QApplication>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QTextEdit>
#include <QInputDialog>
#include "Haffman.h"


class GuiInteraction : public QMainWindow
{
	Q_OBJECT


private:
	Node Wood;
	Package *zip;
	Haffman Íaff;
	std::vector<std::string> files;
	std::string path;
	std::string fileName;
	bool ifFileArchive;
	bool ifFileUnarchive;
	bool ifFilePath;
	bool ifFileName;
	bool ifFileDirCleaning;
	bool ifFileNameCleaning;
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