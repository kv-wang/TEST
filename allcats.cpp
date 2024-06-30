#include "allcats.h"
#include "ui_allcats.h"
#include <catlist.h>
#include "catinfo.h"
#include "ui_catinfo.h"
#include <QLabel>
#include <QScrollArea>
#include <QString>
#include <QStringList>
#include <QMouseEvent>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <vector>
#include <QPushButton>
#include<QString>
using namespace std;
Allcats::Allcats(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Allcats)
{
    ui->setupUi(this);


    for(int i=0;i<vbtn.size();i++){
        QString str="";
        str+=":/";
        str+=QString::number(i+1);
        str+=".png";
        QPixmap p(str);
        QIcon I(p);
        vbtn[i]->setIcon(I);
        vbtn[i]->setIconSize(vbtn[i]->size());
    }

    //将每个猫信息的按钮存储进数组，方便搜索查找工作
    vbtn.push_back(ui->pushButton);//ui->pushButton 返回的是 QPushButton 的指针
    vbtn.push_back(ui->pushButton_2);
    vbtn.push_back(ui->pushButton_3);
    vbtn.push_back(ui->pushButton_4);
    vbtn.push_back(ui->pushButton_5);
    vbtn.push_back(ui->pushButton_6);
    vbtn.push_back(ui->pushButton_7);
    vbtn.push_back(ui->pushButton_8);
    vbtn.push_back(ui->pushButton_9);
    vbtn.push_back(ui->pushButton_10);
    vbtn.push_back(ui->pushButton_11);
    vbtn.push_back(ui->pushButton_12);
    vbtn.push_back(ui->pushButton_13);
    vbtn.push_back(ui->pushButton_14);
    vbtn.push_back(ui->pushButton_15);
    vbtn.push_back(ui->pushButton_16);
    vbtn.push_back(ui->pushButton_17);
    vbtn.push_back(ui->pushButton_18);
    vbtn.push_back(ui->pushButton_19);


    for(int i=0;i<vbtn.size();i++){
        QString str="";
        str+=":/Image(1)/untitled folder/";
        str+=QString::number(i+1);
        str+=".png";
        QPixmap p(str);
        QIcon I(p);
        vbtn[i]->setIcon(I);
        vbtn[i]->setIconSize(QSize(38,38));
        vbtn[i]->setStyleSheet("QPushButton { background-color: white; }");
    }


    for(int i=0;i<20;i++){
        Health<<"健康";
    }
    Health[1]="不健康";

    //下面尝试读入猫猫信息
    // 读取的文件路径
    QString filePath = ":/others/catinfo.txt";

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
        //qDebug()<<line;
        QStringList parts=line.split(' ');


        names.append(parts[0]);
        add_appear.append(parts[1]);
        Appearrance.append(parts[2]);
        Gender.append(parts[3]);
        natures.append(parts[4]);
        Info.append(line);


    }

    // 关闭文件
    file.close();


    QString filePath2 = ":/others/relation.txt";

    // 打开文件
    QFile file2(filePath2);
    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Could not open file: " << file2.errorString();

    }

    // 读取文件内容并存入QStringList relation
    QTextStream in2(&file2);
    //QStringList lines;
    int tmp=0;
    while (!in2.atEnd())
    {
        QString line2 = in2.readLine();
        //qDebug()<<line2;
        vector<int> vtmp;
        for(int i=0;i<names.size();i++){
            if(line2.indexOf(names[i])!=-1){//第i个猫的名字出现在当前猫(第tmp个)的关系字符串中(有关系）
                vtmp.push_back(i);
            }
        }
        relate_id[tmp]=vtmp;
        tmp++;

    }

    // 关闭文件
    file2.close();

    /*
    // 输出QStringList中的内容（可选）
    qDebug() << "Content of QStringList:";
    for (const QString &line : Info)
    {
        qDebug() << line;
    }
    */
}




Allcats::~Allcats()
{
    delete ui;
}
void Allcats::set(int i){//设置第i只猫的信息窗口


    Catinfo* c=new Catinfo;
    c->request=str_inquiry;
    QSoundEffect* js=new QSoundEffect();
    js->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/meow3.wav"));
    js->play();

    //c->ui->deb->setText(Info[i]);

    for(int j=0;j<relate_id[i].size();j++){//把所有与第i个猫相关的猫关联
        //c->friends.push_back(vbtn[relate_id[i][j]]);
        c->friends[j]->setVisible(true);
        QString str="";
        str+=":/Image(1)/untitled folder/";
        str+=QString::number(relate_id[i][j]+1);
        str+=".png";
        QPixmap p(str);
        QIcon icon(p);
        c->friends[j]->setIcon(icon);
        c->friends[j]->setIconSize(c->friends[j]->size());
        //c->friends[j]->setText(str);

        c->friends_id.push_back(relate_id[i][j]);
    }

    c->health=Health[i];
    c->btn->setText(c->health);
    QString s="";
    s=s+":/BigImage/BigImage/";
    s+=QString::number(i+1);//将i转换为字符串
    s+="cat.png";
    c->cat_pic->setPixmap(QPixmap(s));
    c->cat_pic->setScaledContents(true);
    c->info->setText(Info[i]);

    c->ui->name->setText(names[i]);
    c->ui->add->setText(add_appear[i]);
    c->ui->appearance->setText(Appearrance[i]);
    c->ui->gender->setText(Gender[i]);
    c->ui->nature->setText(natures[i]);

    if(natures[i].indexOf("怕人")!=-1){
        /*
        QPixmap pixmap(":/5.17/button1_pressed.jpg");
        QIcon icon(pixmap);
        ui->chazhao->setIcon(icon);
        */
        QPixmap pixmap(":/5.22/others/afraid.jpg");
        QIcon icon(pixmap);
        c->ui->nature_pic->setIcon(icon);
    }
    else if(natures[i].indexOf("玄学")!=-1){
        QPixmap pixmap(":/5.22/others/shrodinger.jpg");
        QIcon icon(pixmap);
        c->ui->nature_pic->setIcon(icon);
    }
    else if(natures[i].indexOf("可摸不可抱")!=-1){
        QPixmap pixmap(":/5.22/others/stroke.jpg");
        QIcon icon(pixmap);
        c->ui->nature_pic->setIcon(icon);
    }
    else if(natures[i].indexOf("喂")!=-1){
        QPixmap pixmap(":/5.22/others/feed.jpg");
        QIcon icon(pixmap);
        c->ui->nature_pic->setIcon(icon);
    }
    else if(natures[i].indexOf("可抱")!=-1){
        QPixmap pixmap(":/5.22/others/shrodinger.jpg");
        QIcon icon(pixmap);
        c->ui->nature_pic->setIcon(icon);
    }
    // 设置图标大小以适应按钮大小
    c->ui->nature_pic->setIconSize(c->ui->nature_pic->size());


    c->show();
    this->close();
}

void Allcats::on_pushButton_clicked()
{   int i=0;

    set(i);
}


void Allcats::on_pushButton_2_clicked()
{
    int i=1;
    set(i);
}


void Allcats::on_pushButton_3_clicked()
{
    int i=2;
    set(i);
}


void Allcats::on_pushButton_4_clicked()
{
    int i=3;
    set(i);
}


void Allcats::on_pushButton_5_clicked()
{
    int i=4;
    set(i);
}


void Allcats::on_pushButton_6_clicked()
{
    int i=5;
    set(i);
}


void Allcats::on_pushButton_7_clicked()
{
    int i=6;
    set(i);
}


void Allcats::on_pushButton_8_clicked()
{
    int i=7;
    set(i);
}


void Allcats::on_pushButton_9_clicked()
{
    int i=8;
    set(i);
}


void Allcats::on_pushButton_10_clicked()
{
    int i=9;
    set(i);
}


void Allcats::on_pushButton_11_clicked()
{
    int i=10;
    set(i);
}


void Allcats::on_pushButton_12_clicked()
{
    int i=11;
    set(i);
}



void Allcats::on_back_clicked()
{
    Catlist* x=new Catlist;

    x->show();
    this->close();
}


void Allcats::on_pushButton_13_clicked()
{
    int i=12;
    set(i);
}


void Allcats::on_pushButton_14_clicked()
{
    int i=13;
    set(i);
}


void Allcats::on_pushButton_15_clicked()
{
    int i=14;
    set(i);
}


void Allcats::on_pushButton_16_clicked()
{
    int i=15;
    set(i);
}


void Allcats::on_pushButton_17_clicked()
{
    int i=16;
    set(i);
}


void Allcats::on_pushButton_18_clicked()
{
    int i=17;
    set(i);
}


void Allcats::on_pushButton_19_clicked()
{
    int i=18;
    set(i);
}

