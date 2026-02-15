function score(str::String)::Integer
    score::Integer=0
    for l in str
        L=uppercase(string(l))
        if occursin(L,"A, E, I, O, U, L, N, R, S, T") >0
            score+=1
        elseif occursin(L,"D, G")>0
            score+=2
        elseif occursin(L,"B, C, M, P")>0
            score+=3
        elseif occursin(L,"F, H, V, W, Y") > 0
            score+=4
        elseif L == "K"
            score+=5
        elseif occursin(L,"J, X")>0
            score+=8
        elseif occursin(L,"Q, Z")>0
            score+=10
        end
    end
    return score
end
