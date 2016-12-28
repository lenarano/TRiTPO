#include "GuiInteraction.h"


GuiInteraction::GuiInteraction(QWidget *parent)
	: QMainWindow(parent)
{
	ifFileArchive=false;
	ifFileUnarchive=false;
	ifFilePath=false;
	ifFileDirCleaning=false;
	ifWarning=false;
	path = "";

}


GuiInteraction::~GuiInteraction()
{

}


void GuiInteraction::cleaning()
{
	ifFileArchive=false;
	ifFilePath=false;
	dialogNameFile.setIfFileName(false);
	files.clear();
	Wood.getCounting().clear();
	path = "";
	dialogNameFile.getFileName() ="";
	dialogNameFile.getName() ="";
	dialogNameFile.getParole() ="";
	zip->getPassword()="";
}


void  GuiInteraction::open()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
		tr("Text Files (*.txt);;C++ Files (*.cpp *.h);;Documents (*.doc);;All files (*.*)"));

	if (fileName != "") {
		QFile file(fileName);
		if (!file.open(QIODevice::ReadOnly)) {
			QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
			return;
		}
		QTextStream in(&file);
		textEdit->setText(in.readAll());
		file.close();
	}
}

void GuiInteraction::save()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
		tr("Text Files (*.txt);;C++ Files (*.cpp *.h);;Documents (*.doc);;All files (*.*)"));

	if (fileName != "") {
		QFile file(fileName);
		if (!file.open(QIODevice::WriteOnly)) {
			// error message
		} else {
			QTextStream stream(&file);
			stream << textEdit->toPlainText();
			stream.flush();
			file.close();
		}
	}
}



void GuiInteraction::openFileArchive()
{
	//files.clear();
	QString fileName = QFileDialog::getOpenFileName(this, tr("Choose the file(s) to backup"), "",
		tr("Text Files (*.txt);;C++ Files (*.cpp *.h);;Documents (*.doc);;All files (*.*)"));

	if (fileName != "") {
		QFile file(fileName);
		qDebug( fileName.toLatin1() );
		ifFileArchive=true;
		if (!file.open(QIODevice::ReadOnly)) {
			QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
			return;
		}
		QByteArray ba = fileName.toLocal8Bit();
		std::string resfileName = std::string(ba.data(), ba.size());   	
		files.push_back(resfileName);

	}

}

void GuiInteraction::openFiles()
{
	QStringList filenames = QFileDialog::getOpenFileNames(
		this,
		tr("Select one or more files for archiving"),
		QDir::currentPath(),
		tr("Text Files (*.txt);;C++ Files (*.cpp *.h);;Documents (*.doc);;All files (*.*)") );
	if( !filenames.isEmpty() )
	{
		qDebug( filenames.join(",").toLatin1());
		ifFileArchive=true;

	}
	foreach( QString str, filenames) { files.push_back(str.toStdString());
	}
}


void GuiInteraction::openFileUnarchive()
{
	files.clear();
	ifFileUnarchive=false;
	QString fileName = QFileDialog::getOpenFileName(this, tr("Choose the file to backup"), "",
		tr("Archive (*.zipp*);;Archive (*.bin)"));

	if (fileName != "") {
		QFile file(fileName);
		qDebug( fileName.toLatin1() );
		ifFileUnarchive=true;
		if (!file.open(QIODevice::ReadOnly)) {
			QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
			return;
		}
		QByteArray ba = fileName.toLocal8Bit();
		std::string resfileName = std::string(ba.data(), ba.size());   	
		files.push_back(resfileName);

	}

}

void GuiInteraction::openDir()
{
	while (!ifFilePath)
	{
		QString dirname = QFileDialog::getExistingDirectory( 
			this, 
			tr("Select a Directory"), 
			QDir::currentPath() );
		if( !dirname.isNull() )
		{
			qDebug( dirname.toLatin1() );
			ifFilePath=true;
			QByteArray ba = dirname.toLocal8Bit();
			path = std::string(ba.data(), ba.size());  
		}
		else
		{
			ifWarning = QMessageBox::warning(0,"Warning", "Attention! When archiving(unzipping), you must specify a folder," 
				"\n Do you want to stop the backup process?", "Yes", "No", QString(), 0, 1 ); 
			if(!ifWarning) 
			{ 
				cleaning();
				ifFileDirCleaning=true;
				break;
			}
			else {continue;}
		}
	}
}

void GuiInteraction::nameFile()
{
	while (!dialogNameFile.getIfFileName())
	{
		if (dialogNameFile.exec() == QDialog::Accepted) 
		{
			dialogNameFile.findClicked();
		}
		else 
		{
			dialogNameFile.setIfWarning(QMessageBox::warning(0,"Warning", "Attention! When archiving, you must specify the name of the file-archive," 
				"\n Do you want to stop the backup process?", "Yes", "No", QString(), 0, 1 )); 
			if(!dialogNameFile.getIfWarning()) 
			{ 
				dialogNameFile.setIfFileNameCleaning(true);
				cleaning();
				break;
			}
			else{continue;}
		}
	}
}




void GuiInteraction::archiveFile()
{		
	if(ifFileArchive)
	{			
		openDir();
		if(ifFileDirCleaning)
		{
			QMessageBox::information(0, "Information", "The output is initiated by the user.\n If necessary repeat the process again!");
			ifFileDirCleaning=false;
		}
		else
		{
			nameFile();

			if(dialogNameFile.getIfFileNameCleaning())
			{
				QMessageBox::information(0, "Information", "The output is initiated by the user.\n If necessary repeat the process again!");
				cleaning();
				dialogNameFile.setIfFileNameCleaning(false);
			}
			else
			{
				msb.setText("To begin archiving click Ok!");
				msb.exec();
				QApplication::setOverrideCursor(Qt::WaitCursor); 
				zip = new Package(files,path,dialogNameFile.getFileName(),dialogNameFile.getParole());
				zip->packaging();//упаковка файлов в один
				Нaff.archiving(zip,Wood,Нaff);
				QApplication::restoreOverrideCursor();
				cleaning();
				delete zip;
				QMessageBox::information(0, "Information", "Backup completed successfully!");
			}
		}
	}			
	else
	{
		QMessageBox::information(0, "Information", "Choose the file(s) to backup!");
	}
}


void GuiInteraction::dearchiveFile()
{		
	if(ifFileUnarchive)
	{
		openDir();
		if(ifFileDirCleaning)
		{
			QMessageBox::information(0, "Information", "The output is initiated by the user.\n If necessary repeat the process again!");
			ifFileDirCleaning=false;
		}
		else
		{
			zip = new Package(files,path,"","");
			Нaff.unСompression(Wood.getCounting(),files,zip);//разархивация
			zip->unPacking1(zip->getUnhoff_bin_file());
			if(zip->getPassword()!="нет_пароля") dialogNameFile.PasswordVerification(zip->getPassword());
			if(dialogNameFile.getCheck()==true||zip->getPassword()=="нет_пароля")
			{
				zip->unPacking2(zip->getUnhoff_bin_file());
				QApplication::restoreOverrideCursor();
				QMessageBox::information(0, "Information", "Unzipping produced!");
				dialogNameFile.setCheck(false);
			}
			else
			{
				fclose(zip->getBin());
				remove((zip->getUnhoff_bin_file()).c_str());
				msb.setText("Error! Try again!");
				msb.exec();
			}
			cleaning();
			delete zip;
		}
	}
	else
	{
		QMessageBox::information(0, "Information", "Choose the file to backup!");
	}	
}


