#include "../include/ngram.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NGramCollection* create_ngrams(char** tokens, int token_count, int n) {
    if (token_count < n) {
        return NULL;
    }
    
    NGramCollection* collection = (NGramCollection*)malloc(sizeof(NGramCollection));
    if (collection == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    // Initial capacity
    collection->capacity = token_count - n + 1;
    collection->count = 0;
    collection->ngrams = (NGram*)malloc(collection->capacity * sizeof(NGram));
    
    if (collection->ngrams == NULL) {
        printf("Memory allocation failed\n");
        free(collection);
        return NULL;
    }
    
    // Create n-grams
    for (int i = 0; i <= token_count - n; i++) {
        // Calculate the length of the n-gram
        int ngram_len = 0;
        for (int j = 0; j < n; j++) {
            ngram_len += strlen(tokens[i + j]);
            if (j < n - 1) {
                ngram_len++; // Space between tokens
            }
        }
        
        // Create the n-gram string
        char* ngram = (char*)malloc((ngram_len + 1) * sizeof(char));
        if (ngram == NULL) {
            printf("Memory allocation failed\n");
            continue;
        }
        
        ngram[0] = '\0';
        for (int j = 0; j < n; j++) {
            strcat(ngram, tokens[i + j]);
            if (j < n - 1) {
                strcat(ngram, " ");
            }
        }
        
        // Add to collection
        add_ngram(collection, ngram);
        free(ngram);
    }
    
    return collection;
}

void add_ngram(NGramCollection* collection, const char* ngram) {
    // Check if n-gram already exists
    for (int i = 0; i < collection->count; i++) {
        if (strcmp(collection->ngrams[i].text, ngram) == 0) {
            collection->ngrams[i].count++;
            return;
        }
    }
    
    // Resize if needed
    if (collection->count >= collection->capacity) {
        collection->capacity *= 2;
        collection->ngrams = (NGram*)realloc(collection->ngrams, 
                                            collection->capacity * sizeof(NGram));
        if (collection->ngrams == NULL) {
            printf("Memory reallocation failed\n");
            return;
        }
    }
    
    // Add new n-gram
    collection->ngrams[collection->count].text = strdup(ngram);
    collection->ngrams[collection->count].count = 1;
    collection->count++;
}

void free_ngram_collection(NGramCollection* collection) {
    if (collection == NULL) {
        return;
    }
    
    for (int i = 0; i < collection->count; i++) {
        free(collection->ngrams[i].text);
    }
    
    free(collection->ngrams);
    free(collection);
}