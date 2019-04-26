#include <stdio.h>
#include <stdlib.h>

void pruebita(void)
{
printf("hola mundo desde utn.c\n");
}

int utn_getNumber(  int *puntero,
                    int max,
                    int min,
                    int reintentos,
                    char* msg,
                    char* msgError)
{
    int aux;
    int retorno=-1;
    while(reintentos>0){
        printf("%s",msg);
        if (scanf("%d",&aux)==1)
        {
            if (aux>=min && aux<=max)
            {
                retorno=0;
                break;
            }
        }
        else {
            printf("%s",msgError);
            reintentos--;
        }
    };
    *puntero=aux;
    return retorno;
}

int utn_getArrayInt (   int *pArrayResultados,
                        int limite,
                        char *mensaje,
                        char *mensajeError,
                        int maximo,
                        int minimo,
                        int reintentos)
{
    int i;
    int buffer;
    int ret=0;
    for (i=0; i<limite;i++){
        ret=utn_getNumber(&buffer, maximo,minimo, reintentos, mensaje, mensajeError);
        if (ret==-1){
            break;
        }
        pArrayResultados[i]=buffer;
    }
    return ret;
}

int utn_calcularPromedio(   int *pArrayInt,
                            int limite,
                            float *pResultado)
{
    int i;
    int acumulador=0;
    for (i=0; i<limite; i++) {
        acumulador=acumulador + pArrayInt[i];
    }
    *pResultado=(float)acumulador/limite;
    return 0;
}

int utn_ordenarArrayMenorMayor( int*pArrayParaOrdenar,
                                int limite)
{
    int flagSwap;
    int i;
    int buffer;
    do{
        flagSwap=0;
        for(i=0;i<limite-1;i++){
            if(pArrayParaOrdenar[i]>pArrayParaOrdenar[i+1]){
                buffer=pArrayParaOrdenar[i+1];
                pArrayParaOrdenar[i+1]=pArrayParaOrdenar[i];
                pArrayParaOrdenar[i]=buffer;
                flagSwap=1;
            }
        }
    }
    while (flagSwap == 1);
    return 0;
}

int utn_ordenarArrayMayorMenor( int*pArrayParaOrdenar,
                                int limite)
{
    int flagSwap;
    int i;
    int buffer;
    do{
        flagSwap=0;
        for(i=0;i<limite-1;i++){
            if(pArrayParaOrdenar[i]<pArrayParaOrdenar[i+1]){
                buffer=pArrayParaOrdenar[i+1];
                pArrayParaOrdenar[i+1]=pArrayParaOrdenar[i];
                pArrayParaOrdenar[i]=buffer;
                flagSwap=1;
            }
        }
    }
    while (flagSwap == 1);
    return 0;
}

int utn_getMaximo(  int *pArrayInt,
                    int limite,
                    int *pMaximo)
{
    int i;
    int maximo=pArrayInt[0];
    for (i=0; i<limite; i++) {
        if (pArrayInt[i]>maximo){
            maximo=pArrayInt[i];
        }
    }
    *pMaximo=maximo;
    return 0;
}

int utn_getMinimo(  int *pArrayInt,
                    int limite,
                    int *pMinimo)
{
    int i;
    int minimo=pArrayInt[0];
    for (i=0; i<limite; i++) {
        if (pArrayInt[i]<minimo){
        minimo=pArrayInt[i];
        }
    }
    *pMinimo=minimo;
    return 0;
}

int utn_encontrarNumero (   int *pArrayInt,
                            int limite,
                            int max,
                            int min,
                            int reintentos,
                            char* msg,
                            char* msgError)
{
    int i;
    int numeroABuscar;
    utn_getNumber(&numeroABuscar, max, min, reintentos, msg, msgError);
    for (i=0; i<limite; i++) {
        if (pArrayInt[i]==numeroABuscar){
            printf("Se encontró el número %d", numeroABuscar);
            return 0;
        }
    }
    printf("No se encontró el número %d", numeroABuscar);
    return -1;
}


