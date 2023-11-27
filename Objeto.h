#ifndef OBJETO_H_INCLUDED
#define OBJETO_H_INCLUDED

#include <string>

class Objeto{
private:
    string nombre;
    int valor;
    int precio;

public:
    Objeto(string, int, int); // nombre, valor, precio
    Objeto();

    void setNombre(string);
    void setValor(int);
    void setPrecio(int);

    string getNombre();
    int getValor();
    int getPrecio();

    string getInfo();
};

Objeto::Objeto(string _nombre, int _valor, int _precio){
    nombre = _nombre;
    valor = _valor;
    precio = _precio;
}

Objeto::Objeto(){}

void Objeto::setNombre(string _nombre){
    nombre = _nombre;
}
void Objeto::setPrecio(int _precio){
    precio = _precio;
}
void Objeto::setValor(int _valor){
    valor = _valor;
}

string Objeto::getNombre(){
    return nombre;
}
int Objeto::getValor(){
    return valor;
}
int Objeto::getPrecio(){
    return precio;
}

string Objeto::getInfo(){
    string texto =  "Nombre: " + nombre + ": " + "\n\tPrecio: $" + to_string(precio) + "\n\tEfecto: +" + to_string(valor);
    return texto;
}




#endif // OBJETO_H_INCLUDED
