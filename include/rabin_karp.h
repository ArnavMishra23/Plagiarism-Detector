#ifndef RABIN_KARP_H
#define RABIN_KARP_H

#include "ngram.h"

/**
 * Finds matching n-grams between two collections using Rabin-Karp algorithm
 * @param collection1 The first collection
 * @param collection2 The second collection
 * @param matches Pointer to store the number of matches
 * @return An array of indices of matching n-grams in collection1
 */
int* find_matches(NGramCollection* collection1, NGramCollection* collection2, int* matches);

#endif // RABIN_KARP_H