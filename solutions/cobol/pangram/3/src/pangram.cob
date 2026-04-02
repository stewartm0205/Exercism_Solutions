        IDENTIFICATION DIVISION.
        PROGRAM-ID. PANGRAM.
        ENVIRONMENT DIVISION.
        DATA DIVISION.
        WORKING-STORAGE SECTION.
        01 WS-SENTENCE PIC X(60).
        01 WS-S-TABLE REDEFINES WS-SENTENCE.
                05 WS-S PIC X occurs 60 times.

        01 UC PIC X(26) VALUE 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'.
        01 UCC-TABLE REDEFINES UC.
                05 UCC PIC X occurs 26 times.
        01 LC PIC X(26) VALUE 'abcdefghijklmnopqrstuvwxyz'.
        01 LCC-TABLE REDEFINES LC.
                05 LCC PIC X OCCURS 26 TIMES.
        01 H PIC X(26) VALUE ZEROES.
        01 H-TABLE REDEFINES H.
                05 HH PIC 9 OCCURS 26 TIMES.   
        01 WS-RESULT PIC 9.
        01 COUNTERS.
                05 SI PIC 9(3) COMP.
                05 HI PIC 9(3) COMP.
                

        PROCEDURE DIVISION.
        PANGRAM.
        MOVE ZEROES TO H
      * GO THRU THE SENTENCE AND SEE IF THE LETTER IS A HIT
        PERFORM VARYING SI FROM 1 BY 1 UNTIL SI > 60 
            PERFORM VARYING HI FROM 1 BY 1 UNTIL HI > 26
                IF WS-S ( SI ) = UCC ( HI ) OR 
                    WS-S ( SI ) = LCC ( HI )
                   MOVE 1 TO HH ( HI )
               END-IF    
            END-PERFORM
        END-PERFORM
      * CHECK IF THERE ARE ANY NO HIT
        MOVE 1 TO WS-RESULT
        PERFORM VARYING HI FROM 1 BY 1 UNTIL HI > 26
           IF HH (HI) = 0 
               MOVE 0 TO WS-RESULT
           END-IF
           END-PERFORM.              
                   
        EXIT.   

