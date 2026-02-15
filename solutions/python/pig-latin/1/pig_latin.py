""" Module doc string """

def translate(text):
    """ Function doc string """
    result = ""
    for t in text.split(' '):

        if t[0] in 'eaiou' or t[0:2] == 'xr' or t[0:2] == 'yt':
            result += t + "ay "
        elif t[0:1] == 'y':
            result += t[1:] + "yay "
        elif t[0:2] == 'qu':
            result += t[2:] + "quay "
        else:
            cons_clus = ''
            for i in range(len(t)):
                if t[i] in 'eaiou' or (i> 0 and t[i] in 'qy'):
                    break
                cons_clus += t[i]

            rest = t[len(cons_clus):]
            if len(rest) >= 2 and rest[0:2] == 'qu':
                result += rest[2:] + cons_clus + 'qu' + 'ay '
            elif rest[0:1] == 'y':
                result += rest+cons_clus+'ay '
            else:
                result += rest+cons_clus+'ay '

    return result.rstrip()
    