#ifndef HEROE_H_INCLUDED
#define HEROE_H_INCLUDED

#endif // HEROE_H_INCLUDED

class Heroe : public Persona{
private:
    string rol;
    int mp;
    int fuerza;
    int destreza;
    int dinero;

    // Ataques fisico;

public:
    Heroe(string, int, int, int);

    void setRol(string, int, int);
    string getRol();

    void setDinero(int);
    int getDinero();

    int getMP();
    int getFuerza();
    int getDestreza();
};

Heroe::Heroe(string _nombre, int _nivel, int _vida, int _mp) : Persona(_nombre, _nivel, _vida){
    mp = _mp;
    dinero = 0;
}

void Heroe::setRol(string _rol, int _fuerza, int _destreza){
    rol = _rol;
    fuerza = _fuerza;
    destreza = _destreza;
}
string Heroe::getRol(){
    return rol;
}

void Heroe::setDinero(int _dinero){
    dinero += _dinero;
}
int Heroe::getDinero(){
    return dinero;
}

int Heroe::getMP(){
    return mp;}
int Heroe::getFuerza(){
    return fuerza;}
int Heroe::getDestreza(){
    return destreza;}

