//well.h - класс well

#ifndef WELL_H
#define WELL_H

#include <string>
#include <iostream>

class Well
{
    private:
        std::string stname;     //название скважины
        float ft0;              //начальное время
        float fQ0;              //объем добычи за t0
        float ftimeSum;         //общее время работы скважины
        float fQSum;            //общий объем добычи скважины
        float fq0;              //начальный дебит скважины
        float fq;               //текущий дебит скважины

    public:
        //конструктор
        Well(const std::string &name, float &t0, float &Q0, float &timeSum, float &QSum)
            :stname(name), ft0(t0), fQ0(Q0), ftimeSum(timeSum), fQSum(QSum), fq0(Q0/t0), fq(QSum/timeSum) {}

        const std::string & Name() {return stname;}                 //возращает название скважины
        const float & t0() {return ft0;}                            //возращает начальное время
        const float & Q0() {return fQ0;}                            //возращает объем добычи за t0
        const float & timeSum() {return ftimeSum;}                  //возращает общее время работы скважины
        const float & QSum() {return fQSum;}                        //возращает общий объем добычи скважины
        const float & q0() {return fq0;}                            //возращает начальный дебит скважины
        const float & q() {return fq;}                              //возращает текущий дебит скважины

        friend std::ostream & operator<<(std::ostream& os, const Well& w);    //перегрузка вывода в поток
};

#endif // WELL_H
