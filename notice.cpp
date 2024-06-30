#include "notice.h"
#include "ui_notice.h"
#include <QFile>
#include<mainwindow.h>

Notice::Notice(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Notice)
{
    ui->setupUi(this);
    // 读取的文件路径
    QString filePath = ":/about maoxie.txt";

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
        xuzhi.append(line);
    }

    // 关闭文件
    file.close();

    //把QLabel的文字设置成读取的信息
    //QString text = xuzhi.join("\n");
    //ui->words->setText(text);
}

Notice::~Notice()
{
    delete ui;
}

void Notice::on_pushButton_clicked()
{
    MainWindow *mw=new MainWindow;
    mw->show();
    this->close();
}


void Notice::on_pushButton_pressed()
{
    QPixmap pixmap(":/back_press.png");
    QIcon icon(pixmap);
    ui->back->setIconSize(ui->back->size());
    ui->back->setIcon(icon);
}


void Notice::on_back_clicked()
{
    MainWindow *mw=new MainWindow;
    mw->show();
    this->close();
}


void Notice::on_back_pressed()
{
    QPixmap pixmap(":/back_press.png");
    QIcon icon(pixmap);
    ui->back->setIconSize(ui->back->size());
    ui->back->setIcon(icon);
}

