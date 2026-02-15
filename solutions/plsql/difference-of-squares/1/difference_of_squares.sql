create or replace function "DIFFERENCE_OF_SQUARES"
(n in NUMBER)
return NUMBER
is
    sumsq number := 0;
    s number := 0;
begin
    for i in 1..n loop
        s := s + i; 
        sumsq := sumsq + i*i;   
    end loop;
    return (s * s)- sumsq;  
end;
