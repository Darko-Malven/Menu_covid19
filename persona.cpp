#include "persona.h"
#include <iostream>
#include <string>
using namespace std;

Persona::Persona(){
    nombre=" ";
    apellidos=" ";
    run=" ";
}
void Persona::setNombreApellidos(string _nombre,string _apellidos){
    this->nombre=_nombre;
    this->apellidos=_apellidos;
}
void Persona::setRun(string _run){
    rut.setRun(_run);
    run=rut.getRun();
}
string Persona::getNombre(){
    return this->nombre;
}
string Persona::getApellidos(){
    return this->apellidos;
}
string Persona::getRun(){
    return this->run;
}