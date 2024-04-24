

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


    //��������
    QAction* about_action;
    QAction* line_action;
    QAction* rectangle_action;
    QAction* ellipse_action;
    QAction* polygon_action;
    QAction* delete_action;
    //�����˵�
    QMenu* Figure_Tool_menu;
    //����������
    QToolBar* Figure_Tool_toolbar;
    //��������
    void CreateButtons();
    void Init();

    //����ViewWidgetָ��
    ViewWidget* view_widget_;
   
};
