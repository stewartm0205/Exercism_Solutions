       IDENTIFICATION DIVISION.
       PROGRAM-ID. COLLATZ-CONJECTURE.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-NUMBER PIC S9(8).
       01 WS-STEPS PIC 9(4).
       01 WS-ERROR PIC X(35).

       PROCEDURE DIVISION.
       COLLATZ-CONJECTURE.
           MOVE SPACE TO WS-ERROR.
           IF WS-NUMBER <= 0 THEN
               MOVE 'Only positive integers are allowed' TO WS-ERROR
           END-IF.    
           PERFORM VARYING WS-STEPS FROM 0 BY 1 UNTIL WS-NUMBER <= 1
               IF FUNCTION REM(WS-NUMBER 2) = 0 THEN
                   COMPUTE WS-NUMBER = WS-NUMBER / 2
               ELSE 
                   COMPUTE WS-NUMBER = 3 * WS-NUMBER + 1
               END-IF    
           END-PERFORM
       DISPLAY WS-STEPS.
       DISPLAY WS-ERROR.
