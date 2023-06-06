#include <stdio.h>
#include <string.h>

#define MAX_TEXT_SIZE 1000
#define MAX_PATTERN_SIZE 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void computeBadCharTable(char* pattern, int patternSize, int badCharTable[]) {
    int i;
    for (i = 0; i < 256; i++) {
        badCharTable[i] = -1;
    }
    for (i = 0; i < patternSize; i++) {
        badCharTable[(int)pattern[i]] = i;
    }
}

void boyerMoore(char* text, char* pattern) {
    int textSize = strlen(text);
    int patternSize = strlen(pattern);

    int badCharTable[256];
    computeBadCharTable(pattern, patternSize, badCharTable);

    int shift = 0;
    while (shift <= (textSize - patternSize)) {
        int j = patternSize - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            printf("Pattern found at index %d\n", shift);
            
            // Move the window to the right
            shift += (shift + patternSize < textSize) ? patternSize - badCharTable[text[shift + patternSize]] : 1;
        } else {
            int badCharShift = j - badCharTable[text[shift + j]];
            shift += max(1, badCharShift);
        }
    }
}

int main() {
    char text[MAX_TEXT_SIZE];
    char pattern[MAX_PATTERN_SIZE];

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter the pattern to search: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0';

    boyerMoore(text, pattern);

    return 0;
}