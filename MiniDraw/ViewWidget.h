#pragma once
#include <qwidget.h>

#include <vector>
#include "Line.h"
#include "Ellipse.h"
#include "Figure.h"

using namespace std;


class ViewWidget :
    public QWidget  //��ӳ�Ա��������
{
public:
    ViewWidget(QWidget* parent = nullptr);
    ~ViewWidget();

    void mousePressEvent(QMouseEvent* event);//��������Ӧ���������Ҽ�����˫����
    void mouseMoveEvent(QMouseEvent* event);//����ƶ���Ӧ����
    void mouseReleaseEvent(QMouseEvent* event);//����ͷ���Ӧ���������Ҽ�����˫����
    
    void paintEvent(QPaintEvent* event);//Qt���л��ƶ�ֻ���ڴ˺��������
    void set_figure_type_to_line();
    void set_figure_type_to_ellipse();


   
private:
   

    bool draw_status_;//��ǰ����״̬��trueΪ���Ƶ�ǰ����϶���ͼԪ��falseΪ������
    QPoint start_point_;//��ǰͼԪ����ʼ��
    QPoint end_point_;//��ǰͼԪ����ֹ��

    vector<Line* >  line_array_;
    vector<Ellipse* >  ellipse_array_;
    vector<Figure* > figure_array_;//����ָ������洢����
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









