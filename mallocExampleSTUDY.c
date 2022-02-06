/*
INSERT TITLE
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAXCHARS 1000
#define INITIAL 8

typedef char word_t[MAXCHARS+1];
int getword(word_t W, int limit);
void exit_if_null(void *ptr, char *msg);

int
main(int argc, char *argv[]) {
    
    size_t current_size = INITIAL;
    int numdistinct=0, totwords=0, i, found;
    word_t one_word;
    char **all_words;
    
    all_words = (char**)malloc(INITIAL*sizeof(*all_words));
    exit_if_null(all_words, "initial allocation");
    printf("-- all_words = %u\n", (unsigned)all_words);

    while (getword(one_word, MAXCHARS) != EOF) {
        totwords = totwords+1;
        // Linear search in array of previous words
        found=0;
        for (i=0; i<numdistinct && !found; i++) {
            found =  (strcmp(one_word, all_words[i]) == 0);
        }    
        if (!found) {
            // New word exists, but is there space?
            if (numdistinct == current_size) {
                current_size *=2;
                all_words = realloc(all_words, 
                        current_size*sizeof(*all_words));
                exit_if_null(all_words, "reallocation");
                printf("-- doubled to %lu\n", current_size);
                printf("-- all_words = %u\n", 
                        (unsigned)all_words);
            }
        // Definately space now.
        all_words[numdistinct] = (char*)malloc(1+strlen(one_word));
        exit_if_null(all_words[numdistinct], "string malloc");

        // and there is also a space for the new word.
        strcpy(all_words[numdistinct], one_word);
        numdistinct++;
        
        }
    }

    printf("%d words read\n", totwords);
    for (i=0; i<numdistinct; i++) {
        printf("word #%d is \"%s\"\n", i, all_words[i]);
        free(all_words[i]);
        all_words[i] = NULL;
    }
    free(all_words);
    all_words = NULL;
    return 0;
}