#include "MiniDraw.h"
#include <QDebug>
//#include <iostream>
//using namespace std;
#include <QLine>


MiniDraw::MiniDraw(QWidget *parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    CreateButtons();//���ú���
    Init();
    

}

MiniDraw::~MiniDraw()
{}

void MiniDraw::CreateButtons()
{
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);//ʧ�����
    setFixedSize(this->width(), this->height());//�̶����ڳߴ�
    //��������
    about_action = new QAction( tr("&About"),this);
    line_action = new QAction(tr("&Line"), this);
    rectangle_action = new QAction(tr("&Rectangle"), this);
    ellipse_action = new QAction(tr("&Ellipse"), this);
    polygon_action = new QAction(tr("&Polygon"), this);
    delete_action = new QAction(tr("&Delete"), this);
    
    //�����˵�
    Figure_Tool_menu = menuBar()->addMenu(tr("&Figure Tool"));
    //���������ص�Figure Tool�˵���
    Figure_Tool_menu->addAction(about_action);
    Figure_Tool_menu->addAction(line_action);
    Figure_Tool_menu->addAction(rectangle_action);
    Figure_Tool_menu->addAction(ellipse_action);
    Figure_Tool_menu->addAction(polygon_action);
    Figure_Tool_menu->addAction(delete_action);
    //����������
    Figure_Tool_toolbar = addToolBar(tr("&Figure Tool"));
    Figure_Tool_toolbar ->addAction(about_action);
    Figure_Tool_toolbar ->addAction(line_action);
    Figure_Tool_toolbar ->addAction(rectangle_action);
    Figure_Tool_toolbar ->addAction(ellipse_action);
    Figure_Tool_toolbar ->addAction(polygon_action);
    Figure_Tool_toolbar ->addAction(delete_action);




}

void MiniDraw::Init()//ʵ�������н���ͼ�ؼ���ʵ��������Init�����У�Init��������MiniDraw�Ĺ��캯���б�����
{
    view_widget_ = new ViewWidget();//ʵ����ViewWidget�ؼ�����
    setCentralWidget(view_widget_);//��ViewWidget�ؼ�����Ϊ�����ڵ�����λ��
    //cout<< "abd";
}
