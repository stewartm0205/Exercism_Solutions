       IDENTIFICATION DIVISION.
       PROGRAM-ID. PROTEIN-TRANSLATION.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-INPUT                  PIC X(60).
       01 CODON-TABLE REDEFINES WS-INPUT.
           05 CODON PIC XXX OCCURS 20 TIMES.
       01 WS-PROTEIN                PIC X(120).
       01 WS-ERROR                  PIC X(60).
       01 CI PIC 9(3).

       PROCEDURE DIVISION.
       TRANSLATE-CODON.
           MOVE SPACES TO WS-PROTEIN 
               EVALUATE CODON(1)
                   WHEN 'AUG' 
                      STRING 'Methionine' INTO WS-PROTEIN
                   WHEN 'UUU'
                   WHEN 'UUC'	
                       STRING 'Phenylalanine' INTO WS-PROTEIN
                   WHEN 'UUA'
                   WHEN 'UUG'
                       STRING 'Leucine' INTO WS-PROTEIN
                   WHEN 'UCU'
                   WHEN 'UCC'
                   WHEN 'UCA'
                   WHEN 'UCG'	
                       STRING 'Serine'  INTO WS-PROTEIN
                   WHEN 'UAU'
                   WHEN 'UAC'	
                       STRING 'Tyrosine'  INTO WS-PROTEIN
                   WHEN 'UGU'
                   WHEN 'UGC'	
                       STRING 'Cysteine' INTO WS-PROTEIN
                   WHEN 'UGG'	
                       STRING 'Tryptophan'  INTO WS-PROTEIN
                   WHEN 'UAA'
                   WHEN 'UAG'
                   WHEN 'UGA'
                       MOVE SPACES TO WS-PROTEIN                     
                   WHEN OTHER
                       MOVE "Invalid codon" TO WS-ERROR    
               END-EVALUATE.    
       TRANSLATE-RNA.
           MOVE SPACES TO WS-PROTEIN 
           PERFORM VARYING CI FROM 1 BY 1 
               UNTIL CODON(CI)=SPACES OR CODON(CI) = 'UAA' OR
                 CODON(CI) = 'UAG' OR CODON(CI) = 'UGA'
               IF CI > 1  THEN
                 STRING WS-PROTEIN DELIMITED by SPACE
                 "," INTO WS-PROTEIN
               END-IF
               EVALUATE CODON(CI)
                   WHEN 'AUG' 
                        STRING WS-PROTEIN DELIMITED BY SPACE
                        'Methionine' INTO WS-PROTEIN
                   WHEN 'UUU'
                   WHEN 'UUC'	
                        STRING WS-PROTEIN DELIMITED BY SPACE
                       'Phenylalanine' INTO WS-PROTEIN
                   WHEN 'UUA'
                   WHEN 'UUG'
                        STRING WS-PROTEIN DELIMITED BY SPACE
                       'Leucine' INTO WS-PROTEIN
                   WHEN 'UCU'
                   WHEN 'UCC'
                   WHEN 'UCA'
                   WHEN 'UCG'	
                        STRING WS-PROTEIN DELIMITED BY SPACE
                       'Serine'  INTO WS-PROTEIN
                   WHEN 'UAU'
                   WHEN 'UAC'	
                        STRING WS-PROTEIN DELIMITED BY SPACE
                       'Tyrosine'  INTO WS-PROTEIN
                   WHEN 'UGU'
                   WHEN 'UGC'	
                        STRING WS-PROTEIN DELIMITED BY SPACE
                       'Cysteine' INTO WS-PROTEIN
                   WHEN 'UGG'	
                        STRING WS-PROTEIN DELIMITED BY SPACE
                       'Tryptophan'  INTO WS-PROTEIN
                   WHEN 'UAA'
                   WHEN 'UAG'
                   WHEN 'UGA'
                       EXIT PERFORM
                   WHEN OTHER
                       MOVE "Invalid codon" TO WS-ERROR    
               END-EVALUATE    
           END-PERFORM. 
       
