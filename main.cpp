#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "rlutil.h"

using namespace std;

#include "funciones.h"

int main()
{
    string scoreboard[5] = {"NO HAY DATOS"};
    int c_jueg = 0;
    int opc;
    string i;

    i = char(205);

    system("color 5f");

    while(true)  /// al ponerlo en false el programa se corrompe y se muestra todo en negro
    {
        system("cls"); /// al quitarlo, al finalizar una partida no se limpiaria la pantalla

        /// utilizando rlutil, ubicamos en la columna y fila deseada, en este caso seria en el medio de la pantalla

        rlutil::locate(30, 7);
        cout << "#################################################" <<endl;
        rlutil::locate(30, 8);
        cout << "###### TP FINAL - FUENTES, BOTTELI, MONZON ######" << endl;
        rlutil::locate(30, 9);
        cout << "#################################################" << endl;
        rlutil::locate(30, 10);
        cout << endl;
        rlutil::locate(30, 11);
        cout << "MENU PRINCIPAL"<<endl;
        rlutil::locate(30, 12);
        cout <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<endl;
        rlutil::locate(30, 13);
        cout << "1. UN JUGADOR" << endl;
        rlutil::locate(30, 14);
        cout << "2. DOS JUGADORES" << endl;
        rlutil::locate(30, 15);
        cout << "3. MOSTRAR GANADORES" << endl;
        rlutil::locate(30, 16);
        cout << "0. SALIR DEL JUEGO " << endl;
        rlutil::locate(30, 17);
        cout <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<endl;
        rlutil::locate(30, 18);
        cout << "SELECCIONE UNA OPCION: ";


        cin >> opc;

        system("cls"); /// al quitarlo, cuando seleccionamos un modo juego, sigue quedando el menu principal

        switch(opc)
        {
        case 1:
            if (c_jueg < 5)
            {
                scoreboard[c_jueg] = partida(1);
                c_jueg++;
            }
            else
            {
                rlutil::locate(30, 18);
                cout << "TABLA DE JUGADORES LLENA, NO SE GUARDARAN LOS DATOS.";
                partida(1);
            }
            break;
        case 2:
            if (c_jueg < 5)
            {
                scoreboard[c_jueg] = partida(2);
                c_jueg++;
            }
            else
            {
                rlutil::locate(30, 18);
                cout << "TABLA DE JUGADORES LLENA, NO SE GUARDARAN LOS DATOS.";
                partida(1);
            }
            break;
        case 3:
            tablaPuntuaciones(scoreboard);
            break;
        case 4:
            tirarDados(true);
            break;
        case 0:
            return 0;
            break;

        default:
            cout << "OPCION INVALIDA, VUELVA A INGRESAR OTRA. " << endl;
            system("pause"); /// pausa de sistema añadida, ya que sin ella, no se llegaba a leer lo que dice
            break;
        }
    }
    return 0;
}
