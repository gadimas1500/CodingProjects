import random as rand
import time


wordList = []
wordLength = []
wordNum = 1
symbol = '^'
longestWord = 0
answers = False
letter = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
         'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
         'u', 'v', 'w', 'x', 'y', 'z']
recordKeeperFile = open("recordKeeperWordSearch", "r+")#rand.randint(1000, 9999)
recentNum = recordKeeperFile.readlines()[-1]
def setPostitions(): #TAKES IN THE LIST OF WORDS
   global wordGrid
   global boolGrid
   randLen = rand.randint(0, dimension)
   randWidth = rand.randint(0, dimension)
   trueDem = dimension - 1
   charPos = 0
   for word in wordList:

       while True:
           randPos = rand.randint(0, 3)    #CHOOSES A RANDOM ORIENTATION TO PUT THE WORD
           randLen = rand.randint(0, dimension - 1)
           randWidth = rand.randint(0, dimension - 1)
           goodPosition = True
           '''
           print("for 1: ", ((randWidth + len(word)) <= dimension))
           print("for 2: ", (randWidth-len(word) >= 0) and randPos == 1)
           print("for 3: ", ((randLen+len(word)) <= dimension) and randPos == 2)
           print("for 4: ", (randLen >= len(word)) and randPos == 3)
           print(f"randPos: {randPos}")
           '''
           if ((randWidth + len(word)) <= dimension) and randPos == 0: #CHECKS IF WE CAN PUT LEFT TO RIGHT FROM A POINT
               for r in range(0, len(word)):
                   if (boolGrid[randLen][randWidth+r] != True) or wordGrid[randLen][randWidth+r] == word[r]:    #THIS CHECKS THE BOOLEAN GRID IF WE CAN PUT THE WORD IN THAT POSITION, ELSE CHOOSE ANOTHER POSITION
                       goodPosition = False
                       break
               if not goodPosition:
                   continue
               for i in range(0, len(word)):
                   if wordGrid[randLen][randWidth+i] != word[charPos]:
                       wordGrid[randLen][randWidth+i] = word[charPos]
                       answerGrid[randLen][randWidth+i] = word[charPos] + symbol

                       boolGrid[randLen][randWidth+i] = False
                   charPos += 1
           elif (randWidth-len(word) >= 0) and randPos == 1:           #CHECKS IF WE CAN PUT TO RIGHT TO LEFT FROM A POINT
               for r in range(0, len(word)):
                   if (boolGrid[randLen][randWidth-r] != True) or wordGrid[randLen][randWidth-r] == word[r]:    #THIS CHECKS THE BOOLEAN GRID IF WE CAN PUT THE WORD IN THAT POSITION, ELSE CHOOSE ANOTHER POSITION
                       goodPosition = False
                       break
               if not goodPosition:
                   continue
               for i in range(0, len(word)):
                   if wordGrid[randLen][randWidth-i] != word[charPos]:
                       wordGrid[randLen][randWidth-i] = word[charPos]
                       answerGrid[randLen][randWidth-i] = word[charPos] + symbol
                       boolGrid[randLen][randWidth-i] = False
                   charPos += 1
           elif ((randLen+len(word)) <= dimension) and randPos == 2: #CHECKS IF WE CAN PUT BOTTOM TO TOP FROM A POINT
               for r in range(0, len(word)):
                   if (boolGrid[randLen+r][randWidth] != True) or wordGrid[randLen+r][randWidth] == word[r]:    #THIS CHECKS THE BOOLEAN GRID IF WE CAN PUT THE WORD IN THAT POSITION, ELSE CHOOSE ANOTHER POSITION
                       goodPosition = False
                       break
               if not goodPosition:
                   continue
               for i in range(0, len(word)):
                   if wordGrid[randLen+i][randWidth] != word[charPos] :
                       wordGrid[randLen+i][randWidth] = word[charPos]
                       answerGrid[randLen+i][randWidth] = word[charPos] + symbol
                       boolGrid[randLen+i][randWidth] = False
                   charPos += 1
           elif (randLen >= len(word)) and randPos == 3:           #CHECKS IF WE CAN PUT TO TOP TO BOTTOM FROM 0
               for r in range(0, len(word)):
                   if (boolGrid[randLen-r][randWidth] != True) or wordGrid[randLen-r][randWidth] == word[r]:    #THIS CHECKS THE BOOLEAN GRID IF WE CAN PUT THE WORD IN THAT POSITION, ELSE CHOOSE ANOTHER POSITION
                       goodPosition = False
                       break
               if not goodPosition:
                   continue
               for i in range(0, len(word)):
                   if wordGrid[randLen-i][randWidth] != word[charPos]:
                       wordGrid[randLen-i][randWidth] = word[charPos]
                       answerGrid[randLen-i][randWidth] = word[charPos] + symbol
                       boolGrid[randLen-i][randWidth] = False
                   charPos += 1
           else:
               #print(f"Something wrong @ ROW {randLen} COL {randWidth} RANDPOS {randPos} for {word}")
               charPos = 0
               continue
          # print(f"{word} [{randLen}, {randWidth}]")
           charPos = 0
           break

def printWordList():
   print()
   for i in range(len(wordList)):
       print(f"{i+1}. {wordList[i]}")

def randomLetter():
   global letter
   toRet = rand.randint(0, 25)
   return letter[toRet]

def printGrid():
   print()
   print("    ", end='')
   for i in range(dimension):  #TOP COORDINATE NUMS
       if i < 10:
           print(f'{i}  ', end= '')
       else:
           print(f"{i} ", end= '')
   print()
   for i in range(dimension):  #SIDE COORDINATE NUMS
       if i < 10:
           print(i, '  ', end='')
       else:
           print(i, ' ', end='')
       for r in range(dimension):
           print(wordGrid[i][r], " ", end='')
       print()

def printBoolGrid():
   for i in range(dimension):
       for r in range(dimension):
           print(boolGrid[i][r], " ", end='')
       print()

def checkFileName(namePassed):
   global fileName
   nameFiles = open("WordSearchFileNames", 'r+')
   names = nameFiles.readlines()
   while f"{namePassed}\n" in names:
       namePassed = input(f"The name '{namePassed}' already exists. Please choose a different name...\n")
   fileName = namePassed
   nameFiles.write(f"\n{namePassed}\n")
   nameFiles.close()





#MAIN
while True:
   user = input(f"Enter Word #{wordNum} (Type 0 to stop): ")
   if user.isnumeric() and user != '0':
       print("Please only use letter characters! Try Again...")
       continue
   elif user != '0':
       tempUser = user.split()
       store = ''
       for i in tempUser:
           store += i

       wordList.append(store.lower())
       #continue
   elif user == '0':
       break
   else:
       print("I did not understand that input! Try again please...")
       continue
   wordNum += 1
'''

wordList.append("inland")
wordList.append("empire")
wordList.append("health")
wordList.append("plan")
wordList.append("truthfully")
wordList.append("inspirational")
wordList.append("cisco")
wordList.append("boston")
wordList.append("gabriel")
wordList.append("victoria")
wordList.append("enrique")
wordList.append("mother")
'''

for word in wordList:
   wordLength.append(len(word))
wordLength.sort()

for i in wordList:
   if wordLength[-1] == len(i):
       longestWord = i         #THIS IS THE LONGEST STRING IN THE LIST
dimension = wordLength[-1] + 5
wordGrid = [[''] * dimension for _ in range(dimension)]
boolGrid = [[True] * dimension for _ in range(dimension)]
answerGrid = [[''] * dimension for _ in range(dimension)]
for i in range(dimension):      #SETS THE LIST WITH RANDOM LETTERS (ONLY USED TO FILL UP SPACE)
   for r in range(dimension):
       char = randomLetter()
       wordGrid[i][r] = char
       answerGrid[i][r] = char
setPostitions()
fileName = f"{recentNum} WordSearch"
while True:
   user = input(f"Would you like to rename your file? [y/n]\nCurrent File Name: {fileName}\n")
   if user == 'y':
       name = input("Enter your new file name: ")
       checkFileName(name)
       break
   elif user == 'n':
       fileName = f"{recentNum} Word Search"
       recordKeeperFile.write(f"\n{int(recentNum) + 1}")
       recordKeeperFile.close()
       break
   else:
       print("I did not understand that input")
#printGrid()
#printWordList()
print()
print(f"Stored as: \"{fileName}\"")

#SAVES TO FILE
doc = open(fileName, 'w')
ansDoc = open(f"{fileName} [Answers]", 'w')
   #USER
doc.write(f"                {fileName}   \n\n") #A TOP SPACE BUFFER
doc.write("    ") #SHIFTS THE TOP NUMBERS
for i in range(dimension):  # TOP COORDINATE NUMS
   if i < 10:
       doc.write(f'{i}  ') #NUMBER SPACING BETWEEN EACH OTHER
   else:
       doc.write(f"{i} ")
doc.write('\n')
for i in range(dimension):  # SIDE COORDINATE NUMS
   if i < 10:      #THE NUMBERS
       doc.write(f'{i}   ')
   else:
       doc.write(f'{i}  ')
   for r in range(dimension):  #THE LETTERS
       doc.write(f'{wordGrid[i][r]}  ')
   doc.write('\n')
doc.write('\n')
for i in range(len(wordList)):
   doc.write(f'{i+1}. {wordList[i]}\n')
doc.close()

   #ANSWERS
ansDoc.write(f"                {fileName} [Answers]   \n\n") #A TOP SPACE BUFFER
ansDoc.write(f"{fileName}\n")
ansDoc.write("    ") #SHIFTS THE TOP NUMBERS
for i in range(dimension):  # TOP COORDINATE NUMS
   if i < 10:
       ansDoc.write(f'{i}  ') #NUMBER SPACING BETWEEN EACH OTHER
   else:
       ansDoc.write(f"{i} ")
ansDoc.write('\n')
for i in range(dimension):  # SIDE COORDINATE NUMS
   if i < 10:      #THE NUMBERS
       ansDoc.write(f'{i}   ')
   else:
       ansDoc.write(f'{i}  ')
   for r in range(dimension):  #THE LETTERS
       if answerGrid[i][r][-1] == symbol:
           ansDoc.write(f'{answerGrid[i][r]} ')
       else:
           ansDoc.write(f'{answerGrid[i][r]}  ')
   ansDoc.write('\n')
ansDoc.write('\n')
for i in range(len(wordList)):
   ansDoc.write(f'{i+1}. {wordList[i]}\n')
ansDoc.close()



