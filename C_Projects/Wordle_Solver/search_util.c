#include "search_util.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


// This function should loop over the vocabulary (which contains num_words
// entries) and return the number of words in which that particular letter
// occurs. So if there are 15 words containing the letter 'x' for the particular
// vocabulary, then this function will return 15.
int score_letter(char letter, char **vocabulary, size_t num_words) {

  // TODO(you): implement this function!
  int score = 0;
  for(int i = 0; i < (int)num_words; i++){	//the word
  		for(int j = 0; j < 5; j++){
  			if(letter == vocabulary[i][j]){		//a character in that word
  				score++;
  			}
  		}
  }
  return score;
}


// Calculate the score for a given word, where the letter_scores array has
// already been filled out for you and is guaranteed to be of length 26. Slot 0
// contains the score for 'a', and slot 25 contains the score for 'z'.
// The score for a word is the sum of all of the letter scores, *for unique
// letters*. So if the letter 'e' occurs three times, it only contributes to the
// score once.
int score_word(char *word, int *letter_scores) {

  // TODO(you): implement this function!
  char appeared[5];
  bool move_on = false;
  int word_score = 0;
  for(int i = 0; i < 5; i++){			//for all the chars in the word
  		for(int j = 0; j < 26; j++){	//iterates all the chars in the letter list
  			for(int k = 0; k < 5; k++){	//checks if we already awarded a score for that letter
				if(appeared[k] == word[i]){
					move_on = true;
					break;
				}
			}
			if(move_on){	//if there is a repeat
				break;
	  		}
	  		word_score += letter_scores[j];	
	  		appeared[i] = word[i];
  		}
  		if(move_on){	//if there is a repeat
  			move_on = false;
  			continue;
  		}	
  }
  return word_score;

}

// Returns the optimum guess, based on our heuristic.
// This one works, you don't have to change it.
// Note that this function allocates a new string every time it runs, and those
// strings will need to be freed!
char *get_guess(char **vocabulary, size_t num_words) {
  int letter_scores[26];

  for (int i = 0; i < 26; i++) {
    letter_scores[i] = score_letter('a' + i, vocabulary, num_words);
    
  }

  char *best_guess = NULL;
  int best_score = 0;
  int score = 0;
  for (size_t i = 0; i < num_words; i++) {
    if (vocabulary[i] == NULL) {
      continue;
    }
    score = score_word(vocabulary[i], letter_scores);
    if (score > best_score) {
      best_guess = vocabulary[i];
      best_score = score;
    }
  }
  return best_guess ? strdup(best_guess) : NULL;
}

// This function will filter down the vocabulary based on the knowledge that the
// specified letter *does not occur* in the secret word. So for any of the words
// in the vocabulary that do contain that letter, free their pointers and set
// the corresponding slot to NULL.
// Returns the number of words that have been filtered from the vocabulary.
size_t filter_vocabulary_gray(char letter, char **vocabulary,
                              size_t num_words) {
                              
  // TODO(you): implement this function!
  size_t filtered = 0;
  for(int i = 0; i < (int)num_words; i++){	//all the words in the vocan list
  		if(vocabulary[i] == NULL){	//ensures we don'e check a null position
  			continue;
  		}	
		for(int j = 0; j < 5; j++){	//all the chars in a word
			if(letter == vocabulary[i][j]){	//if the character exists in a word
				free(vocabulary[i]);
				vocabulary[i] = NULL;	//'removes' that word from the list
				filtered++;
				break;	//onto the next word
			}
		}
	}
  return filtered;

}

// This function will filter down the vocabulary based on the knowledge that the
// specified letter occurs in the word, *but not at this particular position*.
// So remove any words that either don't contain the letter at all, or do
// contain it, but at the specified position.
// Returns the number of words that have been filtered from the vocabulary.
size_t filter_vocabulary_yellow(char letter, int position, char **vocabulary,
                                size_t num_words) {
  // TODO(you): implement this function!
  bool move_on = false;
  int removed = 0;
  for(int i = 0; i < (int)num_words; i++){	//for all the words in the list
  		for(int j = 0; j < 5; j++){		//for all the chars in the vocab word
  			if(letter == vocabulary[i][j] && i == position){	//the char exists in the word and at the same position
				move_on = false;
				break;
  			} else{ 
  				move_on = true;
  			}
  		}
  		if(move_on){
			continue;
	  	} else{
	  		free(vocabulary[i]);
	  		vocabulary[i] = NULL;
	  		removed++;
	  	}
  }
  return removed;

}


// This function will filter down the vocabulary based on the knowledge that the
// specified letter *definitely* occurs as the specified position. So remove any
// word that does not contain, for the specified position, the specified letter.
// Returns the number of words that have been filtered from the vocabulary.
size_t filter_vocabulary_green(char letter, int position, char **vocabulary,
                               size_t num_words) {

  // TODO(you): implement this function!
  return 0;

}

// Free each of the strings in the vocabulary, as well as the pointer vocabulary
// itself (which points to an array of char *).
void free_vocabulary(char **vocabulary, size_t num_words) {
  for (size_t i = 0; i < num_words; i++) {
    free(vocabulary[i]);
  }
  free(vocabulary);
}
