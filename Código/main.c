#include "comparacao.h"

int main () {
    	int qtd, i = 0, j = 0;
	srand((unsigned)time(NULL));
	clock_t ticks[4];
	FILE *file;
	char nome[20],nomeaux[20],res[3000];

	printf("Digite o nome do arquivo: ");
	scanf("%s", nome);
	strcat(nome, "");
	strcpy(nomeaux, nome);
	strcat(nomeaux, ".txt");
	file = fopen(nomeaux, "a");
	strcat(res, nome);
	strcat(res, "\n"); 

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &qtd);
	int vetor[qtd],vetor2[qtd],t2,vetor3[qtd],t3;

	//preenche o vetor de números aleatoriamente
    	for(i=0;i < qtd;i++) {
        	vetor[i] = rand()%100;
    	}

	//imprimi os números do vetor
	printf("Numeros:\n");
	fprintf(file, "Numeros:");
	for(i=0;i<qtd;i++){
		printf("%d ",vetor[i]);
		fprintf(file, "%d ",vetor[i]);
	}

	//mostra a maior sequencia crescente (dinâmico), o comprimento e o tempo
	printf("\nMaior(es) sequencia(s) programação dinamica:\n");
	fprintf(file, "\nMaior(es) sequencia(s) programação dinamica:\n");
	ticks[0] = clock();
	t2 = sequenciaCrescente(vetor,vetor2, qtd);
	for (i = 0; i < t2; i++){
		printf("%d ", vetor2[i]);
		fprintf(file, "%d ",vetor2[i]);
	}
	ticks[1] = clock();
	double tempo = ticks[1]-ticks[0];
	printf("\nComprimento MSC: %d\nTempo: %lf ns\n", t2,tempo);
	fprintf(file, "\nComprimento MSC: %d\nTempo: %lf ns\n", t2,tempo);

	//mostra a maior sequencia crescente (guloso), o comprimento e o tempo
	printf("\nMaior(es) sequencia(s) programação gulosa:\n");
	fprintf(file, "\nMaior(es) sequencia(s) programação gulosa:\n");
	ticks[2] = clock();
	t3 = sequenciaCrescenteGuloso(vetor, vetor3, qtd);
	for (i=0;i<t3;i++){
		printf("%d ", vetor3[i]);
		fprintf(file, "%d ",vetor3[i]);
	}
	ticks[3] = clock();
	double tempo1 = ticks[3] - ticks[2];
	printf("\nComprimento guloso: %d\nTempo: %lf ns\n",t3, tempo1);
	fprintf(file, "\nComprimento MSC: %d\nTempo: %lf ns\n", t3,tempo1);
	
	if(t3==t2){
		printf("\nOs dois metodos tiveram o mesmo MSC\n");
		fprintf(file, "\nOs dois metodos tiveram o mesmo MSC\n");
	}else if(t3>t2){
		printf("\nO metodo guloso obteve um numero maior de MSC do que o dinamico\n");
		fprintf(file, "\nO método guloso obteve um numero maior de MSC do que o dinamico\n");
	}else{
		printf("\nO metodo dinamico obteve um numero maior de MSC do que o guloso\n");
		fprintf(file, "\nO método dinamico obteve um numero maior de MSC do que o guloso\n");
	}

	if(tempo==tempo1){
		printf("\nOs dois metodos tiveram o mesmo tempo de execucao\n");
		fprintf(file, "\nOs dois metodos tiveram o mesmo tempo de execucao\n");
	}else if(tempo>tempo1){
		printf("\nO metodo guloso foi mais rapido que o metodo dinamico\n");
		fprintf(file, "\nO metodo guloso foi mais rapido que o metodo dinamico\n");
	}else{
		printf("\nO metodo dinamico foi mais rapido que o metodo guloso\n");
		fprintf(file, "\nO metodo dinamico foi mais rapido que o metodo guloso\n");
	}
	fclose(file);
	return 0;
}
