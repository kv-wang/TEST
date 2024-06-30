#include "interact.h"
#include "ui_interact.h"
#include<knowledge.h>
#include<QString>
#include<QFile>
#include<QStringList>
#include<mainwindow.h>
interact::interact(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::interact)
{
    ui->setupUi(this);
    ui->link->setVisible(false);
    setWindowTitle("人猫和谐小知识喵~");
    ui->back->setIconSize(ui->back->size());
}

interact::~interact()
{
    delete ui;
}

void interact::on_input_returnPressed()
{
    QString searchtext = ui->input->text();//当按下回车键时，获取搜索框的文本
    if(searchtext=="喂食"){
        flag=1;
        ui->link->setIcon(QIcon(":/feed_info.jpg"));
        ui->link->setIconSize(ui->link->size());
        ui->link->setVisible(true);
    }
    else if(searchtext=="疫苗"){
        flag=2;
        ui->link->setIcon(QIcon(":/vaccine.jpg"));
        ui->link->setIconSize(ui->link->size());
        ui->link->setVisible(true);
    }
    else if(searchtext=="绝育"){
        flag=3;
        ui->link->setIcon(QIcon(":/jueyu.jpg"));
        ui->link->setIconSize(ui->link->size());
        ui->link->setVisible(true);
    }
    else if(searchtext=="日光"){
        flag=4;
        ui->link->setIcon(QIcon(":/riguang.jpg"));
        ui->link->setIconSize(ui->link->size());
        ui->link->setVisible(true);
    }
}


void interact::on_link_clicked()
{
    QStringList list;
    // 读取的文件路径
    QString filePath;
    if(flag==1)
        filePath = ":/to feed.txt";
    else if(flag==2)
        filePath = ":/vaccine.txt";
    else if(flag==3)
        filePath=":/steralization.txt";
    // 打开文件
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Could not open file: " << file.errorString();

    }

    // 读取文件内容并存入QStringList Info
    QTextStream in(&file);
    //QStringList lines;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        list.append(line);
    }

    // 关闭文件
    file.close();

    //把QLabel的文字设置成读取的信息
    QString str = list.join("\n");



    knowledge *k=new knowledge;
    k->f(str);
    k->show();
    this->close();
}


void interact::on_back_clicked()
{
    MainWindow *m=new MainWindow;
    m->show();
    this->close();
}


void interact::on_back_pressed()
{
    QPixmap pixmap(":/back_press.png");
    QIcon icon(pixmap);
    ui->back->setIconSize(ui->back->size());
    ui->back->setIcon(icon);
}

