#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int i = ui->lineEditi->text().toInt();
    double x = ui->lineEditx->text().toInt();


    if (ui->radioButton->isChecked())
    {
        x = sinh(x);
    }
    else if (ui->radioButton_2->isChecked())
    {
        x = pow(2, x);
    }
    else if (ui->radioButton_3->isChecked())
    {
        x = pow(2.718, x);
    }
    else
    {
        QMessageBox *MB = new QMessageBox(this);
        MB->setText("RADIO BUTTON DIDN\'T CLIKED");
        MB->show();
    }

    double answer{0};
    if (i % 2 != 0 && x > 0)
        answer = i * sqrt(x);
    else if (i % 2 == 0 && x < 0)
        answer = i / 2 * sqrt(fabs(x));
    else
        answer = sqrt(fabs(i * x));

    ui->label_3->setText(QString::number(answer));
}
