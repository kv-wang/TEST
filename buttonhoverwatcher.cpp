#include "buttonhoverwatcher.h"
#include<allcats.h>
#include<QString>
#include<QLabel>
#include<QSoundEffect>
ButtonHoverWatcher::ButtonHoverWatcher() {}

ButtonHoverWatcher::ButtonHoverWatcher(QObject * parent,QString s) :
    QObject(parent)
{
    release_inquiry=s;
}

bool ButtonHoverWatcher::eventFilter(QObject * watched, QEvent * event)
{
    QPushButton * button = qobject_cast<QPushButton*>(watched);
    if (!button) {
        return false;
    }

    if (event->type() == QEvent::Enter) {
        // 鼠标进入按钮时，保存当前图标
        //QIcon originalIcon;
        originalIcon = button->icon();
        // The push button is hovered by mouse
        button->setIcon(QIcon(":/5.22/ready.jpg"));
        return true;
    }

    if (event->type() == QEvent::Leave){
        // The push button is not hovered by mouse
        button->setIcon(originalIcon);
        return true;
    }


    //我又在这个类中增加了对按钮按下和完成一次点击的处理，增强程序可扩展性
    if (event->type() == QEvent::MouseButtonPress) {
        // 当按钮被按下时，保存当前图标并设置按下时的图标
        QSoundEffect* s=new QSoundEffect();
        s->setSource(QUrl::fromLocalFile(":/WAVs/WAVs/meow2.wav"));
        s->play();

        button->setIcon(QIcon(":/5.22/others/catbutton_pressed.png")); // 按下时的图标路径
        return true;
    }

    if (event->type() == QEvent::MouseButtonRelease) {
        // 当按钮被释放时，点击完毕，打开新的窗口
        Allcats* x=new Allcats;//打开一个新界面，只显示满足条件的猫猫对应的按钮
        x->str_inquiry=release_inquiry;
        int y=0;
        QString refined_searchtext=release_inquiry;
        for(int i=0;i<19;i++) {
            if(x->Info[i].indexOf(refined_searchtext)==-1)
                x->vbtn[i]->setVisible(false);//如果当前猫的信息中找不到关键词，按钮不可见（也无法点击）
            else{
                x->vbtn[i]->move(0,y*40);
                y++;
            }//移动显示的按钮，实现搜索出来的按钮从上到下紧密排列
        }
        if(y==0){
            QLabel* label=new QLabel("没有找到符合条件的猫猫哦~",x);
            label->move(90,40);
        }
        x->show();

        // 关闭按钮所在的窗口
        QWidget *parentWindow = button->window();
        if (parentWindow) {
            parentWindow->close();
        }

        return true;
    }

    return false;
}
