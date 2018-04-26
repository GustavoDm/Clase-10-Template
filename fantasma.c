#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fantasma.h"
#include "utn.h"


/** \brief Inicializa isEmpty dentro de la estructura
 *
 * \param array EFantasma*
 * \param size int
 * \return int
 *
 */
int fantasma_init(EFantasma *array, int size)
{
    int i;
    int retorno=-1;
    if(size>0&& array !=NULL)
    {
        for(i=0; i<size; i++)
        {
            array[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}


/** \brief busca un lugar libre despues de haber inicializado isEmpty
 *
 * \param array EFantasma*
 * \param size int
 * \return int
 *
 */
int buscarLugarLibre(EFantasma *array, int size)
{
    int i;
    int retorno;
    if(size>0&&array !=NULL)
    {
        for(i=0; i<size; i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno =i;
            }
        }
    }
    return retorno;

}
int fantasma_alta(EFantasma *array, int size)
{

    int retorno=-1;
    int i;
    char buffer[50];

    if(size>0 && array !=NULL)
    {
        i=buscarLugarLibre(array, size);
        if(i>0)
        {
            if(!getValidString("Nombre: \n", "\n Error", "\nError, el maximo de caracteres es de 40", buffer, 40, 2))
            {

                strcpy(array[i].nombre,buffer);
                array[i].isEmpty=0;
                array[i].idFantasma=proximoId();
                retorno=0;
            }
            else
            {
                retorno =-3;
            }
        }
        else
        {
            retorno=-2;
        }
    }
    return retorno;
}

int fantasma_baja(EFantasma *array, int size, int ID)
{

    int i;
    int retorno=-1;

    if(size>0&&array!=NULL)
    {

        for(i=0; i<size; i++)
        {
            if(!array[i].isEmpty && array[i].idFantasma==ID)
            {

                array[i].isEmpty=1;
                retorno=0;
            }
        }
    }
    return retorno;
}
int fantasma_modificacion(EFantasma *array, int size, int ID)
{

    int retorno=-1;
    int i;
    char buffer[50];

    if(size>0 && array !=NULL)
    {
        for(i=0; i<size; i++)
        {
            if(!array[i].isEmpty && array[i].idFantasma==ID)
            {
                if(!getValidString("Nombre: \n", "\n Error", "\nError, el maximo de caracteres es de 40", buffer, 40, 2))
                {

                    strcpy(array[i].nombre,buffer);
                    retorno=0;
                }
                else
                {
                    retorno =-3;
                }
            }
            else
            {
                retorno=-2;
            }
        }
    }
    return retorno;
}
int fantasma_mostrar(EFantasma *array, int size)
{

    int retorno=-1;
    int i;
    if(size>0 && array!=NULL)
    {
        for(i=0; i<size; i++)
        {
            printf("[DEGUB] - %d %s %d", array[i].idFantasma, array[i].nombre, array[i].isEmpty);
            retorno=0;
        }
    }
    return retorno;

}


int fantasma_ordenar(EFantasma *array, int size, int orden)
{
    int i;
    int retorno =-1;
    int flagSwap;
    EFantasma auxiliarEstructura;

    if(size>0&&array!=NULL)
    {

        do
        {
            flagSwap=0;
            for(i=0; i<size; i++)
            {
                if((strcmp(array[i].nombre, array[i+1].nombre)>0 && orden) || (strcmp(array[i].nombre, array[i+1].nombre) <0&& !orden))
                {

                    auxiliarEstructura = array[i];
                    array[i]=array[i+1];
                    array[i+1]=auxiliarEstructura;
                    flagSwap=1;

                }
            }
            retorno=0;
        }
        while(flagSwap);
    }
    return retorno;
}

int proximoId()
{

    static int proximoId=-1;
    proximoId++;
    return proximoId;
}
