//PROGRAMA MATRICULA DE ALUNOS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

void inserir ();
void excluir ();
void consultar ();
void listar ();
void receber_campos ();
void mostrar_campos (int pos);

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

// FUNÇÃO PARA AS CAIXAS

void caixaMenu();
void caixaIncluir();
void caixa_consultar_matricula();
struct alunos{
    char nome[40];
    int matricula, idade;
    float  nota1, nota2;
    };

  alunos aluno[100];
 
//Variável global

int total_registrado; 
int opc=1;

//VARIÁVEL GLOBAL DAS CAIXAS
char lateral_topo_esquerda = 218;
char lateral_topo_direita = 191;
char centro = 196;
char lateral = 179;
char espaco = 32;
char lateral_base_esquerda = 192;
char lateral_base_direita = 217;
char centro_esquerda = 195;
char centro_direita = 180;

int main (void){
	
	while (opc != 0){
        system("cls");
        caixaMenu();
        gotoxy(30,11);
		scanf("%d", &opc);
        if(opc == 1){
            inserir();
        }
        	if(opc == 2){
        	excluir();
        	}
    
        		if(opc == 3){
            		listar();
        		}
        			if(opc == 5){
            	    printf("\n\n");
        				return 0;
        			}
        				
    }
    
}

void inserir (){
    system("cls");
    if (total_registrado < 100){
        receber_campos();
        system("pause");
    }
    else{
        printf("======= Vetor cheio - Impossível cadastrar aluno ======\n\n");
    }
   
}

void excluir (){
	system("cls");
	
	int i=0,matricula;
	int comfirma_exclusao=0;
	if (total_registrado == 0) {
		printf ("Não tem alunos cadastrados\n");
		system ("pause");		
	}
	else {	
	printf("\t DIGITE A MATRICULA PARA EXCLUIR \n\n");
	printf("Matricula: ");
	scanf("%i",&matricula);
    printf("Deseja excluir? (1) sim (2) não");
    scanf ("%d", &comfirma_exclusao);
    	if (comfirma_exclusao == 1) {
    	total_registrado--;
    	aluno[matricula].matricula = 0;
	 		if(matricula != aluno[matricula].matricula){
     			printf("\n======= Matrícula não cadastrada ==========\n");
     		}
    		system("pause");
     	}
     }
}

void listar(){
    int espCentro_lista = 60; 
	int aux_contador_lista = 0;
	
	
	system("cls");
     if(total_registrado < 0){
      printf("\n======= Nao existe nenhum aluno cadastrado ======\n");
    }
    else{
    
	
		printf(" LISTAR \n\n");
		while (aux_contador_lista < espCentro_lista){
        printf("%c", centro);
        aux_contador_lista++;
	    }printf("\n");
		for(int i = 0 ; i < total_registrado; i++){
        printf(" Matricula    Nome    Nota 1    Nota 2    Media\n");
		while (aux_contador_lista < espCentro_lista){
        printf("%c", centro);
        aux_contador_lista++;
	    }
	    printf("\n");
		printf(" %i            %s       %.2f      %.2f      %.3f  \n\n ",aluno[i].matricula,aluno[i].nome,aluno[i].nota1,aluno[i].nota2,
		(aluno[i].nota1 + aluno[i].nota2) / 2);
	    	}
    		system("pause");
		}
}
    
void receber_campos(){
    int novocadastro;
    int i = total_registrado;
    int valordigitado;
    
    caixaIncluir();
	
    gotoxy(13,5);
    scanf("%d", &aluno[i].matricula);
	gotoxy(8,6);
	scanf("%s", &aluno[i].nome);
	gotoxy(9,7);
	scanf("%d", &aluno[i].idade);
	gotoxy(10,8);
	scanf("%f", &aluno[i].nota1); 
	gotoxy(10,9);
	scanf("%f", &aluno[i].nota2); 
	
	gotoxy(3,15);
	printf("Deseja incluir? (1) sim (2) não\n");
    gotoxy(3,16);
	scanf ("%d", &valordigitado);
    if (valordigitado == 1) {
    	total_registrado++;
    }else{
    	return;
	}
    gotoxy(3,18);
	printf("Deseja efetuar mais cadastros?\n\n");
 	gotoxy(3,19);
	printf("[1] SIM ou [2] NAO?\n");
 	gotoxy(3,20);
	scanf("%d", &novocadastro);
 	if(novocadastro == 1){
 	system("cls");
 	receber_campos();
 	}
 	printf("\n\n");
}

void mostrar_campos(int pos){
    int i = pos;
    int espCentro = 40; 
    int conta=0;	
    
	printf("%c", lateral_topo_esquerda);
	while (conta < espCentro){
    printf("%c", centro);
    conta++;
	} 
  printf("%c\n", lateral_topo_direita);
  printf("%c           ALUNO: %s                     %c\n", lateral, aluno[i].nome, lateral);
  printf("%c                                        %c\n", lateral, lateral);
  printf("%c                                        %c\n", lateral, lateral);
  printf("%c Nome: %s                 	         %c\n", lateral, aluno[i].nome, lateral);
  printf("%c Matricula: %d            	         %c\n", lateral, aluno[i].matricula, lateral);
  printf("%c Idade: %d                		 %c\n", lateral, aluno[i].idade, lateral);
  printf("%c Media: %.1f                             %c\n", lateral,(aluno[i].nota1 + aluno[i].nota2) / 2, lateral);
  printf("%c                                        %c\n", lateral, lateral);
  printf("%c", lateral_base_esquerda);
  int espcentro_mostrar_campos = 40, cont_mostrar_campos = 0;
  
  while (cont_mostrar_campos < espcentro_mostrar_campos){
    printf("%c", centro);
    cont_mostrar_campos++;
  }
  printf("%c\n", lateral_base_direita);
}

void caixaMenu(){
	
int espacoCentro = 40; 
int cont=0;	

printf("%c", lateral_topo_esquerda);
	while (cont < espacoCentro){
    printf("%c", centro);
    cont++;
	}
  printf("%c\n", lateral_topo_direita);
  printf("%c           ALUNOS CADASTRADOS: %d        %c\n", lateral, total_registrado, lateral);
  printf("%c                                        %c\n", lateral, lateral);
  printf("%c                                        %c\n", lateral, lateral);
  printf("%c           [1] Incluir aluno            %c\n", lateral, lateral);
  printf("%c           [2] Excluir aluno            %c\n", lateral, lateral);
  printf("%c           [3] Listar alunos            %c\n", lateral, lateral);
  printf("%c           [4] Lancar Notas [OFF]       %c\n", lateral, lateral);
  printf("%c           [5] Sair                     %c\n", lateral, lateral);
  printf("%c                                        %c\n", lateral, lateral);
  printf("%c           Escolha um icone:            %c\n", lateral, lateral);
  printf("%c                                        %c\n", lateral, lateral);
  printf("%c                                        %c\n", lateral, lateral);
  printf("%c", lateral_base_esquerda);
  int espacocentro = 40, contador = 0;
  while (contador < espacocentro){
    printf("%c", centro);
    contador++;
  }
  printf("%c\n", lateral_base_direita);
 } 
  
void caixaIncluir(){
int espacocentro = 40, contador = 0;
int espCentro = 40; 
int aux_contador =0;	

system("cls");
printf("%c", lateral_topo_esquerda);
	while (aux_contador < espCentro){
    printf("%c", centro);
    aux_contador++;
	}
printf("%c\n", lateral_topo_direita);
  printf("%c           ALUNOS CADASTRADOS: %d        %c\n", lateral, total_registrado, lateral);
  printf("%c                                        %c\n", lateral, lateral);
  printf("%c                                        %c\n", lateral, lateral);
  printf("%c Matricula:                             %c\n", lateral, lateral);
  printf("%c Nome:                                  %c\n", lateral, lateral);
  printf("%c Idade:                                 %c\n", lateral, lateral);
  printf("%c Nota 1:                                %c\n", lateral, lateral);
  printf("%c Nota 2:                                %c\n", lateral, lateral);
  printf("%c                                        %c\n", lateral, lateral);
  printf("%c                                        %c\n", lateral, lateral);
  printf("%c                                        %c\n", lateral, lateral);
  printf("%c",centro_esquerda);
  while (contador < espacocentro){
  printf("%c",centro);
  contador++;
  }
  printf("%c\n",centro_direita);
  printf("%c                                        %c\n", lateral, lateral);
  printf("%c                                        %c\n", lateral, lateral);
  printf("%c                                        %c\n", lateral, lateral);
  printf("%c                                        %c\n", lateral, lateral);
  printf("%c                                        %c\n", lateral, lateral);
  printf("%c                                        %c\n", lateral, lateral);
  printf("%c                                        %c\n", lateral, lateral);
  printf("%c", lateral_base_esquerda);
  int espacocentro_incluir = 40, contador_incluir = 0;
  while (contador_incluir < espacocentro_incluir){
    printf("%c", centro);
    contador_incluir++;
  }
  printf("%c\n", lateral_base_direita);
}

void caixa_consultar_matricula(){
	
	int espCentro_consultar = 40; 
    int cont_consultar=0;
	int espcentro_mostrar_campos = 40, cont_mostrar_campos = 0;	
    // CAIXA CONSULTAR
	printf("%c", lateral_topo_esquerda);
	while (cont_consultar < espCentro_consultar){
    printf("%c", centro);
    cont_consultar++;
	} 
  	printf("%c\n", lateral_topo_direita);
  	printf("%c\t   CONSULTAR MATRICULA           %c\n", lateral,lateral);
  	printf("%c                                        %c\n", lateral,lateral);
  	printf("%c                                        %c\n", lateral,lateral);
  	printf("%cDigite a matricula a consultar:         %c\n", lateral, lateral);
  	printf("%c                                        %c\n", lateral,lateral);
  	printf("%c", lateral_base_esquerda);
  	while (cont_mostrar_campos < espcentro_mostrar_campos){
    printf("%c", centro);
    cont_mostrar_campos++;
  }
  printf("%c\n", lateral_base_direita);
}
