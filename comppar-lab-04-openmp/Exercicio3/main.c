/*
CAROLINA ORTEGA - 31935214
MATHEUS MENDES - 31944507
Faça um programa de multiplicação de matrizes. Fique atento a um bom uso de cache (L1/L2)

Construa uma versão sequencial e uma versão paralela com OpenMP, utilizando alguma das técnicas estududas e/ou apresentadas na literatura.

Faça uma comparação de tempo de execução com 1, 2, 3, 4, 5 e 6 threads, para cada versão. Construa uma tabela contendo o tempo médio de 3 execuções para cada versão e sua respectiva quantidade de threads.

Faça um gráfico que mostre a escalabilidade do Speedup para cada quantidade de threads utilizada.

Entregue os códigos fontes e as tabelas no formato Excel, onde cada aba da planilha é relativa a uma versão diferente de código com sua respectiva tabela de execução .
Submeter: o código fonte e prints da tela da execução.
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>
#define NUM_THREADS 6

	
int main()
{

	//Tempo
	struct timeval tv;
    double start_t, end_t, tempo_gasto;
	
	//Inicialização Matriz
	int tamanhoMatrizQuadrada = 300;
	int i = 0;
	int j = 0;
	int k = 0;
	int matriz1 [tamanhoMatrizQuadrada][tamanhoMatrizQuadrada];
	int matriz2 [tamanhoMatrizQuadrada][tamanhoMatrizQuadrada];
	
	long int matrizFinalParalela [tamanhoMatrizQuadrada][tamanhoMatrizQuadrada];
	long int matrizFinalNaoParalela [tamanhoMatrizQuadrada][tamanhoMatrizQuadrada];
	
	
	//Popular Matriz 1 com valores randomicos
	for (i = 0; i < tamanhoMatrizQuadrada; i++)
        for (j = 0; j < tamanhoMatrizQuadrada; j++)
        	matriz1[i][j] = rand() % 11;
         	
         	
    //Popular Matriz 2 com valores randomicos
    for (i = 0; i < tamanhoMatrizQuadrada; i++)
        for (j = 0; j < tamanhoMatrizQuadrada; j++)
         	matriz2[i][j] = rand() % 11;
         	
    
    //Execução Sem ser Paralela
	printf("\n===========   Iniciando execucao nao Paralela  ============\n");     
  	gettimeofday(&tv, NULL);
  	start_t = (double) tv.tv_sec + (double)tv.tv_usec / 1000000.0;
  
	
	for (i = 0; i < tamanhoMatrizQuadrada; i++) 
        for (k = 0; k < tamanhoMatrizQuadrada; k++) 
            for (j = 0; j < tamanhoMatrizQuadrada; j++) 
                matrizFinalNaoParalela[i][j] += matriz1[i][k] * matriz2[k][j];
                
	//Mostrar Matriz final não paralela
    //for (i = 0; i < tamanhoMatrizQuadrada; i++)
        //for (j = 0; j < tamanhoMatrizQuadrada; j++)
        	//printf ("\nElemento[%d][%d] = %d", i, j, matrizFinalNaoParalela[i][j]);
        
    gettimeofday(&tv,NULL); 
  	end_t = (double) tv.tv_sec + (double) tv.tv_usec / 1000000.0;
  	tempo_gasto = end_t - start_t;
  	
  	printf("Tempo Gasto: %f Segundos.", tempo_gasto);
  	printf("\n");
  	printf("===========  Finalizando execucao Nao Paralela ============\n"); 
  	//Fim Execução sem ser paralela
	
	
	//Começo execução Paralela
	printf("\n===========   Iniciando execucao Paralela  ============\n");     
  	gettimeofday(&tv, NULL);
  	start_t = (double) tv.tv_sec + (double)tv.tv_usec / 1000000.0;
  
	#pragma omp parallel num_threads (NUM_THREADS) private (i, j, k) shared (matriz1, matriz2, matrizFinalParalela, tamanhoMatrizQuadrada)
	{
		#pragma omp for
		for(i = 0; i < tamanhoMatrizQuadrada; i++){
			for (k = 0; k < tamanhoMatrizQuadrada; k++){
				for(j = 0; j < tamanhoMatrizQuadrada; j++){
					matrizFinalParalela[i][j] += matriz1[i][k] * matriz2[k][j];
				}
			}
		}
	}
	
	//Mostrar Matriz final paralelo
    //for (i = 0; i < tamanhoMatrizQuadrada; i++)
        //for (int j = 0; j < tamanhoMatrizQuadrada; j++)
        	//printf ("\nElemento[%d][%d] = %d", i, j, matrizFinalParalela[i][j]);
        
    gettimeofday(&tv,NULL); 
  	end_t = (double) tv.tv_sec + (double) tv.tv_usec / 1000000.0;
  	tempo_gasto = end_t - start_t;
  	
  	printf("Tempo Gasto: %f Segundos.", tempo_gasto);
  	printf("\n");
  	printf("===========  Finalizando execucao Paralela ============\n"); 
  	//Fim Execução Paralela
	
	return 0;	
}

