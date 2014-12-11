#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


////////////////////////////////



/* DŽefinition de la structure toto*/
struct toto {
int data;
struct toto *next;
};
//type liste synonyme du type pointeur vers une struct toto
typedef struct toto *liste;
/**************************************
* Ins`ere un ŽelŽement en t^ete de liste *
**************************************/
liste insere(int element, liste Q) {
liste L;
L = (liste)malloc(sizeof(struct toto)); // allocation de la zone
// mŽemoire necŽessaire
L->data = element;
L->next = Q;
return L;
}
/***************************************
* Ins`ere un ŽelŽement en queue de liste *
***************************************/
liste insereInTail(int element, liste Q) {
liste L, tmp=Q;
L = (liste)malloc(sizeof(struct toto)); // allocation de la zone
// mŽemoire necŽessaire
L->data = element;
L->next = NULL;
if (Q == NULL)
return L;
// maintenant tmp=Q est forcement non vide => tmp->next existe
while (tmp->next != NULL) tmp = tmp->next; // deplacement jusquau
// dernier elt de la liste
tmp->next = L;
return Q;
}
/***************************************
* Supprime lŽelŽement en t^ete de liste *
***************************************/
liste supprime_tete(liste L) {
liste suivant = L;
if (L != NULL) { // pour etre s^ur que L->next existe
suivant= L->next;
free(L); //libŽeration de lespace allouŽe pour une cellule
}
return suivant;
}
/***************************************
* Supprime lŽelŽement en queue de liste *
***************************************/
liste supprime_queue(liste L) {
liste suivant = L;
liste f;
if(suivant->next==NULL){
f=L;
free(f);
L=NULL;
return L;
    }else{
        do{ suivant=suivant->next;
            }while(suivant->next->next!=NULL);
           f=suivant->next;
           free(f);
           suivant->next=NULL;
           return L;
        }
}
/*****************************
* Supprime toute la liste L *
*****************************/
liste supprime(liste L) {
while (L != NULL)
L = supprime_tete(L); //suppression de la t^ete de liste
return L;
}
/************************************
* Affiche le contenu de la liste L *
************************************/
void print_liste(liste L) {
liste tmp = L;
while (tmp != NULL) { //on aurait pu Žecrire while (tmp)
printf("%d ",tmp->data);
tmp = tmp->next;
}
free(L);
}
/********************************************************/

/********** get length **********************************/
int getLength(liste l){

    int n=0;
    while(l!=NULL){
        n=n+1;
        l=l->next;
        }
    return n;
    }
/********************************************************/

/*************************************inverse list*******/
liste inverser(liste L) {
liste f=NULL,l=L;
while(l!=NULL){

    f=insere(l->data,f);
    l=l->next;
}
   free(L);
    return f;

}
/********************************************************/


void print_integer(){
char x;
x=getchar();
int i;
while(x=='\t'){

printf("enter your first number ending with # and hit Enter. Exp: 1 2 4 3 #\t");
x=getchar();
scanf("%d",&i);
}

}
/*********************************************************/ /*get the first value*/
liste get_value_1(){
liste l,L=NULL;
int i;
printf("enter the first number ending with # and hit Enter. Exp: 1 2 4 3 #\n");
do{
scanf("%d",&i);
if((L==NULL)&&(i==0)){}else{
l=insere(i,L);
L=l;}
}while(getchar()!='#');
l=supprime_tete(l);
return l;
}
/*********************************************************/
/*********************************************************/ /*get the next value*/
liste get_value_2(){
liste l,L=NULL;
int i;
printf("enter the next number ending with # and hit Enter. Exp: 1 2 4 3 #\n");
do{
scanf("%d",&i);
if((L==NULL)&&(i==0)){}else{
l=insere(i,L);
L=l;}
}while(getchar()!='#');
l=supprime_tete(l);
return l;
}
/*********************************************************/
/*********************************************************/
liste addition(liste l11 , liste l12){
liste m=NULL,n=NULL,final=NULL;
    m=l11;
    n=l12;
int r=0,v;
while((m!=NULL)&&(n!=NULL)){
    v= (m->data) + (n->data) + r;
    if(v<10){
        final=insereInTail(v,final);
        r=0;
        m=m->next;
        n=n->next;
        }else{
            final=insereInTail(v-10,final);
            r=1;
            m=m->next;
            n=n->next;
            }
    }
  //  if(r==0){
//return final;
  //  }
//else
if((m!=NULL)&&(n==NULL)){
while(m!=NULL){
if(m->data + r<10){
    final=insereInTail(m->data+r,final);
    r=0;
    m=m->next;}else{
    final=insereInTail(0,final);
    r=1;
    m=m->next;
    }// if (r==1) final=insereInTail(1,final); //wrong if taken
}
if (r==1) {final=insereInTail(1,final);
return final;}return final;


}else{
while(n!=NULL){
if(n->data + r<10){
    final=insereInTail(n->data+r,final);
    r=0;
    n=n->next;}else{
    final=insereInTail(0,final);
    r=1;
    n=n->next;
    }//if (r==1) final=insereInTail(1,final); //wrong if taken
}
if (r==1) {final=insereInTail(1,final);
return final;} return final;
}
/***********************add them as same length***********/
}
/*********************************************************/
//////////////////////////////
void add(){
 liste j,k,j1,k1,l1,p=NULL;

//int color;
printf("THIS PROGRAM CAN COMPUTE THE SUM OF 2 NUMBERS BIGGER THAN THE LENGTH OF OUR USUAL CALCULATOR \n");

j=get_value_1();
k=get_value_2();
p=addition(j,k);
j1=inverser(j);
k1=inverser(k);
l1=inverser(p);
system("cls");
printf("\v\v");
print_liste(j1);
printf("\n+\n\v\v");
print_liste(k1);
printf("\n---------------------------------------------------\n");
print_liste(l1);

    }
liste sudtraction(liste l1,liste l2){

  //  HANDLE hConsole;
//int color;
//hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//SetConsoleTextAttribute(hConsole, 75);

liste U,L,li1,li2,final=NULL;
int val1,val2,r=0;
val1=getLength(l1);
val2=getLength(l2);
if(val1>val2){
U=l1;L=l2;
} if(val2>val1) {
U=l2;L=l1;
    }
    if(val1!=val2){
while(L!=NULL){
if(U->data<L->data){
final=insereInTail(10+U->data+r-L->data,final);
r=-1;
U=U->next;
L=L->next;
    }else{
        final=insereInTail(U->data+r-L->data,final);
        r=0;
        U=U->next;
        L=L->next;
        }
    }
while(U->next!=NULL){
if(r+U->data<0){
final=insereInTail(9,final);
r=-1;
U=U->next;
} else{
final=insereInTail(r+U->data,final);
r=0;
U=U->next;
}
}
final=insereInTail(r+U->data,final);
return final;
} /*if(val1==val2){
    li1=inverser(l1);
    li2=inverser(l2);
    while(li1->data==li2->data){
    li1=li1->next;
    li2=li1->next;
    }
    if(li1->data <li2->data){
    U=l2;L=l1;

    while(L!=NULL){
        if(U->data < L->data){
          final=insereInTail(10+U->data+r-L->data,final);
          r=-1;
          U=U->next;
          L=L->next;
            }else{
                final=insereInTail(U->data-L->data+r,final);
                r=0;
                U=U->next;
                L=L->next;
                }
        }
        return final;
        }
if(li1==NULL){
    final=insereInTail(0,final);
    return final;
     }
if(li1->data >li2->data){
    U=l1;L=l2;

    while(L!=NULL){
        if(U->data < L->data){
          final=insereInTail(10+U->data+r-L->data,final);
          r=-1;
          U=U->next;
          L=L->next;
            }else{
                final=insereInTail(U->data-L->data+r,final);
                r=0;
                U=U->next;
                L=L->next;
                }
        }
        return final;
        }else /*final=insereInTail(0,final);*//*return final;
    }*///end

    }//88888888888888
int main()
{add();
/*
 liste j,k,j1,k1,l1,p;
//add();

j=get_value_1();
k=get_value_2();
p=sudtraction(j,k);
j=inverser(j);
k=inverser(k);
p=inverser(p);
system("cls");
print_liste(j);
printf("\n-\n");
print_liste(k);
printf("\n---------------------------------------------------\n");
if(getLength(j)<getLength(k)){
    printf("\t(-)");
print_liste(p);}
if(getLength(j)>getLength(k)){
    printf("\t(+)");
print_liste(p);}
free(p);*/
    return 0;
}
