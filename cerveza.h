#ifndef CERVEZA_H_INCLUDED
#define CERVEZA_H_INCLUDED

const char *cervezaText = "ArchivoCreveza.dat";

class Cerveza{

    private:

        int idCerveza;

        char nombreCerveza[50];

        int cantidadDeBotellas;

        float importeUnitario;

    public:

        Cerveza(int ,const char * , int ,float);

        void cargarCerveza();
        void mostrarCerveza();

        void setIdCerveza(int idC){idCerveza = idC;}
        int getIdCerveza(){return idCerveza;}

        void setNombreCerveza(const char *nom){strcpy(nombreCerveza,nom);}
        const char *getNombreCerveza(){return nombreCerveza;}


        void setCantidadDeBotellas(int cantB){cantidadDeBotellas = cantB;}
        int getCantidadDeBotellas(){return cantidadDeBotellas;}

        void setImporte(float import){importeUnitario  = import;}
        float getImporte(){return importeUnitario;}

        bool leerDiscoCerveza(int);
        bool grabarDiscoCerveza();
        void listarDiscoCerveza();
        bool modificarCompraCerveza();
};

Cerveza :: Cerveza(int id = 0 ,const char *nom ="000", int cant = 0  ,float impo = 0){

    idCerveza = id;
    strcpy(nombreCerveza,nom);
    cantidadDeBotellas = cant;
    importeUnitario = impo;
}


void Cerveza :: cargarCerveza(){

    fflush(stdin);

    cout << "INGRSE NOMBRE DE CERVEZA:"; cin.getline(nombreCerveza,50,'\n');

    cout << "INGRSE  LA CANTIDAD DE BOTELLAS:"; cin >> cantidadDeBotellas;

    cout << "INGRESE EL IMPORTE: "; cin >> importeUnitario;

}

void Cerveza :: mostrarCerveza(){

    cout << "ID CERVEZA:" << idCerveza << endl;

    cout << "NOMBRE DE CERVEZA:" << nombreCerveza << endl;

    cout << "CANTIDAD DE BOTELLAS:" << cantidadDeBotellas << endl;

    cout << "PRECIO: " << importeUnitario << "$" << endl;
}


bool Cerveza :: leerDiscoCerveza(int pos){

    FILE *punCerveza;

    punCerveza = fopen(cervezaText,"rb");

    if(punCerveza  == NULL) return false;

    fseek(punCerveza , pos*sizeof(Cerveza),0);

    fread(this,sizeof(Cerveza),1,punCerveza);

    return true;



    fclose(punCerveza);
}

#include "funcioncerveza.h"

/// GRABAR CERVEZA ///


bool Cerveza :: grabarDiscoCerveza(){

    FILE *punCerveza;

    punCerveza = fopen(cervezaText,"ab");

    if(punCerveza == NULL) return false;

    cout << "NUMERO DE ID OTORGADO:" << autoIdCerveza() << endl;

    setIdCerveza(autoIdCerveza());

    cargarCerveza();

    fwrite(this,sizeof(Cerveza),1,punCerveza);

    fclose(punCerveza);

    return true;

    }



/// LISTAR CERVEZA ///

void  Cerveza :: listarDiscoCerveza(){

    int cantidad = contarCerveza();

    if(cantidad < 0) cout << "SIN  REGISTROS EN LA BASE DE DATOS" << endl;

    for(int  i = 0; i < cantidad; i++){

        leerDiscoCerveza(i);

        mostrarCerveza();

        cout << endl;

    }


}

bool Cerveza :: modificarCompraCerveza(){

    int id,pos , _tipoCer ,_cantidad, _impotU;

    FILE *punCerveza;

    punCerveza = fopen(cervezaText,"rb+");

    if(punCerveza == NULL) return false;

    cout << "INGRSE EL ID QUE QUIERE MODIFICAR: "; cin >> id;

    pos = buscarIdcerveza(id);

    if(pos < 0) {cout << "NO SE ENCONTRO NINGUN CLIENTE REGISTRADO" << endl; return false;}

    Cerveza cer = leerCerveza(pos);

    cout << "INGRESE CANTIDAD DE BOTELLAS:" ;  cin >> _cantidad;

    cout << "INGRESE EL IMPORTE: "; cin >> _impotU;


    cer.setCantidadDeBotellas(_cantidad);

    cer.setImporte(_impotU);

    fseek(punCerveza,pos*sizeof(Cerveza),0);

    fwrite(&cer,sizeof(Cerveza),1,punCerveza);

    fclose(punCerveza);

    return true;
}

#endif // CERVEZA_H_INCLUDED
