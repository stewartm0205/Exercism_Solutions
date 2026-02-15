local grains = {}

function grains.square(n)
    v=1.0
    for i=2,n,1
    do 
        v=v*2
    end
    return v
end

function grains.total()
    t=0.0
    for i=1,64,1
    do 
        t=t+grains.square(i)
    end
    return t
end

return grains
