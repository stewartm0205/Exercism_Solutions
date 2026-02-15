"Your optional docstring here"
function distance(a, b)
    d::Int = 0
    if length(a) != length(b)
        throw(ArgumentError(a))
    end
    for (ac,bc) in zip(a,b)
        if ac!=bc
            d+=1
        end
    end
    return d
end
