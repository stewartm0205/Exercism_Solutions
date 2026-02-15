def recite(start, take=1):
    numBottles=start
    song = []
    while (take > 0):
        if numBottles > 2:
            line1 = str(numBottles) + " bottles of beer on the wall, " + \
                   str(numBottles) + " bottles of beer."
            line2 = "Take one down and pass it around, " + \
                   str(numBottles - 1) + " bottles of beer on the wall."
        elif numBottles == 2:
            line1 = str(numBottles) + " bottles of beer on the wall, " + \
                   str(numBottles) + " bottles of beer."
            line2 = "Take one down and pass it around, " + \
                     "1 bottle of beer on the wall."
        elif numBottles == 1:
            line1 = "1 bottle of beer on the wall, " + \
                   "1 bottle of beer."
            line2 = "Take it down and pass it around, " + \
                     "no more bottles of beer on the wall."
        else:
            line1 = "No more bottles of beer on the wall, " + \
                   "no more bottles of beer."
            line2 = "Go to the store and buy some more, " + \
                     "99 bottles of beer on the wall."
        song.append(line1)
        song.append(line2)

        if take > 1:
            song.append("")

        take-=1
        numBottles-=1
    return(song)

