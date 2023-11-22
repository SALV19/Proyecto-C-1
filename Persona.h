#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#endif // PERSONA_H_INCLUDED

using namespace std;

class Persona{
private:
    string nombre;
    int nivel;
    int vida;

    string *ataques;
    int *dano;

public:
    Persona(string, int, int);
    Persona(int, int);

    void setNombre(string);
    string getNombre();

    int getVida();

    void recibirDano(int);
};

Persona::Persona(string _nombre, int _nivel, int _vida){
    nombre = _nombre;
    nivel = _nivel;
    vida = _vida;
}
Persona::Persona(int _nivel, int _vida){
    nivel = _nivel;
    vida = _vida;
}

void Persona::setNombre(string _nombre){
    nombre = _nombre;
}

string Persona::getNombre(){
    return nombre;
}
int Persona::getVida(){
    return vida;
}

void Persona::recibirDano(int dano){
    vida -= dano;
}
