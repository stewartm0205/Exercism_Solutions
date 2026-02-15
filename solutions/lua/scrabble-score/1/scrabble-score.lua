local function score(word)
    if word=='' or word==nil
    then
        return 0
    end    
    word=string.upper(word)
    s=0
    for i=1,string.len(word),1
    do 
        if string.find('A, E, I, O, U, L, N, R, S, T',
           string.sub(word,i,i))~=nil
        then
            s=s+1
        elseif string.find('D, G',string.sub(word,i,i))~=nil
        then
            s=s+2
        elseif string.find('B, C, M, P',string.sub(word,i,i))~=nil
        then
            s=s+3 
        elseif  string.find('F, H, V, W, Y',string.sub(word,i,i))~=nil   
        then
            s=s+4  
        elseif  string.sub(word,i,i)=='K'      
        then
            s=s+5 
        elseif  string.find('J, X',string.sub(word,i,i))~=nil          
        then
            s=s+8 
        elseif  string.find('Q, Z',string.sub(word,i,i))~=nil     
        then
            s=s+10  
        end
    end    
    return s
end

return { score = score }
