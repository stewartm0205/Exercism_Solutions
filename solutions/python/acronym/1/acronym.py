""" Module doc string"""
def abbreviate(words):
    abbr = ""
    words = words.replace(",", " ")
    words = words.replace("-", " ")
    words = words.replace("_", " ")
    for word in words.split(" "):
        print(word)
        if len(word) > 0 and word[0].isalpha():
            abbr += word[0].upper()

    return abbr
