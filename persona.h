#ifndef PERSONA_H
#define PERSONA_H
#include "run.h"
#include <iostream>
using namespace std;
class Persona{
    
    protected:
    
    string nombre,apellidos,run;
    
    Run rut;
    
    public:
    
    Persona();
    void setRun(string);
    void setNombreApellidos(string,string);
    string getApellidos();
    string getNombre();
    string getRun();
    
    
};
#endif