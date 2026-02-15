"Square the sum of the first `n` positive integers"
function square_of_sum(n)::Integer
    s::Int=0
    for i in 1:n
        s=s+i
    end
    return s*s
end

"Sum the squares of the first `n` positive integers"
function sum_of_squares(n)::Integer
    s::Int=0
    for i in 1:n
        s=s+i*i
    end
    return s
end

"Subtract the sum of squares from square of the sum of the first `n` positive ints"
function difference(n)::Integer
    return square_of_sum(n) - sum_of_squares(n)
end
