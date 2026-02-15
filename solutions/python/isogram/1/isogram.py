def is_isogram(string):
    #print (string)
    #print (len(string))
    for i in range(len(string)):
        #print (i)
        string=string.lower()
        ch = string[i:i+1]
        #print(ch)
        if ch not in (' -') and string.count(ch) > 1:
            return False

    return True

print (is_isogram("ABB"))
print (is_isogram("a-bc"))
print (is_isogram("a-bb"))