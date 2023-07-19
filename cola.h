#ifndef cola_h
#define cola_h

using namespace std;
#include <queue>

template <class tipo>
class Cola : private std::queue<tipo> {
public:
    tipo extraer() {
        tipo a = queue<tipo>::front();
        queue<tipo>::pop();
        return a;
    }

    void agregar(tipo valor) {
        queue<tipo>::push(valor);
    }

    bool vacio() {
        return queue<tipo>::empty();
    }
};
#endif