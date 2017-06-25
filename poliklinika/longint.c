#include "longint.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//**************************************************
list *Read( char *read ){
  int sk=0;
  int n=0;
    list *head = NULL; list * curr1;
    list *curr = NULL;
    list *dummy;
int i=0;
int k = 0;

    if(*(read)=='-')
    {
        ++n;
        i++;
    }
    if(*(read+i) != NULL)
        {
        dummy = malloc(sizeof(list));
            if (*(read+i) >= 48 && *(read+i) < 58 ) {  dummy -> number = (int)*(read+i); dummy -> number = dummy -> number-48; ++sk;}
            else   { printf("klaida\n"); exit(1);}

                dummy -> next = NULL;
                curr = dummy;
                head = dummy;
        i++;
        }
        while( *(read+i) != NULL){
        dummy = malloc(sizeof(list));
            if (*(read+i) >= 48 && *(read+i)< 58) {  dummy -> number = (int)*(read+i); dummy -> number = dummy -> number-48; ++sk;}
            else   { printf("klaida\n"); exit(1);}

        dummy -> next = curr;
        curr = dummy;
        i++;
    }
curr1 = curr;
while (1)
    {
        if ( curr1 -> number != 0 ) k++;
        if ( curr1 -> next == NULL ) break;
        else curr1 = curr1 -> next;

    }
        if ( k == 0 )
        {
            n = 2;
        }
	curr->a = n;
	curr->ilgis =sk;
	curr -> dal = 0;

return curr;
}
//*******************************************************
char* printnumber(list *num){

    list *dummy, *save=NULL;
    int nulis=0, kiek = 0;
        char *skaicius;

    if (num->a == 1 ){
        nulis=1;
    }

    while (num!= NULL){
        dummy = malloc(sizeof(list));
        dummy->number = num->number;
        num=num->next;
        dummy-> next = save;
        save = dummy;
        kiek ++;
    }
skaicius = calloc( kiek , sizeof(char));

    while(dummy->number==0){
            if(dummy -> next == NULL){
                break;
                }
            kiek--;
            dummy = dummy -> next;
        }

    if(nulis == 1){
        kiek ++;
        realloc(skaicius, (kiek , sizeof(char)));
            nulis=0;
        strcat(skaicius, "-");
        nulis++;
        kiek --;
    }
 char *ms = malloc( sizeof(char));

        while( dummy != NULL ){
            sprintf (ms, "%d", dummy-> number);
            strcat (skaicius, ms);
            dummy = dummy-> next;
        }
return skaicius;
    free(skaicius);
    free(ms);
}
//**********************************************
void deleteList(list *head)
{
    list *current = head;
    list *temp;
    while(current->next != NULL)
    {
         temp = current;
         current = current->next;
         free(temp);
    }
}
//************************************************
list * sum(list *one, list *two){
    list *save, *dummy, *point;
    int s=0;

    dummy = malloc(sizeof(list));
    point=dummy;

    if (one -> a == 1){
    point ->a = 1;
    }
    while(1){
        save = malloc(sizeof(list));

        if((one != NULL)&&(two != NULL)){
        dummy-> number  = (one -> number + two -> number+s)%10;
        s=(one -> number + two -> number + s)/10;

        dummy-> next = save;
        dummy=dummy-> next;
        one = one -> next;
        two = two -> next;
        }
        else if((one != NULL)&&(two  == NULL)){
        dummy-> number  = (one -> number+s)%10;
        s=(one -> number+s)/10;
        dummy-> next = save;
        dummy=dummy-> next;
        one = one -> next;
        }
        else if((one == NULL)&&(two  != NULL)){
        dummy-> number  = (two -> number+s)%10;
        s=(two -> number+s)/10;
        dummy-> next = save;
        dummy=dummy-> next;
        two = two -> next;
        }
        else if((one  == NULL)&&(two == NULL)){
            if(s==0)  {
            dummy->number=0;
            dummy->next = NULL;
            break;
            }
            else {
            dummy-> number = s;
            dummy-> next = NULL;
            break;
            }
        }
    }
    return point;
}
//******************************************************
list * sub(list *one, list *two, int *pozymis ){
    list *save, *dummy, *point;
    list *snum = NULL, *ones = one, *twos=two;
    int s=0, a=0;
    int dal = one -> dal;

    dummy = malloc(sizeof(list));
    point=dummy;
    if (*pozymis==2){
       point->a= 1;
    }

    while(1){
        save = malloc(sizeof(list));

            if((one != NULL)&&(two != NULL)){
            dummy-> number  = (one -> number - two -> number -s);
                if(dummy-> number < 0){
                dummy-> number+=10;
                s=1;
		if (( two -> next == NULL ) && ( one -> next == NULL )) *pozymis = 1;
                }
                else s=0;
            dummy -> next = save;
            dummy = dummy -> next;
            one = one -> next;
            two = two -> next;
            }
            else if((one != NULL)&&(two  == NULL)){
            dummy-> number  = (one -> number - s);
                if(dummy-> number < 0){
                dummy-> number+=10;
                s=1;
                }
                else s=0;
            dummy -> next = save;
            dummy = dummy -> next;
            one = one -> next;
            }
            else if((one == NULL)&&(two  != NULL)){
            dummy-> number  = (-two -> number -s);
                *pozymis = 1;
                if(dummy-> number < 0){
                dummy-> number+=10;
                s=1;

                }
                else s=0;
            dummy -> next = save;
            dummy = dummy -> next;
            two = two -> next;
            }
            else if((one  == NULL)&&(two == NULL)){
                dummy-> next=NULL;
                if(s==0)  {
                dummy-> number=0;
                break;
            }
       else {
            if ( dal == 0 ){

           //printf("-");
           *pozymis = 2;
            a++;

	   ones -> dal = 0;
	   point=sub(twos, ones, pozymis);}
            else{
	      ones -> dal = 1;
                point = sub (twos, ones, pozymis);
            }
            break;

            }
        }
    }

    return point;
}
//******************************************************
list *mul ( list *one, list *two ){
    list *dummy, *first, *second;
    list *point, *save;
    list *ones=one;
    int k = 0, s = 0, n = 0, t;
    int i = 0;
    first = malloc(sizeof(list));

    if((one->a + two -> a) ==1) first->a = 1;


    while(1){
        dummy = malloc(sizeof(list));
            if (k==0){
            save=first;
            k++;
           }

        first->number= (one->number * two-> number +s)%10;
        s = (one->number* two-> number+s)/10;

         if (one->next==NULL){
            first->next=dummy;
            first=first->next;
            first->number=s;
            first->next=NULL;
            break;
            }
        first->next=dummy;
        first=first->next;
        one=one->next;
        }
    first=save;
    one= ones;
    k=0; s=0;
                                while(1){
                                two=two->next;
                                if (two==NULL)break;
                                ++n;
                                second = malloc(sizeof(list));
                                   for(i=0; i<n; i++){
                                            if (k==0){
                                            point=second;
                                            k++;
                                            }
                                        dummy = malloc(sizeof(list));
                                        second->number=0;
                                        second->next=dummy;
                                        second=second->next;
                                   }
                                while(1){
                                    dummy = malloc(sizeof(list));


                                    second->number= (one->number * two-> number +s)%10;
                                    s = (one->number* two-> number + s)/10;

                                     if (one->next==NULL){
                                        second->next=dummy;
                                        second=second->next;
                                        second->number=s;
                                        second->next=NULL;
                                        break;
                                        }
                                    second->next=dummy;
                                    second=second->next;
                                    one=one->next;
                              }
                        second=point;
                        k=0; s=0;
first = sum(first, second);
        second=point;
        deleteList(second);
        one=ones;
        }
        return first;
    }
//******************************************************
list * perrasyti ( list *one )
{
    list * head = NULL; list *curr = NULL; list * dummy;
    int a;
    if (one->a == 1)  a = 1;
            while (1){
                dummy = malloc(sizeof(list));
                    if ( head == NULL )
                    {
                        dummy -> number = one -> number;
                        dummy -> next = NULL;
                        curr = dummy;
                        head = dummy;
                        if ( one -> next == NULL ) break;
                        one = one -> next;
                    }
                    else
                    {
                        dummy -> number = one -> number;
                        dummy -> next = curr;
                        curr = dummy;
                        if ( one -> next == NULL ) break;
                        one = one -> next;
                    }
            }
            if (a==1) curr->a=1;
    return curr;
}
//******************************************************
char * dive ( list *one, list *two, int check )
{
  one -> dal = 1;
  int a = one -> ilgis;
  int b = two -> ilgis;
    list *dummy = malloc(sizeof(list)); list *dalmeniui;
    list *dalmuo; list *twos; int k = 0; list * trinti = malloc(sizeof(list));
    list *daliklis;
    list *liekana;
    list *headdaliklio = NULL;
    list *currdaliklio = NULL;
    list *headdalmens = NULL;
    list *currdalmens = NULL;
    int i, j, z, s, koef, dal = 1, seip = 0, p=0;
    int pozymis;
        twos = two;

     if((one->a + two -> a) ==1) p = 1;

    while (1)
    {
        if ( twos -> number != 0 ) k++;
        if ( twos -> next == NULL ) break;
        else twos = twos -> next;

    }
        if ( k == 0 )
        {
            printf ("-\nDalyba is 0 negalima");
            exit(1);
        }
        if ( one -> number == 0 && one -> next == NULL )
        {
            printf (" 0\nLiekana: 0");
            exit(1);
        }
        if ( a < b )
        {
            k = 0;
           two = perrasyti(two);
                while (1)
                    {
                        if ( two -> number == 0 ) k = 0;
                        else break;
                        if ( two -> next == NULL || k == 1 ) break;
                        if ( k == 0 ){
                        trinti = two;
                        two = trinti -> next;
                        free(trinti);
                        b--;
                        }
                    }
                    if ( a < b ){
            printf (" 0\nLiekana: ");
            printnumber(one);
            exit(1);
                    }
                    else ( two = perrasyti(two));
        }
        if ( a > b )
        {
            for ( i = 0; i < (a - b); i++ )
            {
                daliklis = malloc(sizeof(list));

                    if ( headdaliklio == NULL )
                    {
                        daliklis -> number = 0;
                        daliklis -> next = NULL;
                        headdaliklio = daliklis;
                        currdaliklio = daliklis;
                    }
                    else
                    {
                        daliklis -> number = 0;
                        daliklis -> next = NULL;
                        currdaliklio -> next = daliklis;
                        currdaliklio = daliklis;
                    }
            }
        }
        for ( j = 0; j < b; j++ )
        {
            daliklis = malloc(sizeof(list));
                if ( headdaliklio == NULL)
                {
                    daliklis -> number = two -> number;
                    daliklis -> next = NULL;
                    headdaliklio = daliklis;
                    currdaliklio = daliklis;
                    two = two -> next;
                }
                else
                {
                    daliklis -> number = two -> number;
                    daliklis -> next = NULL;
                    currdaliklio -> next = daliklis;
                    currdaliklio = daliklis;
                    two = two -> next;
                }
        }
   for ( z = 0; z <= (a - b); z++ )
        {
            if (( z == 0 ) && ( a - b != 0 )) seip = 1;
            else seip = 0;
            koef = 0;
            pozymis = 0;
                while ( pozymis != 1 )
                {

		  one -> dal = 1;
                    one = sub(one, headdaliklio, &pozymis );
                    if ( pozymis == 1 )
                    {
		      one -> dal = 1;
                        one = sub(headdaliklio, one, &pozymis );
                            dummy = headdaliklio;
                            headdaliklio = dummy -> next;
                        free(dummy);
                        pozymis = 1;
                    }
                    else if ( pozymis == 0 ) koef++;
                    else break;
                }
            if ( seip == 1 && koef != 0 )
            {
                dalmeniui = malloc(sizeof(list));
                if ( headdalmens == NULL)
                    {
                            dalmeniui -> number = koef;
                            dalmeniui -> next = NULL;
                            headdalmens = dalmeniui;
                            currdalmens = dalmeniui;
                    }
                else
                    {
                            dalmeniui -> number = koef;
                            dalmeniui -> next = NULL;
                            currdalmens -> next = dalmeniui;
                            currdalmens = dalmeniui;
                    }
            }
            else if ( seip == 0 )
            {
                dalmeniui = malloc(sizeof(list));
                if ( headdalmens == NULL)
                    {
                            dalmeniui -> number = koef;
                            dalmeniui -> next = NULL;
                            headdalmens = dalmeniui;
                            currdalmens = dalmeniui;
                    }
                else
                    {
                            dalmeniui -> number = koef;
                            dalmeniui -> next = NULL;
                            currdalmens -> next = dalmeniui;
                            currdalmens = dalmeniui;
                    }
            }
        }
        if (p==1) headdalmens->a = 1;

        liekana = one;
if ( check == 0 ) return  printnumber (perrasyti(headdalmens));
if ( check == 1 )        printnumber(liekana);
}
/////////////////////////////////////////////////////////////////////////////////Tasks
void Write ( list *number , char* x){
    printf("%s=", x);  printf( "%s\n", printnumber(number));
}
//******************************************************
void Compare ( list * one, list *two )
{
 int  a = one -> a;
 int  b = two -> a;
    int c = 0, pozymis = 0; list * rezult; int k = 0;
    if ( a == 1 && b == 1 )
    {
      one -> dal = 1;
        rezult = sub (one, two, &pozymis );
        while (1)
    {
        if ( rezult -> number != 0 ) k++;
        if ( rezult -> next == NULL ) break;
        else rezult = rezult -> next;

    }
        if ( k == 0 ) c = 2;
        else if ( pozymis == 1 ) c = 0; //du neigiami, pirmas didesnis, antras mazesnis
        else  c = 1;  //du neigiami, pirmas mazesnis, antras didesnis
    }
    else if ( a == 1 && b == 0 ) c = 1;
    else if ( a == 0 && b == 1 ) c = 0;
    else if ( a == 0 && b == 0 )
    {
      one -> dal = 1;
        rezult = sub ( one, two, &pozymis );
        while (1)
    {
        if ( rezult -> number != 0 ) k++;
        if ( rezult -> next == NULL ) break;
        else rezult = rezult -> next;

    }
        if ( k == 0 ) c = 2;
        else if( pozymis == 1 ) c = 1;
        else c = 0;
    }
    else if (a==2 && b==2)
    {
        c=2;
    }
    else if (a==2 && b==0)
    {
        c=1;
    }
    else if (a==2 && b==1)
    {
        c=0;
    }
    else if (a==0 && b==2)
    {
        c=0;
    }
    else if (a==1 && b==2)
    {
        c=1;
    }

    if ( c == 0 ) printf("Pirmas skaicius didesnis, antras mazesnis\n");
    else if ( c == 1 ) printf ("Pirmas skaicius mazesnis, antras didesnis\n");
    else printf ("Skaiciai lygus\n");

    if ( a == 0 ) printf ("Pirmas skaicius teigiamas\n");
    else if ( a == 2 ) printf ("Pirmas skaicius lygus 0\n");
    else printf ("Pirmas skaicius neigiamas\n");

    if ( b == 0 ) printf ("Antras skaicius teigiamas\n");
    else if (b == 2 ) printf ("Antras skaicius lygus 0\n");
    else printf ("Antras skaicius neigiamas\n");
}
char * Sum(list *numberone, list *numbertwo){
    char *suma; int * pozymis = 0;
        if(( numberone->a == 0 || numberone->a == 2 ) && ( numbertwo->a == 0 || numbertwo->a == 2 )){
        suma = printnumber(sum(numberone, numbertwo));
        }
        else if(numberone->a==1 && numbertwo->a==1){
        suma = printnumber(sum(numberone, numbertwo));
        }
        else if((numberone->a==0 || numberone->a==2) && numbertwo->a==1){
        suma = printnumber(sub(numberone, numbertwo, &pozymis));
        }
        else if(numberone->a==1 && (numbertwo->a==0 || numbertwo->a == 2)){
        suma = printnumber(sub(numbertwo, numberone, &pozymis));
        }
        return suma;
}

char * Sub(list *numberone, list *numbertwo){
    char *atimtis; int * pozymis = 0;
        if((numberone->a==0 || numberone->a == 2) && numbertwo->a==1){
        atimtis = printnumber(sum(numberone, numbertwo));
        }
        else if(numberone->a==1 && (numbertwo->a==0 || numbertwo->a == 2)){
        atimtis = printnumber(sum(numberone, numbertwo));
        }

        else if((numberone->a==0 || numberone->a == 2) && ( numbertwo->a == 0 || numbertwo->a == 2)){
        atimtis = printnumber(sub(numberone, numbertwo, &pozymis ));
        }

        else if(numberone->a==1 && numbertwo->a ==1){
        atimtis = printnumber(sub(numbertwo, numberone, &pozymis ));
        }
        return atimtis;
}

char * Mul(list *numberone, list *numbertwo){
    return printnumber(mul(numberone, numbertwo));
}

char * Dive ( list *one, list *two){
    return dive ( one, two, 0);
}

char * Rea ( list *one, list *two){
    return dive ( one, two, 1);
}
