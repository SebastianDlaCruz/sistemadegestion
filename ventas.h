#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

const char *ventasText = "ArchvoVentas.dat";

class Ventas{

    private:

        int idCliente;

        int idCerveza;

        char nombreCliente[50];

        char apellidoCliente[50];

        int cantidad;

        Fecha fechasDeVentas;

        float importe;

        bool estado;

    public:

    Ventas(int,int,const char *,const char *,int,float,bool);

    void cargarVentas();
    void mostrarVentas();

    void setidCliente(int idC){idCliente = idC;}
    int getidCliente(){return idCliente;}

    void setNombreDelCliente(const char *nomC){strcpy(nombreCliente,nomC);}
    const char *getNombreDelCliente(){return nombreCliente;}

    void setApellido(const char *ape){strcpy(apellidoCliente,ape);}
    const char *getApellido(){return apellidoCliente;}

    void setidCerveza(int idCer){idCerveza = idCer;}
    int getidCerveza(){return idCerveza;}

    void setCantidad(int ca){cantidad =  ca;}
    int getCantidad(){return cantidad;}

    void setFechaDeVentas(int d, int m, int a){

    fechasDeVentas.setDia(d);
    fechasDeVentas.setMes(m);
    fechasDeVentas.setAnio(a);

    }

    Fecha getFechaDeVentas(){return fechasDeVentas;}

    void setIporte(float impor){ importe = impor;}
    float getIporte(){return importe;}

    void setEstado(bool esta ){ estado = esta;}
    bool getEstado(){return estado;}

    bool leerDiscoVentas(int);
    bool grabarDiscoVentas();
    void listarDiscoVentas();
};

Ventas :: Ventas(int idCl = 0,int idCer = 0,const char *nom ="0000",const char *ape ="000000",int cant = 0, float impor = 0, bool esta = false){

    idCliente = idCl;
    idCerveza = idCer;
    strcpy(nombreCliente,nom);
    strcpy(nombreCliente,ape);
    cantidad = cant;
    importe = impor;
    estado = esta;
}

bool Ventas :: leerDiscoVentas(int pos){

    FILE *punVentas;

    punVentas = fopen(ventasText,"rb");

    if(punVentas == NULL) return false;

    fseek(punVentas, pos*sizeof(Ventas),0);

    fread(this,sizeof(Ventas),1,punVentas);

    return true;


}



#include "funcionventas.h"

void Ventas :: cargarVentas(){


    cout << "INGRSE ID CERVEZA:"; cin >> idCerveza;

    if(!corroborarIdCerveza(idCerveza)) {cout << "ID INCORRECTO" << endl ;}

    else{

       fechasDeVentas.cargarFecha();

        cout << "INGRESE CANTIDAD:"; cin >> cantidad;

        estado = true;
    }


}

void Ventas :: mostrarVentas(){

    if(estado){

    cout << "ID CLIENTE:" << idCliente << endl;

    cout << "ID CERVEZA:" << idCerveza << endl;

    cout << "NOMBRE DEL CLIENTE:" << nombreCliente << endl;

    cout << "APELLIDO:" << apellidoCliente << endl;

    fechasDeVentas.mostrarFecha();

    cout << "CANTIDAD DE BOTELLAS:" << cantidad << endl;

    cout << "IMPORTE :" <<  importe << endl;


    }


}



/// GRABAR DISCO VENTAS ///


bool Ventas ::grabarDiscoVentas(){

    Cerveza cer;

    int _idCliente;

    float monto = 0,importeV ;

    FILE *punVentas;

    punVentas = fopen(ventasText,"ab");

    if(punVentas == NULL) return false;

    cout << "INGRESE ID DE CLIENTE PARA CONFIRMAR LA COMPRA:"; cin >> _idCliente;

    if(!bienvenidaCliente(_idCliente)) return false;

    cer.listarDiscoCerveza();

    this -> setidCliente(_idCliente);

    this -> setNombreDelCliente(buscarNombre(this -> getidCliente()));

    this -> setApellido(buscarApellido(this -> getidCliente()));

    cargarVentas();

   monto = calcularMonto(this -> getidCerveza(),this -> getCantidad()) ;

    importeV = evaluarImporte(monto);

    if(importeV == 0) return false;

    this -> setIporte(importeV);

    fwrite(this,sizeof(Ventas),1,punVentas);

    fclose(punVentas);

    return true;
}


/// LISTASR VENTAS ///


void Ventas :: listarDiscoVentas(){

    int cantidad = contarVentas();

    for(int i = 0; i < cantidad; i++){

        this -> leerDiscoVentas(i);

        this -> mostrarVentas();

        cout << endl;


    }

}

#endif // VENTAS_H_INCLUDED
