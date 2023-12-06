#include <stdio.h>//biblioteca de comunicação with user
#include <stdlib.h>//resposanvel por alocação de espaço de memoria
#include <locale.h>// biblioteca de alocações de texto por região
#include <string.h>//responsavel por cuidar dos strings

int registro() //fun. resp. por cadastrar usuarios ao sistema
   //inicio criação de variaveis string
{
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	// fim da criacao
	
	
	printf("digite o cpf a ser cadastrado:\t");
	scanf("%s", cpf);//%s se refere a string
	
	strcpy(arquivo, cpf);//resp. por copiar os valores string
	
	FILE * file;
	file = fopen(arquivo, "w");//cria o arquivo
	fprintf(file,cpf); //salva valor da variavel
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);

	printf("digite o nome a ser cadastrado:\t ");
	scanf("%s", nome);
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	printf("digite o sobrenome cadastrado:\t");
	scanf("%s", sobrenome);
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
		
	printf("digite o cargo cadastrado:\t");
	scanf("%s", cargo);	
	file =fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
}

int consulta()
{
  setlocale (LC_ALL, "Portuguese");
  
  char cpf[50];
  char conteudo[200];
  
  printf("digite o cpf a ser consultado:\t");
  scanf("%s", cpf);
  
  FILE * file;
  file =fopen(cpf, "r");
  
  if(file==NULL)
  {
  	printf("não fo possivel abrir o arquivo, não localizado");
  }
  while(fgets(conteudo, 200, file)!=NULL)
  {
  	printf("essas são as informações do usuario:\n ");
  	printf("%s", conteudo);
    printf("\n\n");
  }
  system("pause");
}

int deletar()
{
	char cpf[50];
	
	printf("digite o cpf a ser deletado\n");
	scanf("%s, cpf");
	
	remove(cpf);
	
	FILE * file;
	file=fopen(cpf, "r");
	
	if(file== NULL)
	{
		printf("\tusuario não encontrado\n");
		system("pause");
	}
	
}


int main() //função é adicionada parenteses
{
  system("cls");
  
   int opcao=0;//definindo variaveis
   int laco=1;
   for(laco=1;laco=1;)
   {
   
  setlocale (LC_ALL, "Portuguese");//incluindo linguagens

  system("cls");   
   
   printf("\t*Cartório da EBAC*\n\n");   //inicio do menu
   printf("escolha a opção desejada do menu:\n\n");
  //\T é um comando que ajuda a dar espaço
   printf("\t1-registrar nomes\n");
   printf("\t2-consultar nomes\n");
   printf("\t3-deletar nomes\n\n"); 
   printf("\t4-sair do sistema");
   printf("\topção:\n\n"); 
  
 
 scanf("%d",&opcao);//armazenando e escolha do usuario
 
system("cls"); 

 switch(opcao)
{
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
    printf("obrigado por utilizar o sistema");
	return 0;
	break;
    	
    	
    
    
    
    default:
    		printf("\topção indisponivel");
	system("pause");
	break;
}
}
}



