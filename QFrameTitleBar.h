#pragma once
#ifdef nullptr
#include <QFrame>
#include <QMouseEvent>
#include <QLayout>
#include <QPushbutton>
#include <QLabel>
#include <QString>

class QFrameTitleBar : public QFrame
{
public:
	QFrameTitleBar(QWidget *parent = Q_NULLPTR);
protected:
	virtual void mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
	virtual void mouseMoveEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
	virtual void mouseReleaseEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
private:
	bool    m_isPressed;
	QPoint  m_startMovePos;
};
#endif

