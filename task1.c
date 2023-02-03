#include "./utils.h"

void SolveTask1(void *info, int nr_avioane) {
    for (int i = 0; i < nr_avioane; i++) {
        int index_aux = 0;
        short aux1, aux2;
        char aux3;
        char *aux4 = malloc(5);
        int aux5;

        memcpy(&aux1, (info + i * SIZEOF_VECTOR) + index_aux, sizeof(aux1));
        index_aux += 2;

        memcpy(&aux2, (info + i * SIZEOF_VECTOR) + index_aux, sizeof(aux2));
        index_aux += 2;
        
        memcpy(&aux3, (info + i * SIZEOF_VECTOR) + index_aux, 1);
        index_aux++;

        memcpy(aux4, (info + i * SIZEOF_VECTOR) + index_aux, 4);
        index_aux += 4;
        aux4[4] = '\0';

        memcpy(&aux5, (info + i * SIZEOF_VECTOR) + index_aux, sizeof(int));
        index_aux += sizeof(int);


        printf("(%d, %d)\n%c\n%s\n%d", aux1, aux2, aux3, aux4, aux5);

        printf("\n\n");
        free(aux4);
    }
}
