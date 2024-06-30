#include "knowledge.h"
#include "ui_knowledge.h"
#include<interact.h>

knowledge::knowledge(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::knowledge)
{
    ui->setupUi(this);

}

knowledge::~knowledge()
{
    delete ui;
}

void knowledge::f(QString s){
    ui->text->setText(s);
    ui->text->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    return;
}

void knowledge::on_back_clicked()
{
    interact *in=new interact;
    in->show();
    this->close();
}


void knowledge::on_back_pressed()
{

    QPixmap pixmap(":/back_press.png");
    QIcon icon(pixmap);
    ui->back->setIconSize(ui->back->size());
    ui->back->setIcon(icon);
}

