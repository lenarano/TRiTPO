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



class NameDialog : public QDialog { 
	Q_OBJECT 
public: 
	NameDialog(QWidget *parent = 0);      
	QString name;
	bool ifFileName;
	std::string fileName;
	bool ifFileNameCleaning;
	bool ifWarning;
	void ContinuePasswordName(const QString &str, bool ifName); 
	void ContinueName(const QString &str, std::string &fileName); 
	void findClicked(); 
	QString parole;
	private slots: 
		void enableFindButton(const QString &text); 

private: 
	QLabel *label; 
	QLineEdit *lineEdit; 
	QCheckBox *caseCheckBox;
	QCheckBox *backwardCheckBox; 
	QPushButton *findButton; 
	QPushButton *closeButton; 



}; 

#endif      

