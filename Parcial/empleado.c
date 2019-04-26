#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bibliotecautn.h"
#include "utn.h"
#include "empleado.h"


int empleado_darDeAlta( Empleado *pArrayEmpleados,
                        int limite)
{
return 0;
}

int empleado_inicializarArray( Empleado *pArrayEmpleados,
                                int limite)
{
    int retorno = -1;
    int i;
    if (pArrayEmpleados!=NULL && limite>=0)
    {
        for (i=0;i<limite;i++)
        {
            pArrayEmpleados[i].isEmpty=1;
        }
        retorno = 0;
    }
    return retorno;
}

int empleado_buscarLugarLibre(  Empleado *pArrayEmpleados,
                                int limite)
{
    int i;
    int retorno=-1;

    if (pArrayEmpleados!=NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(pArrayEmpleados[i].isEmpty==1)
            {
                retorno=i;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int empleado_printDebugArray(   Empleado *pArrayEmpleados,
                                int limite)
{
    int retorno = -1;
    int i;
    if (pArrayEmpleados!=NULL && limite>=0)
    {
        for (i=0;i<limite;i++)
        {
        printf("\nID:%d - NOMBRE:%s", pArrayEmpleados[i].idEmpleado, pArrayEmpleados[i].nombre);
        retorno = 0;
        }
    }
    return retorno;
}
