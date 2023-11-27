#ifndef HEROE_H_INCLUDED
#define HEROE_H_INCLUDED

#include "Ataque.h"
#include "Objeto.h"

#include <string>
#include <vector>


// Es la clase del jugador con sus stats específicos del jugador y acciones específicas del jugador
class Heroe : public Persona{
private: // valores del personaje
    string rol;
    int fuerza;     // Aumenta daño
    int destreza;   // Aumenta Usos
    int dinero;

    vector<Objeto> objetos;

    Ataque fisico[4]; // Ataques físicos del personaje

public:
    Heroe(string, int);

    // Creación del personaje dependiendo de la clase inicial
    void setRol(string, int, int);
    string getRol();

    // Acceder al dinero para usar en la tienda
    void setDinero(int);
    int getDinero();

    // Atributos de modificación para daño, usos y habilidades relacionadas con magia
    int getFuerza();
    int getDestreza();

    // Creación de los ataques.
    void setAtaques(Ataque, int); // nombre, usos, daño

    // Acceder a la información la información de los ataques, se regresan en formato de lista
    string* getNombreAtaque_1();

    void setUsosAtaques(int);

    int* getUsosAtaques();
    int* getUsosTotales();
    int* getDanoAtaques();

    void setObjeto(Objeto);
    string getNombreObjeto();
    string getNombreObjeto(int);
    int getValorObjeto(int);
    vector<Objeto> getObjetos();

    // Quitar usos de habilidad para promover el uso de diferentes ataques
    void habilidadUsada(int);

    int getCantidadObjetos();
};

Heroe::Heroe(string _nombre, int _vida) : Persona(_nombre, _vida){
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

int Heroe::getFuerza(){
    return fuerza;}
int Heroe::getDestreza(){
    return destreza;}

string* Heroe::getNombreAtaque_1(){
    static string lista[4];
    int i = 0;
    for (Ataque ataque : fisico){
        lista[i] = ataque.getNombreAtaque();
        i++;
    }

    return lista;
}
int* Heroe::getUsosAtaques(){
    static int lista[4];
    int i = 0;
    for (Ataque ataque : fisico){
        lista[i] = ataque.getUsos();
        i++;
    }

    return lista;
}
int* Heroe::getDanoAtaques(){
    static int lista[4];
    int i = 0;
    for (Ataque ataque : fisico){
        lista[i] = ataque.getDano();
        i++;
    }

    return lista;
}
int* Heroe::getUsosTotales(){
    static int lista[4];
    int i = 0;
    for (Ataque ataque : fisico){
        lista[i] = ataque.getUsosTotales();
        i++;
    }

    return lista;
}

void Heroe::habilidadUsada(int _habilidad){
    fisico[_habilidad].quitarUso();
}

void Heroe::setAtaques(Ataque _ataque, int _posicion){
    fisico[_posicion] = _ataque;
}

void Heroe::setObjeto(Objeto _objetos){
    objetos.push_back(_objetos);
}
string Heroe::getNombreObjeto(){
    return objetos.back().getNombre();
}
string Heroe::getNombreObjeto(int _pos){
    return objetos[_pos].getNombre();
}
vector<Objeto> Heroe::getObjetos(){
    return objetos;
}

int Heroe::getValorObjeto(int _pos){
    return objetos[_pos].getValor();
}

void Heroe::setUsosAtaques(int _usos){
    for (Ataque ataque : fisico){
        ataque.setUsos(_usos);
    }
}

int Heroe::getCantidadObjetos(){
    return objetos.size();
}

#endif // HEROE_H_INCLUDED
