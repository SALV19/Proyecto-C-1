#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED

#endif // ENEMIGO_H_INCLUDED

class Enemigo : public Persona{
private:
    string tipo;
    int cantidad;
public:
    Enemigo(string, int, int);
    Enemigo(string, int);

    void setTipo(string);
    void setCantidad(int);

    string getTipo();
    int getCantidad();

};

Enemigo::Enemigo(string _nombre, int _nivel, int _vida) : Persona(_nombre, _nivel, _vida){}


void Enemigo::setTipo(string _tipo){
    tipo = _tipo;}
void Enemigo::setCantidad(int _cantidad){
    cantidad = _cantidad;}

string Enemigo::getTipo(){
    return tipo;}
int Enemigo::getCantidad(){
    return cantidad;}


