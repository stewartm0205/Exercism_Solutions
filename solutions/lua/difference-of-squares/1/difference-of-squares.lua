local function square_of_sum(n)
  s=0
  for i=1,n,1
  do 
    s=s+i
  end
  return s*s
end

local function sum_of_squares(n)
  s=0
  for i=1,n,1
  do 
    s=s+i*i
  end
  return s
end

local function difference_of_squares(n)
  return square_of_sum(n) - sum_of_squares(n)
end

return {
  square_of_sum = square_of_sum,
  sum_of_squares = sum_of_squares,
  difference_of_squares = difference_of_squares
}
