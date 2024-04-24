

#include <QtWidgets/QMainWindow>
#include "ui_MiniDraw.h"
#include "ViewWidget.h"




class MiniDraw : public QMainWindow
{
    Q_OBJECT

public:
    MiniDraw(QWidget *parent = nullptr);
    ~MiniDraw();




private:
    Ui::MiniDrawClass ui;


    //声明动作
    QAction* about_action;
    QAction* line_action;
    QAction* rectangle_action;
    QAction* ellipse_action;
    QAction* polygon_action;
    QAction* delete_action;
    //声明菜单
    QMenu* Figure_Tool_menu;
    //声明工具栏
    QToolBar* Figure_Tool_toolbar;
    //声明函数
    void CreateButtons();
    void Init();

    //声明ViewWidget指针
    ViewWidget* view_widget_;
   
};
