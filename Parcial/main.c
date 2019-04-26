#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Pantalla.h"
#include "Publicidad.h"
#include "Utn_String.h"
#define Nombre_LEN 20

int main()
{

    Pantalla arrayPantalla[30];
    pantalla_inicializar(arrayPantalla,30);
    int idPantalla=1;
    int opcion;
    do
    {
    scanf(getNumber(&opcion,"Ingrese opción a realizar:\n 1 para dar de alta\n2 para modificar\n3 para dar de baja\4 para contratar publicidad","Error",1,4,3));

    switch(opcion){
        case 1:
            pantalla_alta(arrayPantalla,30);
            break;
        case 2:
            pantalla_modificar
    }
    }while(1>0);
    /*
    int auxTipo=0;
    getValidInt("ingrese el precio en dolares\n","error\n",&auxTipo,1,3000,2);
    printf("%d",auxTipo);
    */

    return 0;
}
