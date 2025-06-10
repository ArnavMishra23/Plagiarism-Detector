#include "../include/cosine_similarity.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double calculate_cosine_similarity(NGramCollection* collection1, NGramCollection* collection2) {
    if (collection1 == NULL || collection2 == NULL) {
        return 0.0;
    }
    
    double dot_product = 0.0;
    double magnitude1 = 0.0;
    double magnitude2 = 0.0;
    
    // Calculate dot product
    for (int i = 0; i < collection1->count; i++) {
        for (int j = 0; j < collection2->count; j++) {
            if (strcmp(collection1->ngrams[i].text, collection2->ngrams[j].text) == 0) {
                dot_product += collection1->ngrams[i].count * collection2->ngrams[j].count;
                break;
            }
        }
    }
    
    // Calculate magnitudes
    for (int i = 0; i < collection1->count; i++) {
        magnitude1 += collection1->ngrams[i].count * collection1->ngrams[i].count;
    }
    
    for (int i = 0; i < collection2->count; i++) {
        magnitude2 += collection2->ngrams[i].count * collection2->ngrams[i].count;
    }
    
    magnitude1 = sqrt(magnitude1);
    magnitude2 = sqrt(magnitude2);
    
    // Avoid division by zero
    if (magnitude1 == 0.0 || magnitude2 == 0.0) {
        return 0.0;
    }
    
    return dot_product / (magnitude1 * magnitude2);
}