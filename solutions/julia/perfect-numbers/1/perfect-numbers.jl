function isperfect(number)
    if number <= 0
        throw(DomainError(number))
    end
    s=0
    for i in 1:number-1
        if mod(number,i)==0
            s=s+i
        end
    end
    if s==number
        return true
    else
        return false
    end
end
function isabundant(number)
    if number <= 0
        throw(DomainError(number))
    end
    s=0
    for i in 1:number-1
        if mod(number,i)==0
            s=s+i
        end
    end
    if s>number
        return true
    else
        return false
    end
end
function isdeficient(number)
    if number <= 0
        throw(DomainError(number))
    end
    s=0
    for i in 1:number-1
        if mod(number,i)==0
            s=s+i
        end
    end
    if s<number
        return true
    else
        return false
    end
end
