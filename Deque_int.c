#include "Deque_int.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

typedef struct cell{
    int data;
    struct cell *suiv;
    struct cell *prev;
} t_cell;

typedef struct t_deque{
    int nbelem;
    t_cell *base;
    t_cell *bout;
} *t_deque;

t_deque init(){
    t_deque ladeque;
    errno=0;
    ladeque=(struct t_deque*)malloc(sizeof(struct t_deque));
    if (errno){
        perror("Deque_init");
        exit errno;

    }
    ladeque->nbelem=0;
    ladeque->base=NULL;
    ladeque->bout=NULL;
    return ladeque;
}

void insertFirst(int i,t_deque d){
    errno=0;
    t_cell *cel=(t_cell *)malloc(sizeof(t_cell));
    t_cell *celprev=(t_cell *)malloc(sizeof(t_cell));
    if (errno){
        perror("Deque_init");
        exit errno;
    }
    cel->data=i;
    cel->prev=NULL;
    //cel->suiv=d->base;
    if (d->nbelem==0){
        cel->suiv=NULL;
        d->base=cel;
        d->bout=cel;

    } else{
        celprev->data=d->base->data;
        celprev->prev=cel;
        celprev->suiv=d->base->suiv;
        cel->suiv=celprev;
        d->base=cel;
    }
d->nbelem++;
printf("insertFirst:%d\n",i);


}


void insertLast(int i,t_deque d){
    errno=0;
    t_cell *cel=(t_cell *)malloc(sizeof(t_cell));
    t_cell *celsuiv=(t_cell *)malloc(sizeof(t_cell));
    if (errno){
        perror("Deque_init");
        exit errno;
    }
    cel->data=i;
    cel->suiv=NULL;
    //cel->suiv=d->base;
    if (d->nbelem==0){
        cel->prev=NULL;
        d->base=cel;
        d->bout=cel;

    } else{
        celsuiv->data=d->bout->data;
        celsuiv->suiv=cel;
        celsuiv->prev=d->bout->prev;
        cel->prev=celsuiv;
        d->bout=cel;
    }
    d->nbelem++;
    printf("insertLast:%d\n",i);

}


int removeFirst(t_deque d){
    int v;
    if (d->nbelem==0){
    errno=EINVAL;
    perror("Deque pb lol");
    exit errno;    
        }
    if (d->nbelem==1){
        v=d->base->data;
        d->nbelem==0;
        d->base=NULL;
        d->bout=NULL;

    } else{
            t_cell *suivant=d->base->suiv;
            
            v=d->base->data;
            suivant->prev=NULL;
            d->base=suivant;


        }
        d->nbelem--;
        return v;
        
}


int removeLast(t_deque d){
    int v;
    if (d->nbelem==0){
    errno=EINVAL;
    perror("Deque pb lol");
    exit errno;    
        }
    if (d->nbelem==1){
        v=d->bout->data;
        d->nbelem==0;
        d->base=NULL;
        d->bout=NULL;

    } else{
            t_cell *precedent=d->bout->prev;
            
            v=d->bout->data;
            precedent->suiv=NULL;
            d->bout=precedent;


        }
        d->nbelem--;
        return v;
      
}

int size(t_deque d)
{
    return d->nbelem;
}

int isEmpty(t_deque d){
    if (d->nbelem==0)
    return 0;
    else{
        return 1;
    }
}

int first( t_deque d){
return d->base->data;
}

int last(t_deque d){
    return d->bout->data;
}

void display(t_deque d){
    if (d->nbelem==0){
        printf("deque vide lol");
    }
    printf("En partant du debut (head/base)\n");
    t_cell *cel=(t_cell *)malloc(sizeof(t_cell));
    t_cell *celsuiv=(t_cell *)malloc(sizeof(t_cell));
    cel=d->base;
    printf("rang :1= %d\n",cel->data);
    int i=1;
    while (cel->suiv!=NULL){
        i++;
        cel=cel->suiv;
        printf("rang :%d",i);
        printf("= %d\n",cel->data);
    }
}
int main(int argc, char * argv[])
{ int x;
t_deque d;

    printf("je suis le main lol\n");
    d=init();
    x=size(d);
    printf("size deque initialise :%d\n",x);
    insertLast(18,d);
    insertFirst(5,d);
    insertFirst(6,d);
    insertFirst(9,d);
    //insertLast(7,d); //!!!!
    x=size(d);
    display(d);
    printf("first :%d\n",first(d));
    printf("last :%d\n",last(d));
    printf("size deque :%d\n",x);

   // x=removeLast(d);
    //printf("remove last resultat :%d\n",x);

    printf("first :%d\n",first(d));
    printf("last :%d\n",last(d));
    x=removeFirst(d);
    printf("remove first resultat : %d\n",x);
    printf("first :%d\n",first(d));
    printf("last :%d\n",last(d));
    x=removeFirst(d);
    printf("remove first resultat :%d\n",x);
    x=removeFirst(d);
    printf("remove first resultat : %d\n",x);

     x=removeLast(d);
    printf("remove last resultat :%d\n",x);
    //printf("remove first resultat : %d\n",x);
}