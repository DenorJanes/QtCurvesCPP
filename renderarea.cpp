#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    mBackgroundColor(0,0,255),
    mShapeColor(255,255,255),
    mShape(Astroid)
{
    on_shape_changed();
}

void RenderArea::on_shape_changed()
{
    switch (mShape)
    {
    case Astroid:
        mStepCount = 256;
        mScale = 40;
        mIntervalLength = 2 * M_PI;
        break;
    case Cycloid:
        mStepCount = 128;
        mScale = 4;
        mIntervalLength = 6 * M_PI;
        break;
    case Huygens:
        mStepCount = 256;
        mScale = 4;
        mIntervalLength = 4 * M_PI;
        break;
    case Hypo_Cycloid:
        mStepCount = 256;
        mScale = 15;
        mIntervalLength = 2 * M_PI;
        break;
    default:
        break;
    }
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

    return QPointF(
                2*cos_t*cos_t*cos_t, // X
                2*sin_t*sin_t*sin_t  // Y
                );
}
QPointF RenderArea::compute_cycloid(float t)
{
    return QPointF (
                1.5 * (1 - cos(t)), // X
                1.5 * (t - sin(t))  // Y
                );
}
QPointF RenderArea::compute_huygens(float t)
{
    return QPointF (
                4*(3*cos(t) - cos(3*t)), // X
                4*(3*sin(t) - sin(3*t))  // Y
                );
}
QPointF RenderArea::compute_hypo(float t)
{
    return QPointF(
                1.5 * (2*cos(t) + cos(2*t)), // X
                1.5 * (2*sin(t) - sin(2*t))  // Y
                );
}

QPointF RenderArea::compute_shape(float t)
{
    switch (mShape)
    {
    case Astroid: return compute_astroid(t);
    case Cycloid: return compute_cycloid(t);
    case Huygens: return compute_huygens(t);
    case Hypo_Cycloid: return compute_hypo(t);
    default: return QPointF(0,0);
    }

}

void RenderArea::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);

    painter.setBrush(mBackgroundColor);
    painter.setPen(mShapeColor);

    painter.drawRect(this->rect());

    QPoint center = this->rect().center();
    float step = mIntervalLength/mStepCount;

    QPointF previous_point = compute_shape(0);
    QPointF previous_pixel;
    previous_pixel.setX(previous_point.x()*mScale + center.x());
    previous_pixel.setY(previous_point.y()*mScale + center.y());

    for(float t = step; t < mIntervalLength; t+= step)
    {
        QPointF current_point = compute_shape(t);

        QPointF current_pixel;
        current_pixel.setX(current_point.x()*mScale + center.x());
        current_pixel.setY(current_point.y()*mScale + center.y());

        painter.drawLine(previous_pixel, current_pixel);

        previous_pixel = current_pixel;
    }
}
