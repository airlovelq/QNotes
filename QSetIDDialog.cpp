#include "QSetIDDialog.h"

QSetIDDialog::QSetIDDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_cancel, &QPushButton::clicked, this, &QSetIDDialog::reject);
	connect(ui.pushButton_accept, &QPushButton::clicked, this, &QSetIDDialog::setID);
}

QSetIDDialog::~QSetIDDialog()
{
}

void QSetIDDialog::setItem(QListWidgetItem *item)
{
	m_item = item;
	ui.lineEdit->setText(item->text());
}

void QSetIDDialog::setEditGeometry(QRect rect)
{
	//auto p1 = this->mapFromGlobal(rect.topLeft());
	//auto p2 = this->mapFromGlobal(rect.bottomRight());
	//ui.lineEdit->setGeometry(QRect(p1,p2));
	ui.lineEdit->setGeometry(rect);
}

void QSetIDDialog::setID()
{
	m_item->setText(ui.lineEdit->text());
	accept();
}
