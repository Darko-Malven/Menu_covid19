#ifndef TENS_H
#define TENS_H
#include "persona.h"
#include <iostream>
using namespace std;
class Tens: public Persona{
    private:
    string email;
    public:
    Tens();
    void setEmail(string);
    void mostrarTens();
    string getEmail();
    
};
#endif