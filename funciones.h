#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void tablaPuntuaciones(string puntuaciones[])
{

    string i;
    i = char (205);
    int j;
        rlutil::locate(30, 7);
        cout << "GANADORES" << endl;
        rlutil::locate(30, 8);
        cout <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<endl;
        for (j = 0; j < 5; j++) // recorre vector de puntuaciones
        {
            rlutil::locate(30, 9+j);
            cout << puntuaciones[j] << endl;

        }
    rlutil::locate(30, 15);
    system("pause");
}


int condiciones(int vec[])
{
    bool vec_escalera[6] = {false}; // crearemos un vector de 6 y booleano con todas las variables en falso
    bool escalera = true; // asumiremos que el caso de la escalera es true hasta que se diga lo contrario

    int primer_valor; // variable para almacenar el primer valor del vector de los dados
    bool iguales = true; // asumimos tambien que todos los numeros son iguales hasta que se diga lo contrario

    for(int i = 0; i < 6; i++) // al modificar el valor del for, el juego tira puntajes ficticios y erroneos
    {
        vec_escalera[vec[i] - 1] = true; // el contenido del vector de los dados se utilizara como indice para poner en true los elementos del vector de la escalera

        if(i == 0)
        {
            primer_valor = vec[i]; // se almacena el primer valor cuando el indice es 0
        }
        else if(vec[i] != primer_valor)  // si cualquiera de los numeros es distinto al primero, significa que los numeros no son iguales
        {
            iguales = false;
        }
    }

    for(int x = 0; x < 6; x++)  // si todas las variables del vector booleano estan en true, significa que efectivamente hay una escalera, al modificar el for se tiran puntajes ficticios y erroneos
    {
        if (vec_escalera[x] != true)
        {
            escalera = false;
        }
    }
    // luego devolveremos un numero que representa un caso especial para cada uno, 1 para escalera, 2 para iguales, 0 para sexteo, y 3 para simplmemente sumar puntaje
    if(escalera == true)
    {
        return 1;
    }
    else if(iguales == true)
    {
        if(primer_valor != 6) // verifica que no sea un sexteto de 6
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 3;
    }
}

string registrarJugador(int pos_vec, int n_jug)
{
    string nombre;
    string apellido;

    string i;

    i = char (205);
    if (pos_vec == 0) /// al modificar, el numero, el programa pide 2 veces el apellido y nunca el nombre
    {
        rlutil::locate(38, 7);
        cout <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i << endl;
        rlutil::locate(38, 8);
        cout << " INGRESE NOMBRE DEL JUGADOR " << n_jug << endl;
        rlutil::locate(38, 9);
        cout <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<< endl;
        rlutil::locate(38, 10);
        cin >> nombre;
        return nombre;
    }
    else
    {
        rlutil::locate(38, 12);
        cout <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i << endl;
        rlutil::locate(38, 13);
        cout << " INGRESE APELLIDO DEL JUGADOR "  << n_jug << endl;
        rlutil::locate(38, 14);
        cout <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i << endl;
        rlutil::locate(38, 15);
        cin >> apellido;
        system("cls"); /// al quitar este cls, luego de ingresar el nombre y apellido, cuando se pidan la cantidad de rondas, estos seguiran apareciendo
        return apellido;
    }
}

string mostrarDado(int cara, int linea)
{
    string v[3]; // array de lineas de caras del dado
    switch (cara)
    {
    case 1:                   /// al modificar cualquier valor de v[] en cualquier case, al momento de jugar el programa se rompe, y en caso de ser numeros entre el 0, 1 y 2, los dados se verian todos horribles
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

int tirarDados(bool prueba)
{
    int caso;
    int puntaje = 0;
    int i;
    int dado[6];
    if (prueba == true)
    {
        for(i=0; i<6; i++)
        {
            rlutil::locate(38, 8);
            cout << "Ingrese un numero del 1 al 6: " << i+1 << "/6";
            rlutil::locate(38, 9);
            cin >> dado[i];
            if (dado[i] < 1 || dado[i] > 6)
            {
                system("cls");
                rlutil::locate(38, 8);
                cout << "Vuelva a intentarlo. ";
                rlutil::locate(38, 9);
                cin >> dado[i];
            }
            system("cls");
        }
    }
    else
    {

        srand(time(NULL));
        for(i=0; i<6; i++)
        {
            dado[i]=(rand()%6)+1;
        }
        /// al quitar cualquier salto de linea, se desordenaria todo y quedaria horrible
    }
    rlutil::locate(30, 10);
    cout << "+-----+ +-----+ +-----+ +-----+ +-----+ +-----+" << endl;
    rlutil::locate(30, 11);
    cout << "|" << mostrarDado(dado[0], 0) << "| |" << mostrarDado(dado[1], 0) << "| |" << mostrarDado(dado[2], 0) << "| |" << mostrarDado(dado[3], 0) << "| |" << mostrarDado(dado[4], 0) << "| |" << mostrarDado(dado[5], 0) << "|" << endl;
    rlutil::locate(30, 12);
    cout << "|" << mostrarDado(dado[0], 1) << "| |" << mostrarDado(dado[1], 1) << "| |" << mostrarDado(dado[2], 1) << "| |" << mostrarDado(dado[3], 1) << "| |" << mostrarDado(dado[4], 1) << "| |" << mostrarDado(dado[5], 1) << "|" << endl;
    rlutil::locate(30, 13);
    cout << "|" << mostrarDado(dado[0], 2) << "| |" << mostrarDado(dado[1], 2) << "| |" << mostrarDado(dado[2], 2) << "| |" << mostrarDado(dado[3], 2) << "| |" << mostrarDado(dado[4], 2) << "| |" << mostrarDado(dado[5], 2) << "|" << endl;
    rlutil::locate(30, 14);
    cout << "+-----+ +-----+ +-----+ +-----+ +-----+ +-----+" << endl;


    caso = condiciones(dado);
    switch (caso)
    {
    case 1:
        puntaje = -1;
        rlutil::locate(30, 15);
        cout << "Escalera " << endl; // 1 para escalera
        rlutil::locate(30, 16);
        cout << "(" << puntaje << ")"<< endl;
        break;
    case 2:
        puntaje = dado[0]*10;
        rlutil::locate(30, 15);
        cout << "Sexteto " << endl; // 2 para iguales
        rlutil::locate(30, 16);
        cout << "(" << puntaje << ")"<< endl;
        break;
    case 3:
        for(i=0; i<6; i++) // 3 para simplmemente sumar puntaje
        {
            puntaje += dado[i];

        }
        rlutil::locate(30, 15);
        cout << "Suma de dados" <<endl; /// añadido para mejorar la estetica
        rlutil::locate(30, 16);
        cout << "(" << puntaje << ")"<< endl;
        break;
    case 0:
        puntaje = 0;
        rlutil::locate(30, 15);
        cout << "Ups, Sexteto de 6, se reiniciara tu puntaje! " << endl; // 0 para sexteo
        rlutil::locate(30, 16);
        cout << "(" << puntaje << ")"<< endl;
        break;
    }

    if (prueba == true)
    {
        rlutil::locate(30, 7);
        system("pause");
    }
    return puntaje;
}

string partida(int c_jug)
{
    string i;

    i = char(205);

    bool modo_2jug = false; // Por defecto se activa el modo un jugador
    string nom_jug[4]; // Crea un vector del doble de la cantidad de jugadores

    //Las variables de los nombres estan alternadas: (nombre1, nombre2, apellido1, apellido2), ya que se usa un mismo indice para todo el juego
    nom_jug[0] = registrarJugador(0, 1); // Pide el nombre del primer jugador
    nom_jug[2] = registrarJugador(1, 1); // Pide el apellido del primer jugador
    if (c_jug == 2) // Verifica la cantidad de jugadores, si son 2, activa el modo multi
    {
        nom_jug[1] = registrarJugador(0, 2); // Pide nombre del segundo jugador
        nom_jug[3] = registrarJugador(1, 2); // Pide nombre del segundo jugador
        modo_2jug = true;
    }

    int n_jug = 0; // Indice del jugador para alternar entre rondas
    int ronda = 1; // Cantidad de rondas
    int ronda_multi = 0; // Cantidad de rondas en multijugador
    int c_rondas_totales = 0; // Cantidad de rondas totales
    int ganador = 0; // Indice del vector de jugadores para el ganador, por defecto 0
    int perdedor; // Indice del vector de jugadores para el perdedor
    int puntaje = 0; // Puntaje obtenido en el lanzamiento
    int lanz_jug[2] = {1,1}; // Contador de lanzamientos para cada jugador (el jugador 1 empieza, por lo que comienza en 1)
    int lanz_jug_totales[2] = {0,0}; // Contador de lanzamientos totales para cada jugador, se usa para el desempate (el jugador 1 empieza, por lo que comienza en 1)
    int max_punt[2] = {0,0}; // Puntaje re donda del jugador 1 y 2, en case de estar en un jugador, queda la segunda posicion en 0
    int puntuacion_total[2] = {0,0}; // Puntutacion total entre ambos jugadores

    rlutil::locate(32, 7);
    cout <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<< endl;
    rlutil::locate(32, 8);
    cout << "INGRESE CANTIDAD DE RONDAS POR JUGADOR" << endl;
    rlutil::locate(32, 9);
    cout <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<< endl;
    rlutil::locate(32, 10);
    cin >> c_rondas_totales;
    if (c_rondas_totales < 1)
    {
        rlutil::locate(32, 12);
        cout << "Vuelva a ingresar." << endl;
        rlutil::locate(32, 13);
        cin >> c_rondas_totales;
    }

    system("cls");
    while (ronda <= c_rondas_totales)
    {
        for (lanz_jug[n_jug] = 1; lanz_jug[n_jug] <=3 ; lanz_jug[n_jug]++)
        {
            system("cls");

            rlutil::locate(30, 5);
            cout << "TURNO DE: " << nom_jug[n_jug] << " | RONDA N: " << ronda << "/" << c_rondas_totales << endl;
            rlutil::locate(30, 6);
            cout <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<< endl;
            rlutil::locate(30, 7);
            cout << "MAXIMO PUNTAJE DE LA RONDA: " << max_punt[n_jug] << endl;
            rlutil::locate(30, 8);
            cout << "LANZAMIENTO N: " << lanz_jug[n_jug] << "/3" << endl;
            rlutil::locate(30, 9);
            cout <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<< endl;

            puntaje = tirarDados(false); // Llama a la funcion de tirar dados

            if (puntaje > max_punt[n_jug])
            {
                max_punt[n_jug] = puntaje;
            }

            if (puntaje == 0)
            {
                puntuacion_total[n_jug] = 0; // Si los dados devuelven un cero, quiere decir que es un sexteto de 6, por lo que se resetea el puntaje
            }
            else if (puntaje == -1)
            {
                rlutil::locate(30, 16);
                cout << "GANASTE LA PARTIDA: " << nom_jug[n_jug] << endl;
                rlutil::locate(30, 17);
                system("pause");
                return nom_jug[n_jug];
            }
            else
            {
                puntuacion_total[n_jug] += puntaje;// Guarda el puntaje en el determinado jugador
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

            rlutil::locate(30, 17);
            cout <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<< endl;
            rlutil::locate(30, 18);
            cout << "PUNTAJE TOTAL: "<< puntuacion_total[n_jug] << " PUNTOS" << endl;
            rlutil::locate(30, 19);
            cout <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<< endl;
            rlutil::locate(30, 20);
            system("pause"); /// al quitar este pause, no se verian las tiradas y ademas se tirarian solas rapidamente
            system("cls"); /// al quitar este cls, se jugarian las rondas de seguidas, es decir no se mostraria el puntaje al finalizar cada ronda, ( solo en el modo 1 jugador )
        }
        max_punt[0] = 0; // reset del puntaje maximo
        max_punt[1] = 0;
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
                system("cls"); /// al quitar este cls, se jugarian las rondas de seguidas, es decir no se mostraria el puntaje al finalizar cada ronda, ( solo en el modo 1 jugador )
                rlutil::locate(30, 5);
                cout <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<< endl;

                rlutil::locate(30, 6);
                cout << "RONDA N: " << ronda+1 << endl;

                rlutil::locate(30, 7);
                cout << "SIGUIENTE TURNO: " << nom_jug[n_jug] << endl;

                rlutil::locate(30, 8);
                cout <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<< endl;
                rlutil::locate(30, 9);
                cout << "PUNTAJE " << nom_jug[0] << ": " << puntuacion_total[0] << endl;

                rlutil::locate(30, 10);
                cout << "PUNTAJE " << nom_jug[1] << ": " << puntuacion_total[1] << endl;

                rlutil::locate(30, 11);
                cout <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<< endl;

                rlutil::locate(30, 12);
                system("pause"); /// al quitar este pause en cualquier modo, se jugarian todas las rondas seguidas, sin llegar a mostrar ninguna pausa

            }

        }
        // FIN MODO MULTI
        else
        {
            ronda++;
        }

    }


    if (puntuacion_total[0] >= 100 && puntuacion_total[1] >= 100) // Si empatan
    {
        // Desempatar
        if (lanz_jug_totales[0] < lanz_jug_totales[1]) // Si el jugador 1 llego a 100 pts antes, pasa a ser el ganador
        {
            ganador = 0;

        }
        else   // Si no, es el ganador el jugador 2
        {
            ganador = 1;

        }
    }
    else if (puntuacion_total[0] < 100 && puntuacion_total[1] < 100) // si ninguno llega a los 100pts
    {
        if (puntuacion_total[0] > puntuacion_total[1])
        {
            ganador = 0;
        }
        else
        {
            ganador = 1;
        }

    }

    system("cls"); /// al quitar este cls, se jugarian todas las rondas de seguidas, sin pausas de por medio ( solo en modo de 1 jugador )
    rlutil::locate(30, 5);
    cout << "RONDAS TOTALES: " << ronda-1 << endl;
    rlutil::locate(30, 6);
    cout <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<< endl;
    //
    rlutil::locate(30, 7);
    cout << "GANADOR: " << nom_jug[ganador] << " " << nom_jug[ganador+2] << " | PUNTUACION: " << puntuacion_total[ganador] << "/100" << endl;
    rlutil::locate(30, 8);
    cout << "LANZAMIENTOS: " << lanz_jug_totales[ganador] << endl;
    rlutil::locate(30, 9);
    cout <<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<< endl;
    rlutil::locate(30, 10);
    system("pause");
    return nom_jug[ganador];

}



#endif // FUNCIONES_H_INCLUDED
