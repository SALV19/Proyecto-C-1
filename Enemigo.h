#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED

#endif // ENEMIGO_H_INCLUDED

// Todos los enemigos con sus atributos.
class Enemigo : public Persona{
private:
    int cantidad;

    Ataque ataque[3];

public:
    Enemigo(string, int);

    void setCantidad(int);

    int getCantidad();

    void crearAtaques(Ataque, int);
    string getNombreAtaque(int);
    int getDanoAtaque(int);

};

Enemigo::Enemigo(string _nombre, int _vida) : Persona(_nombre, _vida){}

void Enemigo::setCantidad(int _cantidad){
    cantidad = _cantidad;}

int Enemigo::getCantidad(){
    return cantidad;}

void Enemigo::crearAtaques(Ataque _ataque, int _pos){
    ataque[_pos] = _ataque;
}

string Enemigo::getNombreAtaque(int _pos){
    return ataque[_pos].getNombreAtaque();
}
int Enemigo::getDanoAtaque(int _pos){
    return ataque[_pos].getDano();
}
