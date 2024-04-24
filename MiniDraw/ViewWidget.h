#pragma once
#include <qwidget.h>

#include <vector>
#include "Line.h"
#include "Ellipse.h"
#include "Figure.h"

using namespace std;


class ViewWidget :
    public QWidget  //添加成员变量声明
{
public:
    ViewWidget(QWidget* parent = nullptr);
    ~ViewWidget();

    void mousePressEvent(QMouseEvent* event);//鼠标击发响应函数（左右键，单双击）
    void mouseMoveEvent(QMouseEvent* event);//鼠标移动响应函数
    void mouseReleaseEvent(QMouseEvent* event);//鼠标释放响应函数（左右键，单双击）
    
    void paintEvent(QPaintEvent* event);//Qt所有绘制都只能在此函数中完成
    void set_figure_type_to_line();
    void set_figure_type_to_ellipse();


   
private:
   

    bool draw_status_;//当前绘制状态，true为绘制当前鼠标拖动的图元，false为不绘制
    QPoint start_point_;//当前图元的起始点
    QPoint end_point_;//当前图元的终止点

    vector<Line* >  line_array_;
    vector<Ellipse* >  ellipse_array_;
    vector<Figure* > figure_array_;//父类指针数组存储数据
    int figure_type_;
    //FigureType figure_type_;
   
};
enum  figure_type
{
    kDefault = 0,
    kLine = 1,
    kRectangle = 2,
    kEllipse = 3,
    kPolygon = 4,
};









