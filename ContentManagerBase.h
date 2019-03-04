#pragma once
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "QNotes.h"
class QNotes;
class CContentManagerBase
{
protected:
	CContentManagerBase() = delete;
	CContentManagerBase(QString strFilePath);

	CContentManagerBase(CContentManagerBase &) = delete;
	CContentManagerBase& operator = (CContentManagerBase &) = delete;

public:
	virtual ~CContentManagerBase();
public:
	virtual bool openFile() = 0;
	virtual bool addRecord(const QString &sID, const QString &sContent) = 0;
	virtual bool changeRecord(const QString &sID, const QString &sContent) = 0;
	virtual bool deleteRecord(const QString &sID) = 0;
	virtual bool queryRecord() = 0;
	virtual bool queryRecord(const QString &sID, bool blike = false) = 0;
	virtual void readRecord(QString &sID, QString &sContent) = 0;
	virtual bool readEOF() = 0;
	virtual bool changeID(QString &sIDOld, QString &sIDNew) = 0;
protected:
	QString m_strFilePath;
	
};

class CContentManagerSqlite
	:public CContentManagerBase
{
public:
	CContentManagerSqlite(QString strFilePath);
	~CContentManagerSqlite();
public:
	virtual bool openFile() override;
	virtual bool addRecord(const QString &sID, const QString &sContent) override;
	virtual bool changeRecord(const QString &sID, const QString &sContent) override;
	virtual bool deleteRecord(const QString &sID) override;
	virtual bool queryRecord() override;
	virtual bool queryRecord(const QString &sID,bool blike=false) override;
	virtual void readRecord(QString &sID, QString &sContent) override;
	virtual bool readEOF() override;
	virtual bool changeID(QString &sIDOld, QString &sIDNew) override;
protected:
	QSqlDatabase m_db;
	QSqlQuery m_sqlq;
	
};

