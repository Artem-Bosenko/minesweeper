#ifndef FIELD
#define FIELD

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

class Field
{
protected:
    int n;
    int bomb;
    int** FieldLogic;
    int** FieldView;
public:
    Field();
    Field(int x);
    void calc_mine();
    ~Field();
};
#endif 