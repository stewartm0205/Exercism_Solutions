import re
def word_count(phrase):
    phrase = phrase.lower()
    words = re.findall(r"[a-z0-9']+",phrase)
    print (words)
    words2 = []
    for word in words:
        if word[0] in "'"+'"' and word[-1] in "'"+'"':
            words2.append(word[1:-1])
        else:
            words2.append(word)   
    wc = {word: words2.count(word) for word in words2}
    return wc
    

print(word_count('hey,my_spacebar_is_broken.'))