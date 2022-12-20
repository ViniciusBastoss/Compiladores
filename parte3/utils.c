// Estrutura da Tabela de Simbolos

#define TAM_TAB 100
//#include <string.h>

struct elemTabSimbolos {
    char id[100];  // identificador
    int end;       // endereço
    int tip;       // tipo
} tabSimb[TAM_TAB], elemTab;

int posTab = 0;

/*void maiuscula (char *s){
    for(int i = 0; s[i]; i++)
       s[i] = toupper(s[i]);
}
*/
int buscaSimbolo(char *id){
    int i;
    //maiuscula(id);
    for (i = posTab - 1; strcmp(tabSimb[i].id, id) && i >= 0; i--);

    if(i == -1)
    {
        char msg[100];
        sprintf(msg, "Identificador [%s] não encontrado!", id);
        yyerror(msg);
    }
 
    return i;
}

void insereSimbolo (struct elemTabSimbolos elem){
    int i;
    //maiuscula(elem.id);
    if(posTab == TAM_TAB)
        yyerror("Tabela de Simbolos Cheia!");
    for (i = posTab - 1; strcmp(tabSimb[i].id,elem.id) && i >= 0; i--);
    //i = buscaSimbolo(elem.id);
    if( i != -1)
    {
        char msg[200];
        sprintf(msg, "Identificador [%s] duplicado!", elem.id);
        yyerror(msg);
    }
       
    tabSimb[posTab++] = elem;

}

void mostraTabela(){
    puts("Tabela de Simbolos");
    puts("------------------");
    printf("\n%30s | %s\n", "ID", "END");
    for(int i = 0; i < 50; i++)
        printf("-");
    for(int i = 0; i < posTab; i++)
        printf("\n%30s | %d", tabSimb[i].id, tabSimb[i].end);
    printf("\n");
}

//Estrutura da Pilha Semantica
// usada para enderecos, variaveis, rotulos

#define TAM_PIL 100
int pilha[TAM_PIL];
int topo = -1;

void empilha (int valor){
    if(topo == TAM_PIL)
       yyerror("Pilha semântica cheia!");
    pilha[++topo] = valor;
}

int desempilha(){
    if (topo == -1)
       yyerror("Pilha semântica vazia!");
    return pilha[topo--];
}



