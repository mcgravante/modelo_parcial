#ifndef UTN_STRING_H_INCLUDED
#define UTN_STRING_H_INCLUDED

//int utn_getString(char* pResultado,char* msg,char* msgError,int minimo,int maximo,int reintentos);

//a partir de esta funcion puedo crear muchas otras de validacion
int isValidIntNumber(char* cadena);
int validarLetra (char letras[]);
int getNumber(int *pResult,char *pMsg,char *pMsgError,int min,int max,int attempts);
int getString(char *pResult, char *pMsg, char *pMsgError, int min, int max, int intentos);
int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps);
void choreadoGetString(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int esNumerico(char str[]);
#endif // UTN_STRING_H_INCLUDED
