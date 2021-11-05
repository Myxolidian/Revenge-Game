#include <iostream>
#include <istream>
#include <string>
#include <ctime>
#include <conio.h>

#include "rlutil.h"

using namespace std;
using namespace rlutil;

void mostrarMenu(void);

void mostrarCreditos(void);

bool confirmacion(void);

bool establecerPrimerJugador(char j1[], int sizej1, char j2[], int size);

int main()
{

    setlocale(LC_ALL, "Spanish");

    srand(time(NULL));

    int opcion;
    bool salir = false;   
    char jugador1[50] = {};
    char jugador2[50] = {};

    do
    {

    // Se ejecuta funcion de mostrar men�
    mostrarMenu();

    cout << "Bienvenido! Seleccion� la opcion deseada: ";
    cin >> opcion;

    switch (opcion)
    {
    //Opcion Jugar
    case 1:

        system("cls");
        //Pedir Nombres
        cout << "Jugador uno, ingres� tu nombre: ";
        cin >> jugador1;

        cout << "Jugador dos, ingres� tu nombre: ";
        cin >> jugador2;

        system("cls");

        cout << "Comienza el juego! Se determinar� que jugador tira primero. El jugador que tire el dado mas alto empieza tirando." << endl << endl;

        // Se ejecuta funcion de establecer primer jugador
        if (establecerPrimerJugador(jugador1, 50, jugador2, 50) == true)
        {
            cout << jugador1 << " sac� el n�mero mas alto! Comienza tirando." << endl;
            anykey();
        }
        else
        {
            cout << jugador2 << " sac� el n�mero mas alto! Comienza tirando." << endl;
            anykey();
        }

        break;
    case 2:
        break;
    case 3:
        mostrarCreditos();
        break;
    case 0:
        salir = confirmacion();
    default:
        break;
    }
    
    //      Tirada primer jugador
    //          Lanzar 2 dados 12 caras
    //          Calcular numero objetivo
    //          Lanzar dados stock (6 caras)
    //          Elegir suma seleccionada
    //          Tirada Exitosa
    //      Tirada segundo jugador
    //          Lanzar dados stock (6 caras)
    //      
    //      
    //      
    //  Opcion Estadist�cas
    //  Opcion Salir
    //marie
     
    
    } while (salir == false);

    return 0;
}

void mostrarMenu(void)
{
    system("cls");

    cout << "\t- Revenge -" << endl;
    cout << "---------------------------" << endl;
    cout << "1 - Jugar" << endl;
    cout << "2 - Estad�sticas" << endl;
    cout << "3 - Cr�ditos" << endl;
    cout << "---------------------------" << endl;
    cout << "0 - Salir" << endl << endl;
}

void mostrarCreditos(void)
{
    system("cls");

    cout << "\t\t-- Cr�ditos --" << endl << endl;
    cout << "            Desarollado por SkyNet" << endl;
    cout << "    para la Universidad Tecnol�gica Nacional (FRGP)" << endl << endl;
    cout << "Marianella Gottig - Legajo: 25508" <<endl;
    cout << "Maria Jose Illanes Saldivia - Legajo: 24512" << endl;
    cout << "Emiliano Ram�rez - Legajo: 25583" << endl << endl;

    cout << "Presion� cualquier tecla para volver al men� principal." << endl;
    system("Pause>nul");

}

bool confirmacion(void)
{
    char conf;
    
    cout << endl << "\t�Desea salir del juego?" << endl;
    cout << "\t   S -- Si | N -- No" << endl;
    cin >> conf;

    conf = toupper(conf);

    if (conf == 'S')
    {
        return true;
    }
    else
        if(conf == 'N')
    
        {
            return false;
        }
}

bool establecerPrimerJugador(char j1[], int sizej1, char j2[], int sizej2)
{
    int dadocomienzo1;
    int dadocomienzo2;
    bool reroll = false;

    do {

        cout << j1 << " presion� Enter para tirar tu dado." << endl;
        system("Pause>nul");

        dadocomienzo1 = 1 + rand() % 6;

        cout << "Salio el: " << dadocomienzo1 << endl << endl;

        cout << j2 << " presion� Enter para tirar tu dado." << endl;
        system("Pause>nul");

        dadocomienzo2 = 1 + rand() % 6;

        cout << "Salio el: " << dadocomienzo2 << endl << endl;

        if (dadocomienzo1 == dadocomienzo2)
        {
            cout << "Empate. Tiremos de nuevo." << endl;
            reroll = true;
        }
        else
        {
            reroll = false;
        }

    } while (reroll == true);

    if (dadocomienzo1 > dadocomienzo2)
    {
        return true;
    }
    else
    {
        return false;
    }

}