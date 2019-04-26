#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Pantalla.h"
#include "Publicidad.h"
#include "Utn_String.h"
#define Nombre_LEN 20

static int generarId(void);

static int generarId(void){
static int idPantalla=0;
return idPantalla++;
}

int pantalla_inicializar(Pantalla *arrayPantalla,int len)
{
    int i;
    int ret=-1;
    if(arrayPantalla != NULL && len >= 0)
    {
        for(i=0;i<len;i++)
        {
            arrayPantalla[i].isEmpty=1;
            ret=0;
        }
    }
    return ret;
}
int pantalla_lugarLibre(Pantalla *arrayPantalla,int len,int *lugarLibre)
{
    int i;
    int ret=-1;
    if(arrayPantalla != NULL && len >= 0)
    {
        for(i=0; i<len ; i++)
        {
            if(arrayPantalla[i].isEmpty==1)
            {
                *lugarLibre = i;
                ret=0;
                break;
            }
        }
    }
    return ret;
}

int pantalla_alta(Pantalla *arrayPantalla,int len)
{
    int ret=-1;
    int lugarLibre;
    int auxTipo;
    int auxPrecio;
    char auxNombre[Nombre_LEN];
    char auxDireccion[Nombre_LEN];

    if(arrayPantalla != NULL && len >= 0)
    {
        if(pantalla_lugarLibre(arrayPantalla,30,&lugarLibre)==0)
        {
            if(getString(auxNombre,"Ingrese un nombre: \n", "ERROR!\n", 1, Nombre_LEN, 2)==0)
            {
                strncpy(arrayPantalla[lugarLibre].nombre,auxNombre,Nombre_LEN);
            }
            if(getString(auxDireccion,"Ingrese direccion: \n", "ERROR!\n", 1, Nombre_LEN, 2)==0)
            {
                strncpy(arrayPantalla[lugarLibre].direccion,auxDireccion,Nombre_LEN);
            }
            if(getValidInt("ingrese 1 para led normal 2 para led gigante\n","error\n",&auxTipo,1,2,2)==0)
            {
                arrayPantalla[lugarLibre].tipo=auxTipo;
            }
            if(getValidInt("ingrese el precio en dolares\n","error\n",&auxPrecio,1,30000,2)==0)
            {
                arrayPantalla[lugarLibre].precio=auxPrecio;
            }
            arrayPantalla[lugarLibre].idPantalla=generarId();

            printf(" %d\n %s\n %s\n %d\n %d\n", arrayPantalla[lugarLibre].idPantalla,
                                                arrayPantalla[lugarLibre].nombre,
                                                arrayPantalla[lugarLibre].direccion,
                                                arrayPantalla[lugarLibre].tipo,
                                                arrayPantalla[lugarLibre].precio);
            arrayPantalla[lugarLibre].isEmpty=0;
            ret=0;
        }

    }
    return ret;
}

int pantalla_baja(Pantalla *arrayPantalla,int len)
{
    int ret=-1;
    int idPantalla;

    if(arrayPantalla != NULL && len >= 0)
    {
        if(getValidInt("Ingrese el legajo a ser borrado","error",&idPantalla,0,30,2)!=0)
        {
            printf("el legajo debe ser numerico\n");
        }
        if(arrayPantalla[idPantalla].isEmpty==1)
        {
            printf("esa posicion esta vacia\n");
        }
        else
        {
            arrayPantalla[idPantalla].isEmpty=1;
            ret=0;
        }
    }
    return ret;
}

int buscarPorId(Pantalla *arrayPantalla,int len,int *posicionDeLaCoincidencia,int idPantalla){
    int ret=-1;
    int idPantalla;
    if(arrayPantalla != NULL && len >= 0)
        {
            for(i=0;i<len;i++)
            {
                if(arrayPantalla[i].idPantalla==idPantalla)
                {
                    *posicionDeLaCoincidencia=i;
                    ret=0;
                    break;
                }
            }
    }
    return ret;
}

int pantalla_modificar(Pantalla *arrayPantalla,int len)
{
    int ret=-1;
    int idPantalla;
    int i;
    int posicionDeLaCoincidencia=0;
    int ready=0;
    int opcion;

    if(arrayPantalla != NULL && len >= 0)
    {
        getNumber(&idPantalla,"Ingrese el id a ser borrado","error",1,9999,3)

       if(buscarPorId(&arrayPantalla,len,&posicionDeLaCoincidencia,&idPantalla)!=0)
        {
            printf("no se encontraron coincidencias\n");
        }
        else
        {
            while(ready!=1)
            {
                scanf(getNumber(&opcion,"Ingrese valor a modificar:\n 1 para nombre\n2 para direccion\n3 para tipo\4 para precio\5 para salir","Error",1,5,3));

                switch(opcion){
                    case 1:
                        getString(*arrayPantalla[posicionDeLaCoincidencia].nombre,"Nuevo valor para nombre:","Error",1,Nombre_LEN,3);
                        break;
                    case 2:
                        getString(*arrayPantalla[posicionDeLaCoincidencia].direccion,"Nuevo valor para direccion:","Error",1,Nombre_LEN,3);
                        break;
                    case 3:
                        getNumber(*arrayPantalla[posicionDeLaCoincidencia].tipo,"Nuevo valor para tipo:","Error",1,2,3);
                        break;
                    case 4:
                        getNumber(*arrayPantalla[posicionDeLaCoincidencia].precio,"Nuevo valor para precio:","Error",1,999,3);
                        break;
                    case 5:
                        ready
                        break;
                }

        }
    }
    return ret;
}



