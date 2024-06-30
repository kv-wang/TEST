#ifndef ALLCATS_H
#define ALLCATS_H

#include <QWidget>
#include <QStringList>
#include <vector>
#include <QPushButton>
#include <map>
#include<string>
#include<QString>
using namespace std;
namespace Ui {
class Allcats;
}

class Allcats : public QWidget
{
    Q_OBJECT

public:
    explicit Allcats(QWidget *parent = nullptr);
    ~Allcats();
    QStringList Health;//所有猫的健康状态
    QStringList Gender;//所有猫性别
    QStringList Appearrance;//外貌
    QStringList add_appear;//补充外貌
    //QStringList Color;//毛色
    QStringList names;
    QStringList natures;
    QStringList Info;

    QStringList relations;//记录猫猫关系
    map<int,vector<int>> relate_id;//跟第i个猫有关系的猫的id
    //QStringList friends_name;

    QString str_inquiry;

    vector<QPushButton*> vbtn;//所有猫的按钮

    void set(int i);//设置第i只猫的信息窗口
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_back_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

private:
    Ui::Allcats *ui;
};



#endif // ALLCATS_H
