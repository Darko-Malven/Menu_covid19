#ifndef FECHA_H
#define FECHA_H
using namespace std;

class Fecha{
    
    public:
    Fecha();
    void setFechad(int _dia,int _mes,int _anho);
    bool verificar(string fecha);
    int Imes(string _mes);
    int getDia();
    int getMes();
    int getAnho();
    void ver();
    
    private:
    int dia,anho,mes;
};
#endif