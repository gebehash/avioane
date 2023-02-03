#include "./utils.h"
/*
sortare crescator dupa tip
    pentru tipuri egale, descrescator dupa Codul Aeroportului
        pentru coduri egale, crescator dupa viteza
*/

typedef struct {
    short linie;
    short coloana;
    char dir;
    char tip;
    char* cod;
    int speed;
} Avion;

int cmp(const void *a, const void *b) {
    Avion *avion1 = a;
    Avion *avion2 = b;
    if (avion1->tip < avion2->tip) return -1;
    if (avion1->tip > avion2->tip) return 1;
    if (strcmp(avion1->cod, avion2->cod) > 0) return -1;
    if (strcmp(avion1->cod, avion2->cod) < 0) return 1;
    if (avion1->speed > avion2->speed) return 1;
    if (avion1->speed < avion2->speed) return -1;
    return 0;
}

void SolveTask3(void *info, int nr_avioane) {
    Avion avioane[nr_avioane];

    for (int i = 0; i < nr_avioane; i++) {
        avioane[i].cod = malloc(4);
        avioane[i].cod[3] = '\0';

        memcpy(&avioane[i].linie, (info + i * SIZEOF_VECTOR), sizeof(avioane[i].linie));
        memcpy(&avioane[i].coloana, (info + i * SIZEOF_VECTOR) + 2, sizeof(avioane[i].coloana));
        memcpy(&avioane[i].dir, (info + i * SIZEOF_VECTOR) + 4, 1);
        memcpy(&avioane[i].tip, (info + i * SIZEOF_VECTOR) + 5, 1);
        memcpy(avioane[i].cod, (info + i * SIZEOF_VECTOR) + 6, 3);
        memcpy(&avioane[i].speed, (info + i * SIZEOF_VECTOR) + 9, 4);

        
    }
    
    qsort(&avioane, nr_avioane, sizeof(Avion), cmp);
    for (int i = 0; i < nr_avioane; i++)
       printf("(%d, %d)\n%c\n%c%s\n%d\n\n", avioane[i].linie, avioane[i].coloana, avioane[i].dir, avioane[i].tip, avioane[i].cod ,avioane[i].speed);
}
