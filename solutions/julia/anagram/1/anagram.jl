function detect_anagrams(subject, candidates)
    ssubject=join(sort(collect(subject)))
    ana=[]
    print("subject=",subject,",sort subject=",ssubject,"\n")
    for can in candidates
        if join(sort(collect(lowercase(subject)))) ==
           join(sort(collect(lowercase(can)))) &&
           lowercase(subject)!=lowercase(can)
           push!(ana,can)
        end
    end
    return ana
end
