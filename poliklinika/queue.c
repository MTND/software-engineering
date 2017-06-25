#include "type.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct node STRUCTURE; // Paprastesniam skaitomumui kode

/* Struktūrinis dinaminio sąrašo elementas */

struct node {

TIPAS info;
STRUCTURE *ptr;

};
///----------------------------------------------------------------------------------
/* 1. Funkcija - Eilės inicializacija */

STRUCTURE *create()
{

    return NULL;

}
///----------------------------------------------------------------------------------
/* 2. Funkcija, tikrinanti, ar eilė tuščia */

int isEmpty(STRUCTURE **front)
{
    if (*front == NULL)
    {
        return 0; // eile tuscia
    }
    else
    {
        return 1; // eile nera tuscia
    }
}
///----------------------------------------------------------------------------------
/* 3. Funkcija, tikrinanti, ar eilė pilna (nebepakanka atminties išskyrimui) */

int isFull(void)
{
    STRUCTURE *temp = (STRUCTURE *)malloc(1*sizeof(STRUCTURE));
    if (temp == NULL)
    {
        return 0; // eile pilna
    }
    else
    {
        free(temp);
        return 1; // eile nera pilna
    }

}
///----------------------------------------------------------------------------------
/* 4. Funkcija, įdedanti elementą į eilės galą */

int enqueue(TIPAS data, STRUCTURE **front)
{

    STRUCTURE *temp;
    temp = (*front);
    STRUCTURE *temp1 = (STRUCTURE *)malloc(1*sizeof(STRUCTURE));
        if (temp1 == NULL)
        {
            return 1; // nepakanka atminties
        }
        else
    {
        temp1->info = data;
        temp1->ptr = NULL;
        if (temp==NULL)
        {
            (*front) = temp1;
            return 0; // nebera atminties ideti i eile
        }
        else
        {
            while (temp->ptr != NULL)
            {
                temp = temp->ptr;
            }
            temp->ptr = temp1;
            temp = temp1;
            return 0;
        }
    }
}
///----------------------------------------------------------------------------------
/* 5. Funkcija, išimanti elementą iš eilės pradžios */

int dequeue(STRUCTURE **front, TIPAS *duomuo)
{
    STRUCTURE *front_copy = *front;

    if (front_copy==NULL)
    {
        return 1; // Bandoma isimti is tuscios eiles.
    }
    else
    {
        if ((*front)->ptr != NULL)
        {
            (*front) = (*front)->ptr;
            *duomuo = front_copy->info;
            free(front_copy);
            return 0;
        }
        else
        {
            *duomuo = (*front)->info;
            free (*front);
            *front = NULL;
            return 0;
        }
    }

}
///----------------------------------------------------------------------------------
/* 6. Funkcija, grąžinanti eilės pradžioje esančio elemento reikšmę jo neišimdama. */

int peek(STRUCTURE **front, TIPAS *value)
{
    if (*front == NULL)
    {
        return 1; // Tuščia eilė
    }
    else
    {
        *value = (*front)->info;
        return 0;
    }
}
///----------------------------------------------------------------------------------
/* 7. Funkcija, skaičiuojanti kiek eilėje yra elementų. */

int numOfElements(STRUCTURE **front, int *value)
{
    int temp_len_var=0;
    STRUCTURE *temp_node = (STRUCTURE *)malloc(1*sizeof(STRUCTURE));
    if (temp_node == NULL)
    {
        return 1; // nepakanka atminties
    }
    else
    {
        if ((*front) == NULL)
        {
            *value = 0;
            return 2; // eile tuscia
        }
        else
        {
            temp_node = (*front);
            while (temp_node->ptr!=NULL)
            {
                temp_len_var++;
                temp_node = temp_node->ptr;
            }
            *value = temp_len_var+1;
            return 0; // sekmingai apskaiciuotas ilgis
        }
    }
}
///----------------------------------------------------------------------------------
/* 8. Funkcija, sunaikinanti eile */

int destroyQueue(STRUCTURE **front)
{
    STRUCTURE *temp = (*front);
    if (temp == NULL)
    {
        return 1; // bandoma sunaikinti tuscia eile
    }
    else
    {
        while ((*front) != NULL)
        {
            temp = *front;
            (*front) = (*front)->ptr;
            free(temp);
        }
        return 0; // Eile sunaikinta
    }
}
///Realizacijos pabaiga
///----------------------------------------------------------------------------------
