return function(n)
    if n<=0 
    then
        error('Only positive numbers are allowed')
    end
    c=0
    while (n~=1)
    do 
        c=c+1
        if n % 2 == 0
        then
            n=n/2
        else
            n=3*n+1
        end
    end
    return c
end
