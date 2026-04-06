       IDENTIFICATION DIVISION.
       PROGRAM-ID. rna-transcription.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-COMPLEMENT PIC X(64).
       01 WS-C-TABLE REDEFINES WS-COMPLEMENT.
          05 WS-C PIC X OCCURS 64 TIMES.
       
       01 WS-T-COMP PIC X(64).
       01 WS-T-TABLE REDEFINES WS-T-COMP.
          05 WS-T PIC X OCCURS 64 TIMES.
       01 WS-I PIC 99.
       PROCEDURE DIVISION.
       RNA-TRANSCRIPTION.
        PERFORM VARYING WS-I FROM 1 BY 1 
          UNTIL WS-I > 64 OR WS-C(WS-I) = SPACE 
   
         EVALUATE WS-C(WS-I)
           WHEN 'G'
            MOVE 'C' TO WS-T(WS-I) 
           WHEN 'C'
            MOVE 'G' TO WS-T(WS-I) 
           WHEN 'T'
            MOVE 'A' TO WS-T(WS-I) 
           WHEN 'A'
            MOVE 'U' TO WS-T(WS-I) 
         END-EVALUATE
        END-PERFORM.
        MOVE WS-T-COMP TO WS-COMPLEMENT.

