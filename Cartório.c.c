#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
		
int registro()// Função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");// Coletando informação dos usuários
	scanf("%s", cpf);// %s refere-se as string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");// Abrindo a pasta 
	fprintf(file,","); // Adicionando a vírgula entre as palavras
	fclose(file);// Fechando a pasta
	
	printf("Digite o nome a ser cadastrado: ");// Coletando informação do usuário
	scanf("%s",nome);// %s refere-se as string
	
	file = fopen(arquivo, "a"); // Abrindo a pasta 
	fprintf(file,nome);// salvo o valor da variavel
	fclose(file);// Fechando a pasta
	
	file = fopen(arquivo, "a");// Abrindo a pasta 
	fprintf(file,",");// Adicionando a vírgula entre as palavras
	fclose(file);// Fechando a pasta
	
	printf("Digite o sobrenome a ser cadastrado: ");// Coletando informação do usuário
	scanf("%s",sobrenome);// %s refere-se as string
	
	file = fopen(arquivo, "a");// Abrindo a pasta 
	fprintf(file,sobrenome);// salvo o valor da variavel
	fclose(file);// Fechando a pasta
	
	file = fopen(arquivo, "a");// Abrindo a pasta 
	fprintf(file,",");// Adicionando a vírgula entre as palavras
	fclose(file);// Fechando a pasta
	
	printf("Digite o cargo a ser cadastrado: ");// Coletando informação do usuário
	scanf("%s",cargo);// %s refere-se as string
	
	file = fopen(arquivo, "a");// Abrindo a pasta 
	fprintf(file,cargo);// salvo o valor da variavel
	fclose(file);// Fechando a pasta	
	
    system("pause");// Pausando a tela 

}

int consulta()// Função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio da criação de variáveis/string
    char cpf[40];
    char conteudo [200];
    //final da criação de variáveis/string
    
    printf("Digite o CPF a ser consultado: ");// Coletando informação do usuário
    scanf("%s",cpf);// %s refere-se as string
    
    FILE *file;// cria o arquivo
    file = fopen(cpf, "r");// Abrindo e lendo a pasta 
    
    
    if(file == NULL)//condicional para ver se encontra o CPF do usuário
    {
    	printf("\nNão foi possivel abrir o arquivo, não localizado!\n\n"); //Informando o usuário que o CPF não foi localizado
	}
	
	while(fgets(conteudo,200,file) != NULL)//Função para encontrar CPF do Úsuario
	{
		printf("\nEssas são as informações do usuário: ");// Mensagem ao usuário informando que o CPF foi localizado
		printf("%s",conteudo);// %s refere-se as string
		printf("\n\n");//pulando linhas
	}
	system("pause");//Pausando sistema
	fclose(file);// Fechando a pasta
}

int deletar()
{
	//inicio da criação de variáveis/string
	char cpf[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: ");// Coletando informação do usuário
	scanf("%s",cpf);// %s refere-se as string
	
	FILE *file;// cria o arquivo
	file = fopen(cpf,"r");// Abrindo o arquivo
	fclose(file);// Fechando o arquivo

	if(file == NULL)//Condicional para encontrar CPF
	{
		printf("O usuário não se encontra no sistema!\n");// Mensagem que aparece ao usuário caso não encontre o CPF
		system("pause");// Pausando o sistema
	}
	else
	{
		printf("O usuário encontrado foi excluido do sistema!\n");// Mensagem que aparece ao usuário caso encontre o CPF
		system("pause");// Pausando o sistema
	}
	
	remove(cpf);// Removendo usuário do sistema
}


	
int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");// Responsável por limpar a tela

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: ");//fim do menu
				
		scanf("%d", & opcao); //armazenando a escolha do usuÃ¡rio
		
		system("cls");// Responsável por limpar a tela
	
		switch(opcao) //inicio da seleção
		{
			case 1:// Selecionando a opção 1
			registro(); // Chamada de funções
			break;// Finalizando a função
			
			case 2:// Selecionando a opção 2
			consulta();// Chamada de funções
			break;// Finalizando a função
		
			case 3:// Selecionando a opção 3
			deletar();// Chamada de funções
			break;// Finalizando a função
		
			default:// Função para informar o usuário que a opção não está disponível no sistema
			printf("Essa opção não está disponivel!\n");// Mensagem que aparece ao usuário caso o sistema não reconheça a opção escolhida
			system("pause");// Pausando o sistema
			break;// Finalizando a função
		} //fim da seleção
			
	}	
}
