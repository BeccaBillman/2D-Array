/* Becca Billman, 2D Array and Mem Allocation,COP 3223C, CR02, 07/16/2018*/

//Pre-processor directives
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//have to declare so that the program knows this function exists
int searchForWord(char *list[], int length, char *word);

int main() 
{
    char* words[10];
    FILE* ifp;
    
    //we need to allocate memory for the searchwords so that we have somewhere to store it once we ask the user for a word
    char* searchword = (char*) malloc(20*sizeof(char));
    
// Open the input file (required to have 10 words).
    ifp = fopen("words.txt", "r");
    
// Read in the words into the array words.
    int i;
    for (i = 0; i < 10; i++){
        words[i] = (char*) malloc(20*sizeof(char));
        fscanf(ifp, "%s", words[i]);

    }
// Get the word to search for.char searchword[20];
    printf("Enter a word for which to search?\n");
    scanf("%s", searchword);
    
// Print out an appropriate message, based on the search results.
    if (searchForWord(words, 10, searchword))
        printf("Your word was in the list!\n");
    else{
    	printf("Sorry, your word was NOT on the list.\n"); 
    }
    system("PAUSE");
    return 0; }


// Returns 1 if word is in list. list must have length strings in it.
int searchForWord(char *list[], int length, char *word) {
        int i;
        
// Go through each word.
    for (i = 0; i < length; i++) {
        // See if it's a match.
        if (strcmp(list[i], word) == 0){
        	return 1; 
        }
    }
    
    // If we get here, no match was found.
	return 0;
}

        