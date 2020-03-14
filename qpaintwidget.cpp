#include "qpaintwidget.h"
#include "ui_qpaintwidget.h"
#include "construction.h"
#include <vector>
#include <iostream>
#include <QThread>
#include <QTimer>

using namespace std;

QPaintWidget::QPaintWidget(QWidget *parent) :
    QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&QPaintWidget::update));
    timer->start(1);
}

QPaintWidget::~QPaintWidget()
{
}

void QPaintWidget::paintEvent(QPaintEvent */*event*/){
    vector<vector<int>> colors = {{255, 30, 0, 255}, {255, 150, 50, 255}, {255, 255, 0, 255}, {0, 255, 0, 255}, {0, 250, 250, 255}, {0, 0, 250, 255}, {255, 0, 255, 255}, {250, 250, 250, 255}};
    QPainter paint(this);
    paint.setBrush(QColor(0, 0, 0));
    paint.drawRect(0, 0, 10000, 10000);
    paint.setPen(QColor(colors[7][0], colors[7][1], colors[7][2], colors[7][3]));
    for (long double i = 1; i < tm; ++i)
    {
        construct.update_vectors(i / 1000);
        paint.drawPoint((int)construct.p[construct.n].x + 400, (int)construct.p[construct.n].y + 400);
    }
    std::cout << tm << std::endl;
    for (auto i : construct.v){
        cout << i.length << " " << i.speed << endl;
    }
    construct.update_vectors(tm / 1000);
    for (int i = 1; i <= construct.n; ++i)
    {
        paint.setPen(QColor(colors[i - 1][0], colors[i - 1][1], colors[i - 1][2], colors[i - 1][3]));
        paint.drawPoint((int)construct.p[i].x + 400, (int)construct.p[i].y + 400);
        paint.drawLine((int)construct.p[i - 1].x + 400, (int)construct.p[i - 1].y + 400, (int)construct.p[i].x + 400, (int)construct.p[i].y + 400);
    }
    ++tm;
    std::cout << tm << std::endl;
}
