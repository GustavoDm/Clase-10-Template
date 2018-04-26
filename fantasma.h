#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED

typedef struct{

char nombre[50];
int idFantasma;
int isEmpty;

}EFantasma;

int fantasma_init(EFantasma *array, int size);
int fantasma_alta(EFantasma *array, int size);
int fantasma_baja(EFantasma *array, int size, int ID);
int fantasma_modificacion(EFantasma *array, int size, int ID);
int fantasma_ordenar(EFantasma *array, int size, int orden);
int buscarLugarLibre(EFantasma *array, int size);
int proximoId();
int fantasma_mostrar(EFantasma *array, int size);
#endif // FANTASMA_H_INCLUDED
