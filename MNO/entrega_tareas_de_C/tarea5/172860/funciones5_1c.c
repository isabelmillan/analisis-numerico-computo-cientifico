/*
Metodos Numéricos y Optimización
Tarea 5

c) Modifica el archivo funciones.c para que alojes e inicialices a las matrices matriz1, matriz2 y matriz_resultado con malloc y apuntadores. Modifica main.c para que llame a una función dentro del archivo funciones.c que inicialice y aloje a las matrices anteriores y llame a otra función para que las desaloje una vez hecha la multiplicación (usa free):
*/

#include<stdio.h>
#include<stdlib.h>
#include"definiciones5_1c.h"
#include<assert.h>
//definiciones de variables que serán externas
static int i=0,j=0, k=0;
static double **matriz1;//[NUM_REN_MAT1][NUM_COL_MAT1]={
//        {0, 1.5},
  //      {4, -5},
    //    {-1, 2.5}
   // };
static double **matriz2;//[NUM_REN_MAT2][NUM_COL_MAT2]={
//        {1, 0, 0},
  //      {0, -1, 1}
    //};
static double **matriz_resultado;//[NUM_REN_MAT1][NUM_COL_MAT2];

void aloja_espacio_e_inicializa_matrices(void){
    size_t longitud_ren_1, longitud_ren_2, longitud_ren_3, longitud_col_1, longitud_col_2, longitud_col_3;
    longitud_ren_1 = NUM_REN_MAT1 * sizeof(double*);//*NUM_COL_MAT1;
    longitud_ren_2 = NUM_REN_MAT2 * sizeof(double*);//*NUM_COL_MAT2;
    longitud_ren_3 = NUM_REN_MAT1 * sizeof(double*);//*NUM_COL_MAT2;
    longitud_col_1 = NUM_COL_MAT1  * sizeof(double);
    longitud_col_2 = NUM_COL_MAT2  * sizeof(double);
    longitud_col_3 = NUM_COL_MAT2  * sizeof(double);

    matriz1 = malloc(longitud_ren_1);
    matriz2 = malloc(longitud_ren_2);
    matriz_resultado = malloc(longitud_ren_3);
   for (int i = 0; i < NUM_REN_MAT1; i++){
       *(matriz1+i) = malloc(longitud_col_1);
       *(matriz_resultado+i) = malloc(longitud_col_3);
   }
   for (int i = 0; i < NUM_REN_MAT2; i++)
       *(matriz2+i) = malloc(longitud_col_2);

    assert( matriz1 !=NULL);
    **matriz1 = 0;
    *(*(matriz1)+1) = 1.5;
    *(*(matriz1+1)) = 4;
    *(*(matriz1+1)+1) = -5;
    *(*(matriz1+2)) = -1;
    *(*(matriz1+2)+1) = 2.5;
    assert( matriz2 !=NULL);
    **matriz2 = 1;
    *(*(matriz2)+1) = 0;
    *(*(matriz2)+2) = 0;
    *(*(matriz2+1)) = 0;
    *(*(matriz2+1)+1) = -1;
    *(*(matriz2+1)+2) = 1;

}

void imprime_matrices(void){
	printf("Matriz1\n");
		for(i=0;i<NUM_REN_MAT1;i++){ //el nombre: NUM_REN_MAT1 está definido en "definiciones.h"
			for(j=0;j<NUM_COL_MAT1;j++){
				if(j<NUM_COL_MAT1-1)
				printf("matriz1[%d][%d]=%4.2f\t",i,j,*(*(matriz1+i)+j));//matriz1[i][j]
				else
				printf("matriz1[%d][%d]=%4.2f\n",i,j,*(*(matriz1+i)+j));
			}
		}
	printf("\n");
	printf("Matriz2\n");
		for(i=0;i<NUM_REN_MAT2;i++){
			for(j=0;j<NUM_COL_MAT2;j++){
				if(j<NUM_COL_MAT2-1)
				printf("matriz2[%d][%d]=%4.2f\t",i,j,*(*(matriz2+i)+j));
				else
				printf("matriz2[%d][%d]=%4.2f\n",i,j,*(*(matriz2+i)+j));
			}
		}
	printf("\n");
}

void imprime_matriz_resultado(void){
	printf("Matriz resultado\n");
		for(i=0;i<NUM_REN_MAT1;i++){
			for(j=0;j<NUM_COL_MAT2;j++){
				if(j<NUM_COL_MAT2-1)
				printf("matriz_res[%d][%d]=%4.2f\t",i,j,*(*(matriz_resultado+i)+j));
				else
				printf("matriz_res[%d][%d]=%4.2f\n",i,j,*(*(matriz_resultado+i)+j));
			}
		}

	printf("\n");

}

void multiplica_matrices(void){
        assert( matriz_resultado !=NULL);
	for(i=0;i<NUM_REN_MAT1;i++){
		for(k=0;k<NUM_COL_MAT2;k++){
                        **matriz_resultado=0;
 			for(j=0;j<NUM_COL_MAT1;j++)
                                *(*(matriz_resultado+i)+k)=*(*(matriz_resultado+i)+k) + *(*(matriz1+i)+j) * *(*(matriz2+j)+k);
		}
	}
}

void libera_espacio(void){
    free(matriz1);
    free(matriz2);
    free(matriz_resultado);
}
