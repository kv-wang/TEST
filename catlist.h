#ifndef CATLIST_H
#define CATLIST_H

#include <QWidget>
#include<QSoundEffect>
namespace Ui {
class Catlist;
}

class Catlist : public QWidget
{
    Q_OBJECT

public:
    explicit Catlist(QWidget *parent = nullptr);
    ~Catlist();
    //QSoundEffect* m[6];


private slots:
    void on_pushButton_clicked();

    void on_searchbtn_clicked();

    void on_lineEdit_returnPressed();

    void on_bai_clicked();

    void on_hei_clicked();

    void on_daimao_clicked();

    void on_ju_clicked();

    void on_lihua_clicked();

    void on_sanhua_clicked();

    void on_nainiu_clicked();

    void on_back2main_clicked();

    void on_back2main_pressed();

    void on_back_clicked(bool checked);

    void on_back_clicked();

    void on_back_pressed();

private:
    Ui::Catlist *ui;
};

#endif // CATLIST_H
