#include "tens.h"
#include "persona.h"
#include <iostream>
using namespace std;

Tens::Tens(){
    this->email=" ";
}

void Tens::setEmail(string _email){
    this->email=_email;
}

string Tens::getEmail(){
    return email;
}

void Tens::mostrarTens(){
    cout<<"Nombre: "<<getNombre()<<getApellidos()<<endl;
    cout<<"Rut: "<<getRun()<<endl;
    cout<<"Email: "<<email<<endl;
}