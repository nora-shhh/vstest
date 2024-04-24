#pragma once
#include <qwidget.h>


class Figure
{
public:
    virtual void Draw(QPainter& paint);//父类的析构函数必须是virtual的
    virtual ~Figure();
    //inline void SetFigureType(const FigureType& figureType) { figure_type_ = figureType; }//接口
    //inline const FigureType& GetFigureType() const { return figure_type_; }

private:
   
   
};

