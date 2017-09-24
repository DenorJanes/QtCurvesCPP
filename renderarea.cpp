#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    mBackgroundColor(0,0,255),
    mShapeColor(255,255,255),
    mShape(Astroid)
{

}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100,100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400,200);
}



void RenderArea::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);

    switch (mShape) {
    case Astroid:
        mBackgroundColor = Qt::red;
        break;
    case Cycloid:
        mBackgroundColor = Qt::yellow;
        break;
    case Huygens:
        mBackgroundColor = Qt::green;
        break;
    case Hypo_Cycloid:
        mBackgroundColor = Qt::blue;
        break;
    default:
        break;
    }

    painter.setBrush(mBackgroundColor);
    painter.setPen(mShapeColor);

    painter.drawRect(this->rect());
    painter.drawLine(this->rect().bottomLeft(),this->rect().topRight());

}
