#include "story.h"
#include "ui_setting.h"
story::story(QWidget *parent)
    : QWidget(parent), ui(new Ui::setting)
{
    ui->setupUi(this);
}
