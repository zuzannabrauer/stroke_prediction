#include "data_row.h"

data_row::data_row(float bmi, bool smoking, bool drinking, char sex, bool stroke) {
    this->bmi = bmi;
    this->smoking = smoking;
    this->drinking = drinking;
    this->sex = sex;
    this->stroke = stroke;
}

bool data_row::matches(float bmi, bool smoking, bool drinking, char sex) {
    return bmi - 1 <= this->bmi and this->bmi <= bmi + 1
        and smoking == this->smoking and drinking == this->drinking
        and tolower(sex) == tolower(this->sex);
}

bool data_row::hasStroke() {
    return stroke;
}
