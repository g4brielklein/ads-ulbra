#include <stdio.h>
#include <stdlib.h>

typedef struct data1{
	int cod;
	char nome[30];
	char email[30];
	char telefone[13];
	char logradouro[200];
	char cidade[20];
	char estado[20];
	char cep[8];
	char cpf[11];
	char rg[8];
	char data_nascimento[10];
	
}clientes;


int menu();
void cadastrarClientes();
void buscarClienteId();
void listarClientes();

void main(){
	int op;
	do{
		op = menu();
		switch(op){
			case 1:
				cadastrarClientes();
				break;
			case 2:
				listarClientes();
				break;
			case 3: 
				buscarClienteId();
				break;
			case 0:
				printf("  Saindo!\n");
				break;
			default:	
				printf("Escolha uma opcao valida\n");
				break;
		}
	}while(op != 0);
}
int menu(){
	int op;
	
	printf("\n       == MENU ==        \n\n");
	printf(" (1)...Cadastrar clientes\n");
	printf(" (2)...Listar clientes\n");
	printf(" (3)...Buscar clientes\n\n");
	printf(" ---------------------\n\n");
	printf(" (0)...Sair do sistema\n\n");
	printf("  Escolha uma opcao: ");
	scanf("%d", &op);
	printf("\n");
	return(op);
}
void cadastrarClientes(){
	clientes cliente;
	FILE *arq_clientes;
	arq_clientes = fopen("clientes.txt", "a");
	if(arq_clientes == NULL){
		printf("\nERRO AO ABRIR O ARQUIVO");
		exit(1); 
	}
	system("cls");
	printf("\n ==== Cadastro de clientes ==== \n");
	printf("\nInforme um codigo para o cliente: ");
	scanf("%d", &cliente.cod);
	fprintf(arq_clientes, "%d\n", cliente.cod);
	
	printf("\nInforme o nome: ");
	setbuf(stdin, NULL);
	scanf(" %[^\n]s", cliente.nome);
	fprintf(arq_clientes, "%s\n", cliente.nome);
	
	printf("\nInforme o email: ");
	scanf(" %[^\n]s", cliente.email);
	fprintf(arq_clientes, "%s\n", cliente.email);
	
	printf("\nInforme o telefone: ");
	scanf(" %[^\n]s", cliente.telefone);
	fprintf(arq_clientes, "%s\n", cliente.telefone);
	
	printf("\nInforme o logradouro: ");
	scanf(" %[^\n]s", cliente.logradouro);
	fprintf(arq_clientes, "%s\n", cliente.logradouro);
	
	printf("\nInforme a cidade: ");
	scanf(" %[^\n]s", cliente.cidade);
	setbuf(stdin, NULL);
	fprintf(arq_clientes, "%s\n", cliente.cidade);
	
	printf("\nInforme o estado: ");
	scanf(" %[^\n]s", cliente.estado);
	fprintf(arq_clientes, "%s\n", cliente.estado);
	
	printf("\nInforme o cep: ");
	scanf(" %[^\n]s", cliente.cep);
	fprintf(arq_clientes, "%s\n", cliente.cep);
	
	printf("\nInforme o cpf: ");
	scanf(" %[^\n]s", cliente.cpf);
	fprintf(arq_clientes, "%s\n", cliente.cpf);
	
	printf("\nInforme o rg: ");
	scanf(" %[^\n]s", cliente.rg);
	fprintf(arq_clientes, "%s\n", cliente.rg);
	
	printf("\nInforme o data de nascimento(dd/mm/aaaa): ");
	scanf(" %[^\n]s", cliente.data_nascimento);
	fprintf(arq_clientes, "%s\n", cliente.data_nascimento);
	
	printf("\n === Cliente cadastrado! === \n\n");
	fclose(arq_clientes);
	system("pause");
	system("cls");
}

void listarClientes(){
		clientes cliente;
		FILE *arq_clientes;
		arq_clientes = fopen("clientes.txt", "r");
		if(arq_clientes == NULL){
			printf("\nERRO AO ABRIR O ARQUIVO");
			exit(1);
		}
		system("cls");
		printf("\n ==== Lista de clientes: ==== \n");
		while(1){	
			fscanf(arq_clientes, "%d", &cliente.cod);
			if(feof(arq_clientes)){
				break;
			}
			printf("\n COD [%d]", cliente.cod);
		
			fscanf(arq_clientes, " %[^\n]s", cliente.nome);
			printf("\n Nome do cliente: %s", cliente.nome);
			
			fscanf(arq_clientes, " %[^\n]s", cliente.email);
			printf("\n Email: %s", cliente.email);
	
			fscanf(arq_clientes, " %[^\n]s", cliente.telefone);
			printf("\n Telefone: %s", cliente.telefone);
			
			fscanf(arq_clientes, " %[^\n]s", cliente.logradouro);
			printf("\n Logradouro: %s", cliente.logradouro);
			
			fscanf(arq_clientes, " %[^\n]s", cliente.cidade);
			printf("\n Cidade: %s", cliente.cidade);
			
			fscanf(arq_clientes, " %[^\n]s", cliente.estado);
			printf("\n Estado: %s", cliente.estado);
			
			fscanf(arq_clientes, " %[^\n]s", cliente.cep);
			printf("\n Cep: %s", cliente.cep);
			
			fscanf(arq_clientes, " %[^\n]s", cliente.cpf);
			printf("\n Cpf: %s", cliente.cpf);
			
			fscanf(arq_clientes, " %[^\n]s", cliente.rg);
			printf("\n Rg: %s", cliente.rg);
			
			fscanf(arq_clientes, " %[^\n]s", cliente.data_nascimento);
			printf("\n Data de Nascimento: %s\n", cliente.data_nascimento);
			printf(" -----------------------");
		}fclose(arq_clientes);	
		printf("\n\n === FIM DA LISTA ===\n\n");
		system("pause");
		system("cls");
}
void buscarClienteId(){
	clientes cliente;
	FILE *arq_clientes;
	arq_clientes = fopen("clientes.txt", "r");
	if(arq_clientes == NULL){
		printf("\nERRO AO ABRIR O ARQUIVO");
		exit(1);
	}
	int cod;
	system("cls");
	printf("\n === Buscar cliente ===\n");
	printf("\n Informe o codigo do cliente: ");
	scanf("%d", &cod);
	while (!feof(arq_clientes)){
			// le todo o arquivo 
			fscanf(arq_clientes, "%d", &cliente.cod);
			fscanf(arq_clientes, " %[^\n]s", cliente.nome);
			fscanf(arq_clientes, " %[^\n]s", cliente.email);
			fscanf(arq_clientes, " %[^\n]s", cliente.telefone);
			fscanf(arq_clientes, " %[^\n]s", cliente.logradouro);
			fscanf(arq_clientes, " %[^\n]s", cliente.cidade);
			fscanf(arq_clientes, " %[^\n]s", cliente.estado);
			fscanf(arq_clientes, " %[^\n]s", cliente.cep);
			fscanf(arq_clientes, " %[^\n]s", cliente.cpf);
			fscanf(arq_clientes, " %[^\n]s", cliente.rg);	
			fscanf(arq_clientes, " %[^\n]s", cliente.data_nascimento);
			if(cod != cliente.cod){ // testa se o cod informado se compara ao lido no arq
				if(!feof(arq_clientes)){
					continue; 
				}else{
					printf("\n Cliente n cadastrado! \n\n");
					break;
				}
			}else{
				printf("\n COD [%d]", cliente.cod);
				printf("\n Nome do cliente: %s", cliente.nome);
				printf("\n Email: %s", cliente.email);
				printf("\n Telefone: %s", cliente.telefone);
				printf("\n Logradouro: %s", cliente.logradouro);
				printf("\n Cidade: %s", cliente.cidade);
				printf("\n Estado: %s", cliente.estado);
				printf("\n Cep: %s", cliente.cep);
				printf("\n Cpf: %s", cliente.cpf);
				printf("\n Rg: %s", cliente.rg);
				printf("\n Data de Nascimento: %s\n\n", cliente.data_nascimento);
				break;
			}
		} fclose(arq_clientes);
		system("pause");
		system("cls");
}
