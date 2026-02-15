function myreverse(str)
    revstr=""
    for c in str
        revstr=c * revstr
    end
    return revstr
end
