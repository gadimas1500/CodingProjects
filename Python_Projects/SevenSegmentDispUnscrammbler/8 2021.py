import math
tempArr = list()
arr = []
for i in open('input.txt', 'r'):
    tempArr.append(i)
print(tempArr)
for i in range(len(tempArr)):
    tempArr[i] = tempArr[i].split(" | ")
    tempArr[i][1] = tempArr[i][1][:-1]
for i in range(len(tempArr)):
    arr.append([["".join(list(sorted(r))) for r in tempArr[i][0].split()]])
    arr[i].append(["".join(list(sorted(r))) for r in tempArr[i][1].split()])
counter = 0

for i in range(len(arr)):
    eval = i
    assemble = dict()
    ints = {1:str(), 4:str(),7:str(),8:str(),2:str(),3:str(),5:str(),0:str(),6:str(),9:str()}
    position = {"top":str(), "topLeft":str(), "topRight":str(), "mid":str(),"botLeft":str(), "botRight":str(),"bot":str()}
    lenFive = []
    lenSix = []
    for k in range(len(arr[eval][0])):    #ALL BEFORE DELIMETER
        s = arr[eval][0][k]#"".join(list(set(arr[i][0][k])))    #A NUMBER ON THE LEFT
        if len(s) == 2: #DIGIT 1
            assemble[s] = 1         #MIGHTS TELL US THAT THIS IS A '1'
            ints[1] = s           #AFFIRMING THAT '1' IS THIS 2 BIT STR
        elif len(s) == 3:   #DIGIT 7
            assemble[s] = 7
            ints[7] = s           #AFFIRMING THAT '7' IS THIS 3 BIT STR
        elif len(s) == 4:   #DIGIT 4
            assemble[s] = 4
            ints[4] = s           #AFFIRMING THAT '4' IS THIS 4 BIT STR
        ######WE DON'T NEED 8 BC IT'S IMPLIED THAT IT TAKES ALL EIGHT DIGITS
        elif len(s) == 7:   #DIGIT 8
            assemble[s] = 8
            ints[8] = s           #AFFIRMING THAT '8' IS THIS 7 BIT STR
        elif len(s) == 5:  # DIGITs 2, 3, 5
            lenFive.append(s)   #ADDS LEN 5 DIGITS TO A LIST
        elif len(s) == 6:
            lenSix.append(s)    #ADDS LEN 5 DIGITS TO A LIST

    #LET'S LOOK AT THE ASSIGNMENT OF CHARS INTO THEIR POSITIONS
    for char in ints[7]:        #CHAR AT TOP IS A GUARANTEED POSITION
        if char not in ints[1]:
            position["top"] = char
            break
    for vals in lenFive:        #THIS SAYS THAT ONE OF THE LEN 5 NUMS IS A THREE
        if (ints[7][0] in vals) and (ints[7][1] in vals) and (ints[7][2] in vals):
            ints[3] = vals
            lenFive.remove(vals)
            break
    for vals in lenSix:         #GETS TOP RIGHT, BOTTOM RIGHT, AND VALUE TO REPRESENT 3
        first = ints[1][0]
        second = ints[1][1]
        if ((first in vals) or second in vals) and not (first in vals and second in vals):
            ints[6] = vals
            if first in vals:
                position["topRight"] = second
                position["botRight"] = first
            else:
                position["topRight"] = first
                position["botRight"] = second
            lenSix.remove(vals)
            break
    for vals in range(len(lenSix)): #AT THIS len(LEN SIX) == 2   TOP LEFT, BOTTOM LEFT
        char = set(set(ints[8])).difference(lenSix[vals])

        char = list(char)                   #NINE
        if char[0] in ints[4]:
            position["mid"] = char[0]

            ints[0] = lenSix[vals]
            lenSix.remove(lenSix[vals])
            break
    ints[9] = lenSix[0]                                   #THE LAST ELEMENT IS ZERO
    char = list(set(ints[8]).difference(set(ints[9])))    #BOT LEFT POSITION
    position["botLeft"] = char[0]
    lenSix.remove(lenSix[0])

    #NOW LET'S WORK WITH LEN 5 LIST
    if position["topRight"] in lenFive[0]:   #IF A CHAR IS IN A VALUE AT INDEX ZERO
        ints[2] = lenFive[0]
        for chars in lenFive[0]:
            if chars not in position.values():  # ADDS THE VALUE TO TOP LEFT
                position["bot"] = chars
    else:
        ints[5] = lenFive[0]
        for chars in lenFive[0]:
            if chars not in position.values():      #ADDS THE VALUE TO TOP LEFT
                position["bot"] = chars
    for i in lenFive:
        if i not in ints.values():
            if ints[5] == '':
                ints[5] = i
            else:
                ints[2] = i
            break
    e = []
    for i in position.values():                 #THE LAST POSITION ON THE DISPLAY
        if i != "":
            e.append(i)
    position["topLeft"] = list(set(ints[8]).difference(set(e)))[0]
    lenFive.remove(lenFive[0])              #REMOVES FROM THE LIST LEN 5
    lenFive.remove(lenFive[0])
    key = [i for i in ints.keys()]
    val = [i for i in ints.values()]
    finalDict = dict()
    for i in range(len(key)):
        finalDict[val[i]] = key[i]
    print(finalDict)
    print(arr[eval][1])
    final = ""
    for w in range(len(arr[eval][1])):
        final += str(finalDict[arr[eval][1][w]])
    print(int(final))
    print(f"Counter {counter} + {final} = {int(final) + counter}")
    counter += int(final)
    print(position)
print(f"Counter: {counter}")

