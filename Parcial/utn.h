#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
void pruebita(void);

int utn_getNumber(  int *puntero,
                    int maximo,
                    int minimo,
                    int reintentos,
                    char* msg,
                    char* msgError);

int utn_getArrayInt (   int *pArrayResultados,
                        int limite,
                        char *mensaje,
                        char *mensajeError,
                        int maximo,
                        int minimo,
                        int reintentos);

int utn_calcularPromedio(   int *pArrayInt,
                            int limite,
                            float *pResultado);

int utn_ordenarArrayMenorMayor( int*pArrayParaOrdenar,
                                int limite);

int utn_ordenarArrayMayorMenor( int*pArrayParaOrdenar,
                                int limite);

int utn_getMaximo(  int *pArrayInt,
                    int limite,
                    int *pMaximo);

int utn_getMinimo(  int *pArrayInt,
                    int limite,
                    int *pMinimo);

int utn_encontrarNumero (   int *pArrayInt,
                            int limite,
                            int maximo,
                            int minimo,
                            int reintentos,
                            char* msg,
                            char* msgError);
#endif // UTN_H_INCLUDED
