def detect_anagrams(word, candidates):
    aw = []
    for w in candidates:
        if word.lower() != w.lower() and \
        sorted(list(word.lower())) == sorted(list(w.lower())):
            aw.append(w)

    return aw
