#ifndef GUIINTERFACE_H
#define GUIINTERFACE_H

#include <QToolBar>

#include "ui_zipper.h"
#include "InfoBrowser.h"
#include "GuiInteraction.h"


class GuiInterface : public QMainWindow
{
	Q_OBJECT

public:
	GuiInterface(QWidget *parent = 0);
	~GuiInterface();
	
private:
	Ui::ZipperClass ui;
	GuiInteraction activity;
	QAction *openUnzipAction;
	QAction *openZipAction;
	QAction *archiveAction;
	QAction *dearchiveAction;
	QAction *helpAction;
	QAction *aboutAction;
    QAction *exitAction;
	QAction *saveAction;
	QAction *openAction;
	QMenu *fileMenu;
	QMenu *zipperMenu;
	QMenu *unzipperMenu;
	QMenu *helpMenu;
	QMenu *aboutMenu;
	QMenu *exitMenu;
	
private slots:
	QToolBar* createToolBar();
	void openActiv();
    void saveActiv();
	void openFilesActiv();
	void openFileUnarchiveActiv();
	void archiveFileAction();
	void dearchiveFileActiv();
	void helpProgramm();
	void aboutProgramm();
	void quit();
	void zipper();
	void unZipper();
		
};

#endif // GUIINTERFACE_H
