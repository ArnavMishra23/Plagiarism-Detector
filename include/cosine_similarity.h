#ifndef COSINE_SIMILARITY_H
#define COSINE_SIMILARITY_H

#include "ngram.h"

/**
 * Calculates the cosine similarity between two n-gram collections
 * @param collection1 The first collection
 * @param collection2 The second collection
 * @return The cosine similarity (0-1)
 */
double calculate_cosine_similarity(NGramCollection* collection1, NGramCollection* collection2);

#endif // COSINE_SIMILARITY_H