#ifndef INTERACT_H
#define INTERACT_H

#include <QWidget>

namespace Ui {
class interact;
}

class interact : public QWidget
{
    Q_OBJECT

public:
    explicit interact(QWidget *parent = nullptr);
    ~interact();
    int flag=0;

private slots:
    void on_input_returnPressed();

    void on_link_clicked();

    void on_back_clicked();

    void on_back_pressed();

private:
    Ui::interact *ui;
};

#endif // INTERACT_H
