#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define length 3 //numero de paginas

int tamanio;

struct Pagina
{
  int numero_pagina;
  int presencia;
  int modificado;
  char dato[20];
  void *p_direccion;
} tabla_paginas[length];


int main()
{
  for(int i=0;i<length;i++)
  {
    printf("Pagina numero: ");
    scanf("%d",&tabla_paginas[i].numero_pagina);
    printf("Bit de presencia: ");
    scanf("%d",&tabla_paginas[i].presencia);
    printf("Bit de modificado: ");
    scanf("%d",&tabla_paginas[i].modificado);
    printf("Ingrese el dato a guardar: \n" );
    scanf("%s",tabla_paginas[i].dato);
    tamanio = strlen(tabla_paginas[i].dato);
    tabla_paginas[i].p_direccion = malloc(tamanio * sizeof(char));
    if(NULL == tabla_paginas[i].p_direccion)
      printf("Error al asignar memoria a la pagina %d\n",i );
    else
    {
      printf("Se asigno de forma correcta la memoria de la pagina %d\n",i );
    }

  }

  for(int i = 0;i<length;i++)
  {
    printf("La pagina %d tiene el dato %s\n",i,tabla_paginas[i].dato);
  }

  printf("\nBits modificados : [");
  for(int i=0;i<length;i++)
  {
    mostrar_bits_modificados(tabla_paginas[i]);
  }
  printf("]\n");
  return 0;
}


void mostrar_bits_modificados(struct Pagina pagina )
{
    printf("%d,",pagina.modificado);
}
