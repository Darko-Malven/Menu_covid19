#include <iostream>
#include <vector>
#include <sstream>
#include "fecha.h"
#include "persona.h"
#include "paciente.h"
using namespace std;

Paciente::Paciente (){
    edad=0;
    dia=0;
    mes=0;
    anho=0;
}
void Paciente::setFechaN(Fecha Nfecha){
    dia=Nfecha.getDia();
    mes=Nfecha.getMes();
    anho=Nfecha.getAnho();
}
int Paciente::calcularEdad(Fecha Nfecha){
    int _dia,_mes,_anho;
    int cont = 0;
   _dia = Nfecha.getDia();
   _mes = Nfecha.getMes();
   _anho =Nfecha.getAnho();

  cont = _anho-anho ;
  if (mes >= _mes)
    {
      if (dia >= _dia )
	{
	  cont++;
	}
    }
  return cont;
}
void Paciente::setEdad(Fecha hoy){
    int _edad;
    _edad=calcularEdad(hoy);
    edad=_edad;
}

int Paciente::getFechaN(){
    int fecha=dia*1000000+mes*10000+anho;
    return fecha;
}
int Paciente::getEdad(){
    return edad;
}

void Paciente::mostrar(){
    cout<<"Nombre: "<<getNombre()<<" "<<getApellidos()<<endl;
    cout<<"Rut: "<<getRun()<<endl;
    cout<<"edad: "<<edad<<endl;
}

