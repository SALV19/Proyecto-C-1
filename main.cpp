#include <iostream>
#include <random>

#include "Persona.h"
#include "Heroe.h"
#include "Enemigo.h"
#include "Ataques.h"

using namespace std;

// Esta función permite selecciónar la clase de tu personaje, que cambiará los valores de vida, MP, fuerza y destreza, que se usan durante la pelea.
string elegirRol(){
    string rol;

    cout << "Cual Rol quieres elegir? " << endl;

    cout << "1. Bandido" << endl << "\tVida: Medio" << endl <<"\tMP: Medio" << endl << "\tFuerza: Bajo" << endl << "\tDestreza: Alto" << endl;
    cout << "2. Paladin" << endl << "\tVida: Alta" << endl <<"\tMP: Bajo" << endl << "\tFuerza: Medio" << endl << "\tDestreza: Medio" << endl;
    cout << "3. Hechicero" << endl << "\tVida: Baja" << endl << "\tMP: Alto" << endl << "\tFuerza: Bajo" << endl << "\tDestreza: Medio" << endl;
    int res;
    do{
        cout << "Selecciona una opcion: ";
        cin >> res;
        if (res == 1){
            rol = "Bandido";
        }
        else if (res == 2){
            rol = "Paladin";
        }
        else if (res == 3){
            rol = "Hechicero";
        }
        else{
            cout << "Opcion invalida. " << endl;
        }
    }
    while (res <1 || res > 3);
    return rol;
}

//Asigna los valores de tu personaje dependiendo la clase
int* seleccionRol(string rol){
    static int vida_mp[] = {1, 2};// Vida, MP, Fuerza, Destreza

    if (rol == "Bandido"){
        vida_mp[0] = 75;
        vida_mp[1] = 25;
        vida_mp[2] = 5;
        vida_mp[3] = 15;
    }
    else if (rol == "Paladin"){
        vida_mp[0] = 100;
        vida_mp[1] = 10;
        vida_mp[2] = 10;
        vida_mp[3] = 10;
    }
    else if (rol == "Hechicero"){
        int vida_mp[] = {50, 50, 10, 10};
        vida_mp[0] = 50;
        vida_mp[1] = 50;
        vida_mp[2] = 10;
        vida_mp[3] = 10;
    }
    return vida_mp;
}

int acciones(){
    int res;
    do{
        cout << "1. Combate" << endl << "2. Magia" << endl << "3. Usar Objeto" << endl << "4. Huir" << endl;
        cin >> res;
    }
    while (res < 1 || res > 4);
    return res;
}
// Ataques físicos del personaje
int ataques(Heroe p1){
    cout << "Ataques";
}
// Ataques mágicos del personaje
int hechizos(Heroe p1){
    cout << "Magia";
}
// Jugador usa un objeto
int usar_objeto(Heroe p1){
    cout << "usaste un objeto";
}

// Ataque enemigo
int accion_enemigo(Enemigo enemy){
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dis(1, 4);

    int random_num = dis(gen);

}

// Función principal para las peleas
void pelear(Heroe p1, Enemigo enemy){
    int res, dano, objeto, ataque_enemigo;

    cout << "Has entrado en combate con: " << enemy.getNombre() << endl;
    while (enemy.getVida() > 0 && p1.getVida() > 0){
        cout << endl << p1.getNombre() + ": " << "\t\t" + enemy.getNombre() + ": " <<endl;
        cout << "Vida: " << p1.getVida() << "\tVida: " << enemy.getVida() << endl;
        cout << "MP: " << p1.getMP() << endl;

        res = acciones();
        if (res == 1){
            dano = ataques(p1);
            enemy.recibirDano(dano);
        }
        else if (res == 2){
            dano = hechizos(p1);
            enemy.recibirDano(dano);
        }
        else if (res == 3){
            objeto = usar_objeto(p1);
        }
        else if (res == 4){
            cout << "Huiste del combate" << endl;
            break;
        }

        ataque_enemigo = accion_enemigo(enemy);
        p1.recibirDano(ataque_enemigo);

    }


}

int main()
{
    string nombre;
    int vida, mp, fuerza, destreza;

    // Creación de enemigos:
        Enemigo goblin("Goblin", 1, 20);
        Enemigo ladron("Ladron", 1, 30);


    /*
    cout << "Bienvenid@ al mundo de Albion, un mundo fantastico que necesita tu ayuda para derrotar al \ntemible Hechicero Oscuro Salvara." << endl;
    cout << "Preparad@ para empezar tu aventura? \n Ingresa tu nombre: ";
    cin >> nombre;

    string rol = elegirRol();
    */

    string rol = "Bandido";
    nombre = "Santi";

    int* vida_mp = seleccionRol(rol); // asignación de valores para el jugador dependiendo del rol

        vida = vida_mp[0];  // Facilita lectura
        mp = vida_mp[1];
        fuerza = vida_mp[2];
        destreza = vida_mp[3];

    Heroe p1(nombre, 1, vida, mp); // creación de tu personaje.
    p1.setRol(rol, fuerza, destreza);

    pelear(p1, goblin);

    return 0;
}
