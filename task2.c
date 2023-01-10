#include "./utils.h"

void freeMatrix(char **m, int r) {
    for (int i = 0; i < r; i++)
        free(m[i]);
    free(m);
}
void printMatrix(char **m, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%c", m[i][j]);
        printf("\n");
    }
}
char **rotateMatrix(char **m, int *r, int *c) {
    char **rm = (char **)malloc((*c) * sizeof(char *));
    for (int i = 0; i < (*c); i++)
        rm[i] = (char *)malloc((*r) * sizeof(char));
    for (int i = 0; i < *r; i++) {
        for (int j = 0; j < *c; j++) {
            printf("rm[%d][%d] = m[%d][%d]\n",j, *r - i - 1, i, j);
            rm[j][*r - i - 1] = m[i][j];
        }
        printf("\n");
    }




    int aux = *r;
    *r = *c;
    *c = aux;
}




/*
r = 4, c = 7
...*...
.*****.
...*...
..***..



i = 1
j = 0

   .
   .
   .
   *
   .
   .
   .



*/
void buildPlanes(char** plane1, char** plane2) {
    strcpy(plane1[0], "...*...");
    strcpy(plane1[1], ".*****.");
    strcpy(plane1[2], "...*...");
    strcpy(plane1[3], "..***..");

    strcpy(plane2[0], "....*....");
    strcpy(plane2[1], "...***...");
    strcpy(plane2[2], ".*******.");
    strcpy(plane2[3], "....*....");
    strcpy(plane2[4], "..*****..");
}

void SolveTask2(void *info, int nr_avioane, int N, char **mat) {
    char** plane1 = (char**) malloc(4 * sizeof(char *));
    for (int i = 0; i < 4; i++)
        plane1[i] = (char*) malloc(7 * sizeof(char));

    char** plane2 = (char**) malloc(5 * sizeof(char *));
    for (int i = 0; i < 5; i++)
        plane2[i] = (char*) malloc(9 * sizeof(char));
    
    buildPlanes(plane1, plane2);
    
    int r = 4, c = 7;
    char **rm = rotateMatrix(plane1, &r, &c);
    // printf("%d %d", r, c);
    printMatrix(plane1, r, c);
}


int main() {
    SolveTask2(NULL, 0, 0, NULL);
}