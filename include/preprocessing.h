#ifndef PREPROCESSING_H
#define PREPROCESSING_H

/**
 * Tokenizes a string into an array of tokens
 * @param text The text to tokenize
 * @param token_count Pointer to store the number of tokens
 * @return An array of token strings
 */
char** tokenize(const char* text, int* token_count);

/**
 * Converts a string to lowercase
 * @param str The string to convert
 */
void to_lowercase(char* str);

/**
 * Removes stop words from an array of tokens
 * @param tokens The array of tokens
 * @param token_count Pointer to the number of tokens (will be updated)
 * @return A new array with stop words removed
 */
char** remove_stop_words(char** tokens, int* token_count);

/**
 * Frees an array of tokens
 * @param tokens The array of tokens to free
 * @param token_count The number of tokens
 */
void free_tokens(char** tokens, int token_count);

#endif // PREPROCESSING_H