#include "ViewWidget.h"
#include <QMouseEvent>
#include <QPainter>

ViewWidget::ViewWidget(QWidget* parent)
    : QWidget(parent)
{
   
    draw_status_ = false;//���ó�ʼ����״̬Ϊ-������
}





//��������Ӧ����������
void ViewWidget::mousePressEvent(QMouseEvent* event)
{
    if (Qt::LeftButton == event ->button())//�ж��Ƿ���������
    {
        draw_status_ = true;//���û���״̬Ϊ-����
        start_point_ = end_point_ = event ->pos();//��ͼԪ��ʼ������Ϊ��ǰ��������
    }
}
//����ƶ���Ӧ����������
void ViewWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (draw_status_)//�жϵ�ǰ����״̬
    {
        end_point_ = event->pos();//��Ϊ�棬������ͼԪ��ֹ��λ��굱ǰλ��
    }
}
//����ͷ���Ӧ����������
void ViewWidget::mouseReleaseEvent(QMouseEvent* event)
{
    Figure* current_figure_ = NULL;//��������ָ��
    switch(figure_type_)
    {
    case kDefault:
        break;
    case kLine:
        current_figure_ = new Line(start_point_.rx(), start_point_.ry(), end_point_.rx(), end_point_.ry());
        figure_array_.push_back(current_figure_);
        draw_status_ = false;//���û���״̬Ϊ-������
        break;
    case kEllipse:
        current_figure_ = new Ellipse(start_point_.rx(), start_point_.ry(), end_point_.rx(), end_point_.ry());
        figure_array_.push_back(current_figure_);
        draw_status_ = false;//���û���״̬Ϊ-������
        break;
    default:
        break;
    }
    current_figure_ = NULL;
}
//������Ϣ��Ӧ����������
void ViewWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);//����painter��thisָ��Ŀؼ�������ΪViewWidget��
    //painter.begin(this);//��ʼ��ͼ
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
    //painter.end();//�����滭
    //painter.drawLine(start_point_, end_point_);//�����߶�
    update();//���´���
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




