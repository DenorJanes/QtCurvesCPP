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

    enum Shapes { Astroid, Huygens, Cycloid, Hypo_Cycloid };

    void setBackgroundColor(QColor color) { mBackgroundColor = color; }
    QColor getBackgroundColor() const { return mBackgroundColor; }

signals:

protected:
    void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE;

private:
    QColor mBackgroundColor;
    QColor mShapeColor;

public slots:
};

#endif // RENDERAREA_H
