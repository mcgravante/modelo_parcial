#ifndef BIBLIOTECAUTN_H_INCLUDED
#define BIBLIOTECAUTN_H_INCLUDED

int getString(  char *pResultado,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos);

int getNumber(  int *resultado,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos);

int isValidNumber (char* cadena);

int buscarLugarLibre (  char array[][20],
                        int *pIndex,
                        int len);

int buscarNombre (  char *pNombre,
                    char array[][20],
                    int len,
                    int *pIndex);

#endif // BIBLIOTECAUTN_H_INCLUDED
