return {
  decode = function(c1, c2, c3)
  colors={'black','brown','red','orange',
        'yellow','green','blue','violet',
        'grey','white'}
    for i=1,10,1
    do
      if colors[i]==c1
      then 
        value = 10 * (i-1)
        break
      end
    end  
    for i=1,10,1
    do
      if colors[i]==c2
      then 
        value = value + (i-1)
        break
      end
    end
    for i=1,10,1
    do
      if colors[i]==c3
      then 
        pow = i-1 
        break
      end
    end
    for i = 1,pow,1
    do
      value=value * 10
    end  

    if value % 1000 == 0 
    then 
      unit='kiloohms'
      value=value/1000
    else  
      unit='ohms'
    end  
    return value, unit
  end
}
