#ifndef STORIES_H
#define STORIES_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class storiesData;

class stories:public QWidget
{
    Q_OBJECT
    QML_ELEMENT
public:
    stories();
    stories(const stories &);
    stories &operator=(const stories &);
    ~stories();

private:
    QSharedDataPointer<storiesData> data;
};

#endif // STORIES_H
