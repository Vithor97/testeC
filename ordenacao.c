
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preenche_vetor(int *v, int n){
	int i;
	for(i=0;i<n;i++){
		v[i] = rand() %10;
	}
}

void mostra_vetor(int *v, int n, char *msg){
	int i;
	printf("\n%s\n", msg);
	for(i=0; i<n; i++){
		printf("%d ", v[i]);
	}
	printf("\n");
}

void bubble (int *v, int n){
	int i, j, aux;
	for(i=1; i<n; i++){
		printf("I = %d\n", i);
		for(j=0; j<n-i; j++){
			printf("J: %d", j);
			mostra_vetor(v,n, "bubble antes");
			
			if(v[j]> v[j+1]){
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
				
			}
			mostra_vetor(v,n, "bubble depois ");
		}
	}
	
}
void insertion(int *v, int n){
	int i, j , chave;
	for(i=1; i<n; i++){
		chave = v[i];
		j= i-1;
		while (j>=0 && v[j]> chave){
			v[j+1] = v[j];//v[j--]
			j--;
		}
		printf("J = %d ", j);
		v[j+1] = chave;
	}
}

int main(){
	srand(time(0));
	
	int *v, n;
	time_t ini, fim;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	v = (int *) malloc (n * sizeof(int));
	
	if(v){// if (v != NULL)
		//printf("Valores desordenados:\n");
		preenche_vetor(v,n);
		mostra_vetor(v,n, "vetor 1");
		//printf("Valores ordenados:\n");
		ini = time(0);
		bubble(v,n);
		fim = time(0);
		printf("\nbubble demorou demorou %d segundos\n", fim-ini);
		//preenche_vetor(v,n);
		mostra_vetor(v,n, "Vetor ordenado - bubble");
		//printf("Valores ordenados:\n");
		preenche_vetor(v,n);
		mostra_vetor(v,n, "vetor 2");
		ini = time(0);
		insertion(v, n);
		fim = time(0);
		printf("\nInsertion demorou demorou %d segundos\n", fim-ini);
		mostra_vetor(v,n, "Vetor ordenado - insertion");
		
		
	}
	
	
	return 0;
}
