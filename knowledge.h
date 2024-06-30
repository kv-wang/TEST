#ifndef KNOWLEDGE_H
#define KNOWLEDGE_H

#include <QWidget>
#include<QString>

namespace Ui {
class knowledge;
}

class knowledge : public QWidget
{
    Q_OBJECT

public:
    explicit knowledge(QWidget *parent = nullptr);
    ~knowledge();
    Ui::knowledge *ui;
    void f(QString s);

private slots:
    void on_back_clicked();

    void on_back_pressed();

private:
    //Ui::knowledge *ui;
};

#endif // KNOWLEDGE_H
