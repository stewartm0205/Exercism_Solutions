def is_armstrong(number):
    nd = len(str(number))
    s = 0
    for d in str(number):
        s = s+int(d)**nd
    if number == s:
        return True
    else:
        return False

