#pragma once
#include <qwidget.h>


class Figure
{
public:
    virtual void Draw(QPainter& paint);//�������������������virtual��
    virtual ~Figure();
    //inline void SetFigureType(const FigureType& figureType) { figure_type_ = figureType; }//�ӿ�
    //inline const FigureType& GetFigureType() const { return figure_type_; }

private:
   
   
};

