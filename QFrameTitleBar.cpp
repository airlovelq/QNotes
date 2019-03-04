#include "QFrameTitleBar.h"
#ifdef nullptr
QFrameTitleBar::QFrameTitleBar(QWidget *parent) :
	QFrame(parent),
	m_isPressed(false)
{
	QHBoxLayout *lay = new QHBoxLayout(this);

	QLabel *label = new QLabel("Notes",this);
	lay->addWidget(label);
	QSpacerItem *spacer = new QSpacerItem(200, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
	lay->addSpacerItem(spacer);
	QPushButton *btnclose = new QPushButton("X", this);
	lay->addWidget(btnclose);

}

void QFrameTitleBar::mousePressEvent(QMouseEvent* event)
{
	m_isPressed = true;
	m_startMovePos = event->globalPos();

	return QFrame::mousePressEvent(event);
}

void QFrameTitleBar::mouseMoveEvent(QMouseEvent* event)
{
	if (m_isPressed)
	{
		QPoint movePoint = event->globalPos() - m_startMovePos;

		if (parentWidget())
		{
			QPoint widgetPos = this->parentWidget()->parentWidget()->pos();
			m_startMovePos = event->globalPos();
			parentWidget()->parentWidget()->move(widgetPos.x() + movePoint.x(), widgetPos.y() + movePoint.y());
		}
	}

	return QFrame::mouseMoveEvent(event);
}

void QFrameTitleBar::mouseReleaseEvent(QMouseEvent* event)
{
	m_isPressed = false;

	return QFrame::mouseReleaseEvent(event);
}
#endif 