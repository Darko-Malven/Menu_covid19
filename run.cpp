#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "run.h"
using namespace std;

Run::Run ()
{
  run = "00000000-0";
}

bool Run::verificar ()
{
  string
    rut1,
    ver1;
  int
    rut,
    ver,
    suma = 0, dig = 2, aux;
  stringstream
  ss (run);
  string
    num;
  vector < string > dato;
  while (getline (ss, num, '-'))
    {
      dato.push_back (num);
      rut1 = dato[0];
      ver1 = dato[1];
    }
  rut = atoi (rut1.c_str ());
  if (ver1 == "K")
    {
      for (int i = 0; i < ver1.length (); i++)
	{
	  char
	    x = ver1.at (i);
	  ver = int (x);
	}
    }
  else
    {
      ver = atoi (ver1.c_str ());
    }
  while (rut != 0)
    {
      suma = suma + ((rut % 10) * dig);
      dig++;
      if (dig == 8)
	{
	  dig = 2;
	}
      rut = rut / 10;
    }
  aux = suma / 11;
  suma = suma - (11 * aux);
  suma = 11 - suma;
  if (suma == 11 && ver == 0)
    {
      return true;
    }

  else if (suma == 10 && ver == 75)
    {
      return true;
    }

  else if (suma == ver)
    {
      return true;
    }
  else
    {
      return false;
    }
}

void
Run::setRun (string _run)
{
  run = _run;
}

string Run::getRun ()
{
  return run;
}