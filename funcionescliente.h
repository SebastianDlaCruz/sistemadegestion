#ifndef FUNCIONESCLIENTE_H_INCLUDED
#define FUNCIONESCLIENTE_H_INCLUDED



int contarCliente(){

    int resultado , tam;

    FILE *punCliente;

    punCliente = fopen(clienteText,"rb");

    if(punCliente == NULL) return -2;

    fseek(punCliente,0,2);

    tam  = ftell(punCliente);

    fclose(punCliente);

    resultado = tam / sizeof(Cliente);

    return resultado;

}


int buscarIdCliente(int id){

    FILE *punCliente;

    int pos = 0 , cont = 0;

    Cliente cli;

    punCliente = fopen(clienteText,"rb");

    if(punCliente == NULL) return -1;

    while(cli.leerDiscoCliente(pos++)){

        if(cli.getIdCliente() == id){

            cout << " ID ENCONTRADO " << endl;

            cli.mostrarCliente();

            cout << endl;

             return cont;

            fclose(punCliente);




        }

        cont++;

    }

    return -2;
}


Cliente leerCliente(int pos){

    FILE *punCliente;

    Cliente cli;

    punCliente = fopen(clienteText,"rb");

    if(punCliente == NULL) return -1;

    fseek(punCliente,pos*sizeof(Cliente),0);

    fread(&cli,sizeof(Cliente),1,punCliente);

    fclose(punCliente);

    return cli;
}

void cambiarDatos(int pos){

    Cliente cli;

    int _telefono , dato;

    char _nombre[50];

    char  _apellido[50];

    char  _email[100];

    FILE *punCliente;

    punCliente = fopen(clienteText,"rb+");

    if(punCliente == NULL) cout << "ERROR" << endl;


    cli = leerCliente(pos);

    cout << "1) NOMBRE"  << endl;

    cout << "2) APELLIDO" << endl;

    cout  << "3) TELEFONO" << endl;

    cout << "4) EMAIL" << endl;


    cout << "QUE DATO QUIERE ACTUALIZA:"; cin >> dato;

    switch(dato){

    case 1:

                 fflush(stdin);


                cout << "INGRESE EL NUEVO NOMBRE: "; cin.getline(_nombre,50,'\n');

                cli.setNombreCliente(_nombre);

        break;

    case 2:

                fflush(stdin);


                cout << "INGRSE EL NUEVO APELLIDO: "; cin.getline(_apellido,50,'\n');

                cli.setApellido(_apellido);

        break;


    case 3:

            cout << "INGRESE EL NUEVO NUMERO DE TELEFONO: "; cin >> _telefono;

            cli.setTelefono(_telefono);

        break;


    case 4:

            fflush(stdin);


            cout << "INGRESE EL NUEVO EMAIL:";  cin.getline(_email,50,'\n');

            cli.setEmail(_email);

        break;

    default:

                cout << "OPCION INCORRECTA" << endl;

        break;

    }

    fseek(punCliente,pos*sizeof(Cliente),0);

    fwrite(&cli,sizeof(Cliente),1,punCliente);

    fclose(punCliente);

}


int autoIdCliente(){

    FILE *punCliente;

    Cliente cli;

    punCliente = fopen(clienteText,"rb");

    if(punCliente == NULL) return -1;

    fseek(punCliente,0,2);

    int  id =   ftell(punCliente) / sizeof(Cliente);

    id++;

    fclose(punCliente);

    return id;

}

void validarEmailCLiente(char *vec,int tam ){

    char *arroba = nullptr;

    char *punto = nullptr;

    for(int i = 0; i < tam; i++){

        arroba  = strstr(vec, "@");

        if(arroba != nullptr){break;}

    }

    for(int i = 0; i < tam;i++){

        punto   =  strstr(vec, ".");

        if(punto!= nullptr ){break;}
    }

    if(arroba == nullptr){


        cout << "EMAIL IMVALIDO POR FALTA DE '@'\n"; exit(1);
    }


    if(punto == nullptr){

             cout << "EMAIL IMVALIDO POR FALTA DE '.' \n"; exit(1);



        }




}

#endif // FUNCIONESCLIENTE_H_INCLUDED
