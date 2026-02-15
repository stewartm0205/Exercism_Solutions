"""
    count_nucleotides(strand)

The count of each nucleotide within `strand` as a dictionary.

Invalid strands raise a `DomainError`.

"""
function count_nucleotides(strand)
    nc = Dict('A' => 0, 'C' => 0, 'G' => 0, 'T' => 0)
    for d in strand
        if get(nc, d, "Error") == "Error"
            throw(DomainError(d))
        else
            nc[d] = nc[d]+1
        end
    end
    return nc
end
