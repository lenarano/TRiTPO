#ifndef NAMEDIALOG_H 
#define NAMEDIALOG_H

#include <Qdialog>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include "Package.h"


class NameDialog : public QDialog
{ 
	Q_OBJECT 

public: 
	NameDialog(QWidget *parent = 0);
	bool getIfFileName();
	void setIfFileName(bool b);	
	bool getIfFileNameCleaning();
	void setIfFileNameCleaning(bool b);
	bool getIfWarning();
	void setIfWarning(bool b);
	bool getCheck();
	void setCheck(bool b);
	QString getName();
	std::string getParole();
	std::string getFileName();
	void ContinuePasswordName(); 
	void ContinueName(const QString &str, std::string &fileName); 
	void findClicked(); 
	void PasswordVerification(std:: string &password);

	private slots: 
		void enableFindButton(const QString &text); 

private: 
	QLabel *label; 
	QLineEdit *lineEdit; 
	QCheckBox *caseCheckBox;
	QCheckBox *backwardCheckBox; 
	QPushButton *findButton; 
	QPushButton *closeButton; 
	std::string parole;
	std::string fileName;
	QString name;
	bool check;
	bool ifWarning;
	bool ifFileNameCleaning;
	bool ifFileName;
}; 

#endif      

