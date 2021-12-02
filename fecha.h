#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{

    private:

        int dia;

        int mes;

        int anio;

    public:

        Fecha(int,int,int);

        void cargarFecha();
        void mostrarFecha();

        void setDia(int _dia) {

        if((dia >= 1)  && (dia <= 31)) {dia  = _dia;}

        else{cout << "DIA INCORRECTO" << endl;}}
        int getDia(){return dia;}

        void setMes(int _mes){

        if((mes >= 1)  && (mes <= 12)) {mes = _mes;}

        else{cout << "MES INCORRECTO" << endl;}}
        int getMes(){return mes;}

        void setAnio(int _anio){

        if((anio >= 2021)  && (anio <= 2026)) {anio = _anio;}

        else{cout << "ANIO INCORRECTO" << endl;}}
        int getAnio(){return anio;}
};


const char *ms[12] = {"ENERO","FEBRERO","MARZO","ABRIL","MAYO","JUNIO","JULIO","AGOSTO","SEPTIEMBRE","OCTUBRE","NOMBRIEMBRE","DICIEMBRE"};

Fecha :: Fecha(int d = 0 , int m = 0, int a = 0){

    dia = d;
    mes = m;
    anio = a;

}

const char *imprimirMes(const char **mes , int tam ,int num){

       const  char *me;
        for (int i = 0; i < tam; i++){

                if( i == num - 1){

                    me = mes[i];

                    return me;
                }

        }

    return  "000";
}

void Fecha :: cargarFecha(){

    cout << "IMPORTANTE LA FECHA DEBE TENER UN VALOR LOGICO DE LO CONTRARIO EL PROGRAMA SE CERRARA. " << endl;

    cout << "ESTE PROGRAMA ACEPTA COMO FECHA DE INICIO EL ANIO 2021 HASTA 2026 ." << endl;

    cout << "INGRESE DIA: "; cin >> dia;

    if((dia >= 1)  && (dia <= 31)) {setDia(dia);}

    else{cout << "DIA INCORRECTO" << endl;}

    cout << "INGRESE MES: "; cin >> mes;

    if((mes >= 1)  && (mes <= 12)) {setMes(mes);}

    else{cout << "MES INCORRECTO" << endl;}

    cout << "INGRESE ANIO: "; cin >> anio;

    if((anio >= 2021)  && (anio <= 2026)) {setAnio(anio);}

    else{cout << "ANIO INCORRECTO" << endl;}

}

void Fecha :: mostrarFecha(){

    cout << "FECHA" << endl;

    const char *MesFch;


   MesFch = imprimirMes(ms,12,mes);

    cout << dia << " / " << MesFch << " / " << anio  << endl;
}



#endif // FECHA_H_INCLUDED
