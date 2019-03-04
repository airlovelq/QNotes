#pragma once
#include "QNotes.h"
#include "ContentManagerBase.h"
#include <memory>
using namespace std;

class QNotes;
class CContentManagerBase;
class CContentManagerSqlite;
class CNoteControllerBase
{
public:
	CNoteControllerBase();
	virtual ~CNoteControllerBase();

protected:
	QNotes *m_View;
	unique_ptr<CContentManagerBase> m_pDbManager;
public:
	virtual bool begin();
	virtual void newNote();
	virtual void saveNote(QString sID,QString sContent);
	virtual void deleteNote();
	virtual void searchNote(QString &sID);
	virtual void searchID(QString str);
	virtual void setView(QNotes *View);
	virtual void updateView();
	virtual void changeID(QString sIDOld,QString sIDNew);
};

