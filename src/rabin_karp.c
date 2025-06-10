#include "../include/rabin_karp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRIME 101

// Hash function for Rabin-Karp
unsigned long hash(const char* str) {
    unsigned long hash = 0;
    for (int i = 0; str[i]; i++) {
        hash = (hash * 256 + str[i]) % PRIME;
    }
    return hash;
}

int* find_matches(NGramCollection* collection1, NGramCollection* collection2, int* matches) {
    if (collection1 == NULL || collection2 == NULL) {
        *matches = 0;
        return NULL;
    }
    
    int* match_indices = (int*)malloc(collection1->count * sizeof(int));
    if (match_indices == NULL) {
        printf("Memory allocation failed\n");
        *matches = 0;
        return NULL;
    }
    
    int match_count = 0;
    
    // Create hash table for collection2
    unsigned long* hashes = (unsigned long*)malloc(collection2->count * sizeof(unsigned long));
    if (hashes == NULL) {
        printf("Memory allocation failed\n");
        free(match_indices);
        *matches = 0;
        return NULL;
    }
    
    for (int i = 0; i < collection2->count; i++) {
        hashes[i] = hash(collection2->ngrams[i].text);
    }
    
    // Find matches
    for (int i = 0; i < collection1->count; i++) {
        unsigned long h1 = hash(collection1->ngrams[i].text);
        
        for (int j = 0; j < collection2->count; j++) {
            if (h1 == hashes[j] && strcmp(collection1->ngrams[i].text, collection2->ngrams[j].text) == 0) {
                match_indices[match_count++] = i;
                break;
            }
        }
    }
    
    free(hashes);
    *matches = match_count;
    return match_indices;
}