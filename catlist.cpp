#include "catlist.h"
#include "ui_catlist.h"
#include "allcats.h"
#include<QLabel>
#include<mainwindow.h>
#include<QEvent>
#include<QObject>

#include <QObject>
#include <QPushButton>
#include <QEvent>
#include <QMediaPlayer>

#include <buttonhoverwatcher.h>
#include<QSoundEffect>

//QSoundEffect *bgm= new QSoundEffect();

QSoundEffect *m[6]= {new QSoundEffect(),new QSoundEffect(),new QSoundEffect(),new QSoundEffect(),new QSoundEffect(),new QSoundEffect()};

Catlist::Catlist(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Catlist)
{
    ui->setupUi(this);
    //this->setStyleSheet("background-image: url(:/5.17/mainmenu2.png);"
                          //"background-repeat: no-repeat;"
                          //"background-position: center;");
    ui->label_2->lower();
    //ui->pushButton->setStyleSheet("QPushButton:hover{border-image:url(:/7.png);}");
    //ButtonHoverWatcher * watcher = new ButtonHoverWatcher(this);
    ui->pushButton->installEventFilter(new ButtonHoverWatcher(this,""));
    ui->ju->installEventFilter(new ButtonHoverWatcher(this,"橘"));
    ui->bai->installEventFilter(new ButtonHoverWatcher(this,"白"));
    ui->hei->installEventFilter(new ButtonHoverWatcher(this,"黑"));
    ui->sanhua->installEventFilter(new ButtonHoverWatcher(this,"三花"));
    ui->daimao->installEventFilter(new ButtonHoverWatcher(this,"玳瑁"));
    ui->lihua->installEventFilter(new ButtonHoverWatcher(this,"狸花"));
    ui->nainiu->installEventFilter(new ButtonHoverWatcher(this,"奶牛"));
    ui->gong->installEventFilter(new ButtonHoverWatcher(this,"公"));
    ui->mu->installEventFilter(new ButtonHoverWatcher(this,"母"));
    ui->unknown->installEventFilter(new ButtonHoverWatcher(this,"未知"));

    m[0]->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/meow_all.wav"));
    m[1]->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/meow1.wav"));
    m[2]->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/meow2.wav"));
    m[3]->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/meow3.wav"));
    m[4]->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/meow4.wav"));
    m[5]->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/meow5.wav"));


    ui->back->setIconSize(ui->back->size());
}

Catlist::~Catlist()
{
    delete ui;
}

void Catlist::on_pushButton_clicked()
{



    Allcats *tmp=new Allcats;
    tmp->show();
    m[1]->setVolume(1);
    m[1]->play();
    this->close();

}


void Catlist::on_searchbtn_clicked()
{
    QString searchtext = ui->lineEdit->text();//当点击搜索按钮时，获取搜索框的文本

    QString refined_searchtext="";//处理后的搜索关键词，去除了空格
    QString meo="猫";
    searchtext.replace(meo,"");//去除“猫”这个太general的词，防止影响搜索
    QString mii="咪";

    searchtext.replace(mii,"");
    //这样以来，像“三花 猫猫”这样的检索就可以查到所有三花猫了！
    for(int i=0;i<searchtext.size();i++){
        if(searchtext[i]!=' ')
            refined_searchtext+=searchtext[i];
    }
    Allcats* x=new Allcats;//打开一个新界面，只显示满足条件的猫猫对应的按钮
    int y=0;
    for(int i=0;i<19;i++) {
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
    //m[rand()%5-1]->play();
    this->close();
}


void Catlist::on_lineEdit_returnPressed()
{
    QString searchtext = ui->lineEdit->text();//当按下回车键时，获取搜索框的文本

    QString meo="猫";
    searchtext.replace(meo,"");
    QString mii="咪";
    searchtext.replace(mii,"");

    QString refined_searchtext="";
    for(int i=0;i<searchtext.size();i++){
        if(searchtext[i]!=' ')
            refined_searchtext+=searchtext[i];
    }
    Allcats* x=new Allcats;//打开一个新界面，只显示满足条件的猫猫对应的按钮
    int y=0;
    for(int i=0;i<19;i++) {
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

    //m[rand()%5-1]->play();
    this->close();
}


void Catlist::on_bai_clicked()
{
    QString refined_searchtext="白";

    Allcats* x=new Allcats;//打开一个新界面，只显示满足条件的猫猫对应的按钮
    int y=0;
    for(int i=0;i<19;i++) {
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
    //m[rand()%5-1]->play();
    this->close();
}




void Catlist::on_hei_clicked()
{
    QString refined_searchtext="黑";

    Allcats* x=new Allcats;//打开一个新界面，只显示满足条件的猫猫对应的按钮
    int y=0;
    for(int i=0;i<19;i++) {
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

    //m[rand()%5-1]->play();
    this->close();
}


void Catlist::on_daimao_clicked()
{
    QString refined_searchtext="玳瑁";

    Allcats* x=new Allcats;//打开一个新界面，只显示满足条件的猫猫对应的按钮
    int y=0;
    for(int i=0;i<19;i++) {
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
    //m[rand()%5-1]->play();
    this->close();
}


void Catlist::on_ju_clicked()
{
    QString refined_searchtext="橘";

    Allcats* x=new Allcats;//打开一个新界面，只显示满足条件的猫猫对应的按钮
    int y=0;
    for(int i=0;i<19;i++) {
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
    //m[rand()%5-1]->play();
    this->close();
}


void Catlist::on_lihua_clicked()
{
    QString refined_searchtext="梨花";

    Allcats* x=new Allcats;//打开一个新界面，只显示满足条件的猫猫对应的按钮
    int y=0;
    for(int i=0;i<19;i++) {
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
    //m[rand()%5-1]->play();
    this->close();
}


void Catlist::on_sanhua_clicked()
{
    QString refined_searchtext="三花";

    Allcats* x=new Allcats;//打开一个新界面，只显示满足条件的猫猫对应的按钮
    int y=0;
    for(int i=0;i<19;i++) {
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
    //m[rand()%5-1]->play();
    this->close();
}



void Catlist::on_nainiu_clicked()
{
    QString refined_searchtext="奶牛";

    Allcats* x=new Allcats;//打开一个新界面，只显示满足条件的猫猫对应的按钮
    int y=0;
    for(int i=0;i<19;i++) {
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
    //m[rand()%5-1]->play();
    this->close();
}


void Catlist::on_back2main_clicked()
{
    MainWindow* mw=new MainWindow;
    mw->show();
    //m[rand()%5-1]->play();
    this->close();
}



void Catlist::on_back2main_pressed()
{
    QPixmap pixmap(":/back_press.png");
    QIcon icon(pixmap);


}


void Catlist::on_back_clicked(bool checked)
{

}


void Catlist::on_back_clicked()
{
    MainWindow* mw=new MainWindow;
    mw->show();
    //m[rand()%5-1]->play();
    this->close();
}


void Catlist::on_back_pressed()
{
    QPixmap pixmap(":/back_press.png");
    QIcon icon(pixmap);
    ui->back->setIconSize(ui->back->size());
    ui->back->setIcon(icon);
}

