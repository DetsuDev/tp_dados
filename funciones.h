#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int condiciones(int vec[])
{
    bool vec_escalera[6] = {false}; // crearemos un vector booleano con todas las variables en falso
    bool escalera = true; // asumiremos que el caso de la escalera es true hasta que se diga lo contrario

    int primer_valor; // variable para almacenar el primer valor del vector de los dados
    bool iguales = true; // asumimos tambien que todos los numeros son iguales hasta que se diga lo contrario

    for(int i = 0; i < 6; i++)
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

    for(int x = 0; x < 6; x++)  // si todas las variables del vector booleano estan en true, significa que efectivamente hay una escalera
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
        if(primer_valor != 6)
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
    if (pos_vec == 0)
    {
        cout << "+------------------------------+" << endl;
        cout << "| INGRESE NOMBRE DEL JUGADOR " << n_jug << " |" << endl;
        cout << "+------------------------------+" << endl;
        cin >> nombre;
        return nombre;
    }
    else
    {
        cout << "+--------------------------------+" << endl;
        cout << "| INGRESE APELLIDO DEL JUGADOR "  << n_jug << " |" << endl;
        cout << "+--------------------------------+" << endl;
        cin >> apellido;
        system("cls");
        return apellido;
    }
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
            cout << "Ingrese un numero: ";
            cin >> dado[i];
        }
    }
    else
    {

        srand(time(NULL));
        for(i=0; i<6; i++)
        {
            dado[i]=(rand()%6)+1;
            //puntaje += dado[i];

        }

    }
    cout << "+-----+ +-----+ +-----+ +-----+ +-----+ +-----+" << endl;
    cout << "|" << mostrarDado(dado[0], 0) << "| |" << mostrarDado(dado[1], 0) << "| |" << mostrarDado(dado[2], 0) << "| |" << mostrarDado(dado[3], 0) << "| |" << mostrarDado(dado[4], 0) << "| |" << mostrarDado(dado[5], 0) << "|" << endl;
    cout << "|" << mostrarDado(dado[0], 1) << "| |" << mostrarDado(dado[1], 1) << "| |" << mostrarDado(dado[2], 1) << "| |" << mostrarDado(dado[3], 1) << "| |" << mostrarDado(dado[4], 1) << "| |" << mostrarDado(dado[5], 1) << "|" << endl;
    cout << "|" << mostrarDado(dado[0], 2) << "| |" << mostrarDado(dado[1], 2) << "| |" << mostrarDado(dado[2], 2) << "| |" << mostrarDado(dado[3], 2) << "| |" << mostrarDado(dado[4], 2) << "| |" << mostrarDado(dado[5], 2) << "|" << endl;
    cout << "+-----+ +-----+ +-----+ +-----+ +-----+ +-----+" << endl;


    caso = condiciones(dado);
    switch (caso)
    {
    case 1:
        puntaje = 100;
        cout << "Escalera" << endl; // 1 para escalera
        cout << "(" << puntaje << ")"<< endl;
        break;
    case 2:
        puntaje = dado[0]*10;
        cout << "Sexteto" << endl; // 2 para iguales
        cout << "(" << puntaje << ")"<< endl;
        break;
    case 3:
        for(i=0; i<6; i++) // 3 para simplmemente sumar puntaje
        {
            puntaje += dado[i];

        }
        cout << "(" << puntaje << ")"<< endl;
        break;
    case 0:
        puntaje = 0;
        cout << "Sexteto 6" << endl; // 0 para sexteo
        cout << "(" << puntaje << ")"<< endl;
        break;
    }

    if (prueba == true)
    {
        system("pause");
    }
    return puntaje;
}

bool partida(int c_jug)
{
    bool modo_2jug = false; // Por defecto se activa el modo un jugador
    string nom_jug[4]; // Crea un vector del doble de la cantidad de jugadores
    int min_rondas = 1; // Minimo de rondas

    //Las variables de los nombres estan alternadas: (nombre1, nombre2, apellido1, apellido2), ya que se usa un mismo indice para todo el juego
    nom_jug[0] = registrarJugador(0, 1); // Pide el nombre del primer jugador
    nom_jug[2] = registrarJugador(1, 1); // Pide el apellido del primer jugador
    if (c_jug == 2) // Verifica la cantidad de jugadores, si son 2, activa el modo multi
    {
        nom_jug[1] = registrarJugador(0, 2); // Pide nombre del segundo jugador
        nom_jug[3] = registrarJugador(1, 2); // Pide nombre del segundo jugador
        min_rondas = 2;
        modo_2jug = true;
    }

    bool en_partida = true; // Inicia la partida
    bool empate = false; // Verifica la situacion de empate
    int n_jug = 0; // Indice del jugador para alternar entre rondas
    int ronda = 1; // Cantidad de rondas
    int ronda_multi = 0; // Cantidad de rondas en multijugador
    int c_rondas_totales = 0; // Cantidad de rondas totales
    int ganador = 0; // Indice del vector de jugadores para el ganador, por defecto 0
    int perdedor; // Indice del vector de jugadores para el perdedor
    int puntaje = 0; // Puntaje obtenido en el lanzamiento
    int lanz_jug[2] = {1,1}; // Contador de lanzamientos para cada jugador (el jugador 1 empieza, por lo que comienza en 1)
    int lanz_jug_totales[2] = {1,0}; // Contador de lanzamientos totales para cada jugador, se usa para el desempate (el jugador 1 empieza, por lo que comienza en 1)
    int max_puntaje[2] = {0,0}; // Puntaje maximo del jugador 1 y 2, en case de estar en un jugador, queda la segunda posicion en 0
    int puntuacion_total[2] = {0,0}; // Puntutacion total entre ambos jugadores

    cout << "-----------------------------------------------" << endl;
    cout << "INGRESE CANTIDAD DE RONDAS (min " << min_rondas << "): " << endl;
    cout << "-----------------------------------------------" << endl;
    cin >> c_rondas_totales;
    if (c_rondas_totales < min_rondas)
    {
        cout << "Vuelva a ingresar." << endl;
        cin >> c_rondas_totales;
    }

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

            puntaje = tirarDados(false); // Llama a la funcion de tirar dados

            if (puntaje == 0)
            {
                puntuacion_total[n_jug] = 0; // Reseta el puntaje a 0 sin es un sexteto de 6
            }
            else
            {
                puntuacion_total[n_jug] += puntaje; // Guarda el puntaje en el determinado jugador
            }



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
        cout << "GANADOR: " << nom_jug[ganador] << " " << nom_jug[ganador+2] << " | PUNTUACION: " << puntuacion_total[ganador] << "/100" << endl;
        cout << "LANZAMIENTOS: " << lanz_jug_totales[ganador] << endl;
        cout << "-----------------------------------------------" << endl;

    }
    else
    {
        cout << "PERDEDOR: " << nom_jug[0] << " " << nom_jug[2] << " | PUNTUACION: " << puntuacion_total[0] << "/100" << endl;
        cout << "LANZAMIENTOS: " << lanz_jug_totales[0] << endl;
        cout << "-----------------------------------------------" << endl;
    }
    system("pause");
    en_partida = false;
    return en_partida;
}

#endif // FUNCIONES_H_INCLUDED
