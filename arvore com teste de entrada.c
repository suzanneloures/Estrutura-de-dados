#include<stdio.h>
#include<stdlib.h>

typedef struct listarvoregen
{
   char nome[50];
   char sexo;
   struct listarvoregen *pai,*irmao,*conjuge,*filho,*prox,*ant;
} tlistarvoregen;

void criarmembrofam(tlistarvoregen **arvoregen, char nomeproc[], char sexproc, char conjugeproc[], char paiproc[]);
void consultarconjuge();
void consultarpais();
void listararv();

int main(void)
{
           tlistarvoregen *arvgenealogica=NULL;    
           int opcao; 
           char paiprinc[50];
           char conjugeprinc[50]; 
           char sexoprinc;
           char nomeprinc[50];
           char aux[5];  
           int caracascii;
           int indice;
           int i=0;
           int j=0,n=49,m=0,v=0;
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
                    aux[0]='n';
                    aux[1]='a';
                    aux[2]='d';
                    aux[3]='a';
                    aux[4]='\0';
                    caracascii=33;
                    m=0;
                    for(i=0;i<10;i++)
                    {                      
                       if(((caracascii+i)%127)==0)
                       {
                          caracascii=caracascii+33;
                       } 
                       if(((((caracascii+i)/127)+m)%n)==0)
                       {
                          if((v%127)==0)
                          {
                             v=v+33;
                          }
                          else
                          {
                             v=v+1;
                          }
                          m=m+(v/127)+1;
                       }  
                       nomeprinc[m-1]=v;
                       nomeprinc[(((caracascii+i)/127)+m)%n]=((caracascii+i)%127);
                       nomeprinc[((((caracascii+i)/127)+m)%n)+1]='\0';
                       if(((i+1)%3)==1)
                       {  
                          j=0;
                          while(nomeprinc[j]!='\0')
                          {
                             paiprinc[j]=nomeprinc[j];
                             conjugeprinc[j]=nomeprinc[j];
                             j=j+1;
                          }
                          paiprinc[j]='\0';
                          conjugeprinc[j]='\0';
                          sexoprinc='m';
                          criarmembrofam(&arvgenealogica,nomeprinc,sexoprinc,aux,aux);
                       }
                       else
                       {
                          if(((i+1)%3)==2)
                          {           
                             sexoprinc='f';                  
                             criarmembrofam(&arvgenealogica,nomeprinc,sexoprinc,conjugeprinc,aux);
                          }
                          else
                          {
                             if(((i+1)%3)==0)
                             {
                                sexoprinc='f';
                                criarmembrofam(&arvgenealogica,nomeprinc,sexoprinc,aux,paiprinc);
                             }
                          }
                       }
                    }
                    getch();               
                 break;
                 
                 case 2:
                    system("cls");
                    consultarconjuge(arvgenealogica);
                 break;

                 case 3:
                    system("cls");
                    consultarpais(arvgenealogica);
                 break;
                 
                 /*case 4:
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
                    printf("Digite o nome da pessoa para listagem dos tios-avos.")
                    */

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

void criarmembrofam(tlistarvoregen **arvoregen, char nomeproc[], char sexproc, char conjugeproc[], char paiproc[])
{
   tlistarvoregen *novo=NULL,*pontaux=NULL;
   char nomeaux[50];
   int cont=0;
   int found=0,caracteratual;
   pontaux=*arvoregen;
   novo=(tlistarvoregen*)malloc(sizeof(tlistarvoregen));
   novo->prox=novo->ant=novo->pai=novo->irmao=novo->conjuge=novo->filho=NULL;
   novo->sexo=sexproc;
   while(nomeproc[cont]!='\0')
   {
      novo->nome[cont]=nomeproc[cont];
      cont=cont+1;
   }
   novo->nome[cont]=nomeproc[cont];
   cont=0; 
   /*Abaixo a rotina para procurar pelo pai*/  
   if((paiproc[0]!='n')||(paiproc[1]!='a')||(paiproc[2]!='d')||(paiproc[3]!='a')||(paiproc[4]!='\0'))
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
            while((caracteratual<50)&&(paiproc[caracteratual]!='\0'))
            {
               if (pontaux->nome[caracteratual]!=paiproc[caracteratual])
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
   /*Abaixo a rotina para procurar pelo conjuge*/
   if((conjugeproc[0]!='n')||(conjugeproc[1]!='a')||(conjugeproc[2]!='d')||(conjugeproc[3]!='a')||(conjugeproc[4]!='\0'))
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
            while((caracteratual<50)&&(conjugeproc[caracteratual]!='\0'))
            {
               if (pontaux->nome[caracteratual]!=conjugeproc[caracteratual])
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
