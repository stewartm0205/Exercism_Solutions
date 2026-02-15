function isarmstrong(number)
    digits=string(number)
    e=length(digits)
    s::Int128=0
    for d in digits
        s=s+(parse(Int,d)^e)
    end
    if s==number
        return true
    else
        return false
    end
end