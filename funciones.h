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
    bool en_partida = true;
    bool alternar = false;
    int lanz_totales = 3;
    int max_puntaje[2] = {0,0};
    string nom_jug[c_jug];
    nom_jug[0] = registrarJugador(1);
    if (c_jug == 2)
    {
        nom_jug[1] = registrarJugador(2);
        lanz_totales = 6;
        alternar = true;
    }

    int ganador;
    int perdedor;
    int n_jug = 0;
    int lanz = 1;
    int lanz_jug[2] = {1,0};
    int ronda = 0;
    int puntaje = 0;
    int puntuacion_total[2] = {0,0};
    system("cls");
    while (puntuacion_total[0] < 100 || puntuacion_total[1] < 100)
    {
        if (lanz%3)
        {
        ronda++;
        }

        for (lanz = 1; lanz <=lanz_totales ; lanz++)
        {
            cout << "PUNTAJE TOTAL: "<< puntuacion_total[n_jug] << " PUNTOS" << endl;
            cout << "-----------------------------------------------" << endl;
            cout << "TURNO DE: " << nom_jug[n_jug] << " | RONDA N: " << ronda << endl;
            cout << "-----------------------------------------------" << endl;
            cout << "MAXIMO PUNTAJE DE LA RONDA " << max_puntaje[n_jug] << endl;
            cout << "LANZAMIENTO N: " << lanz_jug[n_jug] << endl;
            cout << "-----------------------------------------------" << endl;
            puntaje = tirarDados();

            puntuacion_total[n_jug] += puntaje;


            if (puntaje > max_puntaje[n_jug])
            {
                max_puntaje[n_jug] = puntaje;
            }

            if (puntuacion_total[n_jug] >= 100)
            {
                system("cls");
                if (n_jug == 0)
                {
                    ganador = 0;
                    perdedor = 1;
                }
                else
                {
                    ganador = 1;
                    perdedor = 0;
                }

                cout << "RONDAS TOTALES: " << ronda << endl;
                cout << "-----------------------------------------------" << endl;
                cout << "GANADOR: " << nom_jug[ganador] << " | PUNTUACION: " << puntuacion_total[ganador] << "/100" << endl;
                cout << "-----------------------------------------------" << endl;
                if (c_jug == 2)
                {
                    cout << "PERDEDOR: " << nom_jug[perdedor] << " | PUNTUACION: " << puntuacion_total[perdedor] << "/100" << endl;
                    cout << "-----------------------------------------------" << endl;
                }

                system("pause");
                en_partida = false;
                return en_partida;
            }

            if (alternar == true)
            {
                if (lanz%2)
                {
                    lanz_jug[1]++;
                    n_jug=1;
                }
                else
                {
                    lanz_jug[0]++;
                    n_jug=0;
                }
                cout << "-----------------------------------------------" << endl;
                cout << "SIGUIENTE TURNO: " << nom_jug[n_jug] << endl;
                cout << "PUNTUACION TOTAL: " << puntuacion_total[n_jug] << endl;
                cout << "-----------------------------------------------" << endl;
            }
            else
            {
                lanz_jug[0]++;
            }
            system("pause");
            system("cls");


        }
    }
}


#endif // FUNCIONES_H_INCLUDED
