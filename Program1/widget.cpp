#include "widget.h"
#include "ui_widget.h"

#include <QRegExp>
#include <QRegExpValidator>
#include <QtCore/QCoreApplication>
#include <stdio.h>
#include <iostream>
#include <QMessageBox>

using namespace std;

widget::widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
    ui->edtNumber->setFocus();
    setInputMasks();
}

widget::~widget()
{
    delete ui;
}


void widget::on_pushButton_clicked()
{
    int studentNumber = ui->edtNumber->text().toInt();
    QString moduleCode = ui->edtCode->text();
    int mark = ui->spnNumbe->value();

    // all_right=0 num_wrong=1 code_wrong=2 mark_wrong=3
    int result = validate(studentNumber,moduleCode,mark);

    QMessageBox msgBox;


    if(result==0)
    {
        QString stringNumber = QString::number(studentNumber);
        QString stringMark = QString::number(mark);
        cout << QString("%1,%2,%3").arg(stringNumber).arg(moduleCode).arg(stringMark).toStdString() << endl;
        msgBox.setText("Correct Information Submitted");
        msgBox.exec();

    }
   else if(result == 1)
    {
       msgBox.setText("Student number is not correct, please revise");
       msgBox.exec();
    }
    else if(result == 2)
    {
        msgBox.setText("Module code is not correct, please revise");
        msgBox.exec();
    }
    else if(result == 3)
    {
        msgBox.setText("Mark is not correct, please revise");
        msgBox.exec();
    }
}

void widget::setInputMasks()
{
    ui->edtCode->setInputMask("AAA9999");
    ui->edtNumber->setInputMask("9999");
    ui->spnNumbe->setMaximum(100);
    ui->spnNumbe->setMinimum(0);
   // ui->edtCode->setText("");
}

int widget::validate(int num, QString mod, int m)
{
    int pos = 0;
    QString numS = "" + QString::number(num) + "";
    QString modS = "" + mod + "";
    QString mS = "" + QString::number(m) + "";


    //validate Student Number
    QRegExp studentNumber("\\d{4}");
    QRegExpValidator v1(studentNumber,0);

    //validate module code
    QRegExp modeCode("[A-Z]{3}[1-3][1-9]{2}(\\d|.)");
    QRegExpValidator v2(modeCode,0);

    //validate mark
    QRegExp mark("^[0-9][0-9]?$|^100$");
    QRegExpValidator v3(mark,0);


    // all_right=0 num_wrong=1 code_wrong=2 mark_wrong=3
    if((v1.validate(numS,pos) == QValidator::Acceptable) && (v2.validate(modS,pos) == QValidator::Acceptable)  && (v3.validate(mS,pos) == QValidator::Acceptable))
            return 0;
    else if(v1.validate(numS,pos) == QValidator::Intermediate)
            return 1;
        else if(v2.validate(modS,pos) == QValidator::Intermediate | v2.validate(modS,pos) == QValidator::Invalid )
            return 2;
        else if(v3.validate(mS,pos) == QValidator::Intermediate)
            return 3;

        return -1;

}



void widget::on_edtCode_textChanged(QString )
{
    if(ui->edtCode->text().length() == 7)
    {
       ui->spnNumbe->setFocus();
    }
}

void widget::on_edtNumber_textChanged(QString )
{
    if(ui->edtNumber->text().length() == 4)
    {
       ui->edtCode->setFocus();
       ui->edtCode->clear();
    }
}
