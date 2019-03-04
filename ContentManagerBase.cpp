#include "ContentManagerBase.h"

#include <QVariant>



CContentManagerBase::CContentManagerBase(QString strFilePath)
	:m_strFilePath(strFilePath)
{

}

CContentManagerBase::~CContentManagerBase()
{
}


CContentManagerSqlite::CContentManagerSqlite(QString strFilePath)
	:CContentManagerBase(strFilePath)
{
	m_db = QSqlDatabase::addDatabase("QSQLITE");
}

CContentManagerSqlite::~CContentManagerSqlite()
{
	m_db.close();
}

bool CContentManagerSqlite::openFile()
{
	m_db.setDatabaseName(m_strFilePath);
	auto res = m_db.open();
	if (res)
	    m_sqlq = QSqlQuery(m_db);
	return res;
}

bool CContentManagerSqlite::addRecord(const QString &sID, const QString &sContent)
{
	m_sqlq.prepare("insert into Data values (?,?)");
	m_sqlq.bindValue(0, sID);
	m_sqlq.bindValue(1, sContent);
	return m_sqlq.exec();
	
}
bool CContentManagerSqlite::changeRecord(const QString &sID, const QString &sContent)
{
	auto res = m_sqlq.prepare("select count(*) from Data where Name = ?");
	if (!res)
		return false;
	m_sqlq.bindValue(0, sID);
	if (m_sqlq.exec())
	{
		if (m_sqlq.next())
		{
			if (m_sqlq.value(0).toInt() > 0)
			{
				m_sqlq.prepare("update Data set Content = ? where Name = ?");
				m_sqlq.bindValue(0, sContent);
				m_sqlq.bindValue(1, sID);
				res = m_sqlq.exec();
			}
			else
			{
				res = addRecord(sID, sContent);
			}
		}
		else
			res = false;
	}
	else
		res = false;
	return res;
}
bool CContentManagerSqlite::deleteRecord(const QString &sID)
{
	m_sqlq.prepare("delete from Data where Name = ?");
	m_sqlq.bindValue(0, sID);
	auto res = m_sqlq.exec();
	//m_sqlq.clear();
	//m_db.commit();
	return res;
}

bool CContentManagerSqlite::queryRecord()
{
	m_sqlq.prepare("select * from Data");
	return m_sqlq.exec();
}

bool CContentManagerSqlite::queryRecord(const QString &sID, bool blike)
{
	if (blike)
	{
		m_sqlq.prepare("select * from Data where Name like ?");
		m_sqlq.bindValue(0, sID);
	}
	else
	{
		m_sqlq.prepare("select * from Data where Name = ?");
		m_sqlq.bindValue(0, sID);
	}
	return m_sqlq.exec();
}
void CContentManagerSqlite::readRecord(QString &sID, QString &sContent)
{
	sID = m_sqlq.value(0).toString();
	sContent = m_sqlq.value(1).toString();
}

bool CContentManagerSqlite::readEOF()
{
	return m_sqlq.next();
}

bool CContentManagerSqlite::changeID(QString &sIDOld, QString &sIDNew)
{
	m_sqlq.prepare("update Data set Name = ? where Name = ?");
	m_sqlq.bindValue(0, sIDNew);
	m_sqlq.bindValue(1, sIDOld);
	return m_sqlq.exec();
}
