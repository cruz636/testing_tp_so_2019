#ifndef LIBMUSE_H
#define LIBMUSE_H

//f.t = for test

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/types.h>
#include <unistd.h>

#define ERROR -1
#define META_SIZE sizeof(Block_meta)

//los siguientes datos los sacamos del archivo config.CFG
#define tamaño_MP 512
#define tamaño_segmento 128
#define tamaño_pagina 16
#define cantidad_segmentos (tamaño_MP/tamaño_segmento)
#define cantidad_paginas (tamaño_segmento/tamaño_pagina)



/*Estructuras*/



typedef struct{
  uint32_t *p_memoriaPrincipal;
  uint32_t *p_inicio_mp;
  Segmento tabla_segmentos[cantidad_segmentos];
} Memoria_Principal;



typedef struct
{
  HeapMetadata heap;
  uint32_t *p_inicio_segmento;
  Pagina tabla_paginas[cantidad_paginas];

}Segmento;

typedef struct
{
  HeapMetadata heap;
  Pagina *next_pagina;
  //?? bitmap;

  /* Utiles?
  int tamanio_pagina;
  int tamanio_disponible;
  int tamanio_usado; */

}Pagina;


typedef​ ​struct​ {
  uint32_t index;
  uint32_t size;
  Bool​ isFree;
}​HeapMetadata​ ;

/*
typedef struct
{
  size_t size;
  Block_meta *next;
  int free; //Bool isFree ?
} Block_meta;

*/

/*Fin de estructuras*/
//--------------------------------

//Variables globales

void *global_base = NULL;

//Fin de variables globales
//-------------------------

//FUNCIONES

uint32_t *muse_alloc(int tam);
void muse_free(uint32_t *dir);
int muse_get(void* dst, uint32_t src, size_t n);
uint32_t cargar_segmento(int marco,int numero_segmento,Memoria_Principal *MP);
//void reasignar_tamanio_segmento(int numero_segmento); -> a desarrollar


 /*nuevas funciones:

uint32_t *muse_alloc(int tam);
void muse_free(uint32_t *dir);
void *realloc(void *ptr,size_t size);
void *calloc(size_t nelem,size_t elsize);
Block_meta *get_block_ptr(void *ptr);
Block_meta *find_free_block(struct block_meta **last,size_t size);
Block_meta *request_space(struct block_meta* last, size_t size);

//fin de nuevas funciones
*/

//FIN DE FUNCIONES

#endif
