#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char ** parse(char * iStr) {
    char ** tokens = malloc(3 * sizeof(void *));
    for (int i = 0; i < 3; i++) {
        tokens[i] = malloc(strlen(iStr) * sizeof(char));
    }
    int strIndexer = 0;
    int charIndexer = 0;
    for (int i = 0; i < strlen(iStr); i++) {
        if (iStr[i] == ' ') {
            tokens[strIndexer][charIndexer] = '\0';
            strIndexer++;
            charIndexer = 0;
        } else {
            tokens[strIndexer][charIndexer++] = iStr[i];
        }
    }
    tokens[strIndexer][charIndexer] = '\0';
    return tokens;
}

int main() {
    char * s = "REGISTER mario foobar00";
    char ** sParts = parse(s);
    for (int i = 0; i < 3; i++) {
        printf("%s\n", sParts[i]);
    }
}

