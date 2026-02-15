create or replace function "GIGASECOND"
(birthdate in DATE)
return DATE
is
    gigasec timestamp;
begin
    gigasec := cast(birthdate as timestamp);
    gigasec := gigasec + numToDSInterval( 1000000000, 'second' );
    return cast (gigasec as date);
end;
