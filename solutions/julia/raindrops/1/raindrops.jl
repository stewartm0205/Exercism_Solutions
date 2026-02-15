function raindrops(number)
    rd=""
    if mod(number,3) == 0
        rd="Pling"
    end
    if mod(number,5) == 0
        rd=rd * "Plang"
    end
    if mod(number,7) == 0
        rd=rd * "Plong"
    end
    if rd==""
        rd=string(number)
    end
    return rd

end
