create or replace function "RNA_TRANSCRIPTION"
(dna_strand in VARCHAR2)
return VARCHAR2
is
    i number;
    rna varchar2(100);
    rna_strand varchar2(100);
begin
    for i in 1..length(dna_strand)
    loop
        select decode(substr(dna_strand,i,1),'G','C','C','G','T','A','A','U') into rna from dual;
        rna_strand := rna_strand || rna;
    end loop;
    return rna_strand;
end;
