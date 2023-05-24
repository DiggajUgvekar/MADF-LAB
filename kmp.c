#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void KMPFailureFunction(char *P, int m, int *f) {
    int i = 1, j = 0;
    f[0] = 0;

    while (i < m) {
        if (P[i] == P[j]) {
            f[i] = j + 1;
            i++;
            j++;
        } else if (j > 0) {
            j = f[j - 1];
        } else {
            f[i] = 0;
            i++;
        }
    }
}

int KMPMatch(char *T, char *P) {
    int n = strlen(T);
    int m = strlen(P);

    int *f = (int *)malloc(m * sizeof(int));
    KMPFailureFunction(P, m, f);

    int i = 0, j = 0;
    while (i < n) {
        if (T[i] == P[j]) {
            if (j == m - 1) {
                free(f);
                return i - j;
            }
            i++;
            j++;
        } else if (j > 0) {
            j = f[j - 1];
        } else {
            i++;
        }
    }

    free(f);
    return -1;
}

int main() {
    char T[100];
    char P[100];

    printf("Enter string T: ");
    scanf("%s", T);

    printf("Enter string P: ");
    scanf("%s", P);

    int result = KMPMatch(T, P);
    if (result != -1) {
        printf("Pattern found at index %d\n", result);
    } else {
        printf("Pattern not found in the text.\n");
    }

    return 0;
}
