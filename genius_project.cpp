/***********************************************/
/* Genius Project                              */
/* Programador: Marcos Evaldt Ereno            */
/* Criado em: 25/05/2015                       */
/* Data da ultima alteracao: 25/06/2015        */
/***********************************************/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#define  MAXNUMCORES 4
#define  N_MAX 15

using namespace std;

/***********************************************/
/* Definição dos Registros                     */
/***********************************************/
/*STRUCT'S SEQUENCIAL*/
typedef struct {  	// Registro para uma pessoa     
int score;			// Variavel para receber o score
char nome[30];		// Variavel para receber o nome do rankiado
} NODO;

typedef struct {
NODO info[N_MAX]; // Lista de N_MAX registros
int f;            // Número de registro(s) ocupado(s) na lista
} LISTASEQ;

/***********************************************/
/* Definição dos Registros                     */
/***********************************************/
/*STRUCT'S ENCADEADA*/
typedef struct{    	// Registro para cor
int cor;			// Variavel para receber a cor 
}INFORMACAO;

typedef struct list{
INFORMACAO info;   // Dados do registro
struct list* prox; // Ponteiro para o próximo registro
}LISTA;

/***********************************************/
/* Definição das Funções                       */
/***********************************************/
/*FUNCTION'S SEQUENCIAL*/
void 	cria_listaseq	    ( int  *fim );				   	// Inicializa lista 
void 	inclui_fim      	( LISTASEQ *lista, int score); 	// Inclui score no final da lista
void 	imprime_lista   	( LISTASEQ *lista, int score); 	// Visualização do score
void 	ordena_lista    	( LISTASEQ *lista );		   	// Ordenação do score

/***********************************************/
/* Definição das Funções                       */
/***********************************************/
/*FUNCTION'S ENCADEADA*/
void    cria_lista			( LISTA **l, LISTA **j);		// Inicializa lista
void    inclui_fimrandom	( LISTA **l);					// Inclui cor random no final da lista
void    entrada_dados		( LISTA *aux );					// Leitura de dados
void    entrada_random		( LISTA *aux );					// Chamada para entrada da cor random
void    imprime_lista		( LISTA *aux );					// Visualização da lista das cores  
int     verifica_jogada		( LISTA **l, LISTA **j);		// Verificação das jogadas executada
void 	PlaceCursor			( const int x, const int y);	// Posicionamento do cursor

/***********************************************/
/* Programa Principal                          */
/***********************************************/
/*MAIN PROGRAM*/
int main(){
int op;						// Opção do menu
LISTA* l;					// Declaração da lista
LISTA* j;					// Declaração da lista
LISTASEQ lista;				// Variável do tipo lista = vetor de registros
cria_listaseq( &lista.f );	// Criação automatica da lista sequencia
lista.f=0; 					// Zerando contador da lista sequencial
int pontos; 				// Variavel para receber os pontos
int score=0;				// Variavel dos scores que serão passadas para o ranking
	while (1){
	cout << "--------------------------------------------"<<endl; 
	cout << "                      MENU                  "<<endl;
	cout << "--------------------------------------------"<<endl;
	cout <<"[1] JOGAR"<<endl;
	cout <<"[2] RANKING"<<endl;
	cout <<"[3] DEVELOPER"<<endl;
	cout <<"[0] SAIR"<<endl;
	cout <<"OPCAO: ";
	cin  >> op;															// Recebe a opção
	    switch(op){														// Adentra as opcoes
	    case 1:															// Rotina
		cria_lista( &l , &j);											// Rotina de criação da lista
		score = 0;														// Zera o score do jogador
		do{																// Faça
	    inclui_fimrandom( &l );											// Inclui cor random no final da lista
		imprime_lista( l );												// Imprime a lista cor
	    pontos = verifica_jogada(&l, &j);								// Variavel ponto recebe a verificação da jogada
	    if(pontos!=1)													// Se o ponto for dif de 1 ele pontuara
		score = score + 10;												// Incremento dos pontos
		}while(pontos != 1);											// So retornara 0 se ele errar
		inclui_fim( &lista, score );									// Inclui no fim o jogador que errou com a pontuação
		system("CLS");													// Limpa tela
		break;															// Quebra do looping
	    case 2:															// Rotina
	    ordena_lista( &lista );											// Ordena lista do ranking
	    imprime_lista( &lista, score );									// Imprime a lista de ranking
		break;															// Quebra do looping
		case 3: 														// Mostra o desenvolvedor
		system("CLS");													// Limpa tela
		cout << "--------------------------------------------"<<endl;	// Imprime
		cout << "                    DEVELOPER               "<<endl;	// Imprime
		cout << "--------------------------------------------"<<endl;	// Imprime
		cout <<endl;													// Quebra de linha
		cout << "               MARCOS EVALDT ERENO          "<<endl;	// Imprime
		Sleep(4000);													// Repouso da tela
		system("CLS");													// Limpa tela
		break;															// Quebra do looping
		case 0: 														// Termino do programa
	    exit(1);														// Saida
	    break;															// Quebra do looping
	    default:														// Rotina
	    cout << "                  OPCAO INEXISTENTE         "<<endl;	// Imprime
	    Sleep(1000);													// Repouso da tela
		system("CLS");													// Limpa tela
		break;															// Quebra do looping
	    }																// Fim switch 
	}																	// Fim while
}

/***********************************************/
/*          FUNÇÕES ENCADEADAS                 */
/***********************************************/

/************************************************
 * cria_lista                                   *
 * objetivo: rotina para inicializar a lista    *
 * entrada : fila                               *
 * saída   : NULL                               *
 ************************************************/
void cria_lista( LISTA** l, LISTA **j){
    *l = NULL;	// Lista criada, inicio nao aponta
    *j = NULL;	// Lista criada, inicio nao aponta
}

/************************************************
 * inclui_fimrandom                             * 
 * objetivo: incluir registro no fim da lista   *
 * entrada : lista                              *
 * saída   : lista com novo registro random     *
 ************************************************/
void inclui_fimrandom( LISTA** l ){	
    LISTA* p;											//Ponteiro auxiliar
    LISTA* no =  ( LISTA * ) malloc ( sizeof( LISTA ) );// Aloca novo espaco em memoria 
    if( no != NULL ){									// Verifica se conseguiu alocar memoria para o novo registro                            
             entrada_random( no );						// Le dados                
             if( *l == NULL )							// Lista vazia                    
                 *l= no;								// Insere o primeiro registro                        
             else {										// Senão
                  p = *l;								// Percorre a lista até encontrar o ultimo registro                       
                  while( p->prox != NULL )				// Enquanto lista for dif de nulo
                        p = p->prox;                    // Anda na lista
                  p->prox = no;  						// Ultimo aponta para o novo registro              
                  cout <<endl;                          // Pula linha
                  }                                     // Fim else
        }                                               // Fim (no != NULL) 
    else                                                // Senão
        cout << "LISTA CHEIA"<<endl;                    // Imprime Lista cheia
}

/************************************************
 * entrada_random                               * 
 * objetivo: rotina para receber valor random   *
 * entrada : nodo                               *
 * saída   : nodo com novo valor random         *
 ************************************************/
void entrada_random( LISTA* aux ){
srand( time(NULL) );				// Função randomize
int random = rand()%MAXNUMCORES + 1;// Variavel recebe o valor random dif de nulo
fflush( stdin );					// Limpa dados
aux->info.cor = random;				// registro cor de informação recebe a cor randomica do randomize
aux->prox = NULL;					// o prox registro aponta pro nulo
}

/*************************************************
 * imprime_lista                                 *
 * objetivo: rotina para imprimir dados          *
 * entrada : lista                               *
 * saida   : nenhuma                             *
 *************************************************/
void imprime_lista( LISTA* aux ){
    if( aux == NULL )						 // Se auxiliar for nulo 
        cout <<" EMPTY LIST"<<endl; 		 // Imprime lista vazia
	else {									 // Senão
	      cout << endl; 					 // Quebra de linha
	     while( aux != NULL ){				 // Enquanto aux for dif de nulo
                cout << endl;				 // Quebra de linha
                if (aux->info.cor == 1){ 	 // Se cor randomizada for igual a 1
                 system("cls");				 // Limpa tela
                 Beep( 750, 300 );			 // Aviso sonoro
                 system("color 1A");		 // Pinta tela
                }							 // Fim (aux->info.cor == 1)
                else if (aux->info.cor == 2){// Elseif
                 system("cls");				 // Limpa tela
                 Beep( 700, 300 );			 // Aviso sonoro
				 system("color 2A");		 // Pinta tela	
                }							 // Fim (aux->info.cor == 2)
                else if (aux->info.cor == 3){// Elseif
                 system("cls");				 // Limpa tela
                 Beep( 650, 300 );			 // Aviso sonoro
				 system("color 6A");		 // Pinta tela
                }							 // Fim (aux->info.cor == 3)              
                else{                        // Else
                 Beep( 600, 300 );			 // Aviso sonoro	
                 system("cls");				 // Limpa tela
				 system("color 4A");		 // Pinta tela	
                }							 // Fim else
                aux = aux->prox;			 // Aux aponto para o prox registro
				Sleep(600);					 // Repouso da tela
		 }									 // Fim (aux!=NULL)
		 Sleep(700);						 // Repouso da tela
		 system("color 0f");				 // Pinta tela para o preto novamente
    	 system("cls");						 // Limpa tela
	}										 // Fim else 
}

/************************************************
 * entrada_dados                                *
 * objetivo: rotina para ler dados              *
 * entrada : nodo (ponteiro para o novo espaco) *
 * saida   : nodo com dados                     *
 ************************************************/
void entrada_dados( LISTA* aux ){
	system("CLS");											// Limpa tela
	PlaceCursor(12,10);										// Posiciona cursor
	cout <<"[1] AZUL [2] VERDE [3] AMARELO [4] VERMELHO:";	// Imprime a opção pro usuario
	fflush( stdin );										// Limpa     
	cin >> aux->info.cor; 									// Pega resposta do jogador e coloca na variavel cor
	aux->prox = NULL;     									// Aux aponto pro prox registro
}

/************************************************
 * verifica_jogada                              *
 * objetivo: rotina para verificar jogada       *
 * entrada : duas lista para comparação         *
 * saida   : conferencia das cores              *
 ************************************************/
int verifica_jogada(LISTA** l, LISTA** j){
LISTA* no =  ( LISTA * ) malloc ( sizeof( LISTA ) ); 		// Aloca novo espaco em memoria
LISTA* p = *l;												// Ponteiro auxiliar para percorrer a lista
LISTA* q = *j;												// Ponteiro auxiliar para percorrer a lista
int tempoIni = 0; 											// Pega o tempo inicial, antes da resposta do jogador
int tempoFim = 0; 											// Pega o tempo final, depois da resposta do jogador
int seg = 0; 												// Tempo em segundos da resposta
tempoIni = time(NULL);										// Tempo Inicial
	do{													 	// Faça
		entrada_dados(no);									// Leitura dos dados
		tempoFim = time(NULL);								// Tempo final
		do{													// Faça
			seg = tempoFim - tempoIni;						// Diferença do tempo inicial do final
			q = no;											// Lista recebe o espaco alocado
			if ((q->info.cor == p->info.cor) and seg < 9) {	// Se a cor da maq for igual ao do usuario e menor que 9 segundos
			p = p->prox;									// Prox registro
    		q = q->prox;									// Prox registro
			}else{											// Senao
			return 1;										// Retorna 1
			break;											// Quebra do ciclo
			}												// Fim else
		}while(q != NULL);									// Condicao
	}while(p != NULL);										// Condição
}

/***********************************************/
/*          FUNÇÕES SEQUENCIAIS                */
/***********************************************/

/************************************************
 * cria_listaseq                                *
 * objetivo: rotina para inicializar a lista    *
 * entrada : fim da lista                       *
 * saída   : fim da lista atualizado, com 0     *
 ************************************************/
void cria_listaseq( int *fim ){	
    *fim = 0;  // Iniciliza lista
}

/************************************************
 * inclui_fim                                   *
 * objetivo: rotina para inserir no fim da lista*
 * entrada : lista                              *
 * saída   : lista com novo elemento            *
 ************************************************/
void inclui_fim( LISTASEQ *lista, int score ){
if(lista->f == N_MAX){
	 system("CLS");
	 PlaceCursor(30,10);
	 cout << "LISTA CHEIA"<<endl;
	 Sleep(5000);
}else{
system("CLS");													// Limpa tela
cout << "--------------------------------------------"<<endl;	// Imprime
cout << "                   VOCE ERROU               "<<endl;	// Imprime
cout << "--------------------------------------------"<<endl;	// Imprime
cout << "DIGITE SEU NOME: ";									// Imprime
cin  >> lista->info[lista->f].nome;								// Coloca o nome digita na variavel nome
cout << endl << "SEU SCORE:" << score<<endl;					// Imprime o score
lista->info[lista->f].score = score;							// Coloca o score jogado na variavel score da lista sequencial
lista->f++;														// Incrementa a lista
 Sleep(3000);													// Repouso da tela	
}

}

/*************************************************
 * imprime_lista                                 *
 * objetivo: rotina para imprimir dados          *
 * entrada : lista                               *
 *************************************************/
void imprime_lista( LISTASEQ *lista, int score ){
system("CLS");													// Limpa tela
cout << "--------------------------------------------"<<endl;	// Imprime
cout << "                   RANKING                  "<<endl;	// Imprime
cout << "--------------------------------------------"<<endl;	// Imprime
    int i;														// Declaração do incrementador
    if ( lista->f == 0 )										// Se lista for nula
    cout <<"NENHUM JOGADOR NO RANKING"<<endl; 					// Imprime
    for( i = 0 ; i < lista->f ; i++ ) {							// Percorre a lista
    cout << "Nome  : " << lista->info[i].nome<<endl;			// Imprime o nome do rankeado
    cout << "Pontos: " << lista->info[i].score <<endl;			// Imprime o score do rankeado
    cout <<endl;												// Quebra de linha
    }															// Fim ( i = 0 ; i < lista->f ; i++ )
Sleep(1000);													// Repouso da tela
}

/************************************************
* ordena_lista                                  *
* objetivo: rotina para ordenar lista por codigo*
* entrada : lista                               *
* saída : lista ordenada                        *
*************************************************/
void ordena_lista( LISTASEQ *lista ){
 int i, j;																		// Declaração dos indices
 NODO aux;																		// Auxiliar para troca de dados
    if( lista->f == 0 )															// Se lista for vazia
        cout <<" ";																// Imprime
    else																		// Senão
       if( lista->f == 1 )														// Se lista for igual a 1
       cout<<endl<<"APENAS UM REGISTRO"<<endl<<endl;							// Imprime
       else																		// Senão
          if( lista->f == N_MAX )												// Se lista estiver lotada
              printf( "\n Lista cheia!" );										// Imprime
          else {																// Senão
              for( i = 0; i < lista->f-1; i++)									// Percorre a lista
                   for( j = i + 1; j < lista->f; j++)							// Percorre a lista 
                        if( lista->info[ j ].score > lista->info[ i ].score )	// Se o primeiro indice for maior que o segundo
                        {														// {
                            aux = lista->info[ j ];								// Aux recebe a posição posterior 
                            lista->info[ j ] = lista->info[ i ];				// J recebe I
                            lista->info[ i ] = aux;								// I recebe o aux que guardada o posterior
                        }														// {
            }																	// Fim else
}

/************************************************
 * PlaceCursor                                  * 
 * objetivo: posicionar cursor                  *
 ************************************************/
void PlaceCursor(const int x, const int y) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD PlaceCursorHere;
    PlaceCursorHere.X = x;
    PlaceCursorHere.Y = y;

    SetConsoleCursorPosition(hConsole, PlaceCursorHere);
    return;
}