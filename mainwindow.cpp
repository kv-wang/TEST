#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "catlist.h"
#include <QPainter>
#include <notice.h>
#include <interact.h>
#include<QSoundEffect>

QSoundEffect *bgm= new QSoundEffect();
QSoundEffect *meow[6]= {new QSoundEffect(),new QSoundEffect(),new QSoundEffect(),new QSoundEffect(),new QSoundEffect(),new QSoundEffect()};
bool bgmPlaying=false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setScaledContents(true);

    QString _mainTitle="燕园猫图鉴";
    QString exTitle[5]={"：欢迎使用喵~","：请不要随地大小喂喵喵喵~","：试着在这片大地上搜索猫咪！","：Also try PacKU!","：吃了吗您？"};


    srand(time(0));
    QString mainTitle=_mainTitle+exTitle[rand()%5];
    setWindowTitle(mainTitle);

    meow[0]->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/meow_all.wav"));
    meow[1]->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/meow1.wav"));
    meow[2]->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/meow2.wav"));
    meow[3]->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/meow3.wav"));
    meow[4]->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/meow4.wav"));
    meow[5]->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/meow5.wav"));

    if(!bgmPlaying){
        bgm->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/NYA!!.wav"));
        bgm->setLoopCount(QSoundEffect::Infinite); //设置无限循环
        bgm->setVolume(1);//设置音量，在0到1之间
        bgm->play();
        bgmPlaying=true;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

//这个按钮已经没了，但相关的函数删不清楚，暂时留着
void MainWindow::on_pushButton_clicked()
{
    Catlist *initialpage = new Catlist;
    initialpage->show();
    this->close();
}


void MainWindow::on_chazhao_clicked()
{
    Catlist *initialpage = new Catlist;
    initialpage->show();
    meow[0]->play();
    this->close();
}


void MainWindow::on_chazhao_pressed()
{


    QPixmap pixmap(":/chazhaomaomao_press.png");
    QIcon icon(pixmap);
    ui->chazhao->setIcon(icon);
    //ui->chazhao->setText("查找猫猫");
}


void MainWindow::on_notice_clicked()
{
    Notice *n=new Notice;

    n->show();
    meow[1]->play();
    this->close();
}


void MainWindow::on_notice_pressed()
{
    QPixmap pixmap(":/xuzhi_press.png");
    QIcon icon(pixmap);
    ui->notice->setIcon(icon);
}


void MainWindow::on_settings_clicked()
{

    interact *x=new interact;
    x->show();
    meow[2]->play();
    this->close();
}


void MainWindow::on_settings_pressed()
{
    QPixmap pixmap(":/renmaohexie.png");
    QIcon icon(pixmap);
    ui->settings->setIcon(icon);
}

