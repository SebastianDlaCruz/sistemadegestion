#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

const char * clienteText  = "ArchivoCLiente.dat";

class Cliente{

    private:

        int idCliente;

        char nombreCliente[50];

        char apellidoCliente[50];

        Fecha fechaCliente;

        char email[100];

        int telefono;

        bool estado;

    public:

        Cliente(int, const char *,const char *,const char * ,int,bool);

        void cargarCliente();
        void mostrarCliente();

        void setIdCliente(int idCli){idCliente = idCli;}
        int getIdCliente(){return idCliente;}

        void setNombreCliente(const char *nomC){strcpy(nombreCliente,nomC);}
        const char *getNombreCliente(){return nombreCliente;}

        void setApellido(const char * apell) {strcpy(apellidoCliente,apell);}
        const char *getApellido(){return apellidoCliente;}

        void setFechaCliente(int dia,int mes,int anio){

        fechaCliente.setDia(dia),
        fechaCliente.setMes(mes),
        fechaCliente.setAnio(anio);

        }

        Fecha getFechaCliente(){return fechaCliente;}

        void setEmail(const char *ema){strcpy(email,ema);}
        const char* getEmail(){return email;}

        void setTelefono(int telef){telefono = telef;}
        int getTelefono(){return telefono;}

        void setEstado(bool esta) {estado = esta;}
        bool getEstado(){return estado;}

        bool leerDiscoCliente(int);
        bool crearArchivoCliente();
        void listarArchivoCliente();
        bool modificarCliente();
        bool darDeBajaCliente();
};

Cliente :: Cliente(int idCli = 0 , const char *nom = "0000" ,const char *ape = "0000"  ,const char *ema = "0000", int tele =  0, bool esta = false){

    idCliente = idCli;
    strcpy(nombreCliente,nom);
    strcpy(apellidoCliente,ape);
    strcpy(email,ema);
    telefono = tele;
    estado = esta;
}

bool Cliente :: leerDiscoCliente(int pos){

    FILE *punCliente;

    punCliente = fopen(clienteText,"rb");

    if(punCliente == NULL) return false;

    fseek(punCliente, pos*sizeof(Cliente),0);

    fread(this,sizeof(Cliente),1,punCliente);

    return true;

}


#include "funcionescliente.h"

void Cliente :: cargarCliente(){

     fflush(stdin);

    cout << "INGRESE NOMBRE: "; cin.getline(nombreCliente,50,'\n');

     fflush(stdin);

    cout << "INGRESE APELLIDO: "; cin.getline(apellidoCliente,50,'\n');

    fechaCliente.cargarFecha();

     fflush(stdin);

    cout << "INGRESE EMAIL: "; cin.getline(email,50,'\n');

    validarEmailCLiente(email,50);

     fflush(stdin);

    cout << "INGRESE TELEFONO: "; cin >> telefono;

    estado = true;

}

void Cliente :: mostrarCliente(){

    if(estado){

        cout << "ID CLIENTE: " << idCliente << endl;

        cout << "NOMBRE: " << nombreCliente << endl;

        cout << "APELLIDO: " << apellidoCliente << endl;

        fechaCliente.mostrarFecha();

        cout << "EMAIL: " << email << endl;

        cout << "TELEFONO: " << telefono << endl;

    }

}




/// CREAR ARCHIVO ///

bool Cliente :: crearArchivoCliente(){


    FILE *punCliente;

    punCliente = fopen(clienteText,"ab");

    if(punCliente == NULL) return false;

    cout << "NUMERO DE ID OTORGADO:" << autoIdCliente() << endl;

    setIdCliente(autoIdCliente());

    cargarCliente();

    fwrite(this,sizeof(Cliente),1,punCliente);

    fclose(punCliente);

    return true;
}

/// LISTAR ARCHIVO ///

void Cliente :: listarArchivoCliente(){

    int cantidad = contarCliente();

    if(cantidad < 0) cout << "SIN  REGISTROS EN LA BASE DE DATOS" << endl;

    for(int  i = 0; i < cantidad; i++){

        leerDiscoCliente(i);

        mostrarCliente();

        cout << endl;

    }

}


/// MODIFICAR ARCHIVO ///

bool Cliente :: modificarCliente(){

    int id,pos;

    cout << "INGRSE EL ID QUE QUIERE MODIFICAR: "; cin >> id;

    pos = buscarIdCliente(id);

    cout << pos << endl;
    if(pos < 0) {cout << "NO SE ENCONTRO NINGUN CLIENTE REGISTRADO" << endl; return false; }

    else{

        cambiarDatos(pos);

        return true;
    }


}

/// DAR DE BAJA CLIENTE ///

bool Cliente ::  darDeBajaCliente(){

    FILE *punCliente;

    punCliente = fopen(clienteText,"rb+");

    if(punCliente == NULL) return false;

    int _id, _pos;

    cout << "INGRESE EL ID QUE ESTA  QUIERA DA DE BAJA :"; cin >> _id;

    _pos = buscarIdCliente(_id);

    if(_pos < 0) cout << " NO SE ENCUENTRO NINGU REGISTRO QUE ESTE ID" << endl; return false;

    Cliente cli;

    cli = leerCliente(_pos);

    cli.setEstado(false);

    fseek(punCliente,_pos*sizeof(Cliente),0);

    fwrite(&cli,sizeof(Cliente),1,punCliente);

    fclose(punCliente);

    return true;
}

#endif // CLIENTE_H_INCLUDED
