function collatz_steps(n)
    s::Int=0
    if n <= 0
        throw(DomainError(n))
    end
    while n>1
        s+=1
        if mod(n,2)==0
            n=n/2
        else
            n=3n+1
        end
    end
    return s
end