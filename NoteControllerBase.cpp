#include "NoteControllerBase.h"



CNoteControllerBase::CNoteControllerBase()
{
	m_pDbManager = make_unique<CContentManagerSqlite>(QCoreApplication::applicationDirPath() + "/Data.db");
	
}


CNoteControllerBase::~CNoteControllerBase()
{
}

bool CNoteControllerBase::begin()
{
	return m_pDbManager->openFile();
}

void CNoteControllerBase::newNote()
{
	if (m_pDbManager->queryRecord())
	{
		QRegExp rx("NewNote[0-9]*");
		int c = 0;
		QString sID, sContent;
		while (m_pDbManager->readEOF())
		{
			m_pDbManager->readRecord(sID, sContent);
			if (rx.exactMatch(sID))
				c < sID.right(sID.length() - 7).toInt() ? c = sID.right(sID.length() - 7).toInt() : c = c;
		}
		QString str;
		str.sprintf("NewNote%d", c + 1);
		m_pDbManager->addRecord(str, "");
		m_View->ui.listWidget_Names->addItem(str);
	    //auto item = m_View->ui.listWidget_Names->item(m_View->ui.listWidget_Names->count() - 1);
		//m_View->ui.listWidget_Names->setItemWidget(item, new QLineEdit(str));
		m_View->ui.listWidget_Names->setCurrentRow(m_View->ui.listWidget_Names->count() - 1);
	}
	//m_pDbManager->addRecord(sID, sContent);
	//m_View->ui.listWidget_Names->blockSignals(true);
	//m_View->ui.listWidget_Names->addItem(sID);
	//m_View->ui.plainTextEdit->clear();
	//m_View->ui.listWidget_Names->blockSignals(false);
}

void CNoteControllerBase::saveNote(QString sID, QString sContent)
{
	m_pDbManager->changeRecord(sID, sContent);
}

void CNoteControllerBase::deleteNote()
{
	auto item = m_View->ui.listWidget_Names->currentItem();
	if (item)
	{
		m_View->ui.listWidget_Names->blockSignals(true);
		auto res = m_pDbManager->deleteRecord(item->text());
		m_View->ui.listWidget_Names->takeItem(m_View->ui.listWidget_Names->currentRow());
		delete item;
		m_View->ui.listWidget_Names->blockSignals(false);
		searchNote(m_View->ui.listWidget_Names->currentItem()->text());
	}
	
}

void CNoteControllerBase::searchNote(QString &sID)
{
	QString sContent = "";
	if (m_pDbManager->queryRecord(sID))
	{
		while (m_pDbManager->readEOF())
		{
			m_pDbManager->readRecord(sID, sContent);
			m_View->ui.plainTextEdit->setPlainText(sContent);
		}
	}
}

void CNoteControllerBase::setView(QNotes *View)
{
	this->m_View = View;
}

void CNoteControllerBase::updateView()
{
	if (m_pDbManager->queryRecord())
	{
		m_View->ui.listWidget_Names->blockSignals(true);
		m_View->ui.listWidget_Names->clear();
		m_View->ui.plainTextEdit->clear();
		QString sID, sContent;
		while (m_pDbManager->readEOF())
		{
			m_pDbManager->readRecord(sID, sContent);
			m_View->ui.listWidget_Names->addItem(sID);
			//auto item = m_View->ui.listWidget_Names->item(m_View->ui.listWidget_Names->count() - 1);
			//m_View->ui.listWidget_Names->setItemWidget(item, new QLineEdit(sID));
		}
		m_View->ui.listWidget_Names->blockSignals(false);
	}
}

void CNoteControllerBase::searchID(QString str)
{
	auto res = false;
	if (str.length() == 0)
		res = m_pDbManager->queryRecord();
	else
		res = m_pDbManager->queryRecord("%" + str + "%", true);
	if (res)
	{
		m_View->ui.listWidget_Names->blockSignals(true);
		m_View->ui.listWidget_Names->clear();
		m_View->ui.plainTextEdit->clear();
		QString sID, sContent;
		while (m_pDbManager->readEOF())
		{
			m_pDbManager->readRecord(sID, sContent);
			m_View->ui.listWidget_Names->addItem(sID);

		}
		m_View->ui.listWidget_Names->blockSignals(false);
	}
}

void CNoteControllerBase::changeID(QString sIDOld, QString sIDNew)
{
	m_pDbManager->changeID(sIDOld, sIDNew);
}
