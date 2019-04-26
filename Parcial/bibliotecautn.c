#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

int getString(  char *pResultado,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos)

{
    int retorno = -1;
    char bufferStr[4096];

    while(reintentos>0)
    {
        printf(msg);
        __fpurge(stdin);
        fgets(bufferStr,sizeof(bufferStr),stdin);
        bufferStr[strlen(bufferStr)-1] = '\0';
        int bufferStrLength=strlen(bufferStr);
        if( pResultado != NULL &&
            reintentos >= 0 &&
            bufferStrLength>=minimo &&
            bufferStrLength<=maximo)
        {
            retorno = 0;
            strncpy(pResultado, bufferStr, sizeof(pResultado));
            break;
        } else
        {
            printf(msgError);
            reintentos--;
        }
        reintentos--;
    }
    return retorno;

}

int isValidIntNumber (char* cadena)
{
    int cadenaLength=strlen(cadena);
    int i=0;
    int retorno=1;
    if (cadena[i]=='-')
    {
        i++;
    }
    for (; i<cadenaLength; i++)
    {
        if( !(cadena[i]>='0' && cadena[i]<='9'))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int getNumber(  int *resultado,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos)
{
    int retorno = -1;
    char bufferStr[4096];
    int bufferInt;

    if( resultado != NULL &&
        reintentos >= 0) //FALTAN
    {
        if(!getString(bufferStr,msg,msgError,1,6,1) &&
            isValidIntNumber(bufferStr))
        {
            bufferInt = atoi(bufferStr);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                retorno = 0;
                *resultado = bufferInt;
            }else
            {
                printf(msgError);
            }
        }else
        {
            printf(msgError);
        }
    }
    //printf("%d",*resultado);
    return retorno;
}

int buscarLugarLibre (  char array[][20],
                        int *pIndex,
                        int len)
{
    int i;
    int retorno=-1;
    for(i=0;i<len;i++)
    {
        if(array[i][0]=='\0')
        {
            *pIndex=i;
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int buscarNombre (  char *pNombre,
                    char array[][20],
                    int len,
                    int *pIndex)
{
    int i;
    int retorno=-1;
    for(i=0;i<len;i++)
    {
        if(strcmp(pNombre, array[i])==0)
        {
            *pIndex=i;
            retorno = 0;
            break;
        }
    }
    return retorno;
}

