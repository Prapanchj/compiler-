#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100

// Keywords and operators
const char *keywords[] = {"int", "float", "if", "else", "for", "while", "return"};
const char operators[] = "+-*/=<>!&|";

// Simple check for keyword
int is_keyword(const char *str) {
    for (int i = 0; i < 7; i++) {
        if (strcmp(str, keywords[i]) == 0) return 1;
    }
    return 0;
}

// Simple check for operator
int is_operator(char c) {
    return strchr(operators, c) != NULL;
}

// Lexical analysis
void analyse(FILE *input) {
    char c, buffer[MAX_LEN];
    int index = 0;

    while ((c = fgetc(input)) != EOF) {
        if (isspace(c)) {
            if (index > 0) {
                buffer[index] = '\0';
                printf(is_keyword(buffer) ? "Keyword: %s\n" : "Identifier: %s\n", buffer);
                index = 0;
            }
        } else if (is_operator(c)) {
            printf("Operator: %c\n", c);
        } else if (isalnum(c)) {
            buffer[index++] = c;
        }
    }

    if (index > 0) {
        buffer[index] = '\0';
        printf(is_keyword(buffer) ? "Keyword: %s\n" : "Identifier: %s\n", buffer);
    }
}

int main() {
    printf("Enter code:\n");
    analyse(stdin);
    return 0;
}

