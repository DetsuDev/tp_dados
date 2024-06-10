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

string mostrarDado(int cara, int linea)
{
    string v[3];
    switch (cara)
        {
        case 1:
            v[0]={"     "};
            v[1]={"  x  "};
            v[2]={"     "};
            return v[linea];
            break;
        case 2:
            v[0]={"  x  "};
            v[1]={"     "};
            v[2]={"  x  "};
            return v[linea];
            break;
        case 3:
            v[0]={" x   "};
            v[1]={"  x  "};
            v[2]={"   x "};
            return v[linea];
            break;
        case 4:
            v[0]={" x x "};
            v[1]={"     "};
            v[2]={" x x "};
            return v[linea];
            break;
        case 5:
            v[0]={" x x "};
            v[1]={"  x  "};
            v[2]={" x x "};
            return v[linea];
            break;
        case 6:
            v[0]={" x x "};
            v[1]={" x x "};
            v[2]={" x x "};
            return v[linea];
            break;
        }
}

void tirarDados()
{
    int i, j;
    int dado[6];
    srand(time(NULL));
    for(i=0; i<6; i++)
    {
        dado[i]=(rand()%6)+1;
        //mostrarDado(dado[i]);
        // cout << cara[i] << endl;
    }
    cout << "+-----+ +-----+ +-----+ +-----+ +-----+ +-----+" << endl;
    cout << "|" << mostrarDado(dado[0], 0) << "| |" << mostrarDado(dado[1], 0) << "| |" << mostrarDado(dado[2], 0) << "| |" << mostrarDado(dado[3], 0) << "| |" << mostrarDado(dado[4], 0) << "| |" << mostrarDado(dado[5], 0) << "|" << endl;
    cout << "|" << mostrarDado(dado[0], 1) << "| |" << mostrarDado(dado[1], 1) << "| |" << mostrarDado(dado[2], 1) << "| |" << mostrarDado(dado[3], 1) << "| |" << mostrarDado(dado[4], 1) << "| |" << mostrarDado(dado[5], 1) << "|" << endl;
    cout << "|" << mostrarDado(dado[0], 2) << "| |" << mostrarDado(dado[1], 2) << "| |" << mostrarDado(dado[2], 2) << "| |" << mostrarDado(dado[3], 2) << "| |" << mostrarDado(dado[5], 2) << "| |" << mostrarDado(dado[5], 2) << "|" << endl;
    cout << "+-----+ +-----+ +-----+ +-----+ +-----+ +-----+" << endl;
}

#endif // FUNCIONES_H_INCLUDED
