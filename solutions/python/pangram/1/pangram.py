import string
def is_pangram(sentence):
    sentence = sentence.lower()
    letters = string.ascii_lowercase
    print(letters)
    dict={}
    for ch in letters:
        dict[ch]=0
    for ch in sentence:
        if ch in letters:
            dict[ch] += 1
    for ch in letters:
        if dict[ch] == 0:
            return False
    return True
            
print(is_pangram("test sentence"))
print(is_pangram("The quick brown fox jumps over the lazy dog"))