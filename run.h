#ifndef RUN_H
#define RUN_H
#include <string>
using namespace std;
class Run{
    
    public:
    Run();
    bool verificar();
    void setRun(string _run);
    string getRun();
    
    private:
    string run; //sin puntos, con guión y digito verificador en mayusculas. 
};
#endif