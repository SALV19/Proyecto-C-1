#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#endif // PERSONA_H_INCLUDED

using namespace std;

// Clase padre de los seres vivos del juego, el jugador y los enemigos que almacena sus estadisticas.
class Persona{
private:
    string nombre;
    int nivel;
    int vida;

public:
    Persona(string, int);
    Persona(int, int);


    string getNombre();

    int getVida();
    void setVida(int);

    void recibirDano(int);
};

Persona::Persona(string _nombre, int _vida){
    nombre = _nombre;
    vida = _vida;
}
Persona::Persona(int _nivel, int _vida){
    nivel = _nivel;
    vida = _vida;
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

void Persona::setVida(int _vida){
    vida += _vida;
}

