#ifndef ATAQUE_H_INCLUDED
#define ATAQUE_H_INCLUDED

using namespace std;

class Ataque{
private:
    string nombre_ataque;
    int usos;
    int usos_totales;
    int dano;

public:
    Ataque(string, int, int);
    Ataque(string, int);
    Ataque();

    void setUsos(int);

    string getNombreAtaque();
    int getUsos();
    int getUsosTotales();
    int getDano();

    void quitarUso();
};

Ataque::Ataque(string _nombre_ataque, int _usos, int _dano){
    nombre_ataque = _nombre_ataque;
    usos = _usos;
    dano = _dano;
}
Ataque::Ataque(){}
Ataque::Ataque(string _nombre_ataque, int _dano){
    nombre_ataque = _nombre_ataque;
    dano = _dano;
}

string Ataque::getNombreAtaque(){
    return nombre_ataque;
}

int Ataque::getUsos(){
    return usos;
}

int Ataque::getUsosTotales(){
    return usos_totales;
}

int Ataque::getDano(){
    return dano;
}

void Ataque::quitarUso(){
    usos--;
}

void Ataque::setUsos(int _usos){
    usos = usos + _usos;
}


#endif // ATAQUE_H_INCLUDED
