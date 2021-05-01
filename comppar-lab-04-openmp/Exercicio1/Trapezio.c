#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

#define NUM_THREADS 2
	
//CAROLINA ORTEGA - 31935214
//MATHEUS MENDES - 31944507

double f(double x){
	return exp(x);
}

void Trap(double a, double b, int n, double* variavel_global);

int main(int argc, char* argv[]) {
	double variavel_global = 0.0;
	
	//Variaveis de entrada pelo prompt
	double a;
  	printf("Insira valor para a: ");
  	scanf("%lf", &a);

  	double b;
  	printf("Insira valor para b: ");
  	scanf("%lf", &b);
  	
	int subIntervalos;
	printf("Coloque valor dos sub intervalos:");
	scanf("%d", &subIntervalos);
	//Fim variaveis
	
	
	#pragma omp parallel num_threads(NUM_THREADS)
	Trap(a, b, subIntervalos, &variavel_global);
	
	printf("Valor de a: %lf \n", a);
	printf("Valor de b: %lf \n", b);
	printf("Valor de Sub Intervalos: %d \n", subIntervalos);
	printf("Resultado = %g", variavel_global);
	return 0;
} 

void Trap(double a, double b, int n, double *variavel_global){
	double h, x, my_result;
	double local_a, local_b;
	int i, local_n;
	int my_rank = omp_get_thread_num();
	int thread_count = omp_get_num_threads();
	h = (b-a)/n;
	local_n = n/thread_count;
	local_a = a + my_rank * local_n * h;
	local_b = local_a + local_n * h;
	my_result = (f(local_a) + f(local_b))/ 2.0;
	
	for(i=1; i < local_n - 1; i++){
		x = local_a + i*h;
		my_result += f(x);
	}
	
	my_result = my_result*h;
	
	#pragma omp critical
	*variavel_global += my_result;
}
