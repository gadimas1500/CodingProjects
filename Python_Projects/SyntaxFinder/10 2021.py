import math
arr = []
tempArr = []
#charBoard = []
for i in open("input.txt", 'r'):
    arr.append(i[:-1])
print(arr)
points = {")":3, "]":57,"}":1197,">":25137}
otherPoints = {")":1, "]":2,"}":3,">":4}
open = {"}":"{","]":"[",">":"<",")":"("}
close = {"{":"}","[":"]","<":">","(":")"}
corrupt = []
total = 0
counter = 0
missInfo = []
for i in arr:
    l = []
    temp = 0
    for char in i:
        #THIS WILL RUN IF ABOVE CONDITIONS ARE FALSE
        if char == "(" or len(l)==0:#and (len(l)==0 or l[-1] != ")"):
            l.append(char)  #ADDS A CHAR TO THE LIST
        elif char == "[" or len(l)==0:#and (len(l)==0 or l[-1] != "]"):
            l.append(char)  #ADDS A CHAR TO THE LIST
        elif char == "<" or len(l)==0:#and (len(l)==0 or l[-1] != ">"):
            l.append(char)  #ADDS A CHAR TO THE LIST
        elif char == "{" or len(l)==0:#and (len(l)==0 or l[-1] != "}"):
            l.append(char)  #ADDS A CHAR TO THE LIST


        elif char == ")" and l[-1] == "(":
            #l.remove(l[-1])  #REMOVES A CHAR TO THE LIST
            l.pop()
        elif char == "]" and l[-1] == "[":
            #l.remove(l[-1])  #ADDS A CHAR TO THE LIST
            l.pop()
        elif char == ">" and l[-1] == "<":
            #l.remove(l[-1])  #ADDS A CHAR TO THE LIST
            l.pop()
        elif char == "}" and l[-1] == "{":
            #l.remove(l[-1])  #ADDS A CHAR TO THE LIST
            l.pop()
        else:
            print(l)
            print(f"{counter} Expected: {close[l[-1]]} but got {char}\t{i[:temp+1]}")
            total += points[char]
            corrupt.append(counter)
            break

        temp+=1
    print()

    counter+=1

for i in range(len(arr)):
    if i not in corrupt:
        missInfo.append(i)





print(f"Points: {total}")
print(f"Corrupt lines: {corrupt}")
print(f"Missing Info Lines: {missInfo}")

#PART 2
r = []
for line in missInfo:
    l = []
    temp = 0
    total = 0

    for char in arr[line]:
        # THIS WILL RUN IF ABOVE CONDITIONS ARE FALSE
        if char == "(" or len(l) == 0:  # and (len(l)==0 or l[-1] != ")"):
            l.append(char)  # ADDS A CHAR TO THE LIST
        elif char == "[" or len(l) == 0:  # and (len(l)==0 or l[-1] != "]"):
            l.append(char)  # ADDS A CHAR TO THE LIST
        elif char == "<" or len(l) == 0:  # and (len(l)==0 or l[-1] != ">"):
            l.append(char)  # ADDS A CHAR TO THE LIST
        elif char == "{" or len(l) == 0:  # and (len(l)==0 or l[-1] != "}"):
            l.append(char)  # ADDS A CHAR TO THE LIST


        elif char == ")" and l[-1] == "(":
            # l.remove(l[-1])  #REMOVES A CHAR TO THE LIST
            l.pop()
        elif char == "]" and l[-1] == "[":
            # l.remove(l[-1])  #ADDS A CHAR TO THE LIST
            l.pop()
        elif char == ">" and l[-1] == "<":
            # l.remove(l[-1])  #ADDS A CHAR TO THE LIST
            l.pop()
        elif char == "}" and l[-1] == "{":
            # l.remove(l[-1])  #ADDS A CHAR TO THE LIST
            l.pop()
        else:
            print("SOMETHING FATAL HAPPENED")
            raise InterruptedError
    l.reverse()
    for t in l:
        total *= 5
        total += otherPoints[close[t]]
    r.append(total)
    #print(l)
r.sort()
mid = r[int(len(r)/2)]
print(mid)
print(f"Total: {total}")





