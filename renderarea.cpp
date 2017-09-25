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

QPointF RenderArea::compute_astroid(float t)
{
    float cos_t = cos(t);
    float sin_t = sin(t);

    float x = 2*cos_t*cos_t*cos_t;
    float y = 2*sin_t*sin_t*sin_t;

    return QPointF(x,y);
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

    QPoint center = this->rect().center();
    mStepCount = 256;
    mScale = 70;
    mIntervalLength = 2 * M_PI;
    float step = mIntervalLength/mStepCount;

    for(float t = 0; t < mIntervalLength; t+= step)
    {
        QPointF point = compute_astroid(t);

        QPointF pixel;
        pixel.setX(point.x()*mScale + center.x());
        pixel.setY(point.y()*mScale + center.y());

        painter.drawPoint(pixel);
    }

}
