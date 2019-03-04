#pragma once

#include <QtWidgets/QMainWindow>
#include "QtNoFrameMainWindow.h"
#include <QMenu>
#include <QSystemTrayIcon>
#include <QFileDialog>
#include <qregexp.h>
#include <memory>
#include "NoteControllerBase.h"
#include "QSetIDDialog.h"
#include "ui_QNotes.h"

using namespace std;
class CNoteControllerBase;
class QNotes : public QtNoFrameMainWindow
{
	Q_OBJECT

public:
	QNotes(QWidget *parent = Q_NULLPTR);
	virtual ~QNotes();
public:
	Ui::QNotesClass ui;

	QMenu m_menuMore;
	QMenu m_menuTray;

protected:
	void InitTrayMenu();
	void InitMoreMenu();
	void InitSystemTrayIcon();
	void iconIsActived(QSystemTrayIcon::ActivationReason reason);
	void InitIDDialog();

	void NewNote();
	void ChangeNote(QListWidgetItem *ItCur, QListWidgetItem *ItPre);
	void SaveContent(QListWidgetItem *ItCur , QListWidgetItem *ItPre);
	void DeleteContent();
	void Search(const QString &str);
	void ChangeID(QListWidgetItem *item);
	
	void setMaxorNormal();
	void Export();
	void Import();
protected:
	unique_ptr<CNoteControllerBase> m_pController;
	
	QSetIDDialog *m_EdtID;

	bool m_bMax = false;
};
