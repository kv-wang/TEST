#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_chazhao_clicked();

    void on_chazhao_pressed();

    void on_notice_clicked();

    void on_notice_pressed();

    void on_settings_clicked();

    void on_settings_pressed();

private:
    Ui::MainWindow *ui;
};

/*
class Allcats:public QMainWindow{
    Q_OBJECT

public:
    Allcats(QWidget *parent = nullptr);
    ~Allcats();
};
*/
#endif // MAINWINDOW_H
