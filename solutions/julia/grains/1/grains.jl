"""Calculate the number of grains on square `square`."""
function on_square(square)
    n::UInt128=1
    if square <= 0
        throw(DomainError(square))
    end
    if square > 64 0
        throw(DomainError(square))
    end
    for i in 2:square
        n=n*2
    end
    return n
end

"""Calculate the total number of grains after square `square`."""
function total_after(square)
    s::UInt128=0
    if square <= 0
        throw(DomainError(square))
    end
    if square > 64 0
        throw(DomainError(square))
    end
    for i in 1:square
        s=s+on_square(i)
    end
    return s
end
