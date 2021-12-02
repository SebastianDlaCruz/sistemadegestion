#ifndef MENUVENTAS_H_INCLUDED
#define MENUVENTAS_H_INCLUDED


void menuVentas(){

    int opcion ;

    bool salir = true ;

    Ventas ven;


        setColor(9);

    do{

            gotoxy(45,3);

        cout << "*** MENU MENU VENTAS ***" << endl;

           gotoxy(45,5);
        cout << "1) HACER UNA VENTAN" << endl;

        gotoxy(45,6);
        cout << "2) LISTAR VENTAS " << endl;
        gotoxy(45,7);

        cout << "0) SALIR" << endl;
        gotoxy(45,8);
        cout << "INGRESE UNA OPCION:"; cin >> opcion;


        system("cls");



        switch(opcion){

        case 1:

                   if(!ven.grabarDiscoVentas())cout << "ERROR" << endl;
                    system("pause");
                    system("cls");


            break;



        case 2:

                         ven.listarDiscoVentas();


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


}



#endif // MENUVENTAS_H_INCLUDED
