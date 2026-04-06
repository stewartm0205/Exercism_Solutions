        IDENTIFICATION DIVISION.
        PROGRAM-ID. ISOGRAM.
        ENVIRONMENT DIVISION.
        DATA DIVISION.
        WORKING-STORAGE SECTION.
        01 WS-PHRASE PIC X(60).
        01 WS-PHRASE-TABLE REDEFINES WS-PHRASE.
            05 WS-PH PIC X OCCURS 60.
        01 UC PIC X(26) VALUE 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'.
        01 UCC-TABLE REDEFINES UC.
                05 UCC PIC X occurs 26 times.
        01 LC PIC X(26) VALUE 'abcdefghijklmnopqrstuvwxyz'.
        01 LCC-TABLE REDEFINES LC.
                05 LCC PIC X OCCURS 26 TIMES.
        01 H PIC X(78) VALUE ZEROES.
        01 H-TABLE REDEFINES H.
                05 HH PIC 999 OCCURS 26 TIMES.
        01 WS-RESULT PIC 9.
        01 COUNTERS.
                05 SI PIC 9(3) COMP.
                05 HI PIC 9(3) COMP.
        PROCEDURE DIVISION.
        ISOGRAM.
        MOVE ZEROES TO H
      * GO THRU THE PHRASE AND SEE IF THE LETTER IS A HIT
        PERFORM VARYING SI FROM 1 BY 1 UNTIL SI > 60
            PERFORM VARYING HI FROM 1 BY 1 UNTIL HI > 26
                IF WS-PH ( SI ) = UCC ( HI ) OR
                    WS-PH ( SI ) = LCC ( HI )
                   ADD 1 TO HH ( HI )
               END-IF
            END-PERFORM
        END-PERFORM
      * CHECK IF THERE ARE ANY NO HIT
        MOVE 1 TO WS-RESULT
        PERFORM VARYING HI FROM 1 BY 1 UNTIL HI > 26
           IF HH (HI) > 1 THEN
               MOVE 0 TO WS-RESULT
           END-IF
        END-PERFORM.
