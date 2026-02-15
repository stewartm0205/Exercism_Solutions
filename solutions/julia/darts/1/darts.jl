function score(x, y)
    if sqrt(x*x+y*y)<=1
        return 10
    elseif sqrt(x*x+y*y)<=5
        return 5
    elseif sqrt(x*x+y*y)<=10
        return 1
    end
    return 0
end
