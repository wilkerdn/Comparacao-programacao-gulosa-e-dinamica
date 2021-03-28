#include "comparacao.h"

int sequenciaCrescente( int v[], int resposta[],int tam){
	int sc[tam];
	int sc_index[tam];
	int pred[tam];
	int maxi = 0, x, j, ind, i, a;
	
	for ( i = 0; i < tam; i++ ){
		x = v[i];
		j=0;
		for( a = 0; a < maxi; a++ )
		   if( sc[a] < x )
		      j++;
		
		sc[j] = x;
		sc_index[j] = i;
		
		if( j == maxi ){
			maxi++;
			ind = i;
		}

		if(j)
		   pred[i] = sc_index[j - 1];
		else
		   pred[i] = -1;
	} 
	int pos = maxi - 1, k = v[ind];
	while ( pos >= 0 ){
		resposta[pos--] = k;
		ind = pred[ind];
		k = v[ind];
	}
	return maxi;
} 

int sequenciaCrescenteGuloso(int v[], int resposta[], int tam){
	int sc[tam];
	int adj[tam];
	int m[tam][tam];
	int maxi = 0, j,i_maior,maior,l_maior, i, a;

	for(i=0;i<tam;i++){
		adj[i] = 0;
		sc[i] = 0;
		for(j=0;j<tam;j++){
			m[i][j]=0;
		}
	}

	for(i=0;i<tam;i++){
		for(j=i;j<tam;j++){
			if(v[i] < v[j]){
				m[i][j] = 1;
				adj[i]++;
			}
		}
	}

	i_maior = -1;
	maior = -1;

	for(i=0;i<tam;i++){
		if(maior<adj[i]){
			maior = adj[i];
			i_maior = i;
		}
	}

	sc[0] = v[i_maior];
	maxi = 1;

	do{
		l_maior = i_maior;
		maior = -1;
		for(i = (i_maior+1);i<tam;i++){
			if(m[l_maior][i]==1 && adj[i] > maior){
				maior = adj[i];
				i_maior = i;
			}
		}
		sc[maxi] = v[i_maior];
		maxi++;
	}while(adj[i_maior] != 0);


	for(i=0;i<maxi;i++){
		resposta[i] = sc[i];
	}
	return maxi;
}
