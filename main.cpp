#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

#include "funciones.h"

int main()
{
    int opc;
    int size = 3;
    string nom_jug[size];

    while(true){
        system("cls");
        cout << "#########################################" << endl;
        cout << "###### TP FINAL - FUENTES, BOTTELI ######" << endl;
        cout << "#########################################" << endl;
        cout << endl;
        cout << "---------------------------------------- " << endl;
        cout << "1. UN JUGADOR (Player vs IA)" << endl;
        cout << "2. DOS JUGADORES" << endl;
        cout << "0. SALIR DEL JUEGO " << endl;
        cout << "---------------------------------------- " << endl << endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opc;

        system("cls");

        switch(opc){
            case 1:
                // Llama a la funcion para registrar un jugador en el indice indicado,
                // y la guarda en el vector de nombres, en la misma posicion.
                nom_jug[1] = registrarJugador(1);
                tirarDados();
                system("pause");
                break;
            case 2:
                nom_jug[1] = registrarJugador(1);
                nom_jug[2] = registrarJugador(2);
                system("pause");
                break;
            case 0:
                return 0;
                break;

            default:
                cout << "OPCION INVALIDA" << endl;
                break;
        }

    }
    return 0;
}
