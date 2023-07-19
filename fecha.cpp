#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
#include "fecha.h"
using namespace std;

Fecha::Fecha ()
{
  dia = 1;
  anho = 1900;
  mes = 1;
}

void
Fecha::setFechad (int _dia, int _mes, int _anho)
{
  dia = _dia;
  mes = _mes;
  anho = _anho;
}

bool
Fecha::verificar (string fecha)
{
  int d, a, bi = 0;
  string m;
  vector < string > dato;
  stringstream lin (fecha);
  string solo;
  while (getline (lin, solo, '-'))
    {
      dato.push_back (solo);
    }
  d = atoi (dato[0].c_str ());
  m = dato[1];
  a = atoi (dato[2].c_str ());
  setFechad (d, Imes (m), a);

  if ((a % 4) == 0)
    {
      if ((a % 100) == 0)
	{
	  if ((a % 400) == 0)
	    {
	      bi = 1;
	    }
	}
    }
  if (m == "enero" || m == "marzo" || m == "mayo" || m == "julio"
      || m == "agosto" || m == "octubre" || m == "diciembre")
    {
      if (d <= 31)
	{
	  return true;
	}
      else
	{
	  return false;
	}
    }
  else if (m == "abril" || m == "junio" || m == "septiembre"
	   || m == "noviembre")
    {
      if (d <= 30)
	{
	  return true;
	}
      else
	{
	  return false;
	}
    }
  else if (m == "febrero" && bi == 1)
    {
      if (d <= 29)
	{
	  return true;
	}
      else
	{
	  return false;
	}
    }
  else if (m == "febrero" && bi == 0)
    {
      if (d <= 28)
	{
	  return true;
	}
      else
	{
	  return false;
	}
    }
}

int
Fecha::Imes (string _mes)
{
  int m;
  if (_mes == "enero")
    {
      m = 1;
    }
  else if (_mes == "febrero")
    {
      m = 2;
    }
  else if (_mes == "marzo")
    {
      m = 3;
    }
  else if (_mes == "abril")
    {
      m = 4;
    }
  else if (_mes == "mayo")
    {
      m = 5;
    }
  else if (_mes == "junio")
    {
      m = 6;
    }
  else if (_mes == "julio")
    {
      m = 7;
    }
  else if (_mes == "agosto")
    {
      m = 8;
    }
  else if (_mes == "septiembre")
    {
      m = 9;
    }
  else if (_mes == "octubre")
    {
      m = 10;
    }
  else if (_mes == "noviembre")
    {
      m = 11;
    }
  else if (_mes == "diciembre")
    {
      m = 12;
    }
  return m;
}

int
Fecha::getDia ()
{
  return dia;
}

int
Fecha::getMes ()
{
  return mes;
}

int
Fecha::getAnho ()
{
  return anho;
}

void
Fecha::ver ()
{
  cout << dia << "-" << mes << "-" << anho << endl;
}
