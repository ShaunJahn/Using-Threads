#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QObject>
#include <QProcess>
#include <QString>

#include "studentlist.h"
#include "student.h"

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QProcess *studentProcess;

private slots:
    void on_btnAvg_clicked();
    void on_btnDisplay_clicked();
    void on_btnGraduate_clicked();
    void on_pushButton_clicked();
    void addModule();
};

#endif // WIDGET_H
