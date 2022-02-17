#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char **sort_list(char **l, int size); //helper function to sort the list in alpha order
// Returns true if the guess is an exact match with the secret word, but
// more importantly, fills in the result with the following:
// - 'x' goes in a slot if the corresponding letter in the guess does not appear
//   anywhere in the secret word
// - 'y' goes in a slot if the corresponding letter in the guess appears in the
//   secret word, but not in the corresponding slot
// - 'g' goes in a slot if the corresponding letter in the guess appears in the
//   corresponding slot in the secret word.
//   You can assume that result points at enough memory for a string of length
//   5. (ie, at least 6 bytes long)
bool score_guess(char *secret, char *guess, char *result) {
	char ret[5];// = (char *)calloc(5, sizeof(char));
	char green = 'g';
	char yellow = 'y';
	char not = 'x';
	if(strcmp(secret, guess) == 0){	//if we gues the exact word
		return true;
	}
	for(int i = 0; i < 5; i++){	
		char let = guess[i];	//a char of the guess
		for(int j = 0; j < 5; j++){
			printf("%c == %c\n", let, secret[j]);
			if(strcmp(&let, &secret[j]) == 0){	//chars in the same position and same char
				ret[i] = green;
				//continue;	//move onto the next word
			}
		}
	}
	for(int i = 0; i < 5; i++){
		char let = guess[i];
		if(strcmp(&let, &secret[i]) == 0 && strcmp(&ret[i], &green) != 0){ //checks if the char exists in the secret
			ret[i] = yellow;
		}
	}
	for(int i = 0; i < 5; i++){
		if(strcmp(&result[i], &green) != 0 && strcmp(&result[i], &yellow) != 0){
			ret[i] = not;
		}
	}
	result = ret;
  return false;
}

// Returns true if the specified guess is one of the strings in the vocabulary,
// and false otherwise. num_words is the length of the vocabulary.
// A simple linear scan over the strings in vocabulary is fine for our purposes,
// but consider: could you do this search more quickly?
bool valid_guess(char *guess, char **vocabulary, size_t num_words) {
	for(int i = 0; i < num_words; i++){
		if(strcmp(guess, vocabulary[i]) == 0){
			return true;
		}
	}
  return false;
}

// Returns an array of strings (so, char **), where each string contains a word
// from the specified file. The file is assumed to contain 5-letter words, one
// per line.
// Also, this function sets the value pointed at by *num_words to be the number
// of words read.
// This will need to allocate enough memory to hold all of the char* pointers --
// so you will keep track of the size of your char** array and then use realloc
// to make the array larger over time, so that you have enough space for the
// dynamically-growing array of char *.
// Use fopen to open the input file for reading,
// strdup (or strndup) to make copies of each word read from that file, and
// fclose to close the file when you are done reading from it.
// Each element of the array should be a single five-letter word,
// null-terminated.
char **load_vocabulary(char *filename, size_t *num_words) {
   char **out = NULL;	//the pointer we are assigning this to
   int mem_size = 4;
	out = (char**)malloc(mem_size);
	//*out = (char*)malloc(8);
	FILE* infile;
	char buf[12];
	infile = fopen(filename, "r");	//assigns the file to this var
   size_t nums = 0;	//the start of the file
	char *word;
	for(int i = 0; fgets(buf, 12, infile) != NULL; i++){
		out[i] = strndup(buf, 5);	//assigns the current word to the current index
		//out[i][strlen(out[i])-1] = '\0';
		out = (char**)realloc(out, mem_size*(i+1)*100);	//reallocates new memory for the growing size of the list
		nums++;	
	}
	*num_words = nums;	//assigns the number of words in the list

	out = sort_list(out, nums);	//sorts the list in alpha order
	fclose(infile);	//closes the file
   return out;
}

char** sort_list(char **l, int size){	//sorts the list in alpha order
	for(int i = 0; i < size; i++){
		for(int j = i; j < size; j++){
			if(strcmp(l[i], l[j]) > 0){
				char *hold = l[j];
				l[j] = l[i];
				l[i] = hold;
			}
		}
	}
	return l;
}

// Free each of the strings in the vocabulary, as well as the pointer vocabulary
// itself (which points to an array of char *).
void free_vocabulary(char **vocabulary, size_t num_words) {
  // TODO(you): finish this function
  for(int i = 0; i < num_words; i++){
		free(vocabulary[i]);
	}
	free(vocabulary);
}

// Once your other functions are working, please revert your main() to its
// initial state, but please feel free to change it, during development. You'll
// want to test out each individual function!
int main(void) {
  char **vocabulary;
  size_t num_words;
  int num_guesses = 0;

  srand(time(NULL));

  // load up the vocabulary and store the number of words in it.
  vocabulary = load_vocabulary("vocabulary.txt", &num_words);

  // Randomly select one of the words from the file to be today's SECRET WORD.
  int word_index = rand() % num_words;
  char *secret = vocabulary[word_index];
  printf("****SECRET WORD****: %s\n", secret);


  // input buffer -- we'll use this to get a guess from the user.
  char guess[80];

  // buffer for scoring each guess.
  char result[6] = {0};
  bool success = false;
  printf("time to guess a 5-letter word! (press ctrl-D to exit)\n");
  while (!success) {
    printf("guess: ");
    if (fgets(guess, 80, stdin) == NULL) {
      break;
    }
    // Whatever the user input, cut it off at 5 characters.
    guess[5] = '\0';

    if (!valid_guess(guess, vocabulary, num_words)) {
      printf("not a valid guess\n");
      continue;
    } else {
      num_guesses++;
    }
    success = score_guess(secret, guess, result);
    printf("%s\n", guess);
    printf("%s\n", result);
  }

  if (success) {
    printf("you win, in %d guesses!\n", num_guesses);
  }
  free_vocabulary(vocabulary, num_words);

  return 0;
}
