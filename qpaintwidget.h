#ifndef QPAINTWIDGET_H
#define QPAINTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <vector>
#include <cmath>

namespace Ui {
class QPaintWidget;
}

class QPaintWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QPaintWidget(QWidget *parent = nullptr);
    ~QPaintWidget();

private:
    void paintEvent(QPaintEvent *event);
};

using namespace std;

const long double PI = 3.14159265358;
const long double CONST_TIME = 10;

struct Point{
    long double x, y;

    Point operator+(Point b){
        return {this->x + b.x, this->y + b.y};
    }
};

struct Vector{
    long double x, y, length, speed, angle, start_angle;
    void init(long double input_speed, long double input_length, long double input_angle){
        this -> speed = input_speed;
        this -> length = input_length;
        this -> angle = input_angle / 180 * PI;
        this -> start_angle = input_angle / 180 * PI;
        this -> x = this -> length * cos(this -> angle);
        this -> y = this -> length * sin(this -> angle);
    }
    void update_pos(long double time){
        this -> angle = (this -> speed * PI / CONST_TIME * time + this -> start_angle);
        if (this -> angle > PI * 2) angle -= PI * 2;
        this -> x = this -> length * cos(this -> angle);
        this -> y = this -> length * sin(this -> angle);
    }
};

struct Construction{
    int n;
    vector<Vector> v;
    vector<Point> p;
    void init(int input_n, vector<Vector> input_v){
        this -> n = input_n;
        this -> v = input_v;
        p.resize(n + 1);
    }
    void update_vectors(long double time){
        Point tmp = {0, 0};
        for (int i = 0; i < n; ++i)
        {
            this->p[i] = tmp;
            this->v[i].update_pos(time);
            tmp = tmp + (Point){this->v[i].x, this->v[i].y};
        }
        this->p[n] = tmp;
    }
    void insert(Vector input_vector)
    {
        v.push_back(input_vector);
        p.resize(n + 1);
        ++n;
    }
    void erase(int idx)
    {
        v.erase(v.begin() + idx - 1);
        p.pop_back();
        --n;
    }
};

#endif // QPAINTWIDGET_H
