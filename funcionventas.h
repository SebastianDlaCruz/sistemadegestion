#ifndef FUNCIONVENTAS_H_INCLUDED
#define FUNCIONVENTAS_H_INCLUDED

Ventas leerVentas(int pos){

    Ventas ven;

    FILE *punVentas;

    punVentas = fopen(ventasText,"rb");

    if(punVentas == NULL) return -1;

    fseek(punVentas,pos*sizeof(Ventas),0);

    fread(&ven,sizeof(Ventas),1,punVentas);

    fclose(punVentas);

    return ven;

}

int buscarVenta(int id){

    Ventas ven;

    int pos = 0 , numCli = 0;

    FILE *punVentas;

    punVentas = fopen(ventasText,"rb");

    while(ven.leerDiscoVentas(pos++)){

        if(ven.getidCliente() == id){

            ven.mostrarVentas();

            cout << endl;

            return numCli;

            fclose(punVentas);
        }

        numCli++;
    }

    return -1;
}




int contarVentas(){

    int resultado , tam;

    FILE *punVentas;

    punVentas = fopen(ventasText,"rb");

    if(punVentas == NULL) return -2;

    fseek(punVentas,0,2);

    tam  = ftell(punVentas);

    fclose(punVentas);

    resultado = tam / sizeof(Ventas);

    return resultado;

}


bool bienvenidaCliente(int id){

    Cliente cli;

    int pos = 0;

    while(cli.leerDiscoCliente(pos++)){


        if(cli.getIdCliente() == id){

            cout << "===============================================================" << endl;

            cout << "BIENVENIDO " << cli.getNombreCliente()  << "  " << cli.getApellido() << endl;

            cout << "===============================================================" << endl;

            return true;
        }

    }

    return false;
}

bool corroborarIdCerveza(int idCer){

        Cerveza cer;

        int pos = 0;

        while(cer.leerDiscoCerveza(pos++)){

            if(cer.getIdCerveza() == idCer){

                return true;
            }

        }

     return false;
}



const char *buscarNombre(int id){

    Cliente cli;

    int pos = 0;


    while(cli.leerDiscoCliente(pos++)){

        if(cli.getIdCliente() == id){

            return cli.getNombreCliente();
        }

    }

    return "00000";
}

const char *buscarApellido(int id){

    Cliente cli;

    int pos = 0;

    while(cli.leerDiscoCliente(pos++)){

        if(cli.getIdCliente() == id){

            return cli.getApellido();
        }

    }

    return "0000";
}

float calcularMonto(int idCer,int cantidad){

    Cerveza cer;

    int pos = 0;

    float monto;

    while(cer.leerDiscoCerveza(pos++)){

        if(cer.getIdCerveza() == idCer){

           monto =  cer.getImporte() * cantidad ;

            cout << "TOTAL APAGAR:"  << monto << endl;

           return monto;

        }

    }

    return -1;
}

float evaluarImporte(int monto){

    float importe,calcular;

    cout << "INGRESE EL IMPORTE:"; cin >> importe;

    if(importe >= monto ){

         calcular =  importe - monto ;

        cout << "TU VUELTO ES DE : " << calcular <<  endl;

        return importe;

    }
    else{

        calcular = monto - importe;

        cout << "IMPORTE INSUFICIENTE TE FALTA " << calcular << endl;

        return 0;

    }

}





#endif // FUNCIONVENTAS_H_INCLUDED
