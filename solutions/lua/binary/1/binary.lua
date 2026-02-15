local function to_decimal(input)
  d=0
  m=1
  for i=string.len(input),1,-1
  do
    if string.sub(input,i,i) == '1'
    then 
      d=d+m 
    elseif string.sub(input,i,i) ~= '0'
    then
      return 0
    end
    m=m*2
  end
  return d
end

return {
  to_decimal = to_decimal
}
