#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int LCS(char *X, char *Y, char *subsequence) {
    int n = strlen(X);
    int m = strlen(Y);

    int L[MAX_LENGTH][MAX_LENGTH];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
            }
        }
    }

    int index = L[n][m];
    subsequence[index] = '\0';

    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            subsequence[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] >= L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return L[n][m];
}

int main() {
    char X[MAX_LENGTH], Y[MAX_LENGTH];
    char subsequence[MAX_LENGTH];

    printf("Enter string X: ");
    scanf("%s", X);

    printf("Enter string Y: ");
    scanf("%s", Y);

    int result = LCS(X, Y, subsequence);

    printf("Length of the Longest Common Subsequence: %d\n", result);
    printf("Longest Common Subsequence: %s\n", subsequence);

    return 0;
}
