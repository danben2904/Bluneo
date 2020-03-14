#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpaintwidget.h"
#include "Construction.h"
#include <QMessageBox>
#include <QString>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int num = 1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    d = new QPaintWidget;
    ui->length_3->hide();
    ui->length_4->hide();
    ui->length_5->hide();
    ui->length_6->hide();
    ui->length_7->hide();
    ui->length_8->hide();
    ui->length_9->hide();
    ui->speed_3->hide();
    ui->speed_4->hide();
    ui->speed_5->hide();
    ui->speed_6->hide();
    ui->speed_7->hide();
    ui->speed_8->hide();
    ui->speed_9->hide();
    ui->color_3->hide();
    ui->color_4->hide();
    ui->color_5->hide();
    ui->color_6->hide();
    ui->color_7->hide();
    ui->color_8->hide();
    ui->color_9->hide();
    ui->angle_3->hide();
    ui->angle_4->hide();
    ui->angle_5->hide();
    ui->angle_6->hide();
    ui->angle_7->hide();
    ui->angle_8->hide();
    ui->angle_9->hide();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_new_2_clicked()
{
    if (num == 8){
        QMessageBox::warning(this, "Too many vectors", "Please stop adding vectors");
        return;
    }
    ++num;
    if (num == 2){
        ui->length_3->show();
        ui->speed_3->show();
        ui->color_3->show();
        ui->angle_3->show();
    }
    if (num == 3){
        ui->length_4->show();
        ui->speed_4->show();
        ui->color_4->show();
        ui->angle_4->show();
    }
    if (num == 4){
        ui->length_5->show();
        ui->speed_5->show();
        ui->color_5->show();
        ui->angle_5->show();
    }
    if (num == 5){
        ui->length_6->show();
        ui->speed_6->show();
        ui->color_6->show();
        ui->angle_6->show();
    }
    if (num == 6){
        ui->length_7->show();
        ui->speed_7->show();
        ui->color_7->show();
        ui->angle_7->show();
    }
    if (num == 7){
        ui->length_8->show();
        ui->speed_8->show();
        ui->color_8->show();
        ui->angle_8->show();
    }
    if (num == 8){
        ui->length_9->show();
        ui->speed_9->show();
        ui->color_9->show();
        ui->angle_9->show();
    }
}


void MainWindow::on_start_clicked()
{
    vector<Vector> all_vec;
    Vector to_add;
    to_add.init(ui->speed->text().toDouble(), ui->length->text().toDouble(), ui->angle->text().toDouble());
    all_vec.push_back(to_add);
    to_add.init(ui->speed_3->text().toDouble(), ui->length_3->text().toDouble(), ui->angle_3->text().toDouble());
    all_vec.push_back(to_add);
    to_add.init(ui->speed_4->text().toDouble(), ui->length_4->text().toDouble(), ui->angle_4->text().toDouble());
    all_vec.push_back(to_add);
    to_add.init(ui->speed_5->text().toDouble(), ui->length_5->text().toDouble(), ui->angle_5->text().toDouble());
    all_vec.push_back(to_add);
    to_add.init(ui->speed_6->text().toDouble(), ui->length_6->text().toDouble(), ui->angle_6->text().toDouble());
    all_vec.push_back(to_add);
    to_add.init(ui->speed_7->text().toDouble(), ui->length_7->text().toDouble(), ui->angle_7->text().toDouble());
    all_vec.push_back(to_add);
    to_add.init(ui->speed_8->text().toDouble(), ui->length_8->text().toDouble(), ui->angle_8->text().toDouble());
    all_vec.push_back(to_add);
    to_add.init(ui->speed_9->text().toDouble(), ui->length_9->text().toDouble(), ui->angle_9->text().toDouble());
    all_vec.push_back(to_add);
    tm = 0;
    construct.init(8, all_vec);
    std::cout << tm << std::endl;
    d->show();
}
