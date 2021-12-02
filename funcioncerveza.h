#ifndef FUNCIONCERVEZA_H_INCLUDED
#define FUNCIONCERVEZA_H_INCLUDED

int autoIdCerveza(){

     FILE *punCerveza;

    Cerveza cer;

    punCerveza = fopen(cervezaText,"rb");

    if(punCerveza == NULL) return -1;

    fseek(punCerveza,0,2);

    int  id =   ftell(punCerveza) / sizeof(Cerveza);

    id++;

    fclose(punCerveza);

    return id;

}


int contarCerveza(){

    int resultado , tam;

    FILE *punCerveza;

    punCerveza = fopen(cervezaText,"rb");

    if(punCerveza == NULL) return -2;

    fseek(punCerveza,0,2);

    tam  = ftell(punCerveza);

    fclose(punCerveza);

    resultado = tam / sizeof(Cerveza);

    return resultado;

}


int  buscarIdcerveza(int id){

     FILE *punCerveza;

    int pos = 0 , cont = 0;

    Cerveza cer;

    punCerveza = fopen(cervezaText,"rb");

    if(punCerveza == NULL) return -1;

    while(cer.leerDiscoCerveza(pos++)){

        if(cer.getIdCerveza() == id){

            cout << " ID ENCONTRADO " << endl;

            cer.mostrarCerveza();

            cout << endl;

             return cont;

            fclose(punCerveza);

        }

        cont++;

    }

    return -2;


}


Cerveza leerCerveza(int pos){

    FILE *punCerveza;

    Cerveza cer;

    punCerveza = fopen(cervezaText,"rb");

    if(punCerveza == NULL) return -1;

    fseek(punCerveza,pos*sizeof(Cerveza),0);

    fread(&cer,sizeof(Cerveza),1,punCerveza);

    fclose(punCerveza);

    return cer;
}



#endif // FUNCIONCERVEZA_H_INCLUDED
