#ifndef MENUCERVEZA_H_INCLUDED
#define MENUCERVEZA_H_INCLUDED

void menuCerveza(){

     int opcion ;

    bool salir = true ;

    Cerveza cer;

    setColor(10);

    do{

                    gotoxy(45,3);


        cout << "*** MENU CERVEZA ***" << endl;

                    gotoxy(45,5);
        cout << "1) CARGAR  CERVEZA" << endl;

                    gotoxy(45,6);


        cout << "2) LISTAR CERVEZA" << endl;

                    gotoxy(45,7);


        cout << "3) MODIFICAR PRODUCTO" << endl;

                    gotoxy(45,8);

        cout << "0) SALIR" << endl;

                    gotoxy(45,9);


        cout << "INGRESE UNA OPCION:"; cin >> opcion;


        system("cls");

        switch(opcion){

        case 1:


                    if(!cer.grabarDiscoCerveza()) cout << "ERROR" << endl;

                    system("pause");
                    system("cls");

            break;

        case 2:

                    cer.listarDiscoCerveza();


                    system("pause");
                    system("cls");

            break;

        case 3:

                    if(!cer.modificarCompraCerveza()) cout << "ERROR" << endl;


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

#endif // MENUCERVEZA_H_INCLUDED
