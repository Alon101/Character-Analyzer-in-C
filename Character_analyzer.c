#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    int letters = 0;
    int digits = 0;
    int spaces = 0;
    int symbols = 0;
    printf ("Please enter a sentence:");
    if (fgets(sentence, sizeof(sentence), stdin) != NULL) {
        /* check for buffer overflow*/
        if (strchr(sentence, '\n') == NULL) {
            int ch;
            while((ch = getchar()) != '\n' && ch != EOF) {}
        }
        if (sentence[0] == '\n') {
            printf("you must enter something!");
            return 1;
        }
        for (int i = 0; sentence[i] != '\0' && sentence[i] !='\n'; i++ ) {
            if ( sentence[i] >= '0' && sentence[i] <= '9' ) {
                digits++;
            } else if ( (sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z') ) {
                letters++;
            } else if ( sentence[i] == ' ') {
                spaces++;
            } else {
                symbols++;
            }
        }
    } else {
            printf ("Input error!\n");
            return 1;
        }
    printf ("Letters: %d\n", letters);
    printf ("Digits: %d\n", digits);
    printf ("Spaces: %d\n", spaces);
    printf ("Symbols: %d\n", symbols);
    return 0;
}