//getdata.h - описание функции, которая принимает имя файла
//            и возращает двумерный массив данных в виде vector<vector<string> >

#ifndef GETDATA
#define GETDATA

#include <fstream>
#include <string>
#include <vector>


std::vector<std::vector<std::string> > getData(const char* NameFile)
{
    //открываем файл
    std::ifstream fin(NameFile);

    //вектор для данных всей таблицы
    std::vector<std::vector<std::string> > data;

    //вектор для каждой строки таблицы
    std::vector<std::string> dataStr;

    //считываем данные таблицы из data.txt в data
    std::string str;
    fin >> str;
    int i=0;

    while(!fin.eof()){
        //строкой str формируем данные строки таблицы
        dataStr.push_back(str);
        //после заполнения контейнера 5-ю элементами, заполняем им контейнер data
        if ((i+1 )% 5 == 0){
            data.push_back(dataStr);
            //очищаем буферный контейр, предназначенный для формирования строк data
            dataStr.clear();
        }
        i++;
        fin >> str;
    }

    //закрываем файл
    fin.close();

    //считали таблицу в вектор data, где:
    //data[0][0] - Date
    //data[0][1] - Name
    //data[0][2] - Time
    //data[0][3] - Oil
    //data[0][4] - Aqua

    return data;
}

#endif // GETDATA

