#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

string registrarJugador(int n_jug)
{
    string nombre;
    if (n_jug == 1)
    {
        cout << "+-------------------------------+" << endl;
        cout << "| INGRESE NOMBRE DEL JUGADOR  1 |" << endl;
        cout << "+-------------------------------+" << endl;
        cin >> nombre;
    }
    if (n_jug == 2)
    {
        cout << "+-------------------------------+" << endl;
        cout << "| INGRESE NOMBRE DEL JUGADOR  2 |" << endl;
        cout << "+-------------------------------+" << endl;
        cin >> nombre;
    }
    return nombre;
}

string mostrarDado(int cara, int linea)
{
    string v[3];
    switch (cara)
    {
    case 1:
        v[0]= {"     "};
        v[1]= {"  x  "};
        v[2]= {"     "};
        return v[linea];
        break;
    case 2:
        v[0]= {"  x  "};
        v[1]= {"     "};
        v[2]= {"  x  "};
        return v[linea];
        break;
    case 3:
        v[0]= {" x   "};
        v[1]= {"  x  "};
        v[2]= {"   x "};
        return v[linea];
        break;
    case 4:
        v[0]= {" x x "};
        v[1]= {"     "};
        v[2]= {" x x "};
        return v[linea];
        break;
    case 5:
        v[0]= {" x x "};
        v[1]= {"  x  "};
        v[2]= {" x x "};
        return v[linea];
        break;
    case 6:
        v[0]= {" x x "};
        v[1]= {" x x "};
        v[2]= {" x x "};
        return v[linea];
        break;
    }
}

int tirarDados()
{
    int puntaje = 0;
    int i;
    int dado[6];
    srand(time(NULL));
    for(i=0; i<6; i++)
    {
        dado[i]=(rand()%6)+1;
        puntaje += dado[i];
        //mostrarDado(dado[i]);
        // cout << cara[i] << endl;
    }

    cout << "+-----+ +-----+ +-----+ +-----+ +-----+ +-----+" << endl;
    cout << "|" << mostrarDado(dado[0], 0) << "| |" << mostrarDado(dado[1], 0) << "| |" << mostrarDado(dado[2], 0) << "| |" << mostrarDado(dado[3], 0) << "| |" << mostrarDado(dado[4], 0) << "| |" << mostrarDado(dado[5], 0) << "|" << endl;
    cout << "|" << mostrarDado(dado[0], 1) << "| |" << mostrarDado(dado[1], 1) << "| |" << mostrarDado(dado[2], 1) << "| |" << mostrarDado(dado[3], 1) << "| |" << mostrarDado(dado[4], 1) << "| |" << mostrarDado(dado[5], 1) << "|" << endl;
    cout << "|" << mostrarDado(dado[0], 2) << "| |" << mostrarDado(dado[1], 2) << "| |" << mostrarDado(dado[2], 2) << "| |" << mostrarDado(dado[3], 2) << "| |" << mostrarDado(dado[4], 2) << "| |" << mostrarDado(dado[5], 2) << "|" << endl;
    cout << "+-----+ +-----+ +-----+ +-----+ +-----+ +-----+" << endl;
    cout << "(" << puntaje << ")"<< endl;
    return puntaje;
}

bool partida(int c_jug)
{
    bool modo_2jug = false; // Por defecto se activa el modo un jugador
    string nom_jug[c_jug]; // Crea un vector del tamaño de la cantidad de jugadores
    nom_jug[0] = registrarJugador(1); // Pide nombre del segundo jugador
    if (c_jug == 2) // Verifica la cantidad de jugadores, si son 2, activa el modo multi
    {
        nom_jug[1] = registrarJugador(2); // Pide nombre del segundo jugador
        modo_2jug = true;
    }
    bool en_partida = true; // Inicia la partida
    bool empate = false; // Verifica la situacion de empate
    int ganador = 0; // Indice del vector de jugadores para el ganador, por defecto 0
    int ronda = 1; // Cantidad de rondas
    int ronda_multi = 0; // Cantidad de rondas en multijugador
    int perdedor; // Indice del vector de jugadores para el perdedor
    int c_rondas_totales = 0; // Cantidad de rondas totales
    int n_jug = 0; // Indice del jugador para alternar entre rondas
    int lanz_jug[2] = {1,0}; // Contador de lanzamientos para cada jugador (el jugador 1 empieza, por lo que comienza en 1)
    int lanz_jug_totales[2] = {0,0}; // Contador de lanzamientos totales para cada jugador, se usa para el desempate (el jugador 1 empieza, por lo que comienza en 1)
    int puntaje = 0; // Puntaje obtenido en el lanzamiento
    int max_puntaje[2] = {0,0}; // Puntaje maximo del jugador 1 y 2, en case de estar en un jugador, queda la segunda posicion en 0
    int puntuacion_total[2] = {0,0}; // Puntutacion total entre ambos jugadores

    cout << "-----------------------------------------------" << endl;
    cout << "INGRESE CANTIDAD DE RONDAS: " << endl;
    cout << "-----------------------------------------------" << endl;
    cin >> c_rondas_totales;

    system("cls");
    while (ronda <= c_rondas_totales)
    {
        for (lanz_jug[n_jug] = 1; lanz_jug[n_jug] <=3 ; lanz_jug[n_jug]++)
        {
            system("cls");
            cout << "TURNO DE: " << nom_jug[n_jug] << " | RONDA N: " << ronda << "/" << c_rondas_totales << endl;
            cout << "-----------------------------------------------" << endl;
            cout << "MAXIMO PUNTAJE DE LA RONDA " << max_puntaje[n_jug] << endl;
            cout << "LANZAMIENTO N: " << lanz_jug[n_jug] << "/3" << endl;
            cout << "-----------------------------------------------" << endl;

            puntaje = tirarDados(); // Llama a la funcion de tirar dados

            puntuacion_total[n_jug] += puntaje; // Guarda el puntaje en el determinado jugador

            if (puntaje > max_puntaje[n_jug]) // Verifica si el puntaje es mayor al anterior
            {
                max_puntaje[n_jug] = puntaje;
            }

            // Verifica que jugador esta lanzando, y si esta por debajo de los 100 pts
            if (n_jug == 0) // Si es el jugador 1
            {
                if (puntuacion_total[0] <= 100)
                {
                    lanz_jug_totales[0]++; // Suma lanzamientos totales del jugador 1
                }
            }
            else // Si es el 2
            {
                if (puntuacion_total[1] <= 100)
                {
                    lanz_jug_totales[1]++; // Suma lanzamientos totales del jugador 2
                }
            }

            cout << "-----------------------------------------------" << endl;
            cout << "PUNTAJE TOTAL: "<< puntuacion_total[n_jug] << " PUNTOS" << endl;
            cout << "-----------------------------------------------" << endl;
            system("pause");
            system("cls");
        }

        // MODO MULTI
        if (modo_2jug == true)
        {

            if (lanz_jug[0] == lanz_jug[1] && (lanz_jug[0]%3 && lanz_jug[1]%3)) // Verifica que ambos jugadores hayan hecho sus 3 lanzamientos y tengan la misma cantidad
            {
                ronda_multi++; // Suma una ronda al multijugador
                if (ronda_multi%2) // Verifica si es par para mostrar la mitad en pantalla
                {
                    ronda++;
                }


            }
            if (n_jug==0) // Verifica que jugador esta jugando para alternar
            {
                n_jug=1; // Establece el indice de jugador en 1 (jugador 2)
            }
            else
            {
                n_jug=0; // Establece el indice de jugador en 0 (jugador 1)
            }

            if (ronda <= c_rondas_totales) // Verifica la cantidad de rondas, por que a veces se muestra al terminar todas ellas
            {
                system("cls");
                cout << "-----------------------------------------------" << endl;
                cout << "SIGUIENTE TURNO: " << nom_jug[n_jug] << endl;
                cout << "PUNTUACION TOTAL: " << puntuacion_total[n_jug] << endl;
                cout << "-----------------------------------------------" << endl;
                system("pause");

            }

        }
        // FIN MODO MULTI
        else
        {
            ronda++;
        }

    }


    if (puntuacion_total[0] >= 100 && puntuacion_total[1] >= 100)
    {
        empate = true; // Ambos jugadores superaron los 100 pts, asi que hay que desempatar
        if (lanz_jug_totales[0] < lanz_jug_totales[1]) // Si el jugador 1 llego a 100 pts antes, pasa a ser el ganador
        {
            ganador = 0;
            perdedor = 1;
        }
        else // Si no, es el ganador el jugador 2
        {
            ganador = 1;
            perdedor = 0;
        }
    }

    system("cls");
    cout << "RONDAS TOTALES: " << ronda-1 << endl;
    cout << "-----------------------------------------------" << endl;
    if (puntuacion_total[0] >= 100 || puntuacion_total[1] >= 100)
    {
        cout << "GANADOR: " << nom_jug[ganador] << " | PUNTUACION: " << puntuacion_total[ganador] << "/100" << endl;
        cout << "LANZAMIENTOS: " << lanz_jug_totales[ganador] << endl;
        cout << "-----------------------------------------------" << endl;

    }
    else
    {
        cout << "PERDEDOR: " << nom_jug[0] << " | PUNTUACION: " << puntuacion_total[0] << "/100" << endl;
        cout << "LANZAMIENTOS: " << lanz_jug_totales[0] << endl;
        cout << "-----------------------------------------------" << endl;
    }
    system("pause");
    en_partida = false;
    return en_partida;
}

#endif // FUNCIONES_H_INCLUDED
