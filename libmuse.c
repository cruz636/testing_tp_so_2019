/*
1- definimos estructuras.
2- iniciamos muse.
*/

#include "libmuse.h"


int muse_init() //falta el id,el puerto y la ip como parametros
{
  //iniciar bloque grande de memoria
  Memoria_Principal *MP;
  MP = muse_alloc(sizeof(Memoria_Principal)); //guarda struct de MP en un puntero
  MP->p_memoriaPrincipal = MP;
  MP->bytes_disponibles = muse_alloc(tamanio_bloque_grande);
  MP->segmentos_disponibles = tamanio_bloque_grande / tamanio_paginas;

  //printf("La direccion de la Memoria Principal es %p\n",MP->p_memoriaPrincipal );


  //cargamos un segmento a la Memoria_Principal


  uint32_t tabla_paginas[MP->segmentos_disponibles];
  //estamos usando un array de direcciones
  //podriamos usar un array de segmentos, no se que seria  mas tutorial
  // Segmento tabla_paginas[MP->segmentos_disponibles];
  // Segmento *cargar_segmento(int marco, ... , ... , ...);

  int marco,numero_segmento;
  printf("Ingrese el numero de marco donde quiere cargar el segmento-> " );
  scanf("%d",&marco );
  printf("Ingrese el numero del segmento a cargar -> " );
  scanf("%d",&numero_segmento );
  printf("Cargando segmento %d en el marco %d\n",numero_segmento,marco );

  tabla_paginas[marco] = cargar_segmento(marco,numero_segmento,MP); //@MP podria ser directamente la direccion de MP
  //tabla_paginas[marco] = cargar_segmento(marco,segmento,numero_segmento,MP);

  if(tabla_paginas[marco] == NULL)
  {
    printf("Error al cargar el segmento \n");
  }
  else
  {
    printf("Segmento cargado de forma correcta en la tabla de paginas\n" );
  }



  //liberamos segmento y puntero del segmentos_disponibles
 //  muse_free(segmento->p_direccion);
  //muse_free(segmento);

  //muse_free(tabla_paginas);


 //liberamos memoria Principal y el puntero que guarda la struct de Memoria_Principal
  muse_free(MP->bytes_disponibles);
  muse_free(MP);


  return 0;
}


uint32_t cargar_segmento(int marco,int numero_segmento,Memoria_Principal *MP)
{
  Segmento *segmento;
  segmento = muse_alloc(sizeof(Segmento)); //guarda struct de segmento en un puntero
  segmento->n_segmento = numero_segmento;
  segmento->p_direccion = (MP->bytes_disponibles) + (tamanio_segmento * segmento->n_segmento); // se multiplica por el numero de segmento y obtenemos el marco
  printf("La direccion del segmento %d es %p\n",segmento->n_segmento,segmento->p_direccion);

  return segmento->p_direccion;
}


/*void muse_close()
{
  printf("Cerrando biblioteca\n");
  //cerrar biblioteca
}*/

uint32_t *muse_alloc(int tam)
{
  //reservamos direccion de memoria de tamanio tam
  int *p_bloque= malloc(tam);

  if(NULL==p_bloque)
  {
    printf("Error al asignar la memoria. \n" );
    return 0;
  }
  else
  {
    printf("La memoria se asigno de forma correcta. %u // %p \n",p_bloque,p_bloque);
    return p_bloque;
  }


}


 void muse_free(uint32_t *dir)
 {
   printf("Liberando bloque de memoria.. %u %p\n",dir,dir);
   free(dir);
 }



//* Copia una cantidad `n` de bytes desde una posición de memoria de MUSE a una `dst` local.
 int muse_get(void* dst, uint32_t src, size_t n)
 {
   /**
      * @param dst Posición de memoria local con tamaño suficiente para almacenar `n` bytes.
      * @param src Posición de memoria de MUSE de donde leer los `n` bytes.
      * @param n Cantidad de bytes a copiar.
      * @return Si pasa un error, retorna -1. Si la operación se realizó correctamente, retorna 0.
      */


      // controlar que el tamanio de destino sea suficiente
      if(strlen(dst)<strlen(src))
      {
        printf("Tamanio insuficiente\n");
        return ERROR;
      }
      else{
        printf("Tamanio suficiente\n");
      }

/*      printf("Direccion donde se copiara el contenido: %p\n",dst);
      printf("Puntero desde donde se lee: %p\n",src);
      printf("Cantidad de bytes a leer: %d",n);
*/
      //copiamos @dst en @src
      strcpy(dst,src);

      //comparamos que se hayan copiado :
      if(strcmp(dst,src)==0)
      {
        return 1;
      }
      else
      {
        return ERROR;
      }

 }



 int main(){
   muse_init();



   return 0;
 }
