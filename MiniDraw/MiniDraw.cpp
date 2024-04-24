#include "MiniDraw.h"
#include <QDebug>
//#include <iostream>
//using namespace std;
#include <QLine>


MiniDraw::MiniDraw(QWidget *parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    CreateButtons();//调用函数
    Init();
    

}

MiniDraw::~MiniDraw()
{}

void MiniDraw::CreateButtons()
{
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);//失能最大化
    setFixedSize(this->width(), this->height());//固定窗口尺寸
    //创建动作
    about_action = new QAction( tr("&About"),this);
    line_action = new QAction(tr("&Line"), this);
    rectangle_action = new QAction(tr("&Rectangle"), this);
    ellipse_action = new QAction(tr("&Ellipse"), this);
    polygon_action = new QAction(tr("&Polygon"), this);
    delete_action = new QAction(tr("&Delete"), this);
    
    //创建菜单
    Figure_Tool_menu = menuBar()->addMenu(tr("&Figure Tool"));
    //将动作加载到Figure Tool菜单中
    Figure_Tool_menu->addAction(about_action);
    Figure_Tool_menu->addAction(line_action);
    Figure_Tool_menu->addAction(rectangle_action);
    Figure_Tool_menu->addAction(ellipse_action);
    Figure_Tool_menu->addAction(polygon_action);
    Figure_Tool_menu->addAction(delete_action);
    //创建工具栏
    Figure_Tool_toolbar = addToolBar(tr("&Figure Tool"));
    Figure_Tool_toolbar ->addAction(about_action);
    Figure_Tool_toolbar ->addAction(line_action);
    Figure_Tool_toolbar ->addAction(rectangle_action);
    Figure_Tool_toolbar ->addAction(ellipse_action);
    Figure_Tool_toolbar ->addAction(polygon_action);
    Figure_Tool_toolbar ->addAction(delete_action);




}

void MiniDraw::Init()//实例代码中将绘图控件的实例化放在Init函数中，Init函数将在MiniDraw的构造函数中被调用
{
    view_widget_ = new ViewWidget();//实例化ViewWidget控件窗口
    setCentralWidget(view_widget_);//将ViewWidget控件设置为主窗口的中心位置
    //cout<< "abd";
}
