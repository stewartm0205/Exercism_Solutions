function sieve(limit)
    primes=[]
    for i::Int in 2:limit
        j::Int=1
        while j<=length(primes)
            if mod(i,primes[j])==0
                break
            end
            j+=1
        end
        if j>length(primes)
            push!(primes,i)
        end
    end
    return primes
end
