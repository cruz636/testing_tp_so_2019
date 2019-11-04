#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
prueba de paginacion segmentada
*/

#define tamanio 1024
//#define tamanio_paginas 32


typedef struct
{
  int numero_segmento;
  int tamanio_segmento;
  int tamanio_paginas;
  float cantidad_paginas ; // -> tamanio / tamanio_paginas
  void *p_segmento;
}Segmento;

typedef struct
{
  int numero_pagina;
  int desplazamiento;
  void *p_pagina;
}Pagina;

void rellenar_segmento(Segmento *segmento);
int cargar_pagina(Segmento *segmento,int pagina);
void leer_pagina(Segmento *segmento,int pagina);

int main()
{
  int pagina_modificar,cargado;
  Segmento *segmento = malloc(sizeof(tamanio));// no sería malloc(tamanio)??
  printf("Ingrese el numero de segmento: ");
  scanf("%d", &segmento->numero_segmento);
  segmento->tamanio_segmento = tamanio;
  segmento->tamanio_paginas = 32;
  segmento->cantidad_paginas = tamanio / 32;
  segmento->p_segmento = (char*) malloc(tamanio * sizeof(char));
  printf("Cargando el segmento  ..\n");
  if(NULL==segmento->p_segmento)
  {
    printf("Error al cargar el segmento\n");
  }
  else
  {
    printf("Segmento cargado de forma correta :)\n");
    rellenar_segmento(segmento);
    printf("Paginas cargadas de forma correcta\n" );
  }


  printf("Ingrese una pagina para cargar valores: " );
  scanf("%d",&pagina_modificar );
  cargado = cargar_pagina(segmento,pagina_modificar);
  if(0==cargado)
  {
    printf("Error al cargar data en la pagina\n" );
  }
  else{
    printf("Datos cargados de forma correcta\n");
  }

  printf("Leyendo datos de la pagina %d\n", pagina_modificar );
  leer_pagina(segmento,pagina_modificar);


  printf("\n\n Liberando segmento\n");
  free(segmento->p_segmento);

  return 0;
}

void leer_pagina(Segmento *segmento,int pagina)
{
  char *puntero = (segmento->p_segmento) + (segmento->tamanio_paginas) * pagina ;
  printf("%s\n",puntero);

}

int cargar_pagina(Segmento *segmento,int pagina)
{
  //char data = "tutorial.com";
  char *puntero_copia = (segmento->p_segmento) + (segmento->tamanio_paginas) * pagina ;
  printf("Direccion donde se copiara el contenido : %u\n",puntero_copia );
  strcpy(puntero_copia,"pagina");
  return 1;
}


void rellenar_segmento(Segmento *segmento)
{
  Pagina pagina;
  printf("\n\nEl segmento esta ubicado en la direccon %u\n",segmento->p_segmento);
  printf("El segmento cuenta con %d de memoria reservada\n", segmento->tamanio_segmento);
  printf("El segmento cuenta con %0.1f paginas\n",segmento->cantidad_paginas);
  printf("Cargando paginas en el segmento..\n" );

  for(int i=0;i<segmento->cantidad_paginas;i++)
  {
    printf("Cargando pagina %d\n",i );
    pagina.numero_pagina = i;
    pagina.desplazamiento = segmento->tamanio_paginas;
    pagina.p_pagina = (segmento->p_segmento) + (segmento->tamanio_paginas) * i ;
    printf("La direccion de la pagina %d es %u\n", i , pagina.p_pagina);

  }


}
