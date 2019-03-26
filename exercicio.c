#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void preenche_vetor(long long int * vetorBubble, long long int * vetorInsertion , int n){
    int i, aux=0;
    for(i=0;i<n;i++){
        aux=rand()*rand();
        vetorBubble[i]=aux;
        vetorInsertion[i]=aux;
    }
    
}

void bubble(long long int * v, int n, long long int * contIterBubble){
    int i, j, aux;
    time_t ini, fim;
    char msg[15]="Vetor Bubble";
    for(i=1;i<n;i++){
        for(j=0;j<n-i;j++){
            if(v[j]>v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
            *contIterBubble += 1;
        }
    }
}

void insertion(long long int * v, int n, long long int * contIterInsertion){
    int i, j, chave;
    time_t ini, fim;
    char msg[20]="Vetor Insertion";
    for(i=1;i<n;i++){
        chave=v[i];
        j=i-1;
        while(j>=0 && v[j]>chave){
            v[j+1]=v[j];
            j--;
            *contIterInsertion+=1;
        }
        v[j+1]=chave;
    }
}

int busca_binaria(long long int x, long long int v[], int n, long long int *cont){
    int ini=0, fim=n-1, meio;
    while(ini <= fim){
        meio = (ini+fim)/2;
        *cont = *cont + 1;
        if(x==v[meio]) return meio;
        *cont = *cont + 1;
        if(x>v[meio]) ini=meio+1;
        else fim=meio-1;
    }
    return -1;
}

int busca_simples(long long int x, long long int v[], int n, long long int *cont){
    int i;
    for(i=0;i<n;i++){
        *cont = *cont + 1;
        if(x==v[i]){
            return i;
        }
    }
    return -1;
}

void calculos(long long int * vetorBubble,long long  int * vetorInsertion, int tamanhoVet, int fatorMultiplicativo, int qtdTest ){
	//O fator multiplicativo tem q ser 1 para vetores de 100k
	//2 para 200K, 4 para 400K, 8 para 800K e 16 para 1600K

	//a variável x é só uma variável morta para n precisar mexer no código da Machion
	//porém no código ele recebe a posição em que está o valor buscado dentro do vetor
	//se achar, e se não achar recebe -1
	int i,x;
	long long int valorBuscado;
    time_t ini, fim; //inteiro sem sinal, doc na time.h

	//Quantidade de iterações
	long long int ContInterOrdBubble[qtdTest], ContInterOrdInsertion[qtdTest];
	//Tempo de ordenação
	long long int TempOrdBubble[qtdTest], TempOrdInsertion[qtdTest];
	//Número de buscas
	long long int ContBuscaSimples[qtdTest], ContBuscaBinaria[qtdTest];
	//Tempo de buscas
	long long int TempBuscaSimples[qtdTest], TempBuscaBinaria[qtdTest];

	if(vetorBubble && vetorInsertion){
        srand(time(0));
        for(i=0;i<qtdTest;i++){
        	
        	long long int contIterBubble=0, contIterInsertion=0, tempIterBubble=0, tempIterInsertion=0;
        	long long int cont_simples=0, tempBuscaSimples=0, cont_binaria=0, tempBuscaBinaria=0;

        	preenche_vetor(vetorBubble, vetorInsertion, tamanhoVet);

        	//Buscar o valor numa busca simples
        	valorBuscado=rand()%rand();
        	ini = time(0);
        	x = busca_simples(valorBuscado,vetorBubble,tamanhoVet,&cont_simples);
        	fim = time(0);
        	tempBuscaSimples = fim-ini;
			
        	//Ordenação Bubble
        	ini = time(0);
        	bubble(vetorBubble,tamanhoVet,&contIterBubble);
        	fim = time(0);
        	tempIterBubble= fim-ini;
			
        	//Ordenação Insertion
        	ini = time(0);
        	insertion(vetorInsertion,tamanhoVet,&contIterInsertion);
        	fim = time(0);
        	tempIterInsertion= fim-ini;
			
        	//Busca binária
        	ini = time(0);
        	x = busca_binaria(valorBuscado,vetorInsertion,tamanhoVet,&cont_binaria);
        	fim = time(0);
        	tempBuscaBinaria = fim-ini;
			
        	//Prenchimento dos vetores de referencia
        	ContBuscaSimples[i] = cont_simples;
        	TempBuscaSimples[i] = tempBuscaSimples;
        	ContInterOrdBubble[i] = contIterBubble;
        	TempOrdBubble[i] = tempIterBubble;
        	ContInterOrdInsertion[i] = contIterInsertion;
        	TempOrdInsertion[i] = tempIterInsertion;
        	ContBuscaBinaria[i] = cont_binaria;
        	TempBuscaBinaria[i] = tempBuscaBinaria;
		}


		long long int somaContInterOrdBubble=0, somaContInterOrdInsertion=0,somaTempOrdBubble=0,somaTempOrdInsertion=0;
		long long int somaContBuscaSimples=0,somaTempBuscaSimples=0, somaContBuscaBinaria=0, somaTempBuscaBinaria=0;
		for (i=0;i<qtdTest;i++){
			somaContBuscaSimples += (long long int) ContBuscaSimples[i];
			somaContInterOrdBubble += (long long int) ContInterOrdBubble[i];
			somaContInterOrdInsertion += (long long int) ContInterOrdInsertion[i];
			somaContBuscaBinaria += (long long int) ContBuscaBinaria[i];
			somaTempBuscaSimples += (long long int) TempBuscaSimples[i];
			somaTempOrdBubble += (long long int) TempOrdBubble[i];
			somaTempOrdInsertion += (long long int) TempOrdInsertion[i];
			somaTempBuscaBinaria += (long long int) TempBuscaBinaria[i];
		}
		long long int mediaContInterOrdBubble = somaContInterOrdBubble/qtdTest;
		long long int mediaTempOrdBubble = somaTempOrdBubble/qtdTest;
		long long int mediaContInterOrdInsertion = somaContInterOrdInsertion/qtdTest;
		long long int mediaTempOrdInsertion = somaTempOrdInsertion/qtdTest;
		long long int mediaContBuscaSimples = somaContBuscaSimples/qtdTest;
		long long int mediaTempBuscaSimples = somaTempBuscaSimples/qtdTest;
		long long int mediaContBuscaBinaria = somaContBuscaBinaria/qtdTest;
		long long int mediaTempBuscaBinaria = somaTempBuscaBinaria/qtdTest;

		//printf("Qtd media de iteracoes Bubble: %lli - Tempo medio de uma ordenacao bubble: %lli\n",mediaContInterOrdBubble,mediaTempOrdBubble);
		//printf("Qtd media de iteracoes Insertion: %lli - Tempo medio de uma ordenacao bubble: %lli\n",mediaContInterOrdInsertion,mediaTempOrdInsertion);
		//printf("Qtd media de buscas simples: %lli buscas - Tempo medio para a localizacao de um numero: %lli\n",mediaContBuscaSimples,mediaTempBuscaSimples);
		//printf("Qtd media de buscas binarias: %lli buscas - Tempo medio para a localizacao de um numero: %lli\n",mediaContBuscaBinaria,mediaTempBuscaBinaria);

		 // criando a variável ponteiro para o arquivo
		FILE *pont_arq;

		time_t t = time(NULL);
		struct tm tm = *localtime(&t);

		char nomeArquivo[] = "";

		if (fatorMultiplicativo==1){
			strcat(nomeArquivo, "arquivo100K.txt");
		}
		else if (fatorMultiplicativo==2){
			strcat(nomeArquivo, "arquivo200K.txt");
		}
		else if (fatorMultiplicativo==4){
			strcat(nomeArquivo, "arquivo400K.txt");
		}
		else if (fatorMultiplicativo==8){
			strcat(nomeArquivo, "arquivo800K.txt");
		}
		else if (fatorMultiplicativo==16){
			strcat(nomeArquivo, "arquivo1600K.txt");
		}

		//abrindo o arquivo
		pont_arq = fopen(nomeArquivo, "a");

		//usando fprintf para armazenar a string no arquivo
  		fprintf(pont_arq, "Qtd media de iteracoes Bubble: %lli - Tempo medio de uma ordenacao bubble: %lli\n",mediaContInterOrdBubble,mediaTempOrdBubble);
		fprintf(pont_arq, "Qtd media de iteracoes Insertion: %lli - Tempo medio de uma ordenacao bubble: %lli\n",mediaContInterOrdInsertion,mediaTempOrdInsertion);
		fprintf(pont_arq, "Qtd media de buscas simples: %lli buscas - Tempo medio para a localizacao de um numero: %lli\n",mediaContBuscaSimples,mediaTempBuscaSimples);
		fprintf(pont_arq, "Qtd media de buscas binarias: %lli buscas - Tempo medio para a localizacao de um numero: %lli\n",mediaContBuscaBinaria,mediaTempBuscaBinaria);

		// fechando arquivo
		fclose(pont_arq);

		//mensagem para o usuário
		printf("Um arquivo foi criado e os dados foram salvos com sucesso!");
    }

}

void chamadaCalculo(long long int *VetorBubble,long long int *VetorInsertion, int tamanhoVet,int fatorMultiplicativo, int qtdTest ){
	//Inicialização dos vetores
	VetorBubble = (long long int *) malloc (tamanhoVet * sizeof(long long int));
	VetorInsertion = (long long int *) malloc (tamanhoVet * sizeof(long long int));
    calculos(VetorBubble, VetorInsertion, tamanhoVet, fatorMultiplicativo, qtdTest);
    free(VetorBubble);
    free(VetorInsertion);
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("\nFim %d00K: %d-%d-%d %d:%d:%d\n", fatorMultiplicativo, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

int main(){
	int tamanhoVet=100000,qtdTest,opcoes;
	printf("Digite a quatidade de testes que serao feitos em cada vetor: ");
	scanf("%d",&qtdTest);
	printf("\nDigite quais vetores serao testados: \n1-100k\t2-200k\t3-400k\t4-800k\t5-1600k\t6-TODOS\n");
	scanf("%d",&opcoes);
	while(opcoes<1 || opcoes>6){
		printf("\nValor digitado fora dos limites, por favor, digite um numero valido!");
		printf("\nDigite quais vetores serao testados: \n1-100k\t2-200k\t3-400k\t4-800k\t5-1600k\n");
		scanf("%d",&opcoes);
	}
	//vetores genéricos para armazenar os números
	long long int *Vetor100KBubble,*Vetor200KBubble,*Vetor400KBubble,*Vetor800KBubble,*Vetor1600KBubble;
	long long int *Vetor100KInsertion,*Vetor200KInsertion,*Vetor400KInsertion,*Vetor800KInsertion,*Vetor1600KInsertion;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("\nInicio: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
	switch(opcoes){
		case 1:
			chamadaCalculo(Vetor100KBubble, Vetor100KInsertion, tamanhoVet*1, 1, qtdTest);
			break;
		case 2:
			chamadaCalculo(Vetor200KBubble, Vetor200KInsertion, tamanhoVet*2, 2, qtdTest);
			break;
		case 3:
			chamadaCalculo(Vetor400KBubble, Vetor400KInsertion, tamanhoVet*4, 4, qtdTest);
			break;
		case 4:
			chamadaCalculo(Vetor800KBubble, Vetor800KInsertion, tamanhoVet*8, 8, qtdTest);
			break;
		case 5:
			chamadaCalculo(Vetor1600KBubble, Vetor1600KInsertion, tamanhoVet*16, 16, qtdTest);
			break;
		case 6:
			chamadaCalculo(Vetor100KBubble, Vetor100KInsertion, tamanhoVet*1, 1, qtdTest);
			chamadaCalculo(Vetor200KBubble, Vetor200KInsertion, tamanhoVet*2, 2, qtdTest);
			chamadaCalculo(Vetor400KBubble, Vetor400KInsertion, tamanhoVet*4, 4, qtdTest);
			chamadaCalculo(Vetor800KBubble, Vetor800KInsertion, tamanhoVet*8, 8, qtdTest);
			chamadaCalculo(Vetor1600KBubble, Vetor1600KInsertion, tamanhoVet*16, 16, qtdTest);
			break;
	}
	return 0;
}
