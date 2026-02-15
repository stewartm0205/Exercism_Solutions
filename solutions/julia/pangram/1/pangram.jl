"""
    ispangram(input)

Return `true` if `input` contains every alphabetic character (case insensitive).

"""
function ispangram(input)
    alpha=zeros(Int64,1,26)
    for c in input
        lc=lowercase(c)
        if lc >='a' && lc <= 'z'
            alpha[lc-'a'+1]+=1
        end
    end
    for i in 1:26
        if alpha[i]==0
            return false
        end
    end
    return true
end

