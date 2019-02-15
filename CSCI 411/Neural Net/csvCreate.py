def processRank(Str):
    Str = Str.replace('-',' ')
    while '\t' in Str:
        Str = Str.replace('\t',' ')
    temp = 1000
    while (temp > len(Str)):
        temp = len(Str)
        Str = Str.replace('  ',' ')
    Str = Str.replace(',','')
    newList = Str.split(' ')
    return newList

def processQual(Str):
    while '\t' in Str:
        Str = Str.replace('\t',' ')
    temp = 1000
    while (temp > len(Str)):
        temp = len(Str)
        Str = Str.replace('  ',' ')
    Str = Str.replace(',','')
    newList = Str.split(' ')
    return newList[7:]
    
def main():
    fileName = input('What is your qualifications match input file? ')
    inQualFile = open(fileName, 'r')
    fileName = input('What is your rankings input file? ')
    inRankFile = open(fileName, 'r')
    fileName = input('What is your qualifications .csv output file name? ')
    outQualFile = outFile = open(fileName, 'w')
    fileName = input('What is your ranking .csv output file name? ')
    outRankFile = outFile = open(fileName, 'w')

    outRankFile.write("Rank,Team,Ranking Score,Match Points,Auto,Rotor,Takeoff,Pressure,Wins,Losses,Ties,Matches Played\n")
    outQualFile.write("Red Team 1,Red Team 2,Red Team 3,Blue Team 1,Blue Team 2,Blue Team 3,Red Score,Blue Score\n")
    for aLine in inRankFile:
        aList = processRank(aLine)
        outLine = ""
        for item in aList:
            outLine = outLine + str(item) + ","
        outLine = outLine[0:len(outLine)-2] + "\n"
        outRankFile.write(outLine)

    for aLine in inQualFile:
        match = processQual(aLine)
        outLine = ""
        for item in match:
            outLine = outLine + str(item) + ","
        outLine = outLine[0:len(outLine)-2] + "\n"
        outQualFile.write(outLine)

    outRankFile.close()
    outQualFile.close()

    return

main()
        
