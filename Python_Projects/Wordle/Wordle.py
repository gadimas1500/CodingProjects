import random
class Wordle:
    def __init__(self):
        self.vocabulary_list = list()
        file = open("vocabulary.txt", 'r')
        for i in file:
            self.vocabulary_list.append(i[:-1])
        num = random.randint(0, 2310)
        self.secret = self.vocabulary_list[num]  # assignes the secret word
        file.close()
        self.can_show = True

    def score_guess(self, guess):   #returns the result of the guess
        result = ['x', 'x', 'x', 'x', 'x']
        if self.secret == guess:
            return True
        for i in range(5):
            let = guess[i]
            if let == self.secret[i]:
                result[i] = 'g'
        for i in range(5):
            let = guess[i]
            for j in range(5):
                if let is self.secret[j] and result[i] != 'g':
                    result[i] = 'y'
        for i in range(5):
            if result[i] != 'g' and result[i] != 'y':
                result[i] = 'x'
        return [guess, result]

    def valid_guess(self, word): #if the guess exists in the list
        if word == "reveal letter":
            return self.reveal_char()
        if word == "show":
            print(f"SECRET WORD: **{self.secret}**")
        return True if len(word) == 5 and word in self.vocabulary_list else False

    def reveal_char(self):
        if self.can_show:
            rand = random.randint(0, 4)
            str = ""
            for i in range(5):
                if i == rand:
                    str+= f"{self.secret[i]}"
                else:
                    str += f"_"
            self.can_show = False
            return str
        else:
            return "You don't have anymore reveals :("






if __name__ == "__main__":
    counter = 0
    vocabulary_list = list()
    file = open("vocabulary.txt", 'r')
    for i in file:
        vocabulary_list.append(i[:-1])
    num = random.randint(0, 2310)
    guess = vocabulary_list[num]  # assignes the secret word
    file.close()


    game_state = True
    game = Wordle()
    alpha = list()
    show_char = True
    tries = 5
    while game_state:
        if tries == 0:
            print(f"You failed. The word was '{game.secret}'")
            break
        elif tries == 1 and show_char:
            print("You have one guess remaining. Would you like me to reveal one character?[y/n]")
            user = input()
            if user == 'y':
                print(f"Sure thing ->{game.reveal_char()}")
            elif user == 'n':
                print("okay")
            else:
                print("I didn't understand that input, so no reveal for you!")
            show_char = not show_char
        guess = input("guess: ")
        if not game.valid_guess(guess):
            print("That was not a valid guess")
            continue
        if isinstance(game.score_guess(guess), bool) and game.score_guess(guess):   #only if it returned true
            print("Yes! You guessed the word!")
            break
        else:
            print(game.score_guess(guess)[0])
            for i in game.score_guess(guess)[1]:
                print(i, end='')
            print()
        tries -=1
        print()






