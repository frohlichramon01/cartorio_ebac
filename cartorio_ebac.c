#include <stdio.h> // lib de comunicação do usuário
#include <stdlib.h> // lib de alocação de espaços em memoria
#include <locale.h> // lib de alocaçoes de texto por região
#include <string.h> // lib para cuidar das strings

int registro(){ // função para cadastrar usuários
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("### Cartório da EBAC ### \n\n");
	printf("1- Registrar nomes\n");
	
	printf("Digite o CPF a ser cadastrado\n");
	scanf("%s", cpf); // recebe o dado digitado e armazena na variavel correta
	
	strcpy(arquivo, cpf); // copia valor do CPF para ARQUIVO
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo com nome 'arquivo'
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o NOME a ser cadastrado\n");
	scanf("%s", nome);
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o SOBRENOME a ser cadastrado\n");
	scanf("%s", sobrenome);
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o CARGO a ser cadastrado\n");
	scanf("%s", cargo);
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta(){// função para consultar usuários
	char cpf[40];
	char conteudo[200];
		
	printf("### Cartório da EBAC ### \n\n");
	printf("2- Consultar nomes\n");
	printf("Digite o CPF a ser consultado\n");
	scanf("%s", cpf);// recebe o dado digitado e armazena na variavel correta
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL){
		printf("Pessoa não localizada!\n");
	}
	
	while(fgets(conteudo,200, file)!=NULL){
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar(){// função para deletar usuários
	char cpf[40];
	printf("### Cartório da EBAC ### \n\n");
	printf("3- Deletar nomes\n");
	printf("Digite o CPF a ser cancelado\n");
	scanf("%s", cpf);// recebe o dado digitado e armazena na variavel correta
	
			
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL){
		printf("O usuário não está cadastrado! \n");
		system("pause");
	}
	else{
		fclose(file);
		remove(cpf);
		file = fopen(cpf,"r");
		if (file == NULL){
			printf("Usuário deletado com sucesso!\n");
			system("pause");
		}
	}
	fclose(file);
}





int main(){
	int opcao=0; //Variável do menu
	
	int laco = 1;
	
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ### \n\n");
	printf("Digite a senha do administrador: \n\n");
	scanf("%s", senhadigitada);// recebe o dado digitado e armazena na variavel correta
	
	comparacao = strcmp(senhadigitada, "admin"); //compara a senha digitada com a do sistema
		
	if(comparacao == 0){
		
		system("cls");
		for (laco=1; laco=1;){
		
			system("cls");
			setlocale(LC_ALL, "Portuguese"); //define a linguagem
			
			printf("### Cartório da EBAC ### \n\n");
			printf("Escolha a opção desejada no menu: \n\n");
			printf("\t1- Registrar nomes\n");
			printf("\t2- Consultar nomes\n");
			printf("\t3- Deletar nomes\n\n");
			printf("\t4- Sair do Sistema\n\n");
			printf("Opção: ");
			
			scanf("%d", &opcao);// recebe o dado digitado e armazena na variavel correta
			system("cls");
			
			switch(opcao){
				case 1:
				registro();
				break;
				
				case 2:
				consulta();
				break;
					
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
					
				default:
				printf("### Cartório da EBAC ### \n\n");
				printf("Esta opção não está disponível\n");
				system("pause");
				break;
			}
			
			printf("Esse Software é de livre uso dos alunos \n");
		}
	}
	else
		printf("Senha incorreta!");
}


