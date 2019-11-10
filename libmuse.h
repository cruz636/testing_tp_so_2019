#ifndef LIBMUSE_H
#define LIBMUSE_H



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

#define ERROR -1

//los siguientes datos los sacamos del archivo config.CFG
#define tamanio_bloque_grande 1024
#define cantidad_paginas 8
#define tamanio_paginas 32
#define tamanio_segmento 32

/*Estructuras*/

typedef struct
{
  int numero_pagina;
  int bit_modif;
  int bit_presen;
  int bit_uso;
  //?? bitmap;

  /* Utiles?
  int tamanio_pagina;
  int tamanio_disponible;
  int tamanio_usado; */

}Pagina;


typedef struct
{
  uint32_t n_segmento;
  uint32_t *p_direccion;
  Pagina tabla_paginas[8]; //array de cantidad definida

}Segmento;


typedef struct{
  uint32_t *p_memoriaPrincipal;
  uint32_t *bytes_disponibles;
  int segmentos_disponibles;
} Memoria_Principal;


typedef​ ​struct​ {
  uint32_t size;
  Bool​ isFree;
}​HeapMetadata​ ;



/*Fin de estructuras*/



uint32_t *muse_alloc(int tam);
void muse_free(uint32_t *dir);
int muse_get(void* dst, uint32_t src, size_t n);
uint32_t cargar_segmento(int marco,int numero_segmento,Memoria_Principal *MP);
//void reasignar_tamanio_segmento(int numero_segmento); -> a desarrollar


#endif
