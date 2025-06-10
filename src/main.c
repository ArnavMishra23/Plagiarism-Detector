#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/file_io.h"
#include "../include/preprocessing.h"
#include "../include/ngram.h"
#include "../include/rabin_karp.h"
#include "../include/cosine_similarity.h"

void print_report(double similarity, int matches, int total_ngrams) {
    printf("\n===== PLAGIARISM DETECTION REPORT =====\n");
    printf("Similarity Score: %.2f (%.2f%%)\n", similarity, similarity * 100);
    printf("Matching n-grams: %d out of %d\n", matches, total_ngrams);
    printf("\nInterpretation:\n");
    
    if (similarity >= 0.8) {
        printf("HIGH SIMILARITY (%.2f%%): There is a very high probability of plagiarism.\n", similarity * 100);
    } else if (similarity >= 0.5) {
        printf("MODERATE SIMILARITY (%.2f%%): There may be some copied content or similar phrasing.\n", similarity * 100);
    } else if (similarity >= 0.3) {
        printf("LOW SIMILARITY (%.2f%%): Some similarities exist, but likely not plagiarism.\n", similarity * 100);
    } else {
        printf("MINIMAL SIMILARITY (%.2f%%): The documents appear to be original.\n", similarity * 100);
    }
    
    printf("=====================================\n");
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file1> <file2>\nExample: ./plagiarism_detector data/doc1.txt data/doc2.txt\n", argv[0]);
        return 1;
    }
    
    // Read files
    char* text1 = read_file(argv[1]);
    char* text2 = read_file(argv[2]);
    
    if (text1 == NULL || text2 == NULL) {
        printf("Error reading files\n");
        free(text1);
        free(text2);
        return 1;
    }
    
    printf("Processing document 1: %s\n", argv[1]);
    printf("Processing document 2: %s\n", argv[2]);
    
    // Tokenize
    int token_count1 = 0, token_count2 = 0;
    char** tokens1 = tokenize(text1, &token_count1);
    char** tokens2 = tokenize(text2, &token_count2);
    
    // Remove stop words
    tokens1 = remove_stop_words(tokens1, &token_count1);
    tokens2 = remove_stop_words(tokens2, &token_count2);
    
    printf("Document 1: %d tokens after preprocessing\n", token_count1);
    printf("Document 2: %d tokens after preprocessing\n", token_count2);
    
    // Create n-grams (using n=3 as default)
    int n = 3;
    NGramCollection* ngrams1 = create_ngrams(tokens1, token_count1, n);
    NGramCollection* ngrams2 = create_ngrams(tokens2, token_count2, n);
    
    if (ngrams1 == NULL || ngrams2 == NULL) {
        printf("Error creating n-grams\n");
        free_tokens(tokens1, token_count1);
        free_tokens(tokens2, token_count2);
        free(text1);
        free(text2);
        free_ngram_collection(ngrams1);
        free_ngram_collection(ngrams2);
        return 1;
    }
    
    printf("Document 1: %d unique %d-grams\n", ngrams1->count, n);
    printf("Document 2: %d unique %d-grams\n", ngrams2->count, n);
    
    // Find matches using Rabin-Karp
    int match_count = 0;
    int* matches = find_matches(ngrams1, ngrams2, &match_count);
    
    printf("Found %d matching n-grams\n", match_count);
    
    // Calculate similarity
    double similarity = calculate_cosine_similarity(ngrams1, ngrams2);
    
    // Generate report
    print_report(similarity, match_count, ngrams1->count);
    
    // Clean up
    free_tokens(tokens1, token_count1);
    free_tokens(tokens2, token_count2);
    free_ngram_collection(ngrams1);
    free_ngram_collection(ngrams2);
    free(text1);
    free(text2);
    free(matches);
    
    return 0;
}