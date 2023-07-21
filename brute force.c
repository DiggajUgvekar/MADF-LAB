#include <stdio.h>
#include <string.h>

// Function to perform brute force pattern matching
void bruteForcePatternMatching(const char *text, const char *pattern) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    // Loop to slide the pattern over the text
    for (int i = 0; i <= textLength - patternLength; i++) {
        int j;

        // Check for a match at current position
        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j])
                break;
        }

        // If the inner loop finished without breaking, we found a match
        if (j == patternLength) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    const char *text = "abbbcbbacbbcabca";
    const char *pattern = "cabca";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    printf("Pattern matching results:\n");

    bruteForcePatternMatching(text, pattern);

    return 0;
}
