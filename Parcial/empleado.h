#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

    typedef struct
    {
        int idEmpleado;
        int isEmpty;
        char nombre[50];
        char apellido[50];
    }Empleado;

    int empleado_darDeAlta( Empleado *pArrayEmpleados,
                            int limite);

    int empleado_darDeBaja( Empleado *pArrayEmpleados,
                            int limite);

    int empleado_modificar( Empleado *pArrayEmpleados,
                            int limite);

    int empleado_ordenarNombre( Empleado *pArrayEmpleados,
                                int limite);

    int empleado_inicializarArray(  Empleado *pArrayEmpleados,
                                    int limite);

    int empleado_printDebugArray(   Empleado *pArrayEmpleados,
                                    int limite);

    int empleado_buscarLugarLibre(  Empleado *pArrayEmpleados,
                                    int limite);

#endif // EMPLEADO_H_INCLUDED
