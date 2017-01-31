//well.cpp - методы класса Well

#include "well.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
const int INDENT = 13;

ostream & operator<<(ostream &os, const Well &w)
{
    os << left;
    os << setw(INDENT) << setfill('.') << "Name:" << w.stname << endl;
    os << setw(INDENT) << setfill('.') << "Time0:" << w.ft0 << endl;
    os << setw(INDENT) << setfill('.') << "TimeSum:" << w.ftimeSum << endl;
    os << setw(INDENT) << setfill('.') << "Volume0:" << w.fQ0 << endl;
    os << setw(INDENT) << setfill('.') << "VolumeSum:" << w.fQSum << endl;
    os << setw(INDENT) << setfill('.') << "Debit0:" << w.fq0 << endl;
    os << setw(INDENT) << setfill('.') << "Debit:" << w.fq << endl;
    os << endl;
    return os;
}



