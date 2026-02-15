create or replace function "NTH_PRIME"
(n in NUMBER)
return NUMBER
is
    type numericarray IS VARRAY(100) OF number;
    primes numericarray := numericarray(2);
    pi number;
    i number;
    num number;
begin
    pi := 1;
    num := 3;
    while pi < n 
    loop
        i := 1;
        while (i < pi and mod(num,primes(i)) != 0)
        loop
            i := i + 1;
        end loop;
        if mod(num,primes(i)) != 0
        then
            pi := pi + 1;
            primes.extend;
            primes(pi) := num;
        end if;
        num := num + 1;
    end loop;
    return primes(pi);
end;
