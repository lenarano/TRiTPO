#include "NameDialog.h" 


NameDialog::NameDialog(QWidget *parent) : QDialog(parent) 
{ 
	name ="";
	fileName ="";
	ifFileName=false;
	ifWarning=false;
	ifFileNameCleaning=false;
	check=false;

	setWindowTitle(tr("Enter a name:")); //надпись заголовка окна setCaption
	label = new QLabel(tr("Name:"), this); 
	lineEdit = new QLineEdit(this); 
	caseCheckBox = new QCheckBox(tr("Password"), this); 
	findButton = new QPushButton(tr("Continue"), this); 
	findButton->setEnabled(false); //запрет на кнопку
	closeButton = new QPushButton(tr("Close"), this);    

	connect(lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(enableFindButton(const QString &))); //вызывается при изменении содержимого поля ввода
	connect(findButton, SIGNAL(clicked()), this,  SLOT(accept()));
	connect(closeButton, SIGNAL(clicked()), this,  SLOT(reject()));

	QHBoxLayout *topLeftLayout = new QHBoxLayout; 
	topLeftLayout->addWidget(label); 
	topLeftLayout->addWidget(lineEdit); 
	QVBoxLayout *leftLayout = new QVBoxLayout; 
	leftLayout->addLayout(topLeftLayout); 
	leftLayout->addWidget(caseCheckBox); 
	QVBoxLayout *rightLayout = new QVBoxLayout; 
	rightLayout->addWidget(findButton); 
	rightLayout->addWidget(closeButton); 
	rightLayout->addStretch(1); 
	QHBoxLayout *mainLayout = new QHBoxLayout(this); 
	mainLayout->setMargin(11);
	mainLayout->setSpacing(6); 
	mainLayout->addLayout(leftLayout); 
	mainLayout->addLayout(rightLayout); 
}   


std::string NameDialog::getParole(){return parole;}

std::string NameDialog::getFileName(){return fileName;}

QString NameDialog::getName(){return name;}


void NameDialog::findClicked() { 
	name = lineEdit->text(); 
	bool caseSensitive = caseCheckBox->isChecked (); 
	if (caseSensitive) 
		ContinuePasswordName(); 
	else 
		{
			ContinueName(name,fileName); 
			parole="нет_пароля";
	    }
	lineEdit->clear();
} 

void NameDialog::enableFindButton(const QString &text) 
{ 
	findButton->setEnabled(!text.isEmpty()); 
}    

void NameDialog::ContinuePasswordName()
{
	bool bOk; 
	QString paroleName = QInputDialog::getText( 0, "Password","Enter the password:", QLineEdit::Password, "", &bOk ); 
	qDebug( paroleName.toLatin1() );
	QByteArray ba = paroleName.toLocal8Bit();
	parole = std::string(ba.data(), ba.size()); 
	if (!bOk) { 
		// Была нажата кнопка Cancel 
	}
	ContinueName(name,fileName); 
	caseCheckBox->setChecked(false);
}

void NameDialog::ContinueName(const QString &str, std::string &fileName)
{
	while (!ifFileName)
	{
		if( !str.isNull())
		{
			qDebug( str.toLatin1() );
			ifFileName=true;
			QByteArray ba = str.toLocal8Bit();
			fileName = std::string(ba.data(), ba.size());  
			
		}
		else
		{
			ifWarning = QMessageBox::warning(0,"Warning", "Attention! When archiving, you must specify the name of the file-archive," 
				"\n Do you want to stop the backup process?", "Yes", "No", QString(), 0, 1 ); 
			if(!ifWarning) 
			{ 
				ifFileNameCleaning=true;
				break;
			}
			else {continue;}
		}
	}
}


void NameDialog::PasswordVerification(std:: string &password)
{
	QString Password = QInputDialog::getText( 0, "Password","Enter the password:", QLineEdit::Password, "", 0 ); 
	qDebug( Password.toLatin1() );
	QByteArray ba = Password.toLocal8Bit();
	std::string enterPassword= std::string(ba.data(), ba.size()); 
	if(enterPassword==password){check=true;}
		
}
