#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "rluti.h"

using namespace std;
using namespace rlutil;
#include "fecha.h"
#include "cliente.h"
#include "menucliente.h"
#include "cerveza.h"
#include "menucerveza.h"
#include "ventas.h"
#include "menuventas.h"

int main(){

    int opcion ;
    bool salir = true ;

  /*  for(int i = 0; i < 12; i ++){

            setColor(i);
            cout <<  i<< endl;

        }*/

        setColor(6);

    do{
        gotoxy(45,3);
        cout << "*** MENU PRINCIPAL CERVEZAS ARTESENALES ***" << endl;

        gotoxy(45,5);
        cout << "1) CLIENTES" << endl;
        gotoxy(45,6);

        cout << "2) CERVEZAS"<< endl;
        gotoxy(45,7);
        cout << "3) VENTAS" << endl;
        gotoxy(45,8);

        cout << "0) SALIR" << endl;
        gotoxy(45,10);
        cout << "INGRESE UNA OPCION:"; cin >> opcion;


        system("cls");

        switch(opcion){

        case 1:
                    menuCliente();

                    system("pause");
                    system("cls");

            break;

        case 2:


                    menuCerveza();


                    system("pause");
                    system("cls");



            break;

        case 3:


                    menuVentas();

                    system("pause");
                    system("cls");


            break;


        case 0:

                salir = false;

            break;

        default:

            cout << "NO ES UNA OPCION VALIDA" << endl;

            break;

        }


    }while(salir);


    return 0;
}
