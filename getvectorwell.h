//getvectorwell.h - функция, котора принимает имя файла
//                  и возращает контейнер vector объектов Well

#ifndef GETVECTORWELL
#define GETVECTORWELL

#include "getdata.h"
#include "well.h"
#include <string>
#include <vector>
#include <set>
#include <numeric>

//функция принимает имя файла и возращает двумерный
//контейнер данных в виде vector<vector<string> >
std::vector<std::vector<std::string> > getData(const char* NameFile);

std::vector<Well> getVectorWell(const char* NameFile)
{
    std::vector<std::vector <std::string> > data;
    data = getData(NameFile);

    //создаем вектор с названиями скважин
    std::vector<std::string> dataName;
    for (unsigned int i=1; i<data.size(); i++)
        dataName.push_back(data[i][1]);

    //с помощью ассоциативного контейнера формируем отсортированный
    //список с названиями
    std::set<std::string> setName(dataName.begin(), dataName.end());

    //перезаписываем вектор с названиями
    dataName.assign(setName.begin(), setName.end());

    std::vector<int> index;          //вектор индексов
    std::vector<float> timeWork;     //время работы сквжины
    std::vector<float> volumeOil;    //объемы добычи нефти
    std::vector<Well> wells;         //вектор объектов класса Well

    //подготавка необходимых данных для конструктора well
    float t0;
    float timeSum ;
    float Q0;
    float QSum;

    //буферная строка
    std::string str;

    //перебор всех имен скважин
    for (auto well: dataName){

        //сохраняем номера строк таблицы, относящиеся к данной скважине
        for (unsigned int i=1; i<data.size();i++)
            if (well == data[i][1])
                index.push_back(i);

        //собираем нароботку по времени и объему добычи нефти для данной скважины
        for (int i: index){
            str = data[i][2];
            timeWork.push_back(atof(str.c_str()));
            str = data[i][3];
            volumeOil.push_back(atof(str.c_str()));
        }

        //подготавка необходимых данных для конструктора well
        t0 = timeWork[0];
        timeSum = accumulate(timeWork.begin(), timeWork.end(), 0.0);
        Q0 = volumeOil[0];
        QSum = accumulate(volumeOil.begin(), volumeOil.end(), 0.0);

        //наполняем вектор объектами well
        wells.push_back(Well(well, t0, Q0, timeSum, QSum));

        //очистка векторов для следующей скважины
        index.clear();
        timeWork.clear();
        volumeOil.clear();
    }

    return wells;
}

#endif // GETVECTORWELL

