#pragma once

#include <QWidget>
#include <QDialog>
#include <QListWidget>
#include "ui_QSetIDDialog.h"

class QSetIDDialog : public QDialog
{
	Q_OBJECT

public:
	QSetIDDialog(QWidget *parent = Q_NULLPTR);
	~QSetIDDialog();

	void setItem(QListWidgetItem *item);
	void setEditGeometry(QRect rect);
	void setID();
private:
	Ui::QSetIDDialog ui;
	QListWidgetItem *m_item;
};
