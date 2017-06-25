#include "type.h"

/******************************************************************************************************************************************
===========================================================================================================================================
GALIMOS OPERACIJOS:
    * SUKURTI TUŠČIĄ EILĘ: inicializuojame 1 STRUCTURE tipo rodykle (eilės priekiui):
        - STRUCTURE *priekis = create();
    * PATIKRINTI, AR EILĖ YRA TUŠČIA:
        - isEmpty(&priekis) -> grąžina 0, jeigu tuščia, 1,jeigu ne tuščia.
    * PATIKRINTI, AR EILĖ PILNA (NEBEĮMANOMA IŠSKIRTI DAUGIAU ATMINTIES):
        - isFull(); - > grąžina 0, jeigu pilna, 1, jeigu ne pilna.
    * NAUJO ELEMENTO ĮTERPIMAS Į EILĖS PABAIGĄ:
        - enqueue(TIPAS duomens_kintamasis, &priekis); -> grąžina 0, jeigu sėkmingai įterpta, 1, jeigu nepavyko išskirti atminties.
    * ELEMENTO IŠĖMIMAS IŠ PRADŽIOS:
        - dequeue(&piekis, TIPAS duomens_adreso_kintamasis) -> reikšmė grąžinama per parametrą, 0, jeigu sėkmingai išimta, 1, jeigu bandoma išimti iš tuščio sąrašo.
    * PIRMO EILĖS ELEMENTO REIKŠMĖS PAĖMIMAS, NEIŠIMANT JO IŠ EILĖS:
        - peek(&priekis, TIPAS *duomens_adreso_kintamasis) -> reikšmė grąžinama per parametrą, 0, jeigu sėkmingai grąžina reikšmę, 1, jeigu bandoma grąžinti tuščios eilės viršūnės reikšmę.
    * EILĖS ELEMENTŲ SKAIČIAUS GRĄŽINIMAS:
        - numOfElements(&priekis, *duomens_adreso_kintamasis) -> reikšmė grąžinama per parametrą, 0, jeigu grąžina sėkmingai eilės elementų skaičių, 1, jeigu trūksta atminties, 2, jeigu eilė tuščia
    * SUNAIKINTI EILĘ:
        - destroyQueue(&priekis); -> grąžina 0, jeigu eilė sėkingai sunaikinta, 1, jeigu nepavyko išskirti atminties.

&priekis - tai susikurtos eilės priekio ir galo rodyklės, TIPAS - asmens naudojamas duomens tipas, apibrėžiamas type.h faile.
==========================================================================================================================================
******************************************************************************************************************************************/

typedef struct node STRUCTURE;

/* Funkcijų aprašai */
//-----------------------------------------------------------------
void main();
STRUCTURE *create();
int isEmpty (STRUCTURE **front);
int isFull (void);
int enqueue (TIPAS data, STRUCTURE **front);
int dequeue (STRUCTURE **front, TIPAS *duomuo);
int peek(STRUCTURE **front, TIPAS *value);
int numOfElements(STRUCTURE **front, int *value);
int destroyQueue(STRUCTURE **front);
//-----------------------------------------------------------------
