/*
Sophisticated programe that shows the numeber of unique
words in a given text. NOT WRITTEN BY ME.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXCHARS 10
#define MAXWORDS 1000

typedef char word_t[MAXCHARS+1];
int getWord(word_t w, int limit);

int
main(int argc, char *argv[]) {
    word_t one_word, all_words[MAXWORDS];
    int numDistinct=0, totWords=0, i, found;
    while (getWord(one_word, MAXCHARS) != EOF) {
        totWords++;
        //Linear search in array of previous words
        found = 0;
        for (i=0; i<numDistinct && !found; i++) {
            found = (strcmp(one_word, all_words[i]) == 0);
        }
        if ( !found && numDistinct<MAXWORDS) {
            strcpy(all_words[numDistinct], one_word);
            numDistinct++;
        }
        /* Program will silently discard words after MAXWORDS have been
        found */
    }

    printf("%d words read\n", totWords);
    for (i=0; i<numDistinct; i++) {
        printf("word #%d is \"%s\"\n", i, all_words[i]);
    }   
    return 0;
}


int
getWord(char W[], int limit) {
    int c, len=0;
    // First, skip over non alphabetics
    while ((c=getchar()) != EOF && !isalpha(c)) {
        // Do nothing more
    }
    if (c == EOF) {
        return EOF;
    }
    // Ok, first character of next word has been found
    W[len++] = c;
    while (len<limit && (c=getchar()) != EOF && isalpha(c)) {
        W[len++] = c;
    }
    // Now, close off the string
    W[len] = '\0';
    return 0;
}