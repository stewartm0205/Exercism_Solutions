def detect_anagrams(word, candidates):
    aw = []
    for w in candidates:
        if word.lower() != w.lower() and sorted(word.lower()) == sorted(w.lower()):
            aw.append(w)

    return aw
