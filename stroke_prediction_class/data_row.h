#ifndef DATAROW_H
#define DATAROW_H
#include <string>

using namespace std;

class data_row {
private:
    float bmi;
    bool smoking;
    bool drinking;
    char sex; /// F or f or M or m
    bool stroke;

public:
    data_row(float bmi, bool smoking, bool drinking, char sex, bool stroke);
    bool matches(float bmi, bool smoking, bool drinking, char sex);
    bool hasStroke();
};

#endif /// DATAROW_H
