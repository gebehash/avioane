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

char **buildPlane(char type) {
    if (type == '1') {
        char** plane1 = (char**) malloc(4 * sizeof(char *));
        for (int i = 0; i < 4; i++)
            plane1[i] = (char*) malloc(7 * sizeof(char));

        strcpy(plane1[0], "...*...");
        strcpy(plane1[1], ".*****.");
        strcpy(plane1[2], "...*...");
        strcpy(plane1[3], "..***..");
        return plane1;
    } else {
        char** plane2 = (char**) malloc(5 * sizeof(char *));
        for (int i = 0; i < 5; i++)
            plane2[i] = (char*) malloc(9 * sizeof(char));
        strcpy(plane2[0], "....*....");
        strcpy(plane2[1], "...***...");
        strcpy(plane2[2], ".*******.");
        strcpy(plane2[3], "....*....");
        strcpy(plane2[4], "..*****..");
        return plane2;
    }
}

int getRowByType(char type, char dir) {
    if (type == '1' && (dir == 'N' || dir == 'S'))
        return 4;
    if (type == '1' && (dir == 'E' || dir == 'W'))
        return 7;

    if (type == '2' && (dir == 'N' || dir == 'S'))
        return 5;
    if (type == '2' && (dir == 'E' || dir == 'W'))
        return 9;
}

int getColumnByType(char type, char dir) {
    if (type == '1' && (dir == 'N' || dir == 'S'))
        return 7;
    if (type == '1' && (dir == 'E' || dir == 'W'))
        return 4;

    if (type == '2' && (dir == 'N' || dir == 'S'))
        return 9;
    if (type == '2' && (dir == 'E' || dir == 'W'))
        return 5;
}

int getStartCol(int coloana, char type, char dir) {
    if (type == '1') 
    {
        switch (dir) {
            case 'N':
            return coloana - 3;

            case 'E':
            return coloana - 3;

            case 'W':
            return coloana;

            case 'S':
            return coloana - 3;
        }
    }

    if (type == '2') 
    {
        switch (dir) {
            case 'N':
            return coloana - 4;

            case 'E':
            return coloana - 4;

            case 'W':
            return coloana;

            case 'S':
            return coloana - 4;
        }
    }
}

int getStartLin(int linie, char type, char dir) {
    if (type == '1') 
    {
        switch (dir) {
            case 'N':
            return linie;

            case 'E':
            return linie - 3;

            case 'W':
            return linie - 3;

            case 'S':
            return linie - 3;
        }
    }

    if (type == '2') 
    {
        switch (dir) {
            case 'N':
            return linie;

            case 'E':
            return linie - 4;

            case 'W':
            return linie - 4;

            case 'S':
            return linie - 4;
        }
    }
}

char **rotateMatrixByDir(char **avion, int *rowLenght, int *colLenght, char dir) {
    char coord[5] = {'N', 'E', 'S', 'W', 0};
    for (int i = 0; coord[i] != dir; i++)
        avion = rotateMatrix(avion, rowLenght, colLenght);
    return avion;
}

void SolveTask2(void *info, int nr_avioane, int N, char **mat) {
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
        avion = buildPlane(tip);
        int rowLenght = getRowByType(tip, 'N');
        int colLenght = getColumnByType(tip, 'N');
        avion = rotateMatrixByDir(avion, &rowLenght, &colLenght, dir);
        int i, j, a, b;
        for (i = getStartLin(linie, tip, dir), a = 0; a < rowLenght; i++, a++)
            for (j = getStartCol(coloana, tip, dir), b = 0; b < colLenght; j++, b++)
                if (avion[a][b] == '*')
                    mat[i][j] = avion[a][b];
        free_mat(avion, getRowByType(tip, dir));
    }
    printMatrix(mat, N, N);
}
