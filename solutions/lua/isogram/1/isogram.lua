return function(s)
    s=string.lower(s)
    cc={}
    alpha='abcdefghijklmnopqrstuvwxyz'
    for i=1,26,1
    do 
        cc[string.sub(alpha,i,i)]=0
    end
    for i=1,string.len(s),1
    do 
        if string.sub(s,i,i) >='a' and string.sub(s,i,i) <='z'
        then
            if cc[string.sub(s,i,i)]==1
            then
                return false 
            else
                cc[string.sub(s,i,i)]=1
            end
        end    
    end
    return true

end
