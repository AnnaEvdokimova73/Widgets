#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radButRead->setText("Почитать");
    ui->radButTask->setText("Сделать домашку");
    ui->radButLearn->setText("Учить испанский");

   if (!ui->radButRead->isChecked())
            ui->radButRead->setChecked(true);

   ui->cbBooks->addItem("Танец с драконами");
   ui->cbBooks->addItem("Зеленая миля");
   ui->cbBooks->addItem("Четвертое крыло");

   ui->butDo->setText("Сделать это");
   ui->butDo->setCheckable(true);

   ui->progressBarData->setMinimum(0);
   ui->progressBarData->setMaximum(10);
   ui->progressBarData->setValue(0);

   connect(ui->butDo, &QPushButton::clicked, this, &MainWindow::increaseValue);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::increaseValue()
{
    if (ui->progressBarData->value() == 10)
    {
        ui->progressBarData->setValue(0);
    }
    else
    {
        int val = ui->progressBarData->value() + 1;
        ui->progressBarData->setValue(val);
    }
}

