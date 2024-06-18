#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

#include "funciones.h"

int main()
{
    int opc;

    while(true){
        system("cls");
        cout << "#########################################" << endl;
        cout << "###### TP FINAL - FUENTES, BOTTELI ######" << endl;
        cout << "#########################################" << endl;
        cout << endl;
        cout << "---------------------------------------- " << endl;
        cout << "1. UN JUGADOR" << endl;
        cout << "2. DOS JUGADORES" << endl;
        cout << "0. SALIR DEL JUEGO " << endl;
        cout << "---------------------------------------- " << endl << endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opc;

        system("cls");

        switch(opc){
            case 1:
                while (partida(1));
                break;
            case 2:
                while (partida(2));
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
