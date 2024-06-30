#ifndef BUTTONHOVERWATCHER_H
#define BUTTONHOVERWATCHER_H

#include <QObject>
#include<QEvent>
#include<QPushButton>
#include<QString>

class ButtonHoverWatcher : public QObject
{
    Q_OBJECT
public:
    QIcon originalIcon;//存储按钮原始图标

    QString release_inquiry;

    explicit ButtonHoverWatcher(QObject * parent = Q_NULLPTR,QString s="");
    ButtonHoverWatcher();
    virtual bool eventFilter(QObject * watched, QEvent * event) Q_DECL_OVERRIDE;
};




#endif // BUTTONHOVERWATCHER_H
