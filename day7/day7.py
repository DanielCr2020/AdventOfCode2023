day7 = open('day7.txt','r')
contents=("".join(day7.readlines()).split('\n'))
day7.close()

strengths=['A','K','Q','J','T','9','8','7','6','5','4','3','2'][::-1]

contentsDict={}
# Part 1 only
for hand in contents:
    contentsDict[hand]={}
    cardDict={}
    for card in hand[:5]:
        if card not in cardDict:
            cardDict[card]=1
        else:
            cardDict[card]+=1
    print(cardDict.values())
    if 5 in cardDict.values():                  # five of a kind
        contentsDict[hand]['typeRank']=7   
    elif 4 in cardDict.values():       # four of a kind
        contentsDict[hand]['typeRank']=6
    elif 3 in cardDict.values() and 2 in cardDict.values(): # full house
        contentsDict[hand]['typeRank']=5   
    elif 3 in cardDict.values() and 2 not in cardDict.values():          # three of a kind
        contentsDict[hand]['typeRank']=4
    elif len(cardDict.values())==3:       # two pair
        contentsDict[hand]['typeRank']=3
    elif len(cardDict.values())==4:       # one pair
        contentsDict[hand]['typeRank']=2
    elif len(cardDict.values())==5:       # high card
        contentsDict[hand]['typeRank']=1


dict2=(dict(sorted(contentsDict.items(), key=lambda x: (x[1]['typeRank'], [strengths.index(c) for c in x[0][:5]]))))
print(dict2)

total=0
for (index,item) in enumerate(dict2):
    total+=(int(item[6:])*(index+1))

print(total)