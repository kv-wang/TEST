#include "catinfo.h"
#include "ui_catinfo.h"
#include<allcats.h>
#include<QLabel>
#include<string>
#include<QString>
#include<buttonhoverwatcher.h>
#include<QFile>
#include<QSoundEffect>
using namespace std;
Catinfo::Catinfo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Catinfo)
{
    ui->setupUi(this);

    friends.push_back(ui->friend1);
    friends.push_back(ui->friend2);
    friends.push_back(ui->friend3);
    friends.push_back(ui->friend4);
    friends.push_back(ui->friend5);
    for(int i=0;i<5;i++)
        friends[i]->setVisible(false);


    QString filePath = ":/relation.txt";

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
        QStringList parts=line.split('&');


    }

    // 关闭文件
    file.close();

    //QLabel *btn = new QLabel(this);   //在当前界面创建按钮
    //health="well-conditioned";

    btn->setText(health);                 //设置按钮显示文本
    btn->setGeometry(120, 250, 50, 25);
    btn->setStyleSheet("background-color: rgb(173, 216, 230);");
    btn->setStyleSheet("QLabel {"
                       "    border-radius: 10px;" // 设置边缘半径为10像素，以使边缘为圆形
                       "    background-color: lightblue;" // 设置背景颜色为浅蓝色（可选）
                       "}");
    btn->setVisible(false);

    cat_pic->setGeometry(100,50,300,200);

    info->setGeometry(240,250,100,25);
    info->setStyleSheet("background-color: rgb(173, 216, 230);");
    info->setStyleSheet("QLabel {"
                        "    border-radius: 10px;" // 设置边缘半径为10像素，以使边缘为圆形
                        "    background-color: lightblue;" // 设置背景颜色为浅蓝色（可选）
                        "}");
    info->setVisible(false);
    ui->back->lower();

    ui->nature_pic->installEventFilter(new ButtonHoverWatcher(this,this->ui->nature->text()));

    ui->name->setStyleSheet("QPushButton {"
                            "    border-radius: 10px;" // 设置边缘半径为10像素，以使边缘为圆形
                            "    background-color: lightblue;" // 设置背景颜色为浅蓝色（可选）
                            "}");
    ui->add->setStyleSheet("QPushButton {"
                            "    border-radius: 10px;" // 设置边缘半径为10像素，以使边缘为圆形
                            "    background-color: lightblue;" // 设置背景颜色为浅蓝色（可选）
                            "}");
    ui->appearance->setStyleSheet("QPushButton {"
                            "    border-radius: 10px;" // 设置边缘半径为10像素，以使边缘为圆形
                            "    background-color: lightblue;" // 设置背景颜色为浅蓝色（可选）
                            "}");
    ui->gender->setStyleSheet("QPushButton {"
                            "    border-radius: 10px;" // 设置边缘半径为10像素，以使边缘为圆形
                            "    background-color: lightblue;" // 设置背景颜色为浅蓝色（可选）
                            "}");
    ui->nature->setStyleSheet("QPushButton {"
                            "    border-radius: 10px;" // 设置边缘半径为10像素，以使边缘为圆形
                            "    background-color: lightblue;" // 设置背景颜色为浅蓝色（可选）
                            "}");
    setWindowTitle("猫猫详情");
}

Catinfo::~Catinfo()
{
    delete ui;
}

void Catinfo::init_friends(int x){//设置第i个朋友按钮
    int i=friends_id[x];
    Catinfo* c=new Catinfo;
    QSoundEffect* s1=new QSoundEffect();
    s1->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/meow4.wav"));
    s1->play();
    //c->ui->deb->setText(Info[i]);

    for(int j=0;j<Allcats().relate_id[i].size();j++){//把所有与第i个猫相关的猫关联
        //c->friends.push_back(vbtn[relate_id[i][j]]);
        c->friends[j]->setVisible(true);
        QString str="";
        str+=":/Image(1)/untitled folder/";
        str+=QString::number(Allcats().relate_id[i][j]+1);
        str+=".png";
        QPixmap p(str);
        QIcon icon(p);
        c->friends[j]->setIcon(icon);
        c->friends[j]->setIconSize(c->friends[j]->size());
        //c->friends[j]->setText(str);

        c->friends_id.push_back(Allcats().relate_id[i][j]);
    }

    //c->health=Health[i];
    //c->btn->setText(c->health);
    QString s="";
    s=s+":/BigImage/BigImage/";
    s+=QString::number(i+1);//将i转换为字符串
    s+="cat.png";
    c->cat_pic->setPixmap(QPixmap(s));
    c->cat_pic->setScaledContents(true);
    c->info->setText(Allcats().Info[i]);

    c->ui->name->setText(Allcats().names[i]);
    c->ui->add->setText(Allcats().add_appear[i]);
    c->ui->appearance->setText(Allcats().Appearrance[i]);
    c->ui->gender->setText(Allcats().Gender[i]);
    c->ui->nature->setText(Allcats().natures[i]);

    if(Allcats().natures[i].indexOf("怕人")!=-1){
        /*
        QPixmap pixmap(":/5.17/button1_pressed.jpg");
        QIcon icon(pixmap);
        ui->chazhao->setIcon(icon);
        */
        QPixmap pixmap(":/5.22/others/afraid.jpg");
        QIcon icon(pixmap);
        c->ui->nature_pic->setIcon(icon);
    }
    else if(Allcats().natures[i].indexOf("玄学")!=-1){
        QPixmap pixmap(":/5.22/others/shrodinger.jpg");
        QIcon icon(pixmap);
        c->ui->nature_pic->setIcon(icon);
    }
    else if(Allcats().natures[i].indexOf("可摸不可抱")!=-1){
        QPixmap pixmap(":/5.22/others/stroke.jpg");
        QIcon icon(pixmap);
        c->ui->nature_pic->setIcon(icon);
    }
    else if(Allcats().natures[i].indexOf("喂")!=-1){
        QPixmap pixmap(":/5.22/others/feed.jpg");
        QIcon icon(pixmap);
        c->ui->nature_pic->setIcon(icon);
    }
    else if(Allcats().natures[i].indexOf("可抱")!=-1){
        QPixmap pixmap(":/5.22/others/shrodinger.jpg");
        QIcon icon(pixmap);
        c->ui->nature_pic->setIcon(icon);
    }
    // 设置图标大小以适应按钮大小
    c->ui->nature_pic->setIconSize(c->ui->nature_pic->size());


    c->show();
    this->close();

}

void Catinfo::on_pushButton_clicked()
{
    Allcats* x=new Allcats;
    int y=0;
    QString refined_searchtext=request;
    for(int i=0;i<12;i++) {
        if(x->Info[i].indexOf(refined_searchtext)==-1)
            x->vbtn[i]->setVisible(false);//如果当前猫的信息中找不到关键词，按钮不可见（也无法点击）
        else{
            x->vbtn[i]->move(0,y*40);
            y++;
        }//移动显示的按钮，实现搜索出来的按钮从上到下紧密排列
    }
    if(y==0){
        QLabel* label=new QLabel("没有找到符合条件的猫猫哦~",x);
        label->move(90,40);
    }
    x->show();
    QSoundEffect* s=new QSoundEffect();
    s->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/meow_all.wav"));
    s->play();
    this->close();
}


void Catinfo::on_add_clicked()
{
    // 当按钮被释放时，点击完毕，打开新的窗口

    Allcats* x=new Allcats;//打开一个新界面，只显示满足条件的猫猫对应的按钮
    QSoundEffect* s=new QSoundEffect();
    s->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/meow3.wav"));
    s->play();

    int y=0;
    QString refined_searchtext=this->ui->add->text();
    for(int i=0;i<12;i++) {
        if(x->Info[i].indexOf(refined_searchtext)==-1)
            x->vbtn[i]->setVisible(false);//如果当前猫的信息中找不到关键词，按钮不可见（也无法点击）
        else{
            x->vbtn[i]->move(0,y*40);
            y++;
        }//移动显示的按钮，实现搜索出来的按钮从上到下紧密排列
    }
    if(y==0){
        QLabel* label=new QLabel("没有找到符合条件的猫猫哦~",x);
        label->move(90,40);
    }
    x->show();
    this->close();
}


void Catinfo::on_appearance_clicked()
{
    // 当按钮被释放时，点击完毕，打开新的窗口
    Allcats* x=new Allcats;//打开一个新界面，只显示满足条件的猫猫对应的按钮
    QSoundEffect* s=new QSoundEffect();
    s->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/meow3.wav"));
    s->play();
    int y=0;
    QString refined_searchtext=this->ui->appearance->text();
    for(int i=0;i<12;i++) {
        if(x->Info[i].indexOf(refined_searchtext)==-1)
            x->vbtn[i]->setVisible(false);//如果当前猫的信息中找不到关键词，按钮不可见（也无法点击）
        else{
            x->vbtn[i]->move(0,y*40);
            y++;
        }//移动显示的按钮，实现搜索出来的按钮从上到下紧密排列
    }
    if(y==0){
        QLabel* label=new QLabel("没有找到符合条件的猫猫哦~",x);
        label->move(90,40);
    }
    x->show();
    this->close();
}


void Catinfo::on_gender_clicked()
{
    // 当按钮被释放时，点击完毕，打开新的窗口
    Allcats* x=new Allcats;//打开一个新界面，只显示满足条件的猫猫对应的按钮
    QSoundEffect* s=new QSoundEffect();
    s->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/meow4.wav"));
    s->play();
    int y=0;
    QString refined_searchtext=this->ui->gender->text();
    for(int i=0;i<12;i++) {
        if(x->Info[i].indexOf(refined_searchtext)==-1)
            x->vbtn[i]->setVisible(false);//如果当前猫的信息中找不到关键词，按钮不可见（也无法点击）
        else{
            x->vbtn[i]->move(0,y*40);
            y++;
        }//移动显示的按钮，实现搜索出来的按钮从上到下紧密排列
    }
    if(y==0){
        QLabel* label=new QLabel("没有找到符合条件的猫猫哦~",x);
        label->move(90,40);
    }
    x->show();
    this->close();
}


void Catinfo::on_nature_clicked()
{
    // 当按钮被释放时，点击完毕，打开新的窗口
    Allcats* x=new Allcats;//打开一个新界面，只显示满足条件的猫猫对应的按钮
    QSoundEffect* s=new QSoundEffect();
    s->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/meow5.wav"));
    s->play();
    int y=0;
    QString refined_searchtext=this->ui->nature->text();
    for(int i=0;i<12;i++) {
        if(x->Info[i].indexOf(refined_searchtext)==-1)
            x->vbtn[i]->setVisible(false);//如果当前猫的信息中找不到关键词，按钮不可见（也无法点击）
        else{
            x->vbtn[i]->move(0,y*40);
            y++;
        }//移动显示的按钮，实现搜索出来的按钮从上到下紧密排列
    }
    if(y==0){
        QLabel* label=new QLabel("没有找到符合条件的猫猫哦~",x);
        label->move(90,40);
    }
    x->show();
    this->close();
}

/*
void Catinfo::on_nature_pic_clicked()
{
}
*/

void Catinfo::on_friend1_clicked()
{
    int i=0;
    init_friends(i);
}


void Catinfo::on_friend2_clicked()
{
    int i=1;
    init_friends(i);
}


void Catinfo::on_friend3_clicked()
{
    int i=2;
    init_friends(i);
}


void Catinfo::on_friend4_clicked()
{
    int i=3;
    init_friends(i);
}


void Catinfo::on_friend5_clicked()
{
    int i=4;
    init_friends(i);
}

