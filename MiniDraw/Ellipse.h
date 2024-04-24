#pragma once
#include <qwidget.h>
#include <QPainter>
#include "Figure.h"
class Ellipse :
    public Figure
{
public:
    Ellipse(void);
    Ellipse(int start_point_x, int start_point_y, int end_point_x, int end_point_y)
    {
        start_point_x_ = start_point_x;
        start_point_y_ = start_point_y;
        end_point_x_ = end_point_x;
        end_point_y_ = end_point_y;
    }
    ~Ellipse(void);
public:
    void Draw(QPainter& paint)
    {
        paint.drawEllipse(start_point_x_, start_point_y_, end_point_x_, end_point_y_);
    }
private:
    int start_point_x_, start_point_y_, end_point_x_, end_point_y_;
};
