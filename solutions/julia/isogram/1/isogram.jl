function isisogram(s)
    cc=zeros(26,1)
    s=lowercase(s)
    for c in s
        if c!=' ' && c!='-'
            if cc[Int(c)-Int('a')+1]>0
                return false
            else
                cc[Int(c)-Int('a')+1]=1
            end
        end
    end
    return true
end
