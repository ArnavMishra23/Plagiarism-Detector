#ifndef NGRAM_H
#define NGRAM_H

/**
 * Structure to represent an n-gram
 */
typedef struct {
    char* text;
    int count;
} NGram;

/**
 * Structure to represent a collection of n-grams
 */
typedef struct {
    NGram* ngrams;
    int count;
    int capacity;
} NGramCollection;

/**
 * Creates n-grams from an array of tokens
 * @param tokens The array of tokens
 * @param token_count The number of tokens
 * @param n The size of each n-gram
 * @return A collection of n-grams
 */
NGramCollection* create_ngrams(char** tokens, int token_count, int n);

/**
 * Adds an n-gram to a collection or increments its count if it already exists
 * @param collection The collection to add to
 * @param ngram The n-gram text to add
 */
void add_ngram(NGramCollection* collection, const char* ngram);

/**
 * Frees an n-gram collection
 * @param collection The collection to free
 */
void free_ngram_collection(NGramCollection* collection);

#endif // NGRAM_H