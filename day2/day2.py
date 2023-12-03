
with open('day2.txt') as day2:
    contents="".join(day2.readlines()).split('\n')

gameDict={}
redMax=12
greenMax=13
blueMax=14
idsum=0
#Part 1
for eachGame in contents:
    dictSplit=eachGame.split(':')       # Game id : game rolls (split on :)
    gameDict[dictSplit[0]]=dictSplit[1]     # Set the dictionary -> Game id : game rolls
    games=gameDict[dictSplit[0]].split(';')     # Split up by set of dice rolls
    possible=True
    for rolls in games:
        eachDie=[x.split(' ') for x in rolls.split(',')]
        for diceInfo in eachDie:
            if diceInfo[2]=='red':
                if int(diceInfo[1])>redMax:
                    possible=False
            elif diceInfo[2]=='green':
                if int(diceInfo[1])>greenMax:
                    possible=False
            elif diceInfo[2]=='blue':
                if int(diceInfo[1])>blueMax:
                    possible=False
    if possible==True:
        idsum+=int(dictSplit[0].split(' ')[1])
    # print(games)

#Part 2
powersum=0
for eachGame in contents:
    dictSplit=eachGame.split(':')       # Game id : game rolls (split on :)
    gameDict[dictSplit[0]]=dictSplit[1]     # Set the dictionary -> Game id : game rolls
    games=gameDict[dictSplit[0]].split(';')     # Split up by set of dice rolls
    minRed=1
    minGreen=1
    minBlue=1
    for rolls in games:
        # minimum red, green, and blue cubes needed to make a game possible
        eachDie=[x.split(' ') for x in rolls.split(',')]
        for diceInfo in eachDie:
            if diceInfo[2]=='red':
                if int(diceInfo[1])>minRed:
                    minRed=int(diceInfo[1])
            elif diceInfo[2]=='green':
                if int(diceInfo[1])>minGreen:
                    minGreen=int(diceInfo[1])
            elif diceInfo[2]=='blue':
                if int(diceInfo[1])>minBlue:
                    minBlue=int(diceInfo[1])
    powersum+=(minRed*minGreen*minBlue)

# Print part 1
print("Part 1:",idsum)

#Print part 2
print("Part 2:",powersum)