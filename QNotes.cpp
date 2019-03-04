#include "QNotes.h"
#include "StringResource.h"
QNotes::QNotes(QWidget *parent)
	: QtNoFrameMainWindow(parent)
{
	//this->setWindowFlag(Qt::WindowType::FramelessWindowHint);
#ifdef USESQLITE
	m_pController = make_unique<CNoteControllerBase>();
	m_pController->setView(this);
#endif
	auto res = m_pController->begin();

	ui.setupUi(this);
	this->centralWidget()->setMouseTracking(true);
	//ui.listWidget_Names->setMouseTracking(true);
	this->setWindowIcon(QIcon("Icon.png"));
	
	InitIDDialog();
	InitMoreMenu();
	InitTrayMenu();
	InitSystemTrayIcon();
	m_pController->updateView();
	ui.plainTextEdit->setEnabled(false);

	connect(ui.pushButton_undo, &QPushButton::clicked, ui.plainTextEdit, &QPlainTextEdit::undo);
	connect(ui.pushButton_redo, &QPushButton::clicked, ui.plainTextEdit, &QPlainTextEdit::redo);
	connect(ui.pushButton_add, &QPushButton::clicked, this, &QNotes::NewNote);
	connect(ui.pushButton_close, &QPushButton::clicked, this, &QNotes::close);
	connect(ui.pushButton_minimize, &QPushButton::clicked, this, &QNotes::showMinimized);
	connect(ui.pushButton_maximize, &QPushButton::clicked, this, &QNotes::setMaxorNormal);
	connect(ui.listWidget_Names, &QListWidget::currentItemChanged, this, &QNotes::ChangeNote);
	connect(ui.pushButton_del, &QPushButton::clicked, this, &QNotes::DeleteContent);
	connect(ui.lineEdit, &QLineEdit::textChanged, this, &QNotes::Search);
	connect(ui.listWidget_Names, &QListWidget::itemDoubleClicked, this, &QNotes::ChangeID);
	
	//connect(ui.listWidget_Names, &QListWidget::currentItemChanged, this, &QNotes::ChangeID2);
}

QNotes::~QNotes()
{
	delete m_EdtID;
}

void QNotes::InitIDDialog()
{
	m_EdtID = new QSetIDDialog(nullptr);
	m_EdtID->hide();
	m_EdtID->setObjectName("EDT");
	m_EdtID->setWindowFlag(Qt::WindowType::FramelessWindowHint);
	QFile f("SetIDStyleSheet.css");
	if (f.open(QFile::ReadOnly | QFile::Text))
	{
		m_EdtID->setStyleSheet(f.readAll());
		f.close();
	}
}

void QNotes::InitSystemTrayIcon()
{
	QSystemTrayIcon *system_tray = new QSystemTrayIcon(this);
	//放在托盘提示信息、托盘图标
	system_tray->setToolTip(STRING_NOTES);
	system_tray->setIcon(QIcon("Icon.png"));
	//TrayMenu *tray_menu = new TrayMenu();
	//system_tray->setContextMenu(tray_menu);
	//点击托盘执行的事件
	connect(system_tray, &QSystemTrayIcon::activated, this, &QNotes::iconIsActived);
	
	//显示托盘
	system_tray->show();
	//托盘显示提示信息
	//system_tray->showMessage(QString("托盘标题"), QString("托盘显示内容"));
}

void QNotes::InitTrayMenu()
{
	QAction *actShow = new QAction(STRING_SHOW, &m_menuTray);
	m_menuTray.addAction(actShow);
	connect(actShow, &QAction::triggered, this, &QNotes::setMaxorNormal);
	QAction *actExit = new QAction(STRING_EXIT, &m_menuTray);
	m_menuTray.addAction(actExit);
	connect(actExit, &QAction::triggered, this, &QNotes::close);
	//ui.pushButton_more->setMenu(&m_menuTray);
}

void QNotes::InitMoreMenu()
{
	QAction *actEx = new QAction(STRING_EXPORT, &m_menuMore);
	m_menuMore.addAction(actEx);
	connect(actEx, &QAction::triggered, this, &QNotes::Export);

	QAction *actIm = new QAction(STRING_IMPORT, &m_menuMore);
	m_menuMore.addAction(actIm);
	connect(actIm, &QAction::triggered, this, &QNotes::Import);

	ui.pushButton_more->setMenu(&m_menuMore);
}

void QNotes::iconIsActived(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason)
	{
		//点击托盘显示窗口
	    case QSystemTrayIcon::Trigger:
	    {
		    //m_menuTray.move(cursor().pos()); //让菜单显示的位置在鼠标的坐标上
		    //m_menuTray.show();
		    //showNormal();
		    break;
	    }
	    //双击托盘显示窗口
	    case QSystemTrayIcon::DoubleClick:
	    {
		    showNormal();
		    break;
	    }
	    case QSystemTrayIcon::ActivationReason::Context:
	    {
		    //m_menuTray.showNormal();
		    m_menuTray.move(cursor().pos().x(), cursor().pos().y()-m_menuTray.sizeHint().height()); //让菜单显示的位置在鼠标的坐标上
		    m_menuTray.show();
	    }
	    default:
		    break;
	}
}

void QNotes::setMaxorNormal()
{
	m_bMax = !m_bMax;
	m_bMax ? this->showMaximized() : this->showNormal();
}

void QNotes::NewNote()
{
	m_pController->newNote();
}
void QNotes::ChangeNote(QListWidgetItem *ItCur, QListWidgetItem *ItPre)
{
	SaveContent(ItCur, ItPre);
	m_pController->searchNote(ItCur->text());
	ui.listWidget_Names->removeItemWidget(ItPre);
	ui.plainTextEdit->setEnabled(true);
	//m_EdtID->hide();
	//auto rect = ui.listWidget_Names->visualItemRect(ItCur);
	//m_EdtID->setGeometry(rect);
	//m_EdtID->setText(ItCur->text());
	//ui.listWidget_Names->setItemWidget(ItCur, m_EdtID);
	//m_EdtID->setEnabled(false);
	//m_EdtID->show();
	
}

void QNotes::SaveContent(QListWidgetItem *ItCur, QListWidgetItem *ItPre)
{
	if (ItPre)
	{
		auto sName = ItPre->text();
		auto sContent = ui.plainTextEdit->toPlainText();
		m_pController->saveNote(sName, sContent);
	}
}

void QNotes::DeleteContent()
{
	m_pController->deleteNote();
}



void QNotes::Search(const QString &str)
{
	m_pController->searchID(str);
}

void QNotes::ChangeID(QListWidgetItem *item)
{
	//for (int i = 0; i<ui->listWidget->count(); i++)
	//{
		//QListWidgetItem* item = new QListWidgetItem;
		//item = ui->listWidget->item(i);
	auto sIDOld = item->text();
		//设置每个item都处于可编辑状态
	    auto rect = ui.listWidget_Names->visualItemRect(item);
		auto p1 = ui.listWidget_Names->mapToGlobal(rect.topLeft());
		auto p2 = ui.listWidget_Names->mapToGlobal(rect.bottomRight());
		
		m_EdtID->setGeometry(QRect(p1.x(),p1.y(),rect.width()+70,rect.height()));
		//m_EdtID->setWindowModality(Qt::WindowModality::ApplicationModal);
		m_EdtID->setItem(item);
		if (QDialog::Accepted == m_EdtID->exec())
		{
			auto sIDNew = item->text();
			m_pController->changeID(sIDOld, sIDNew);
		}
	//m_EdtID->setText(item->text());
	//m_EdtID->setEnabled(true);
		//m_EdtID->show();
		//m_EdtID->setFocus();
	//ui.listWidget_Names->setItemWidget(item, m_EdtID);
		
		
		//item->setFlags(item->flags() | Qt::ItemIsEditable);
		//ui.listWidget_Names->editItem(item);
		//ui.listWidget_Names->focusWidget();
		//((QLineEdit*)fw)->setText("090");
	//}
		//ui.listWidget_Names->currentTextChangeditemChanged
}

void QNotes::Export()
{
	auto filename = QFileDialog::getSaveFileName(this, STRING_EXPATH, QString(), "txt (*.txt);;All (*.*)");
	if (filename.length() <= 0)
		return;
	auto content = ui.plainTextEdit->toPlainText();
	QFile file(filename);
	if (file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		file.write(content.toStdString().c_str());
		file.close();
	}
}

void QNotes::Import()
{
	auto filename = QFileDialog::getOpenFileName(this, STRING_EXPATH, QString(), "txt (*.txt);;All (*.*)");
	if (filename.length() <= 0)
		return;
	QFile file(filename);
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		ui.plainTextEdit->setPlainText(file.readAll());
		file.close();
	}
}

