// main.cpp  - поиск коэффициента D функции f(x)=exp(-Dt) и постраение графика этой функции

#include <QApplication>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "well.h"
#include "getvectorwell.h"
#include "qcustomplot.h"

//функция принимает имя файла
//и возращает контейнер vector объектов Well
std::vector<Well> getVectorWell(const char* NameFile);

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //строка, хранящая путь к файлу
    std::string fileName("/home/alexey/qtProject/practic/data.txt");

    //создаем вектор объектов well
    std::vector<Well> wells(getVectorWell(fileName.c_str()));

    //поиск коэффициента D
    double D;
    for(auto well: wells)
        D =+ log(well.q()/well.q0())/well.timeSum();

    // создаем виджет QCustomPlot
    QCustomPlot cPlot;

    // генерируем данные
    QVector<double> x(101), y(101);
    for (int i=0; i<101; ++i)
    {
        x[i] = i/50.0 - 1; // x изменяется от -1 до 1
        y[i] = exp(-D*x[i]);
    }
    // создаем график и добавляем данные:
    cPlot.addGraph();
    cPlot.graph(0)->setData(x, y);

    // задаем обозначения осей координат:
    cPlot.xAxis->setLabel("x");
    cPlot.yAxis->setLabel("y");

    // устанавливаем диапазоны отображения данных:
    cPlot.xAxis->setRange(-1, 1);
    cPlot.yAxis->setRange(0, 1.8);

    // рисуем график
    cPlot.replot();

    //название графика
    std::string label("f(x)=exp(-Dx), D=");
    std::string fStr = std::to_string(D);
    label += fStr;
    cPlot.setWindowTitle(label.c_str());

    cPlot.resize(548, 420);
    cPlot.show();

    return app.exec();
}
