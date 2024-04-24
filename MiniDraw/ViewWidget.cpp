#include "ViewWidget.h"
#include <QMouseEvent>
#include <QPainter>

ViewWidget::ViewWidget(QWidget* parent)
    : QWidget(parent)
{
   
    draw_status_ = false;//设置初始绘制状态为-不绘制
}





//鼠标击发响应函数函数体
void ViewWidget::mousePressEvent(QMouseEvent* event)
{
    if (Qt::LeftButton == event ->button())//判断是否是鼠标左击
    {
        draw_status_ = true;//设置绘制状态为-绘制
        start_point_ = end_point_ = event ->pos();//将图元初始点设置为当前鼠标击发点
    }
}
//鼠标移动响应函数函数体
void ViewWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (draw_status_)//判断当前绘制状态
    {
        end_point_ = event->pos();//若为真，则设置图元终止点位鼠标当前位置
    }
}
//鼠标释放响应函数函数体
void ViewWidget::mouseReleaseEvent(QMouseEvent* event)
{
    Figure* current_figure_ = NULL;//声明父类指针
    switch(figure_type_)
    {
    case kDefault:
        break;
    case kLine:
        current_figure_ = new Line(start_point_.rx(), start_point_.ry(), end_point_.rx(), end_point_.ry());
        figure_array_.push_back(current_figure_);
        draw_status_ = false;//设置绘制状态为-不绘制
        break;
    case kEllipse:
        current_figure_ = new Ellipse(start_point_.rx(), start_point_.ry(), end_point_.rx(), end_point_.ry());
        figure_array_.push_back(current_figure_);
        draw_status_ = false;//设置绘制状态为-不绘制
        break;
    default:
        break;
    }
    current_figure_ = NULL;
}
//绘制消息响应函数函数体
void ViewWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);//定义painter在this指向的控件（此例为ViewWidget）
    //painter.begin(this);//开始绘图
    for (size_t i = 0; i < figure_array_.size(); i++)
    {
        figure_array_[i]->Draw(painter);
    }
    if (draw_status_)
    {
        switch (figure_type_)
        {
        case kDefault:
            break;
        case kLine:
            painter.drawLine(start_point_, end_point_);
            break;
        case kEllipse:
            painter.drawEllipse(start_point_.rx(), end_point_.ry(),end_point_.rx(),end_point_.ry());
            break;
        }
    }
    //painter.end();//结束绘画
    //painter.drawLine(start_point_, end_point_);//绘制线段
    update();//更新窗口
}

ViewWidget::~ViewWidget()
{
    for (size_t i = 0; i < line_array_.size(); i++)
    {
        if (line_array_[i])
        {
            delete line_array_[i];
            line_array_[i] = NULL;
        }
    }
}

void ViewWidget::set_figure_type_to_line()
{
    figure_type_ = kLine;
}

void ViewWidget::set_figure_type_to_ellipse()
{
    figure_type_ = kEllipse;
}




