local function aliquot_sum(n)
  s=0
  for i = 1, n-1, 1
  do
    if n % i == 0
    then
      s=s+i
    end
  end
  return s
end

local function classify(n)
  if aliquot_sum(n) == n 
  then 
    return 'perfect'
  elseif aliquot_sum(n) > n
  then 
    return 'abundant'
  else
    return 'deficient'
  end
end

return {
  aliquot_sum = aliquot_sum,
  classify = classify
}
