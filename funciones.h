#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

string registrarJugador(int n_jug)
{
    string nom_jug;
    cout << "+-------------------------------+" << endl;
    cout << "| INGRESE NOMBRE DEL JUGADOR: " << n_jug << " |" << endl;
    cout << "+-------------------------------+" << endl;
    cin >> nom_jug;
    return nom_jug;
}

void mostrarDado(int cara)
{
    switch (cara)
        {
        case 1:
            cout << "+-----+" << endl;
            cout << "|     |" << endl;
            cout << "|  x  |" << endl;
            cout << "|     |" << endl;
            cout << "+-----+";
            break;
        case 2:
            cout << "+-----+" << endl;
            cout << "|  x  |" << endl;
            cout << "|     |" << endl;
            cout << "|  x  |" << endl;
            cout << "+-----+";
            break;
        case 3:
            cout << "+-----+" << endl;
            cout << "| x   |" << endl;
            cout << "|  x  |" << endl;
            cout << "|   x |" << endl;
            cout << "+-----+";
            break;
        case 4:
            cout << "+-----+" << endl;
            cout << "| x x |" << endl;
            cout << "|     |" << endl;
            cout << "| x x |" << endl;
            cout << "+-----+";
            break;
        case 5:
            cout << "+-----+" << endl;
            cout << "| x x |" << endl;
            cout << "|  x  |" << endl;
            cout << "| x x |" << endl;
            cout << "+-----+";
            break;
        case 6:
            cout << "+-----+" << endl;
            cout << "| x x |" << endl;
            cout << "| x x |" << endl;
            cout << "| x x |" << endl;
            cout << "+-----+";
            break;
        }
}

void tirarDados()
{
    int i, j;
    int cara[6];
    srand(time(NULL));
    for(i=0; i<6; i++)
    {
        cara[i]=(rand()%6)+1;
        mostrarDado(cara[i]);
        // cout << cara[i] << endl;
    }
}

#endif // FUNCIONES_H_INCLUDED
