#include "QNotes.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QFile f("MainStyleSheet.css");

	QNotes w;
	if (f.open(QFile::ReadOnly|QFile::Text))
	{
		w.setStyleSheet(f.readAll());
		f.close();
	}
	w.show();
	return a.exec();
}
