#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
    class widget;
}

class widget : public QWidget
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = 0);
    ~widget();
    void setInputMasks();
    int validate(int num,QString mod,int m);

private:
    Ui::widget *ui;

private slots:
    void on_edtNumber_textChanged(QString );
    void on_edtCode_textChanged(QString );
    void on_pushButton_clicked();
};

#endif // WIDGET_H
