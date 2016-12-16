#include "GuiInterface.h"

GuiInterface::GuiInterface(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	openAction = new QAction(tr("&Open"), this);
	openAction->setIcon(QPixmap("./Resources/open.png"));
	saveAction = new QAction(tr("&Save"), this);
	saveAction->setIcon(QPixmap("./Resources/save.png"));
	openZipAction = new QAction(tr("&OpenFile(s)"), this);
	openZipAction->setIcon(QPixmap("./Resources/openFile.png"));
	openUnzipAction = new QAction(tr("&OpenFile"), this);
	openUnzipAction->setIcon(QPixmap("./Resources/openFile.png"));
	archiveAction=new QAction(tr("&ArchiveFile"), this);
	archiveAction->setIcon(QPixmap("./Resources/zip.png"));
	dearchiveAction=new QAction(tr("&DearchiveFile"), this);
	dearchiveAction->setIcon(QPixmap("./Resources/unZip.png"));
	helpAction=new QAction(tr("&User manual"), this);
	helpAction->setIcon(QPixmap("./Resources/help.png"));
	aboutAction=new QAction(tr("&About the program"), this);
	aboutAction->setIcon(QPixmap("./Resources/Bandizip.png"));
	exitAction = new QAction(tr("&Exit"), this);
	exitAction->setIcon(QPixmap("./Resources/exit.png"));

	connect(openZipAction, SIGNAL(triggered()), this, SLOT(openFilesActiv()));
	connect(openUnzipAction, SIGNAL(triggered()), this, SLOT(openFileUnarchiveActiv()));
	connect(archiveAction, SIGNAL(triggered()), this, SLOT(archiveFileAction()));
	connect(dearchiveAction, SIGNAL(triggered()), this, SLOT(dearchiveFileActiv()));
	connect(helpAction, SIGNAL(triggered()), this, SLOT(helpProgramm()));
	connect(aboutAction, SIGNAL(triggered()), this, SLOT(aboutProgramm()));
	connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
	connect(openAction, SIGNAL(triggered()), this, SLOT(openActiv()));
	connect(saveAction, SIGNAL(triggered()), this, SLOT(saveActiv()));

	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(openAction);
	fileMenu->addAction(saveAction);

	activity.textEdit = new QTextEdit;
	setCentralWidget(activity.textEdit);

	zipperMenu = menuBar()->addMenu(tr("&Archive"));
	zipperMenu->addAction(openZipAction);
	zipperMenu->addAction(archiveAction);

	unzipperMenu = menuBar()->addMenu(tr("&Unarchive"));
	unzipperMenu->addAction(openUnzipAction);
	unzipperMenu->addAction(dearchiveAction);

	helpMenu = menuBar()->addMenu(tr("&Help"));
	helpMenu->addAction(helpAction);

	aboutMenu = menuBar()->addMenu(tr("&About"));
	aboutMenu->addAction(aboutAction);

	exitMenu=menuBar()->addMenu(tr("&Exit"));
	exitMenu->addAction(exitAction);

	addToolBar(Qt::TopToolBarArea, createToolBar());
}

GuiInterface::~GuiInterface()
{

}

QToolBar* GuiInterface::createToolBar()
{
	QToolBar* ptb = new QToolBar("Linker ToolBar");

	ptb->addAction(QPixmap("./Resources/open.png"), "Open File", this, SLOT(openActiv()));
	ptb->addAction(QPixmap("./Resources/save.png"), "Save File", this, SLOT(saveActiv()));
	ptb->addAction(QPixmap("./Resources/zip.png"), "To archive the file(s)", this, SLOT(zipper()));
	ptb->addAction(QPixmap("./Resources/unZip.png"), "Unzip the file", this, SLOT(unZipper()));
	ptb->addAction(QPixmap("./Resources/help.png"), "Help", this, SLOT(helpProgramm()));
	ptb->addAction(QPixmap("./Resources/Bandizip.png"), "About the program", this, SLOT(aboutProgramm()));
	ptb->addAction(QPixmap("./Resources/exit.png"), "Exit", this, SLOT(quit()));


	return ptb;
}

void GuiInterface::openActiv()
{
	activity.open();
}

void GuiInterface::saveActiv()
{
	activity.save();
}

void GuiInterface::openFilesActiv()
{
	activity.openFiles();
}

void GuiInterface::archiveFileAction()
{
	activity.archiveFile();
}


void GuiInterface::openFileUnarchiveActiv()
{
	activity.openFileUnarchive();
}

void GuiInterface::dearchiveFileActiv()
{
	activity.dearchiveFile();
}

void GuiInterface::zipper()
{
	openFilesActiv();
	archiveFileAction();
}

void GuiInterface::unZipper()
{
	openFileUnarchiveActiv();
	dearchiveFileActiv();
}

void GuiInterface::helpProgramm()
{
	InfoBrowser *helpBrowser = new InfoBrowser("doc", "./Resources/site/index1.html");
	helpBrowser->resize(400, 300);
	helpBrowser->show();
}

void GuiInterface::aboutProgramm()
{
	InfoBrowser *aboutBrowser = new InfoBrowser("doc", "./Resources/site/index2.html");
	aboutBrowser->resize(400, 300);
	aboutBrowser->show();
}	

void GuiInterface::quit()
{
	close();
}