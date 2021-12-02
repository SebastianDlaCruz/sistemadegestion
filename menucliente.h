#ifndef MENUCLIENTE_H_INCLUDED
#define MENUCLIENTE_H_INCLUDED

void menuCliente(){

    int opcion ;

    bool salir = true ;

    Cliente cli;

        setColor(2);
    do{

        gotoxy(45,3);
        cout << "*** MENU CLIENTE ***" << endl;
        gotoxy(45,5);

        cout << "1) ALTA DE CLIENTE" << endl;
        gotoxy(45,6);
        cout << "2) LISTAR CLIENTE" << endl;

        gotoxy(45,7);
        cout << "3) MODIFICAR CLIENTE" << endl;
        gotoxy(45,8);
        cout << "4) DAR DE BAJA CLIENTE" << endl;

        gotoxy(45,9);

        cout << "0) SALIR" << endl;

        gotoxy(45,10);
        cout << "INGRESE UNA OPCION:"; cin >> opcion;


        system("cls");

        switch(opcion){

        case 1:

                   if(!cli.crearArchivoCliente()) cout << "ERROR" << endl;

                    system("pause");
                    system("cls");


            break;

        case 2:

                    cli.listarArchivoCliente();


                    system("pause");
                    system("cls");
            break;

        case 3:

                    if(!cli.modificarCliente()) cout << "ERROR" << endl;



                    system("pause");
                    system("cls");
            break;


        case 4:


                  if(!cli.darDeBajaCliente()) cout << "ERROR" << endl;



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

#endif // MENUCLIENTE_H_INCLUDED
