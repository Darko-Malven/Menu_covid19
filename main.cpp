#include <iostream>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <fstream>
#include "persona.h"
#include "tens.h"
#include "paciente.h"
#include "run.h"
#include "fecha.h"
#include "cola.h"
#include "stack.h"
#include "heap.h"
using namespace std;

void leerArchivo (Cola <Paciente> & lcola,Fecha hoy);
void ingresarTens(Stack <Tens> &pila);
void mostrarTens(Stack <Tens>  pila);
int contar(Cola <Paciente>lcola);
int contar(Stack <Tens>pila);
void citacionesPaciente(Heap<Paciente> &heap,Cola<Paciente> lcola,Stack <Paciente>&pila2);

int main()
{
  int dia, mes, anho; 
  int opc,en; 
  Fecha hoy;
  Cola <Paciente>lcola;
  Stack <Tens> pila;
  Stack <Paciente>pila2;
  Heap <Paciente> heap;
  
    time_t now;
	    struct tm *now_tm;
	    now = time (NULL);
	    now_tm = localtime (&now);
	    dia = now_tm->tm_mday;
	    mes = now_tm->tm_mon + 1;
	    anho = (now_tm->tm_year) + 1900;
	    hoy.setFechad (dia, mes, anho);
    
    do
    {
      cout <<"*********MENU VACUNACION CONTRA COVID-19*********" <<
      endl<<
	"\n1.-Ingresar Tens\n2.-Mostrar Tens\n3.-Cargar datos de pacientes\n4.-Citaciones de Pacientes\n5.-Salir"
	<< endl;
      cout << "Ingrese opcion: ";
      cin >> opc;
      switch (opc)
	{
	case 1:	
	  {
	      ingresarTens(pila);
	      cout<<"SE HAN CARGADO ["<<contar(pila)<<"] TECNICOS"<<endl;
	    break;
	  }
	case 2:
	  {
	      mostrarTens(pila);
	      
	    break;
	    }
	case 3:
	  {
	     leerArchivo (lcola,hoy);
	     cout<<"SE HAN CARGADO ["<<contar(lcola)<<"] PACIENTES"<<endl;
	     break;
	  } 
	case 4: 
	  {
	    citacionesPaciente(heap,lcola,pila2);
	    break;
	  }
	  case 5: {
	    cout<<"Ha salido con exito!"<<endl;
	    exit;
	    break;
	  }
	}
    }
  while (opc != 5 && opc<=5);
    return 0;
}

void
leerArchivo (Cola <Paciente>&lcola, Fecha hoy)
{
  string nom, pa, ma;
  int edad;
  
  ifstream Archivo;
  Archivo.open ("Pacientes.txt", ios::in);

  if (Archivo.is_open ())
    {
        
      string linea;
      while (getline (Archivo, linea, '\n'))
	{
	  
	  stringstream ss (linea);
	  string a;
	  vector < string > dato;
	  while (getline (ss, a, ';'))
	    {
	      dato.push_back (a);
	    }
	  dato[1] += " "+dato[2];
	  Run rut;
	  rut.setRun(dato[0]);
	  Fecha Nfecha;
	  if (rut.verificar () == true)
	    {
	      if (Nfecha.verificar (dato[5]) == true)
		{
		  Paciente b;
		  b.setRun(dato[0]);
          b.setNombreApellidos(dato[3],dato[1]);
		  b.setFechaN(Nfecha);
          b.setEdad(hoy);
          lcola.agregar(b);
		}
	    }
	}
      cout << "se abrio el archivo\n";
    }
  else
    {
      cout << "no se ha podido ingresar al archivo\n" << endl;
    }
}

void ingresarTens(Stack <Tens> &pila){
    Tens tecnico;
    string nombre,apellidos,email,run;
    char opc;
    cout<<"_____Datos personales de Tecnicos_____";
     
    do{
    cin.ignore();   
    cout<<"\nIngrese nombre de Tecnico : ";
    getline(cin,nombre);
    cout<<"\nIngrese apellidos del Tecnico : ";
    getline(cin,apellidos);
    tecnico.setNombreApellidos(nombre,apellidos);
    cout<<"\nIngrese rut del Tecnico : ";
    getline(cin,run);
    tecnico.setRun(run);
    cout<<"\nIngrese email del Tecnico : ";
    getline(cin,email);
    tecnico.setEmail(email);
    pila.push(tecnico);
    cout<<"\n\nDesea agregar otro Tecnico Si[s] o No[n]";
    cin>>opc;
    
    }while((opc=='s')|| (opc=='S'));
}

void mostrarTens(Stack <Tens> pila){
    
    cout<<"******Datos personales de Tecnicos******"<<endl;
    
    while(!pila.empty()){
      Tens tecnico=pila.pop();  
      tecnico.mostrarTens();    
     cout<<"***************"<<endl;
    }
    cout<<endl;
}
int contar(Stack <Tens>pila){
    int cont=0;
    while(!pila.empty()){

        pila.pop();
        cont++;
    }
    return cont;
}
int contar(Cola <Paciente>lcola){
    int cont=0;
    while(!lcola.vacio()){

        lcola.extraer();
        cont++;
    }
    return cont;
}
void citacionesPaciente(Heap <Paciente> &heap,Cola <Paciente> lcola,Stack <Paciente> &pila2){
    int dia=1, cantidad,cont=0;
    if(!lcola.vacio()){
        
    cout<<"\nIngrese cantidad de personas a vacunar por dia: ";
    cin>>cantidad;
    
    while(!lcola.vacio()){
        Paciente persona=lcola.extraer();
        heap.agregar(persona,persona.getEdad());
    }
    while(!heap.vacio()){
            pila2.push(heap.extraer());
        }
        cout<<"\n_____________Dia ["<<"1"<<"]_____________"<<endl;
    while(!pila2.empty()){
        if(cont==cantidad){
            cont=0;
            dia++;
            cout<<"\n_____________Dia ["<<dia<<"]_____________"<<endl;
        }
        Paciente pac=pila2.pop();
        pac.mostrar();
        
        cont++;
        cout<<"***************"<<endl;
    }
}
    else{
    cout<<"\n******NO HAY REGISTROS GUARDADOS******\n"<<endl;
}
}
