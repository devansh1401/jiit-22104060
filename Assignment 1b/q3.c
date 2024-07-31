#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct Word {
    char text[MAX_WORD_LENGTH];
    int frequency;
};

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char paragraph[10000];
    struct Word words[MAX_WORDS];
    int wordCount = 0;

    printf("Enter a paragraph: ");
    fgets(paragraph, sizeof(paragraph), stdin);

    char *token = strtok(paragraph, " \t\n.,;:!?\"()");
    while (token != NULL) {
        toLowerCase(token);
        
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i].text, token) == 0) {
                words[i].frequency++;
                found = 1;
                break;
            }
        }
        
        if (!found && wordCount < MAX_WORDS) {
            strcpy(words[wordCount].text, token);
            words[wordCount].frequency = 1;
            wordCount++;
        }
        
        token = strtok(NULL, " \t\n.,;:!?\"()");
    }

    printf("\nWord frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i].text, words[i].frequency);
    }

    return 0;
}