       IDENTIFICATION DIVISION.
       PROGRAM-ID. ELIUDS-EGGS.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-INPUTVARS.
           05 WS-INPUT             PIC 9(10).
       01 WS-OUTPUTVARS.
           05 WS-RESULT            PIC 9999.
       01 WS-R PIC 9.
       PROCEDURE DIVISION.

       EGG-COUNT.
           DISPLAY WS-INPUT
           MOVE 0 TO WS-RESULT
           PERFORM UNTIL WS-INPUT = 0
               DIVIDE WS-INPUT BY 2 
               GIVING WS-INPUT REMAINDER WS-R
               IF WS-R = 1 THEN
                   ADD 1 TO WS-RESULT
               END-IF
           END-PERFORM.         
               
