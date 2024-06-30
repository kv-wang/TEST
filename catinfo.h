#ifndef CATINFO_H
#define CATINFO_H

#include <QWidget>
#include<string>
#include<QString>
#include<QPushButton>
#include<QLabel>
#include<vector>
using namespace std;
namespace Ui {
class Catinfo;
}

class Catinfo : public QWidget
{
    Q_OBJECT

public:
    explicit Catinfo(QWidget *parent = nullptr);
    ~Catinfo();
    QString health;
    QLabel *btn=new QLabel(this);
    QLabel *cat_pic=new QLabel(this);
    QLabel *info=new QLabel(this);
    Ui::Catinfo *ui;
    vector<QPushButton*> friends;
    vector<int> friends_id;
    void init_friends(int x);
    QString request;

private slots:
    void on_pushButton_clicked();

    void on_add_clicked();

    void on_appearance_clicked();

    void on_gender_clicked();

    void on_nature_clicked();

    //void on_nature_pic_clicked();

    void on_friend1_clicked();

    void on_friend2_clicked();

    void on_friend3_clicked();

    void on_friend4_clicked();

    void on_friend5_clicked();

private:
    //Ui::Catinfo *ui;
};

#endif // CATINFO_H
