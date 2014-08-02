#include<stdio.h>
#include<stdlib.h>

typedef struct listarvoregen
{
   char nome[50];
   char sexo;
   struct listarvoregen *pai,*irmao,*conjuge,*filho,*prox,*ant;
} tlistarvoregen;

void criarmembrofam();
void consultarconjuge();
void consultarpais();
void listararv();

int main(void)
{
           tlistarvoregen *arvgenealogica=NULL;    
           int opcao;    
           system("cls");
           do{system("cls");
              printf("Qual a operacao desejada?\n1-Registrar um nascimento\n2-Consultar conjuge\n");
              printf("3-Consultar pais\n4-Consultar avos\n");
              printf("5-consultar mae;\n6-Consultar irmaos\n");
              printf("7-COnsultar tios\n");
              printf("8-Consultar primos\n9-Consultar sobrinhos\n");
              printf("10-Consultar tios-avos\n11-Listar arvore\n");
              printf("0-Sair\n\n");
              scanf("%d",&opcao);
              switch(opcao){
                 case 1: 
                    system("cls");
                    criarmembrofam(&arvgenealogica);
                 break;
                 
                 case 2:
                    system("cls");
                    consultarconjuge(arvgenealogica);
                 break;

                 case 3:
                    system("cls");
                    consultarpais(arvgenealogica);
                 break;
                 
                 case 4:
                    system("cls");
                    imprimepilha(processos);
                    getch();
                 break;
                
                 case 5:
                    system("cls");
                    imprimetopo(processos);
                    getch();
                 break;

                 case 6:
                    system("cls");
                    imprimebase(processos);
                    getch();
                 break;

                 case 7:
                    system("cls");
                    printf("Digite o ID do processo para impressão dos respectivos dados:\n");
                    scanf("%d",&idproc);
                    imprimeproc(processos,idproc); 
                    getch();
                 break;

                 case 8:
                    system("cls");
                    desempilha(&processos);      
                    getch();
                 break;

                 case 9:
                    system("cls");
                    printf("Digite o ID do processo a ser excluido:\n");
                    scanf("%d",&idproc);
                    excluiprocesso(&processos,idproc);
                    getch();
                 break;
                 
                 case 10:
                    system("cls");
                    printf("Digite o nome da pessoa para listagem dos tios-avos.");
                    break;

                 case 11:
                    system("cls");
                    listararv(arvgenealogica);
                    getch();
                 break;

                 case 0:
                    system("cls");
                    printf("Programa finalizado.\n\n");
                 break;

                 default:
                    system("cls");
                    printf("Opcao invalida. Pressione qualquer tecla para voltar.");
                           }                                    
           }
           while(opcao!=0);          
           return 0;}

/*--------------------------------Modulo I------------------------------------*/

void criarmembrofam(tlistarvoregen **arvoregen)
{
   tlistarvoregen *novo=NULL,*pontaux=NULL;
   char nomeaux[50];
   int found=0,caracteratual;
   pontaux=*arvoregen;
   novo=(tlistarvoregen*)malloc(sizeof(tlistarvoregen));
   novo->prox=novo->ant=novo->pai=novo->irmao=novo->conjuge=novo->filho=NULL;
   system("cls");
   printf("Digite o nome da nova pessoa:\n");
   gets(novo->nome);
   gets(novo->nome);
   printf("\n\nDigite o sexo da nova pessoa:\n");
   novo->sexo=getch();
   printf("\n\nDigite o nome do pai da pessoa(escreva a palavra nada se nao possuir um pai)\n");
   gets(nomeaux);
   if((nomeaux[0]!='n')||(nomeaux[1]!='a')||(nomeaux[2]!='d')||(nomeaux[3]!='a')||(nomeaux[4]!='\0'))
   {
      while(found==0)
      {
         if(pontaux==NULL)
         {  
            printf("Esta pessoa nao existe na lista.\n");
            found=1;
         }
         else
         {  
            found=1;
            caracteratual=0;
            while((caracteratual<50)&&(nomeaux[caracteratual]!='\0'))
            {
               if (pontaux->nome[caracteratual]!=nomeaux[caracteratual])
               {
                  found=0;
               }     
               caracteratual=caracteratual+1;
            }
            if(caracteratual<50)
            {
               if(pontaux->nome[caracteratual]!='\0')
               {
                  found=0;
               }
            }
            if(found==0)
            {
               pontaux=pontaux->prox;
            }
         }
      }
      if(pontaux!=NULL)
      {
         if((pontaux->conjuge==NULL)||(pontaux->sexo=='f'))
         {
            printf("\nEsta pessoa nao pode ser pai.\n");
         }
         else
         {
            novo->pai=pontaux;
            if(pontaux->filho==NULL)
            {
               pontaux->filho=novo;
               pontaux->conjuge->filho=novo;
               
            }
            else
            {
               pontaux=pontaux->filho;
               while(pontaux->irmao!=NULL)
               {
               pontaux=pontaux->irmao;
               }
               pontaux->irmao=novo;
            }         
            printf("\nPai cadastrado.\n");
         }
      }
   }
   else
   {
      printf("\nSem inclusao.");
   }
   found=0;
   pontaux=*arvoregen;
   printf("\n\nDigite o nome do conjuge da pessoa(escreva a palavra nada se nao possuir um conjuge)\n");
   gets(nomeaux); 
   if((nomeaux[0]!='n')||(nomeaux[1]!='a')||(nomeaux[2]!='d')||(nomeaux[3]!='a')||(nomeaux[4]!='\0'))
   {  
      while(found==0)
      {
         if(pontaux==NULL)
         {  
            printf("Esta pessoa nao existe na lista.\n");
            found=1;
         }
         else
         {  
            found=1;
            caracteratual=0;
            while((caracteratual<50)&&(nomeaux[caracteratual]!='\0'))
            {
               if (pontaux->nome[caracteratual]!=nomeaux[caracteratual])
               {
                  found=0;
               }     
               caracteratual=caracteratual+1;
            }
            if(caracteratual<50)
            {
               if(pontaux->nome[caracteratual]!='\0')
               {
                  found=0;
               }
            }
            if(found==0)
            {
               pontaux=pontaux->prox;
            }
         }
      }
      if(pontaux!=NULL)
      {
         if((pontaux->conjuge!=NULL)||(pontaux->sexo==novo->sexo))
         {
            printf("\nEstas pessoas nao podem se casar.\n");
         }
         else
         {
            novo->conjuge=pontaux;
            pontaux->conjuge=novo;
            printf("\nCasamento feito.\n");
         }
      }
   }
   else
   {
      printf("\nSem inclusao.");
   }
   found=0;
   pontaux=*arvoregen;
   if(pontaux==NULL)
   {
      *arvoregen=novo;
   }
   else
   {
      while(found==0)
      {
         if(pontaux->prox==NULL)
         {
            pontaux->prox=novo;
            novo->ant=pontaux;
            found=1;
         }
         else
         {
            pontaux=pontaux->prox;
         }
      }
   }
   getch();
}

/*-----------------------------------Modulo II----------------------------------------*/

void consultarconjuge(tlistarvoregen *arvoregen)
{
      tlistarvoregen *pontaux=NULL;
      char nomeaux[50];
      char caracteratual;
      int found=0;
      pontaux=arvoregen;
      printf("Digite o nome da pessoa para a qual listaremos o respectivo conjuge:\n");
      gets(nomeaux);
      gets(nomeaux);
      while(found==0)
      {
         if(pontaux==NULL)
         {  
            printf("Esta pessoa nao existe na lista.\n");
            found=1;
         }
         else
         {  
            found=1;
            caracteratual=0;
            while((caracteratual<50)&&(nomeaux[caracteratual]!='\0'))
            {
               if (pontaux->nome[caracteratual]!=nomeaux[caracteratual])
               {
                  found=0;
               }     
               caracteratual=caracteratual+1;
            }
            if(caracteratual<50)
            {
               if(pontaux->nome[caracteratual]!='\0')
               {
                  found=0;
               }
            }
            if(found==0)
            {
               pontaux=pontaux->prox;
            }
         } 
      } 
      if(pontaux!=NULL)
      {
         if(pontaux->conjuge==NULL)
         {
            printf("\nPessoa solteira.\n");
         }
         else
         {
            printf("\nConjuge:%s",pontaux->conjuge);
         }
      }
      getch();
}
  
void consultarpais(tlistarvoregen *arvoregen)
{
      tlistarvoregen *pontaux=NULL;
      char nomeaux[50];
      char caracteratual;
      int found=0;
      pontaux=arvoregen;
      printf("Digite o nome da pessoa para a qual listaremos os respectivos pais:\n");
      gets(nomeaux);
      gets(nomeaux);
      while(found==0)
      {
         if(pontaux==NULL)
         {  
            printf("Esta pessoa nao existe na lista.\n");
            found=1;
         }
         else
         {  
            found=1;
            caracteratual=0;
            while((caracteratual<50)&&(nomeaux[caracteratual]!='\0'))
            {
               if (pontaux->nome[caracteratual]!=nomeaux[caracteratual])
               {
                  found=0;
               }     
               caracteratual=caracteratual+1;
            }
            if(caracteratual<50)
            {
               if(pontaux->nome[caracteratual]!='\0')
               {
                  found=0;
               }
            }
            if(found==0)
            {
               pontaux=pontaux->prox;
            }
         } 
      } 
      if(pontaux!=NULL)
      {
         if(pontaux->pai==NULL)
         {
            printf("\nPais nao conhecidos.\n");
         }
         else
         {
            printf("\nPais: %s e %s",pontaux->pai,pontaux->pai->conjuge);
         }
      }
      getch();
}          
            
void listararv(tlistarvoregen *arvoregen)
{
   tlistarvoregen *pontaux=NULL;
   int achou=0;
   pontaux=arvoregen;
   while(achou==0)
   {
      if(pontaux==NULL)
      {
         achou=1;
      }
      else
      {
         printf("\n----------------------------------------\n");
         printf("Nome: %s",pontaux->nome);
         printf("\n----------------------------------------\n");
         pontaux=pontaux->prox;
      }
   }
} 
