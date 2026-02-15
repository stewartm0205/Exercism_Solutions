function to_rna(dna::String)
    out::String=""
    for c::Char in dna
        if c=='G'
             out *= "C"
        elseif c=='C'
            out *= "G"
        elseif c=='T'
            out *= "A"
        elseif c=='A'
            out *= "U"
        else
            throw(ErrorException(dna))
        end
    end
    return out
end

