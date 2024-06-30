#ifndef NOTICE_H
#define NOTICE_H

#include <QWidget>
#include <QStringList>

namespace Ui {
class Notice;
}

class Notice : public QWidget
{
    Q_OBJECT

public:
    explicit Notice(QWidget *parent = nullptr);
    ~Notice();
    QStringList xuzhi;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_pressed();

    void on_back_clicked();

    void on_back_pressed();

private:
    Ui::Notice *ui;
};

#endif // NOTICE_H
