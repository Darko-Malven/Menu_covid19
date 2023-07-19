#ifndef PACIENTE_H
#define PACIENTE_H
#include "persona.h"
#include "fecha.h"
using namespace std;

class Paciente : public Persona{

public:

  Paciente ();
  void setFechaN(Fecha Nfecha);
  int calcularEdad(Fecha Nfecha);
  void setEdad(Fecha Nfecha);
  void mostrar();
  int getFechaN();
  int getEdad();

private:
  int dia,mes,anho,edad;
  Fecha Nfecha;
};
#endif