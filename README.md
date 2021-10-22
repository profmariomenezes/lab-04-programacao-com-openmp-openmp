# comppar-lab04-openmp
Repositório para as atividades de programação OpenMP - 

## Recursos para alunos

----------------------------------------------------------------------
Calcular Área - Método do Trapézio 

=== Cálculo Numérico - Manipulação Algébrica ===

A = [f(a) + f(a+h)]*h/2 + [f(a+h) + f(a+2*h)]*h/2 + [f(a+2*h) + f(a+3*h)]*h/2 + [f(a+3*h) + f(b)]*h/2

A = h/2 * [[f(a) + f(a+h)] + [f(a+h) + f(a+2*h)] + [f(a+2*h) + f(a+3*h)] + [f(a+3*h) + f(b)]]

A= h/2 * [f(a) + 2*f(a+h) + 2*f(a+2*h) + 2*f(a+3*h) + f(b)]

A = h * [f(a)/2 + f(a+h) + f(a+2*h) + f(a+3*h) + f(b)/2]

A = h * [[f(a) + f(b)]/2 + f(a+h) + f(a+2*h) + f(a+3*h) ]


=== Algoritmo Serial ===

1) Cálculo de f(a) e f(b) -> [f(a) + f(b)]/2
approx = (f(a) + f(b))/2.0

2) Parâmetro da função f(a+2*h)
x_i = a + i*h;

3) Partes de cada trapézio: f(a+1*h) + f(a+2*h) + f(a+3*h)
for (i =1; i <= n-1; i++) {
   x_i = a + i*h;
   approx += f(x_i);
}

4) Multiplicação da altura
approx = h * approx;

--------------------------------------------------------------------------


Link: Slides minicurso OpenMP - https://www.researchgate.net/publication/324703570_OpenMP_um_modelo_de_programacao_paralela_com_threads

Link: Site do OpenMP

 --- OpenMP 4.5 complete specification   http://www.openmp.org/mp-documents/openmp-4.5.pdf
 --- OpenMP 4.5 cheat sheet    http://www.openmp.org/mp-documents/OpenMP-4.5-1115-CPP-web.pdf
 
Link: How to compile and run an OpenMP Program    https://www.dartmouth.edu/~rc/classes/intro_openmp/compile_run.html

Link: Youtube - Introduction to OpenMP     https://www.youtube.com/playlist?list=PLLX-Q6B8xqZ8n8bwjGdzBJ25X2utwnoEG

Links Medição de Desempenho
  --- gettimeofday (StackOverflow)      https://stackoverflow.com/a/5249028/1247542
  --- time (bash)      https://ss64.com/bash/time.html
  --- Speedup           https://en.wikipedia.org/wiki/Speedup
  



## Lab 1 - Programação - Integral Regra do Trapézio (em aula)

Faça o código da integral pela regra do trapézio mostrado nos slides de Introdução ao OpenMP (

04 - Programacao de Memoria Compartilhada com OpenMP - ch5), na página 24.
Implemente as diversas melhorias no seu código, até chegar na página 38 (com **reduction** )

Submeta o seu código, com o seu nome no início do código em comentário.

Submeta prints da execução do código.


## Lab 2 - Avaliação de desempenho

### Somatório de números

Faça um programa que some todos os números de um vetor de tamanho 2<sup>30</sup>. Garanta que os números neste vetor sejam sempre os mesmos para garantir o mesmo resultado final!

Construa 2 versões em paralelo utilizando #pragma omp for que soma parcialmente os valores e:

    que utiliza uma variável compartilhada e #pragma omp critial para controle de seção crítica
    que utiliza #pragma omp ... reduction(...) para a somatória final

Faça uma comparação de tempo de execução com 1, 2, 3, 4, 5 e 6 threads, para cada versão. Construa uma tabela contendo o tempo médio de 10 execuções para cada versão e sua respectiva quantidade de threads.

Faça um gráfico que mostre a escalabilidade forte (mínimo de 2<sup>28</sup>, com garantia de todos os dados em memória) e escalabilidade fraca (use 2<sup>30</sup> como quantidade máxima de dados) do Speedup para cada quantidade de threads utilizada.

Entregue os códigos fontes e as tabelas no formato Excel, onde cada aba da planilha é relativa a uma versão diferente de código com sua respectiva tabela de execução e seu respectivo gráfico de speedup.

## Lab 3 -  - Nova multiplicação de matrizes

Faça um programa de multiplicação de matrizes. Fique atento a um bom uso de cache (L1/L2)

Construa uma versão sequencial e uma versão paralela com OpenMP, utilizando alguma das técnicas estududas e/ou apresentadas na literatura.

Faça uma comparação de tempo de execução com 1, 2, 3, 4, 5 e 6 threads, para a versão paralela. Construa uma tabela contendo o tempo médio de 3 execuções para cada versão e sua respectiva quantidade de threads.

Faça um gráfico que mostre a escalabilidade do Speedup para cada quantidade de threads utilizada.

Entregue os códigos fontes e as tabelas no formato Excel, onde cada aba da planilha é relativa a uma versão diferente de código com sua respectiva tabela de execução .

**Tarefas todas em trio.**
