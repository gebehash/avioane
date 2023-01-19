#include "./utils.h"

// void freeMatrix(char **m, int r) {
//     for (int i = 0; i < r; i++)
//         free(m[i]);
//     free(m);
// }

void printMatrix(char **m, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%c ", m[i][j]);
        printf("\n");
    }
}

void swap (int *r, int *c) {
    int aux = *r;
    *r = *c;
    *c = aux;
}

char **rotateMatrix(char **m, int *r, int *c) {
    char **rm = (char **)malloc((*c) * sizeof(char *));
    for (int i = 0; i < (*c); i++)
        rm[i] = (char *)malloc((*r) * sizeof(char));
    for (int i = 0; i < *r; i++) {
        for (int j = 0; j < *c; j++) {
            //printf("rm[%d][%d] = m[%d][%d]\n",j, *r - i - 1, i, j);
            rm[j][*r - i - 1] = m[i][j];
        }
    }

    free_mat(m, *r);
    swap(r, c);
    return rm;
}

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

int getRowByType(char type) {
    if (type == '1')
        return 4;
    return 5;
}

int getColumnByType(char type) {
    if (type == '1')
        return 7;
    return 9;
}

int getStartCol(int coloana, char type) {
    if (type == '1')
        return coloana - 3;
    return coloana - 4;
}

void SolveTask2(void *info, int nr_avioane, int N, char **mat) {
    char** plane1 = (char**) malloc(4 * sizeof(char *));
    for (int i = 0; i < 4; i++)
        plane1[i] = (char*) malloc(7 * sizeof(char));

    char** plane2 = (char**) malloc(5 * sizeof(char *));
    for (int i = 0; i < 5; i++)
        plane2[i] = (char*) malloc(9 * sizeof(char));
    
    buildPlanes(plane1, plane2);

//     int r = 4, c = 7;
//     char **rm = rotateMatrix(plane1, &r, &c);
        int r = getRowByType(2);
        int c = getColumnByType(2);
printMatrix(plane2, r, c);
   printf("\n");
//     rm = rotateMatrix(rm, &r, &c);
//     printMatrix(rm, r, c);
//     printf("\n");
//     rm = rotateMatrix(rm, &r, &c);
//     printMatrix(rm, r, c);
//     printf("\n");
//     rm = rotateMatrix(rm, &r, &c);
//     printMatrix(rm, r, c);
//     printf("\n");
    for (int i = 0; i < nr_avioane; i++) {
        char **avion;
        short linie;
        short coloana;
        char dir;
        char tip;


        memcpy(&linie, (info + i * SIZEOF_VECTOR), sizeof(linie));
        memcpy(&coloana, (info + i * SIZEOF_VECTOR) + 2, sizeof(coloana));
        memcpy(&dir, (info + i * SIZEOF_VECTOR) + 4, 1);
        memcpy(&tip, (info + i * SIZEOF_VECTOR) + 5, 1);

        switch (tip)
        {
            case '1':
                avion = plane1;
                break;

            case '2':
                avion = plane2;
                break;
        }


        int rowLenght = getRowByType(tip);
        int colLenght = getColumnByType(tip);

        switch (dir)
        {
            case 'N':
                
                break;
            
            case 'S':
                for (int i = 0; i < 2; i++)
                    avion = rotateMatrix(avion, &rowLenght, &colLenght);
                break;

            case 'E':
                avion = rotateMatrix(avion, &rowLenght, &colLenght);
                break;

            case 'W':
                for (int i = 0; i < 3; i++)
                    avion = rotateMatrix(avion, &rowLenght, &colLenght);
                break;
        }
        int a = 0;
        for (int i = linie; a < getRowByType(tip); i++, a++) { // se schimba row si column in functie de directie !! 
            int b = 0;
            for (int j = getStartCol(coloana, tip); b < getColumnByType(tip); j++, b++) {
                printf("avion[%d][%d]: %c\n", a, b, avion[a][b]);
                if (avion[a][b] == '*') {
                   printf("mat[%d][%d] = avion[%d][%d]\n", i, j, a, b);
                    mat[i][j] = avion[a][b];
                }
                    
            }
        }
        printMatrix(mat, N, N);
        printf("\n");
    }
    printMatrix(mat, N, N);
}
