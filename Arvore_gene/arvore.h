typedef struct arv Arv;

//Cria uma árvore vazia
Arv* arv_criavazia (void);

//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
Arv* arv_cria (char* c, Arv* e, Arv* d);

//libera o espaço de memória ocupado pela árvorea
void arv_libera (Arv* a);

//retorna true se a árvore estiver vazia e false
//caso contrário
int arv_vazia (Arv* a);

//imprime as informações dos nós da árvore
void arv_imprime (Arv* a);

//void arv_preordem (Arv* a);

// desenha a arvore
void draw_arvore_hor(Arv* A);

//salva a arvore em um arquivo TXT
void arquivar(Arv* arquivo);

// retorna o endereço das folhas disponiveis para gravação
Arv** folhas(Arv* a);

// grava as folhas direita e esqueda de um nó
void gravarFolha(Arv* a, char* info1, char* info2);

// retorna o valor de info do ponteiro passado
char* retornaInfo(Arv* a);

// retorna o numeros folhas, mas a função folhas deve ser chamada
// primeiro para a variável ser incrementada 
int numFolhas(void);