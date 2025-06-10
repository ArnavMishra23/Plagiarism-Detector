#include "../include/preprocessing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// List of common stop words
const char* STOP_WORDS[] = {
    "a", "an", "the", "and", "or", "but", "is", "are", "was", "were",
    "in", "on", "at", "to", "for", "with", "by", "about", "of", "from"
};
const int STOP_WORDS_COUNT = 20;

char** tokenize(const char* text, int* token_count) {
    // Count the number of tokens
    int count = 0;
    char* text_copy = strdup(text);
    char* token = strtok(text_copy, " \t\n\r\f\v.,;:!?\"'()[]{}-");
    
    while (token != NULL) {
        count++;
        token = strtok(NULL, " \t\n\r\f\v.,;:!?\"'()[]{}-");
    }
    
    free(text_copy);
    
    // Allocate memory for tokens
    char** tokens = (char**)malloc(count * sizeof(char*));
    if (tokens == NULL) {
        printf("Memory allocation failed\n");
        *token_count = 0;
        return NULL;
    }
    
    // Extract tokens
    text_copy = strdup(text);
    token = strtok(text_copy, " \t\n\r\f\v.,;:!?\"'()[]{}-");
    int i = 0;
    
    while (token != NULL && i < count) {
        tokens[i] = strdup(token);
        to_lowercase(tokens[i]);
        i++;
        token = strtok(NULL, " \t\n\r\f\v.,;:!?\"'()[]{}-");
    }
    
    free(text_copy);
    *token_count = count;
    return tokens;
}

void to_lowercase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

char** remove_stop_words(char** tokens, int* token_count) {
    int new_count = 0;
    char** new_tokens = (char**)malloc(*token_count * sizeof(char*));
    
    if (new_tokens == NULL) {
        printf("Memory allocation failed\n");
        return tokens;
    }
    
    for (int i = 0; i < *token_count; i++) {
        int is_stop_word = 0;
        
        for (int j = 0; j < STOP_WORDS_COUNT; j++) {
            if (strcmp(tokens[i], STOP_WORDS[j]) == 0) {
                is_stop_word = 1;
                break;
            }
        }
        
        if (!is_stop_word) {
            new_tokens[new_count] = strdup(tokens[i]);
            new_count++;
        }
    }
    
    // Free original tokens
    for (int i = 0; i < *token_count; i++) {
        free(tokens[i]);
    }
    free(tokens);
    
    *token_count = new_count;
    return new_tokens;
}

void free_tokens(char** tokens, int token_count) {
    for (int i = 0; i < token_count; i++) {
        free(tokens[i]);
    }
    free(tokens);
}