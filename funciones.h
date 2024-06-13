#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

string registrarJugador(int n_jug)
{
    string jugadores[2];
    cin >> jugadores[n_jug];
    return jugadores[n_jug];
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

void unJugador()
{
    string jugador = registrarJugador(0);
    int lanz = 0;
    int ronda = 0;
    int max_puntaje = 0;
    int puntaje = 0;
    int puntuacion_total = 0;
    system("cls");
    while (puntuacion_total < 100)
    {
        ronda++;
        for (lanz = 1; lanz <=3 ; lanz++)
        {
            cout << "TURNO DE: " << jugador << " | RONDA N: " << ronda << " | PUNTAJE TOTAL: " << puntuacion_total << " PUNTOS" << endl;
            cout << "-----------------------------------------------" << endl;
            cout << "MAXIMO PUNTAJE DE LA RONDA " << max_puntaje << endl;
            cout << "LANZAMIENTO N: " << lanz << "/3" << endl;
            cout << "-----------------------------------------------" << endl;
            puntaje = tirarDados();
            system("pause");
            system("cls");
            puntuacion_total += puntaje;
            if (puntaje > max_puntaje)
            {
                max_puntaje = puntaje;
            }
            if (puntuacion_total >= 100)
            {
                cout << "GANASTE! " << puntuacion_total << "/100" << endl;
                system("pause");
            }
        }
    }
}

#endif // FUNCIONES_H_INCLUDED
