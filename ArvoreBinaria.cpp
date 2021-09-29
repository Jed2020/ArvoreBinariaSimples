#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//estrutura chamada arvore. carcter chamada item. ponteiro arvore direito e esquerdo
struct arvore{ 
    char item;
    arvore *esq,*dir; 
};

//estrutura arvore recebe ponteiro raiz. e um contador declarado
arvore *Raiz;
int contador;

//inicializando raiz e contador na função construtor
void arvore_Construtor(){
    Raiz=NULL;
    contador=0;
}

//função inserir, alocando na mempria a estrutura arvore. se raiz nao for nula, senao recebe letra, ordem esquerda e depois direita. Contador soma o número de leteas.
bool arvore_Inserir(char letra, arvore *&Raiz){
    if(Raiz==NULL){
        if((Raiz=(arvore *) malloc(sizeof(arvore)))==NULL)
            return false;
        else{
            Raiz->item=letra;
            Raiz->esq=Raiz->dir=NULL;
            contador++;
            return true;
        }
    }
    else{
        if(letra<Raiz->item)
            return arvore_Inserir(letra,Raiz->esq);
        else{
            if(letra>Raiz->item)
                return arvore_Inserir(letra,Raiz->dir);
            else
                return false;//letra já existe na árvore
        }
    }
}

//percorre a árvore na ordem esquerda e direita.
void arvore_Busca_em_Ordem(arvore *&Raiz){
    if(Raiz!=NULL){
        arvore_Busca_em_Ordem(Raiz->esq);
        printf(" %c",Raiz->item);
        arvore_Busca_em_Ordem(Raiz->dir);
    }
}

//menu função opção, chama função contrutor. Informações de menu imprimir informe letra e mais dados
int main(){
    char x,opcao;

    arvore_Construtor();

    do{
        printf("\nInforme a letra: ");
        setbuf(stdin,NULL);
        scanf("%c",&x);

        arvore_Inserir(x,Raiz);

        printf("\nMais dados? S/N:  ");
        setbuf(stdin,NULL);
        scanf("%c",&opcao);
    }while(toupper(opcao)!='N');

//  imprime o tamanho da árvore
    printf("\nQuantidade de elementos: %d\n",contador);

//   impressão em ordem digitada
    printf("\nArvore em ordem:\n");
    arvore_Busca_em_Ordem(Raiz);
    printf("\n\n");

    return 0;
}
