#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define NUM_THREADS 6

//CAROLINA ORTEGA - 31935214
//MATHEUS MENDES - 31944507


int main() {
	//Tempo
	struct timeval tv;
    double start_t, end_t, tempo_gasto;
    
    //Variaveis
	long long tamanhoVetor = pow(2, 28);
	int *vetor = (int *) malloc(sizeof(int) * tamanhoVetor);
	
	//Popular Vetor 2^30
	int i;
	for (i = 0; i < tamanhoVetor; i++)
		vetor[i] = rand() % 11;
	
	//Execução Sem reduction
	printf("\n===========   Iniciando execucao Com Reduction  ============\n");     
  	gettimeofday(&tv, NULL);
  	start_t = (double) tv.tv_sec + (double)tv.tv_usec / 1000000.0;
  	
	//Função sem Reduction
	long long somatoria = 0;
	
	long long j;
	#pragma omp parallel for reduction(+: somatoria) private(j) num_threads (NUM_THREADS)
  		for (j = 0; j < tamanhoVetor; j++) {
  		   	somatoria += vetor[j];
  		}
  	
  	free(vetor);
  	
  	gettimeofday(&tv,NULL); 
  	end_t = (double) tv.tv_sec + (double) tv.tv_usec / 1000000.0;
  	tempo_gasto = end_t - start_t;
  	
  	printf("Somatoria = %d\n", somatoria);
  	printf("Tempo Gasto: %f Segundos", tempo_gasto);
  	printf("\n");
  	printf("===========  Finalizando execucao Com Reduction ============\n"); 

	return 0;
}
