#ifndef ATAQUES_H_INCLUDED
#define ATAQUES_H_INCLUDED

#endif // ATAQUES_H_INCLUDED

using namespace std;

class Ataques{
private:
    string nombre;
    int usos;
    int dano;

public:
    Ataques(string, int, int);

    string getNombre();
};

Ataques::Ataques(string _nombre, int _usos, int _dano){
    nombre = _nombre;
    usos = _usos;
    dano = _dano;
}

string Ataques::getNombre(){
    return nombre;
}
