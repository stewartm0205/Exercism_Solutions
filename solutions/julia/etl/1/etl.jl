function transform(input::AbstractDict)
    output = Dict()
    for (val,letters) in input
        for l in letters
            output[lowercase(l)]=val
        end
    end
    return output
end

