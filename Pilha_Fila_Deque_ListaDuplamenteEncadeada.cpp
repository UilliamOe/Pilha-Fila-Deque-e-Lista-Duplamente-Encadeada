/************************************************
**Universidade do Estado de Mato Grosso- UNEMAT *
**Curso: Bacharel. Ciencia da Computa��o        *
**Disciplina: Etrutura de Dados I               *
**Prof. Me. D�rley Domingos de Almeida          *
**Aluno: Uilliam Pereira de Oliveira            *
************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

//definindo/declarando struct
struct pilha
{
	int dados[MAX];
	int topo;
};

struct fila
{
	int dados[MAX];
	int inicio;
	int fim;
};

typedef struct no
{
	int valor;
	struct no *anterior, *proximo;
} NO;

typedef struct lista
{
	int tam;
	NO *inicio, *fim;
} LISTA;


//	PILHA ===================
void menu_Pilha();
void inicializarPilha(struct pilha *Pilha_X);
int pilha_cheia(struct pilha Pilha_X);
int pilha_vazia(struct pilha Pilha_X);
void empilhar(struct pilha *Pilha_X, int valor);
int consultar_topo(struct pilha Pilha_X);
void desempilhar(struct pilha *Pilha_X);
int altura(struct pilha Pilha_X);

//	FILA ===================
void menu_Fila();
void inicializarFila(struct fila *Fila_X);
int fila_cheia(struct fila Fila_X);
int fila_vazia(struct fila Fila_X);
void enfileirar(struct fila *Fila_X, int valor);
int consultar_primeiro_da_Fila(struct fila Fila_X);
void desenfileirar (struct fila *Fila_X);
int tamanho(struct fila Fila_X);

//	DEQUE ===================
void menu_Deque();
void InserirFim(struct fila *Fila_X, int valor);
void InserirInicio(struct fila *Fila_X, int valor);
int consultar_ultimo_do_deque(struct fila Fila_X);
void removerInicio (struct fila *Fila_X);
void removerFim (struct fila *Fila_X);

// LDE ===================
void menu ();
void menu_LDE();
void exercicio_3 ();
int getValue ();
void InserirInicio (LISTA** L, int val);
void InserirFim (LISTA ** L, int val);
int removerInicio (LISTA** L);
int removerFim(LISTA** L);
void consultarInicio (LISTA* L);
void consultarFim (LISTA* L);
void consultaTamanho (LISTA* L);
void imprimeInicioFim (LISTA* L);
void imprimeFimInicio (LISTA* L);
void inicia_lista (LISTA** L);
void inicia_no (NO** N, int val);

//fun��o principal main (), chamando fun�ao menu ()
int main()
{
	menu();
	system("pause");
	return 0;
}

void menu()
{
	system("color f9");
	int op;
	do
	{
		printf("\n\n >> MENU PRINCIPAL << ");
		printf("\n\t  1 -> PILHA");
		printf("\n\t  2 -> FILA");
		printf("\n\t  3 -> DEQUE");
		printf("\n\t  4 -> LDE");
		printf("\n\t      0 -> Sair");
		printf("\n\t Digite:  ");
		scanf("%d", &op);
		system("cls");
		switch(op)
		{
		case 1:
			menu_Pilha();//chama fun��o responsavel pela pilha

			break;
		case 2:
			menu_Fila();//chama fun��o responsavel pela fila

			break;
		case 3:
			menu_Deque();//chama fun��o responsavel pelo deque

			break;
		case 4:
			menu_LDE();//chama fun��o responsavel pela LDE
		case 0:
			printf("\n\n ... saindo ... \n\n");

			break;
		default:
			printf("\nOpcao Invalida");
		}
	}
	while(op != 0);
}
void menu_Pilha()
{
	struct pilha Rayovac;
	inicializarPilha(&Rayovac);

	system("color f3");
	int op, valor;
	do
	{
		printf("\n\n >> PILHA << ");
		printf("\n\t 1 -> Inserir");
		printf("\n\t 2 -> TOPO");
		printf("\n\t 3 -> Remover");
		printf("\n\t 4 -> Altura");
		printf("\n\t 0 -> sair");
		printf("\n\t Digite:  ");
		scanf("%d", &op);
		system("cls");
		switch(op)
		{
		case 1:
			if(pilha_cheia(Rayovac))
				printf("\n\t PILHA ESTAH CHEIA !!!");
			else
			{
				printf("\n\t Digite um valor:  ");
				fflush(stdin);
				scanf("%d", &valor);
				empilhar(&Rayovac, valor);
			}

			break;
		case 2:
			if(pilha_vazia(Rayovac))
				printf("\n\t PILHA ESTAH VAZIA !!!");
			else
				printf("\n\n Topo da PILHA:  %d ", consultar_topo(Rayovac));

			break;
		case 3:
			if(pilha_vazia(Rayovac))
				printf("\n\t PILHA ESTAH VAZIA !!!");
			else
				printf("\n\n\t Valor removido: %d", consultar_topo(Rayovac));
			desempilhar(&Rayovac);

			break;
		case 4:
			printf("\n\n\t Altura da PILHA eh: %d", altura(Rayovac));

			break;
		case 0:
			printf("\n\n ... saindo ... \n\n");

			break;
		default:
			printf("\nOpcao Invalida");
		}
	}
	while(op != 0);
}

void inicializarPilha(struct pilha *Pilha_X)
{
	Pilha_X->topo = - 1;//iniciao a pilha na posi��o - 1, ou seja, na posi��o inicial == 0
}

void empilhar(struct pilha *Pilha_X, int valor)//aqui iremos pegar a variavel digitada pelo usuario e gravar no nosso vetor
{
	Pilha_X->dados[Pilha_X->topo++] = valor;//nosso vetor inserindo variavel digitada no topo
}

int pilha_cheia(struct pilha Pilha_X)//fun��o que verifica se pilha est� cheia
{

	if(Pilha_X.topo == MAX)//se o topo da pilha for igual ao numero de elementos de MAX, ent�o t� lotada
	{
		return 1;
	}
	else
	{
		return 0;//sen�o, t� disponivel pra adicionar mais itens
	}

}

int pilha_vazia(struct pilha Pilha_X)//fun��o que verifica se pilha est� vazia
{
	if( Pilha_X.dados == NULL )//se for nulo, ou seja, n�o haver dados retona sim
	{
		return 1;
	}
	else
	{
		return 0;//caso haja dados, retona n�o,e mostra valor removido
	}
}

int consultar_topo(struct pilha Pilha_X)//fun��o que consulta o numero que est� no topo
{
	return Pilha_X.dados[Pilha_X.topo - 1];//consultar o numero que est� no topo -1
}

void desempilhar (struct pilha *Pilha_X)//fun��o para deletar o numero do topo
{
	Pilha_X->dados[Pilha_X->topo--];//deleta o numero do topo
}

int altura(struct pilha Pilha_X)//fun��o que retona a altura da pilha
{

	if(Pilha_X.topo == -1)//caso esteja vazio, retorna zero
	{
		return 0;
	}
	else
	{
		return (Pilha_X.topo + 1);//consultando o topo, caso != de -1
	}
}


//==============================================================================
//============================<<<< FILA >>>>====================================
//==============================================================================
void menu_Fila()
{
	struct fila Fila;
	inicializarFila(&Fila);

	system("color f0");
	int op, valor;
	do
	{
		printf("\n\n >> FILA << ");
		printf("\n\t 1 -> Inserir");
		printf("\n\t 2 -> Inicio");
		printf("\n\t 3 -> Remover");
		printf("\n\t 4 -> Tamanho");
		printf("\n\t 0 -> sair");
		printf("\n\t Digite:  ");
		scanf("%d", &op);
		system("cls");
		switch(op)
		{
		case 1:
			if(fila_cheia(Fila))
				printf("\n\t FILA ESTAH CHEIA !!!");
			else
			{
				printf("\n\t Digite um valor:  ");
				fflush(stdin);
				scanf("%d", &valor);
				enfileirar(&Fila, valor);
			}

			break;
		case 2:
			if(fila_vazia(Fila))
				printf("\n\t FILA ESTAH VAZIA !!!");
			else
				printf("\n\n Primeiro da FILA:  %d ", consultar_primeiro_da_Fila(Fila));

			break;
		case 3:
			if(fila_vazia(Fila))
				printf("\n\t FILA ESTAH VAZIA !!!");
			else
				printf("\n\n\t Valor removido: %d", consultar_primeiro_da_Fila(Fila));
			desenfileirar(&Fila);

			break;
		case 4:
			printf("\n\n\t Tamanho da FILA eh: %d", tamanho(Fila));

			break;
		case 0:
			printf("\n\n ... saindo ... \n\n");

			break;
		default:
			printf("\nOpcao Invalida");
		}
	}
	while(op != 0);
}

void inicializarFila(struct fila *Fila_X)/*Fun��o responsavel pala inser��o de valores na fila
                                            com o valores iniciais de uma fila vazia, ou seja, em -1*/
{
	Fila_X->inicio = - 1;
	Fila_X->fim = - 1;
}

int fila_cheia(struct fila Fila_X)//fun��o que verifica o status do fila
{
	if (tamanho(Fila_X) == MAX )//se a fila estiver com seu limite maximo (MAX), retorna fila cheia
	{
		return 1;
	}
	else
	{
		return 0;//caso contrario, continua o processo de inserir dados pelo usuario
	}
}

int fila_vazia(struct fila Fila_X)//semelhante � fun��o anterior, responsavel por verificar se fila est� vazia
{
	if (Fila_X.inicio == -1)//se estiver vazia (NULL ou -1), retorna o aviso de lista sem dados (vazia)
	{

		return 1;
	}
	else
	{
		return 0;//caso contrario, consulta o primeiro da fila e mostra na tela
	}
}

void enfileirar(struct fila *Fila_X, int valor)//inserindo o pessoal no final da fila
{
	if ( Fila_X->inicio == - 1)/*se o inicio da fila estiver NULL ou vazio, ele insere dados no meio de MAX, ou seja,
	                              20 / 2 = 10, respeitando as caracteristicas da estrutura e evitando futuros problemas
						         caso fossem removidos do inicio e movidos para frente. */
	{
		Fila_X->inicio = Fila_X->fim = (int) MAX / 2;
	}
	else
	{
		Fila_X->fim++;//inserindo os ultimos dados recebidos pelo usuario no fim (fim++)
	}
	Fila_X->dados[Fila_X->fim] = valor;//MAX recebendo o valor digitado pelo teclado, com limite de 20 posi�oes


}

int consultar_primeiro_da_Fila(struct fila Fila_X)//consultando quem � o primeiro da fila
{
	return Fila_X.dados[Fila_X.inicio];
	//segui o mesmo exemplo usado na pilha - - - - - return Pilha_X.dados[Pilha_X.topo - 1];
}

void desenfileirar (struct fila *Fila_X)//deletando o primeiro da fila, e colocando o posterior na frente
{
	/*Fila_X->dados[Fila_X->inicio--]; ----> aqui foram alguns erros iniciais at�
	                                     entender que a fila funciona como o deque

	 Pilha_X->dados[Pilha_X->topo--];*/

	Fila_X->inicio++;

	if (Fila_X->inicio == Fila_X->fim)
	{

		Fila_X->dados[(int) MAX / 2] = Fila_X->dados[Fila_X->inicio];
		Fila_X->inicio = Fila_X->fim = (int) MAX / 2;
	}
	else if (Fila_X->inicio > Fila_X->fim)
	{
		Fila_X->inicio = -1;
	}
}

int tamanho(struct fila Fila_X)//aqui contamos a quantidade de elementos e determinamos o tamanho da fila
{
	if (Fila_X.inicio == -1)//se a fila estiver vazia, ir� avisar
	{
		return 0;
	}
	else
	{
		return (Fila_X.fim + 1) - Fila_X.inicio; //opera��o determinando o tamanho da fila
		//outra alternativa usada em outra atividade (Fila_X.inicio - Fila_X.fim + 1);
	}


}

//==============================================================================
//============================<<<< DEQUE >>>>===================================
//==============================================================================
void menu_Deque()
{
	struct fila Deque;
	inicializarFila(&Deque);

	system("color f9");
	int op, valor;
	do
	{
		printf("\n\n >> DEQUE << ");
		printf("\n\t 1 -> Inserir INICIO");
		printf("\n\t 2 -> Inserir FIM");
		printf("\n\t 3 -> Consulta Inicio");
		printf("\n\t 4 -> Consulta Fim");
		printf("\n\t 5 -> Remover INICIO");
		printf("\n\t 6 -> Remover FIM");
		printf("\n\t 7 -> Tamanho");
		printf("\n\t 0 -> sair");
		printf("\n\t Digite:  ");
		scanf("%d", &op);
		system("cls");
		switch(op)
		{
		case 1:
			if(fila_cheia(Deque))
				printf("\n\t DEQUE ESTAH CHEIO !!!");
			else
			{
				printf("\n\t Digite um valor:  ");
				fflush(stdin);
				scanf("%d", &valor);
				InserirInicio(&Deque, valor);
			}

			break;
		case 2:
			if(fila_cheia(Deque))
				printf("\n\t DEQUE ESTAH CHEIO !!!");
			else
			{
				printf("\n\t Digite um valor:  ");
				scanf("%d", &valor);
				InserirFim(&Deque, valor);
			}

			break;
		case 3:
			if(fila_vazia(Deque))
				printf("\n\t DEQUE ESTAH VAZIO !!!");
			else
				printf("\n\n Primeiro elemento do Deque:  %d ", consultar_primeiro_da_Fila(Deque));

			break;
		case 4:
			if(fila_vazia(Deque))
				printf("\n\t DEQUE ESTAH VAZIO !!!");
			else
				printf("\n\n Ultimo elemento do Deque:  %d ", consultar_ultimo_do_deque(Deque));

			break;
		case 5:
			if(fila_vazia(Deque))
				printf("\n\t DEQUE ESTAH VAZIO !!!");
			else
				printf("\n\n\t Valor removido: %d", consultar_primeiro_da_Fila(Deque));
			removerInicio(&Deque);
			system("pause");
			break;
		case 6:
			if(fila_vazia(Deque))
				printf("\n\t DEQUE ESTAH VAZIO !!!");
			else
				printf("\n\n\t Valor removido: %d", consultar_ultimo_do_deque(Deque));
			removerFim(&Deque);

			break;
		case 7:
			printf("\n\n\t Tamanho do DEQUE eh: %d", tamanho(Deque));

			break;
		case 0:
			printf("\n\n ... saindo ... \n\n");

			break;
		default:
			printf("\nOpcao Invalida");
		}
	}
	while(op != 0);
}

void InserirFim(struct fila *Fila_X, int valor)//Aqui temos a fun��o responsavel por inserir dados no fim da estrutura
{
	if ( Fila_X->inicio == - 1)
	{
		Fila_X->inicio = Fila_X->fim = (int) MAX / 2;
	}
	else
	{
		Fila_X->fim++;
	}
	Fila_X->dados[Fila_X->fim] = valor;
}


void InserirInicio(struct fila *Fila_X, int valor)//Aqui inserimos dados no inicio da estrutura
{
	if(fila_vazia(*Fila_X))
		Fila_X->fim = Fila_X->inicio =  (int) MAX / 2;
	else
		Fila_X->inicio--;

	Fila_X->dados[Fila_X->inicio] = valor;
}

int consultar_ultimo_do_deque(struct fila Fila_X)//Aqui consultamos quem � o ultimo elemento do deque
{
	return Fila_X.dados[Fila_X.fim];
}

void removerInicio (struct fila *Fila_X)//Aqui removemos elementos que estiver localizado no inicio do deque
{
	Fila_X->inicio++;

	if (Fila_X->inicio == Fila_X->fim)
	{

		Fila_X->dados[(int) MAX / 2] = Fila_X->dados[Fila_X->inicio];
		Fila_X->inicio = Fila_X->fim = (int) MAX / 2;
	}
	else if (	Fila_X->inicio > Fila_X->fim)
	{
		Fila_X->inicio = -1;
	}
}

void removerFim (struct fila *Fila_X)//Aqui removemos itens do fim da estrutura
{
	Fila_X->fim--;

	if (Fila_X->inicio == Fila_X->fim)
	{

		Fila_X->dados[(int) MAX / 2] = Fila_X->dados[Fila_X->inicio];
		Fila_X->inicio = Fila_X->fim = (int) MAX / 2;
	}
	else if (	Fila_X->inicio > Fila_X->fim)
	{
		Fila_X->inicio = -1;
	}
}


//==============================================================================
//============================<<<< LDE >>>>===================================
//==============================================================================
void menu_LDE()
{
	int op;
	LISTA *lista;
	inicia_lista(&lista);

	system("color f0");

	do
	{
		printf("\n\n >> LDE << ");
		printf("\n\t 1 -> Inserir INICIO");
		printf("\n\t 2 -> Inserir FIM");
		printf("\n\t 3 -> Consultar Inicio");
		printf("\n\t 4 -> Consultar Fim");
		printf("\n\t 5 -> Remover INICIO");
		printf("\n\t 6 -> Remover FIM");
		printf("\n\t 7 -> Imprimir INICIO - FIM");
		printf("\n\t 8 -> Imprimir FIM - INICIO");
		printf("\n\t 9 -> Tamanho do Deque");
		printf("\n\t 0 -> sair");
		printf("\n\t Digite:  ");
		scanf("%d", &op);
		system("cls");
		switch(op)
		{
		case 1:
			InserirInicio(&lista, getValue());
			system("pause");
			system("cls");
			break;
		case 2:
			InserirFim( &lista, getValue());
			system("pause");
			system("cls");
			break;
		case 3:
			consultarInicio(lista);
			system("pause");
			system("cls");
			break;
		case 4:
			consultarFim(lista);
			system("pause");
			system("cls");
			break;
		case 5:
			printf("\n Valor %d removido do INICIO.\n\n\n\n\n", removerInicio(&lista));
			system("pause");
			system("cls");
			break;
		case 6:
			printf("\n Valor %d removido do FIM.\n\n\n\n", removerFim(&lista));
			system("pause");
			system("cls");
			break;
		case 7:
			imprimeInicioFim(lista);
			system("pause");
			system("cls");
			break;
		case 8:
			imprimeFimInicio(lista);
			system("pause");
			system("cls");
		case 9:
			consultaTamanho(lista);
			system("pause");
			system("cls");
		case 0:
			printf("\n\n ... saindo ... \n\n");

			break;
		default:
			printf("\nOpcao Invalida\n\n\n");
		}
	}
	while(op != 0);
}

int getValue()
{
	int valor;
	printf("\n Digite um numero inteiro: ");
	scanf("%d", &valor);
	return valor;
}

void inicia_lista(LISTA** L)//fun��o responsavel pelo teste da LDE, verificando se est� disponivel para iniciar
{

	if (((*L) = (LISTA*) malloc(sizeof(LISTA))) == NULL)/*aqui temos 02 fun�oes importantes quando falamos de uso
		                                                 dinamico da memoria, a malloc () e a sizeoff ().
	                                                    Esse if () est� testando se a lista est� vazia, testando
	                                                    ao mesmo tempo a aloca��o de memoria em "LISTA" */
	{
		printf("\n -------- Memoria Insuficiente -------\n");
		system("pause");
	}
	else//Caso a memoria esteja livre, ele inicia a LDE com inicio e fim == 0 ou NULL, e tam == 0, iniciando nossa LDE
	{
		(*L)->inicio = NULL;
		(*L)->fim = NULL;
		(*L)->tam = 0;
	}

}

void inicia_no(NO** N, int val)//Pelo que entendi, essa fun��o � reponsavel pela inser��o do primeiro dado na LDE
{

	if (((*N) = (NO*) malloc(sizeof(NO))) == NULL)//aqui ele vai testar se h� mamoria disponivel
	{
		printf("\n -------- Memoria Insuficiente -------\n");//caso sim, informa por meio de um printf ()
		system("pause");
	}
	else//caso a memoria esteja disponivel...
	{
		(*N)->valor = val;//ele recebe o valor digitado pelo usuario
		(*N)->anterior = NULL;//o ponteiro anterior do valor digitado aponta pra NULL (j� que lele � o primeiro)
		(*N)->proximo = NULL;//o ponteiro proximo do valor digitado aponta para NULL (j� que s� h� ele no "banco de dados")
	}
}

void InserirInicio(LISTA** L, int val)//fun��o responsavel pela inser��o de dados no inicio da LDE
{
	NO *novo;
	inicia_no(&novo, val);//aqui � aquela fun��o anterior responsavel pelo primeiro dado digitado.

	if((*L)->tam == 0) //se a LISTA n�o houver dados (tam == 0), ele insere o dado recebido
	{
		(*L)->inicio = novo;//inicio recebendo variavel digitada
		(*L)->fim = novo;/*fim recebendo a mesma variavel digitada
		                  ----> sendo a primeira digitada, consequentemente ela
					            ser� a primeira e ultima presenta na LDE*/
		(*L)->tam++;//tamanho ganhando +1
	}
	else//pelo que entendi aqui, se j� houver um dado na memoria, ele insere no proximo e aponta para o anterior
	{
		novo->proximo = (*L)->inicio;
		(*L)->inicio->anterior = novo;
		(*L)->inicio = novo;
		(*L)->tam++;
	}

}

void InserirFim(LISTA** L, int val)//Nessa fun��o, � o mesmo esquema de fun��o InserirInicio (), s� que insere os dados no final da LDE
{

	NO *novo;
	inicia_no(&novo, val);

	if((*L)->tam == 0)
	{
		(*L)->inicio = novo;
		(*L)->fim = novo;
		(*L)->tam++;
		printf("\n--- Valor inserirido no FIM ---\n\n\n\n");
	}
	else
	{
		novo->anterior = (*L)->fim;
		(*L)->fim->proximo = novo;
		(*L)->fim = novo;
		(*L)->tam++;
		printf("\n--- Valor inserirido no FIM ---\n\n\n\n");
	}


}

int removerInicio(LISTA** L)//Remover itens do inicio da LDE
{
	if( L == NULL)//verifica se a LISTA � == 0 ou NULL (vazia)
	{
		printf("\n ---VAZIO ---\n");
		system("pause");
	}
	else//caso exista dados na LISTA,
	{
		int valor = (*L)->inicio->valor;
		NO *aux = (*L)->inicio;//ponteiro aux recebendo valor de inicio
		(*L)->inicio = (*L)->inicio->proximo;//inicio recebendo o proximo dado da fila, j� que o primeiro vai ser "apagado"
		(*L)->inicio->anterior = NULL;//o primeiro dado da LDE � "deletado" ou substituido por NULL
		free(aux);//aqui libera o espa�o de memoria que estava oculpado (aux), disponibilizando para o uso posteriormente
		(*L)->tam--;//tamanho decresce - 1
		printf("\n---Valor Removido do INICIO ---\n\n\n\n");
		return  valor;//retorna o valor removido

	}
}


int removerFim(LISTA** L)//Remover itens do inicio da LDE ( mesmo esquema da fun��o removerInicio ()
{
	if( L == NULL)
	{
		printf("\n ---VAZIO ---\n");
		system("pause");
	}
	else
	{
		int valor = (*L)->fim->valor;
		NO *aux = (*L)->fim;
		(*L)->fim = (*L)->fim->anterior;
		(*L)->fim->proximo = NULL;
		free(aux);
		(*L)->tam--;
		printf("\n--- Valor Removido do FIM ---\n\n\n\n");
		return  valor;

	}
}

void consultarInicio(LISTA * L)//fun��o que consulta o inicio da LDE
{

	if ( L == NULL)//se lista estiver nazia (NULL ou == 0)
	{
		printf("\n--- Vazio ---\n");//um printf () informando
		system("pause");
	}
	else
	{
		printf("\n [%d] Valor do INICIO. \n\n\n", L->inicio->valor);//caso tenhamos dados l�, mostrar� o valor que est� no inicio
	}

}

void consultarFim(LISTA* L)//fun��o que consulta o inicio da LDE, mesmo esquema da fun��o consultaInicio ()
{
	if ( L == NULL)
	{
		printf("\n--- Vazio ---\n");
		system("pause");
	}
	else
	{
		printf("\n [%d] Valor do FIM. \n\n\n", L->fim->valor);
	}

}

void consultaTamanho(LISTA* L)//aqui consultamos o tamanho da LDE
{
	if ( L == NULL)//se a LISTA for NULL ( n�o ter dados nela), est� vazio
	{
		printf("\n--- Deque VAZIO! ---\n");
		system("pause");
	}
	else//caso sim, imprime a quantidade de intens na LDE
	{
		printf("\n Essa LDE possui [%d] Elementos. \n\n\n", L->tam);
	}

}


/*****************************************************************************
Essas 02 fun�oes abaixo (imprimeFimInicio () e imprimeInicioFim ()) s�o 
de carater academico, levando em considera��o que ler e/ou percorrer itens 
da pilha, fila, deque ou LDE s�o um desrepeito �s suas caracteristicas.
******************************************************************************/

void imprimeFimInicio(LISTA* L)//imprime valore da LDE que est�o do inico para o fim
{
	if ( L == NULL)//se lista == NULL, est� vazio
	{
		printf("\n--- VAZIO! ---\n");
		system("pause");
	}
	else//caso contrario, imprime enquanto houver dados
	{
		NO *aux = L ->inicio;
		while(aux != NULL)
		{
			printf(" [%d] \n\n", aux->valor);
			aux = aux->proximo;
		}
	}
}
void imprimeInicioFim(LISTA* L)//imprime valore da LDE que est�o do fim para o inicio
{
	if ( L == NULL)//se lista == NULL, est� vazio
	{
		printf("\n--- VAZIO! ---\n");
		system("pause");
	}
	else//caso contrario, imprime enquanto houver dados
	{
		NO *aux = L ->fim;
		while(aux != NULL)
		{
			printf(" [%d]  \n\n", aux->valor);
			aux = aux->anterior;
		}
	}
}