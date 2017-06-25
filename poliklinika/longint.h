#ifndef LONGINT_H_INCLUDED
#define LONGINT_H_INCLUDED
//***********************************************
typedef struct Sarasas{
  struct Sarasas *next;
  int number;
  int a;
  int ilgis;
  int dal;
}list;
//************************************************
list *Read( char *read );
//************************************************
char *printnumber(list *num);
//************************************************
void deleteList(list *head);
//************************************************
list *sum(list *one, list *two);
//************************************************
list *sub(list *one, list *two, int* pozymis );
//************************************************
list *mul ( list *one, list *two );
//************************************************
list *perrasyti ( list *one );
//************************************************
char *dive ( list *one, list *two, int pozymis );
//************************************************
int Compare ( list *one, list *two );
//************************************************
void Write ( list *number , char* x);
//************************************************
char *Sum(list *numberone, list *numbertwo);
//************************************************
char *Sub(list *numberone, list *numbertwo);
//************************************************
char * Mul(list *numberone, list *numbertwo);
//************************************************
char * Dive(list *numberone, list *numbertwo);
//************************************************
char * Rea(list *numberone, list *numbertwo);
//************************************************
#endif // longint_h_included
