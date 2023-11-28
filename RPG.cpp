#include <iostream>
#include <random>
#include <vector>

#include "Persona.h"
#include "Heroe.h"
#include "Enemigo.h"
#include "Ataque.h"
#include "Objeto.h"

using namespace std;

// Esta función permite selecciónar la clase de tu personaje, que cambiará los valores de vida, fuerza y destreza, que se usan durante la pelea.
string elegirRol(){
    string rol;

    cout << "Cual Rol quieres elegir? " << endl;

    cout << "1. Bandido" << endl << "\tVida: Medio" << endl << "\tFuerza: Bajo" << endl << "\tDestreza: Alto" << endl;
    cout << "2. Paladin" << endl << "\tVida: Alta" << endl << "\tFuerza: Medio" << endl << "\tDestreza: Medio" << endl;
    cout << "3. Hechicero" << endl << "\tVida: Baja" << endl << "\tFuerza: Bajo" << endl << "\tDestreza: Medio" << endl;
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
    static int vida_mp[3];// Vida, Fuerza, Destreza

    if (rol == "Bandido"){
        vida_mp[0] = 75;
        vida_mp[1] = 5;
        vida_mp[2] = 15;
    }
    else if (rol == "Paladin"){
        vida_mp[0] = 100;
        vida_mp[1] = 10;
        vida_mp[2] = 10;
    }
    else if (rol == "Hechicero"){
        vida_mp[0] = 50;
        vida_mp[1] = 10;
        vida_mp[2] = 10;
    }
    return vida_mp;
}

int acciones(){
    int res;
    do{
        cout << "1. Combate" << endl  << "2. Usar Objeto" << endl << "3. Huir" << endl;
        cin >> res;
    }
    while (res < 1 || res > 4);
    return res;
}
// Ataques físicos del personaje
int ataques(Heroe p1){

    for (int i = 0; i < 4; i++){
        cout << endl << i+1 << ". " + p1.getNombreAtaque_1()[i]<< ": " << endl;
        cout << "\tDano: " << p1.getDanoAtaques()[i] + p1.getFuerza() / 10 << endl;
        cout << "\tUsos: " << p1.getUsosAtaques()[i] + p1.getDestreza() / 10<< endl;
    }
    int res;

    do{
        cout << endl <<"Elige un ataque: ";
        cin >> res;

        if (p1.getUsosAtaques()[res-1] + p1.getDestreza() / 10 < p1.getUsosTotales()[res-1] + p1.getDestreza() / 10){
            cout<<endl << "No le quedan usos a esa habilidad. " << endl;
        }
        else{
            cout << endl << "Elige una opcion valida.  "<< endl;
        }
    }
    while(res <1 || res>4);
    cout << endl << "Se ha usado: " << p1.getNombreAtaque_1()[res-1] << endl;

    p1.habilidadUsada(res-1); // Error

    int dano = p1.getDanoAtaques()[res - 1];
    dano += p1.getFuerza();

    return dano;

}

// Jugador usa un objeto
int usar_objeto(Heroe p1){
    for (int i=0; i<p1.getCantidadObjetos(); i++){
        cout << endl <<  i+1 << ": ";
        cout << p1.getNombreObjeto(i) << endl;
    }
    int res;
    while (res <1 || res >4){
        cout << endl << "Cual objeto quieres usar: ";
        cin >> res;
    }
    cout << "Usaste: " << p1.getNombreObjeto(res-1);

    return p1.getValorObjeto(res-1);
}

// Ataque enemigo
int accion_enemigo(Enemigo enemy){
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dis(0, 2);

    int rand = dis(gen);

    cout << enemy.getNombre() << " ha usado: " << enemy.getNombreAtaque(rand) << endl;
    return enemy.getDanoAtaque(rand);
}

Heroe crearAtaques(Heroe p1, string rol){
    if(rol == "Bandido"){
        p1.setAtaques(Ataque("Lanzar Daga", 20, 3), 0);
        p1.setAtaques(Ataque("Corte Sombra", 15, 7), 1);
        p1.setAtaques(Ataque("Corte Rapido", 12, 9), 2);
        p1.setAtaques(Ataque("Mano Rapida", 8, 15), 3);



    }
    else if (rol == "Paladin"){
        p1.setAtaques(Ataque("Golpe Sagrado", 13, 8), 0);
        p1.setAtaques(Ataque("Maza del destino", 10, 15), 1);
        p1.setAtaques(Ataque("Mano del monarca", 15, 7), 2);
        p1.setAtaques(Ataque("Carga", 9, 18), 3);
        cout <<"";
    }
    else{ // rol = Hechicero
        p1.setAtaques(Ataque("Hechizo de Fuego", 10, 10), 0);
        p1.setAtaques(Ataque("Lluvia de hielo", 12, 8), 1);
        p1.setAtaques(Ataque("Ventisca del sur", 9, 15), 2);
        p1.setAtaques(Ataque("Bola de magma", 5, 18), 3);
        cout <<"";
    }
    return p1;

}

Heroe tienda(Heroe p1){

    cout << "Bienvenida a la tienda: " << endl;
    vector<Objeto> objetos_en_venta = {Objeto("Pocion Curacion I", 15, 10), Objeto("Pocion Curacion II", 30, 20), Objeto("Restaruar Usos I", 5, 15), Objeto("Restaruar Usos II", 20, 25)};
    for (int i=0; i< objetos_en_venta.size(); i++){
        cout << i+1 << ": " << objetos_en_venta[i].getInfo() << endl << endl;

    }

    while (true){

        int res;

        cout << p1.getNombre() << ": " << endl << "\tDinero: " << p1.getDinero()<< endl;

        cout << "Cual objeto le interesa? " << endl;
        cin >> res;

        if (p1.getDinero() >= objetos_en_venta[res-1].getPrecio()){
            p1.setDinero(-objetos_en_venta[res-1].getPrecio());
            p1.setObjeto(objetos_en_venta[res-1]);
            cout << "Compraste: " << p1.getNombreObjeto() << endl;
        }
        else{
            cout << "Compra invalida" << endl;
        }

        cout << "Seguir comprando? S/N    ";
        string res_1;
        cin >> res_1;

        if (res_1 != "s" && res_1 != "S"){
            break;
        }
    }


    return p1;
}

// Función principal para las peleas
void pelear(Heroe p1, Enemigo enemy){
    int res, dano, objeto, ataque_enemigo;

    cout << "Has entrado en combate con: " << enemy.getNombre() << endl;
    while (enemy.getVida() > 0 && p1.getVida() > 0){
        cout << endl << p1.getNombre() + ": " << "\t\t" + enemy.getNombre() + ": " <<endl;
        cout << "Vida: " << p1.getVida() << "\tVida: " << enemy.getVida() << endl;

        res = acciones();
        if (res == 1){
            dano = ataques(p1);
            for (int i=0;i<3;i++){
                if (p1.getDanoAtaques()[i] + p1.getFuerza() == dano){
                    p1.habilidadUsada(i);
                }
            }
            enemy.recibirDano(dano);
        }
        else if (res == 2){
            objeto = usar_objeto(p1);
            if (objeto % 3 == 0){
                cout << endl << "Vida = " <<  p1.getVida() << " + " << objeto << endl;
                p1.setVida(objeto);

            }
            else{
                p1.setUsosAtaques(objeto);
            }
        }
        else if (res == 3){
            cout << "Huiste del combate" << endl;
            break;
        }

        if (enemy.getVida() <= 0){
            cout << endl << "Has derrotado a: " << enemy.getNombre() << endl;
        }
        else{
            ataque_enemigo = accion_enemigo(enemy);
            p1.recibirDano(ataque_enemigo);
        }

    }

}

// Selección de a donde ir / enemigos a los que te enfrentas
int viajes(){
    cout << "A donde te gustaria explorar: " << endl << "1. Bosque perdido" << endl<< "2. Tienda" << endl <<"3. Mansión Salvara" << endl;
    int res;
    cin >> res;

    return res;
}



int main()
{
    string nombre;
    int vida, fuerza, destreza;

    // Creación de enemigos:
        Enemigo goblin("Goblin", 20);
            goblin.crearAtaques(Ataque("Daga", 2), 0);
            goblin.crearAtaques(Ataque("Arañazo", 1), 1);
            goblin.crearAtaques(Ataque("Mordizco", 5), 2);
        Enemigo ladron("Ladron", 30);
            ladron.crearAtaques(Ataque("Daga", 2), 0);
            ladron.crearAtaques(Ataque("Golpe", 1), 1);
            ladron.crearAtaques(Ataque("Cuchillo oculto", 5), 2);
        Enemigo salvara("Salvara", 50);
            salvara.crearAtaques(Ataque("Bola de fuego", 10), 0);
            salvara.crearAtaques(Ataque("Ventisca", 20), 1);
            salvara.crearAtaques(Ataque("Pico de Hielo", 30), 2);


    cout << "Bienvenid@ al pais de Varn, un reino fantastico donde vive Capa Salvara, \n jefe de todas las organizaciones criminales de la ciudad" << endl;
    cout << "Preparad@ para empezar tu aventura? \n Ingresa tu nombre: ";
    cin >> nombre;


    string rol = elegirRol();

    int* vida_mp = seleccionRol(rol); // asignación de valores para el jugador dependiendo del rol

        vida = vida_mp[0];  // Facilita lectura
        fuerza = vida_mp[1];
        destreza = vida_mp[2];

    Heroe p1(nombre, vida); // creación de tu personaje.
    p1.setRol(rol, fuerza, destreza);

    p1 = crearAtaques(p1, rol);

    p1.setObjeto(Objeto("Pocion Curacion I", 15, 15));

    p1.setDinero(50);
    int donde_ir;
    bool salvara_sin_derrotar = true;
    while (salvara_sin_derrotar == true){
        donde_ir = viajes();

        if (donde_ir == 1){
            cout << "Viajas al bosque y te encuentras con un Goblin!!! " << endl;
            goblin.setCantidad(50);
            pelear(p1, goblin);

            cout << "Tras derrotar al Goblin conseguiste $"<< goblin.getCantidad()<< ", y una poción de curación";
            p1.setDinero(goblin.getCantidad());
            p1.setObjeto(Objeto("Pocion Curacion II", 30, 20));
        }
        else if (donde_ir == 2){
            p1 = tienda(p1);
        }
        else if (donde_ir == 3){
            cout << "Conforme emprendes tu viaje a la mansion de Don Salvara, te corta el paso un ladron que hara cualquier cosa por despojarte de tus objetos" << endl;
            pelear(p1, ladron);
            ladron.setCantidad(100);
            cout << "Conseguiste $" << ladron.getCantidad() << endl;
            p1.setDinero(100);
            cout << "Al derrotar al ladron, continuas tu viaje a la mansion de Salvara, y te recibe con la puerta abierta y una mirada macabra." << endl;
            pelear(p1, salvara);
            cout << "Derrotaste al capo de la ciudad, y liberaste a la ciudad de Varn";
            salvara_sin_derrotar = false;
        }
        else{
            cout << "Respuesta invalida. Vuelve a intentar";

        }
    }
    cout << endl<<"Gracias por jugar" << endl;

    return 0;
}
