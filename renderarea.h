#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>
#include <QPainter>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum ShapeType { Astroid, Huygens, Cycloid, Hypo_Cycloid };

    // setters
    void setBackgroundColor(QColor color) { mBackgroundColor = color; }
    void setShape(ShapeType shape) { mShape = shape; }

    // getters
    QColor getBackgroundColor() const { return mBackgroundColor; }
    ShapeType getShape() const {return mShape; }

signals:

protected:
    void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE;

private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;
    int mStepCount;
    int mScale;
    float mIntervalLength;

    QPointF compute_astroid(float t);


public slots:
};

#endif // RENDERAREA_H
