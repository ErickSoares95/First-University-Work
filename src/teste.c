#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TypeConta{
  char titular[50];
  int numero;
  float saldo;
  char senha[10];

  //Auxiliar para mostrar o historico
  //Operacao atua no historico, atualizando-o
  //Extrato dispoe o historico
  float vetor_historico[100];
  int index_historico;
}TypeConta;

TypeConta clientes[50];

int qte_clientes=0;

void Cadastrar() {
        printf("\nDigite o nome do titular: ");
        fflush(stdin);
        scanf("%s",clientes[qte_clientes].titular);
        printf("Digite o numero da conta: ");
        fflush(stdin);
        scanf("%d",&clientes[qte_clientes].numero);
        printf("Digite o saldo da conta: ");
        fflush(stdin);
        scanf("%f",&clientes[qte_clientes].saldo);
        printf("Digite a senha da conta: ");
        fflush(stdin);
        scanf("%s", clientes[qte_clientes].senha);
        fflush(stdin);
        printf("\nCliente cadastrado com sucesso!");
        printf("\nTitular: %s",clientes[qte_clientes].titular);
        printf("\nNumero: %d",clientes[qte_clientes].numero);
        printf("\nSaldo: %0.2f",clientes[qte_clientes].saldo);
        printf("\nSenha: %s\n",clientes[qte_clientes].senha);
        printf("\nAguarde enquanto processamos nosso sistema!");
        qte_clientes++;
        printf("\n\nTotal de clientes cadastrados: %d   \n",qte_clientes);
        // system("pause"); 
        // system("cls");
}

void Listar() {
    int i;
    for(i=0;i<qte_clientes;i++) {
    	printf("\nTitular: %s",clientes[i].titular);
        printf("\nNumero: %d",clientes[i].numero);
        printf("\nSaldo: %0.2f",clientes[i].saldo);
        printf("\nSenha: %s\n",clientes[i].senha);
		printf("=====================================\n");	
	}
	printf("\nTotal de clientes cadastrados: %d  \n",qte_clientes);
	printf("\n");
	 system("pause");
	 system("cls");
}

int procuraCliente(char usuario[],TypeConta vetor_conta[], int clientes ){

    int i;
    for(i = 0; i < clientes; i++){
        if(!strcmp(usuario, vetor_conta[i].titular)){
            printf("\nTitular: %s\n",vetor_conta[i].titular);
	        printf("\nNumero: %d\n",vetor_conta[i].numero);
	        printf("Saldo inicial: %0.2f\n\n",vetor_conta[i].saldo);
            return i;
        }
    }
    return -1;
}

void Pesquisar() {
	int i,encontrou = 0;
	char nome[50];
    printf("Digite um nome: ");
    scanf("%s",nome);
    
    if(procuraCliente(nome, clientes,qte_clientes) == -1){
        printf("Nenhum cliente foi encontrado.\n\n");
        return;
    }
    printf("\nSenha: %s \n\n",clientes[i].senha);
     system("pause");
	 system("cls");
}



void operacao(){
	char usuario[50];
	char opcao[10]; 
    float saque=0,deposito=0;
	
    printf("\ndigite o nome do usuario a realizar a operacao: ");
    scanf("%s",usuario);

    int cliente_index = procuraCliente(usuario, clientes, qte_clientes);
    if( cliente_index == -1){
        printf("Cliente não encontrado\n\n");
        return;
    }

    printf("\n\nescolha a opcao saque ou deposito: ");
    
    scanf("%s",opcao);

    if(!strcmp(opcao,"saque")){
        printf("\nquanto deseja retirar: ");
        scanf("%f",&saque);

        clientes[cliente_index].saldo -= saque;

        clientes[cliente_index].vetor_historico[clientes[cliente_index].index_historico] = clientes[cliente_index].saldo;
        clientes[cliente_index].index_historico += 1;

        printf("saldo final: %0.2f\n",clientes[cliente_index].saldo);
        
    }
    
    if(!strcmp(opcao, "deposito")){
        printf("%d\n", strcmp(opcao, "deposito"));
        printf("\nquanto deseja depositar: ");
        scanf("%f",&deposito);

        clientes[cliente_index].saldo += deposito;

        clientes[cliente_index].vetor_historico[clientes[cliente_index].index_historico] = clientes[cliente_index].saldo;
        clientes[cliente_index].index_historico += 1;

        printf("saldo final: %0.2f\n\n",clientes[cliente_index].saldo);
         
    }
    
	
}


void extrato(){
	int i,n;
	char usuario[10];
    printf("digite o nome do usuario para solicitar seu extrato: ");
    scanf("%s",usuario);

    int cliente_index = procuraCliente(usuario, clientes, qte_clientes);
	if(cliente_index == -1){
        printf("Cliente não encontrado\n\n");
    }
    if(clientes[cliente_index].index_historico > 0){
        for(i = 0; i < clientes[cliente_index].index_historico; i++ ){
            printf("Extrato %d - %0.2f \n", i+1, clientes[cliente_index].vetor_historico[i] );
        }
    }


}
int main()
{   
    char opcao[20];
do{
    printf("********************************************************************\n");
    printf("  Banco Erick Corporation\n");
    printf("  Escolha uma das opcoes:\n");
    printf("  cadastrar  operacao  pesquisar  extrato  listar  sair\n");
    printf("********************************************************************\n\n");
    scanf("%s",opcao);
    if(!strcmp(opcao,"cadastrar")){
    	Cadastrar();
	}
    if(!strcmp(opcao,"listar")){
		Listar();
	}
    if(!strcmp(opcao,"pesquisar")){
		Pesquisar();
	}
	if(!strcmp(opcao,"operacao")){
		operacao();
	}
	if(!strcmp(opcao,"extrato")){
		extrato();
	}
}while(strcmp(opcao,"sair"));    
return 0;
}
