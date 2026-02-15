local Hamming = {}

function Hamming.compute(a,b)
    if string.len(a)~=string.len(b)
    then
        return -1
    end
    v=0
    for i=1,string.len(a),1
    do
        if string.sub(a,i,i)~=string.sub(b,i,i)
        then
            v=v+1
        end
    end
    return v        
end

return Hamming
