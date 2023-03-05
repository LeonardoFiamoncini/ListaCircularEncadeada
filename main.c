#include "lista.c"

void josephus(pplista l);

int main (void) {
    setlocale(LC_ALL, "Portuguese");
    srand(time(0));

    plista lst;

    criarLista(&lst);

    inserirInicio(&lst, 10, "Soldado10010");
    inserirInicio(&lst, 20, "Soldado10020");
    inserirFinal(&lst, 30, "Soldado10030");
    inserirPosK(&lst, 2, 40, "Soldado10040");
    inserirFinal(&lst, 50, "Soldado10050");

    imprimirLista(lst);

    printf("\nDeseja iniciar?\n1) Sim.\n2) Não.\nOpção: ");
    int opcao;
    scanf("%d", &opcao);
    
    if(opcao == 1) josephus(&lst);
    else printf("Opção inexistente.");

    if (lst->dimensao == 1) {
        printf("\n\nO soldado ganhador é: ");
        imprimirLista(lst);
    }

    printf("\nSaindo do programa...");
}

void josephus(pplista l){
    if ((*l)->dimensao > 0){
        /*
        Sorteio realizado para escolher o soldado inicial.
        A dimensão da lista é considerada para realizar o sorteio.
        */
        int k = 1 + (rand() % ((*l)->dimensao));
        
        bloco *tmp = (*l)->inicio;
        bloco *ant = NULL;
        int pos;
        for (pos = 1; pos != k; pos++) {
            ant = tmp;
            tmp = tmp->prox;
        }    

        printf("\nO soldado sorteado inicialmente foi: %s", tmp->nome);

        int r = 1 + (rand() % 100);
        printf("\nNúmero sorteado: %d\n\n", r);
        int count = 0;
        while ((*l)->dimensao != 1){
            if (count == r){
                int n = removerPosK(l, pos);
                count = 0;
                printf("\n\nContinuar?\n1) Sim.\n2) Não.\nOpção: ");
                int opcao;
                scanf("%d", &opcao);
                if (opcao != 1) {
                    printf("Opção inexistente.");
                    break;
                }
            } else {
                count++;
                pos++;
            } 
            if (pos > (*l)->dimensao) {
                pos = 1;
            }   
        }   
    }
}