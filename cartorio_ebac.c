#include <stdio.h> // lib de comunica��o do usu�rio
#include <stdlib.h> // lib de aloca��o de espa�os em memoria
#include <locale.h> // lib de aloca�oes de texto por regi�o
#include <string.h> // lib para cuidar das strings

int registro(){ // fun��o para cadastrar usu�rios
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("### Cart�rio da EBAC ### \n\n");
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

int consulta(){// fun��o para consultar usu�rios
	char cpf[40];
	char conteudo[200];
		
	printf("### Cart�rio da EBAC ### \n\n");
	printf("2- Consultar nomes\n");
	printf("Digite o CPF a ser consultado\n");
	scanf("%s", cpf);// recebe o dado digitado e armazena na variavel correta
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL){
		printf("Pessoa n�o localizada!\n");
	}
	
	while(fgets(conteudo,200, file)!=NULL){
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar(){// fun��o para deletar usu�rios
	char cpf[40];
	printf("### Cart�rio da EBAC ### \n\n");
	printf("3- Deletar nomes\n");
	printf("Digite o CPF a ser cancelado\n");
	scanf("%s", cpf);// recebe o dado digitado e armazena na variavel correta
	
			
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL){
		printf("O usu�rio n�o est� cadastrado! \n");
		system("pause");
	}
	else{
		fclose(file);
		remove(cpf);
		file = fopen(cpf,"r");
		if (file == NULL){
			printf("Usu�rio deletado com sucesso!\n");
			system("pause");
		}
	}
	fclose(file);
}





int main(){
	int opcao=0; //Vari�vel do menu
	
	int laco = 1;
	
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ### \n\n");
	printf("Digite a senha do administrador: \n\n");
	scanf("%s", senhadigitada);// recebe o dado digitado e armazena na variavel correta
	
	comparacao = strcmp(senhadigitada, "admin"); //compara a senha digitada com a do sistema
		
	if(comparacao == 0){
		
		system("cls");
		for (laco=1; laco=1;){
		
			system("cls");
			setlocale(LC_ALL, "Portuguese"); //define a linguagem
			
			printf("### Cart�rio da EBAC ### \n\n");
			printf("Escolha a op��o desejada no menu: \n\n");
			printf("\t1- Registrar nomes\n");
			printf("\t2- Consultar nomes\n");
			printf("\t3- Deletar nomes\n\n");
			printf("\t4- Sair do Sistema\n\n");
			printf("Op��o: ");
			
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
				printf("### Cart�rio da EBAC ### \n\n");
				printf("Esta op��o n�o est� dispon�vel\n");
				system("pause");
				break;
			}
			
			printf("Esse Software � de livre uso dos alunos \n");
		}
	}
	else
		printf("Senha incorreta!");
}


