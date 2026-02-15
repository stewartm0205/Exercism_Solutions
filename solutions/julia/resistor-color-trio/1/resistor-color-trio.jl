function label(colors)
    cv=Dict("black"=> "0","brown"=> "1","red"=> "2",
    "orange"=> "3","yellow"=> "4","green"=> "5",
    "blue"=> "6","violet"=> "7","grey"=> "8","white"=> "9")
    r=""
    for i in 1:length(colors)-1
        r=r * cv[colors[i]]
    end
    r=r*repeat("0",parse(Int32,cv[colors[end]]))*" ohms"
    ra=findfirst("000 ohms",r)
    if !isnothing(ra)
       r = r[1:first(ra)-1]*" kiloohms"
    end
    return r
end
