

def tally(rows):
    team = {}
    for row in rows:
        (team1, team2, gres)=row.split(';')


        if team1 not in team:
            team[team1]={"mp":0, "w":0, "d":0, "l":0, "p":0}
        if team2 not in team:
            team[team2]={"mp":0, "w":0, "d":0, "l":0, "p":0}
        team[team1]["mp"]=team[team1]["mp"]+1
        team[team2]["mp"]=team[team2]["mp"]+1
        if gres == 'win':
            team[team1]["w"]=team[team1]["w"]+1
            team[team2]["l"]=team[team2]["l"]+1
        elif gres == 'loss':
            team[team1]["l"]=team[team1]["l"]+1
            team[team2]["w"]=team[team2]["w"]+1
        else:
            print('gres=',gres)
            team[team1]["d"]=team[team1]["d"]+1
            team[team2]["d"]=team[team2]["d"]+1
        team[team1]["p"]=3*team[team1]["w"]+team[team1]["d"]
        team[team2]["p"]=3*team[team2]["w"]+team[team2]["d"]
        print(team)
    result=[]
    #print(len("Team                           "))
    for team,stats in team.items():
        print(team,stats)
        result.append(str.ljust(team,31)+"|  "+str(stats["mp"])+" |  "+str(stats["w"])+" |  "+
            str(stats["d"])+" |  "+str(stats["l"])+" |  "+str(stats["p"]))
    #print(result[0].split('|')[5])
    sorted_result=sorted(result,key=lambda x:(1/(1+int(x.split('|')[5])),x.split('|')[0]))
    sorted_result=["Team                           | MP |  W |  D |  L |  P"]+sorted_result
    print(sorted_result)
    return(sorted_result)

results = ["Blithering Badgers;Allegoric Alaskans;loss"]

tally(results)