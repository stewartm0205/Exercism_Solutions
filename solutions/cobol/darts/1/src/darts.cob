       IDENTIFICATION DIVISION.
       PROGRAM-ID. DARTS.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-X PIC 99V9.
       01 WS-Y PIC 99V9.
       01 WS-RESULT PIC 99.
       PROCEDURE DIVISION.
       DARTS.
           COMPUTE WS-X = FUNCTION ABS(WS-X).
           COMPUTE WS-Y = FUNCTION ABS(WS-Y).
           IF WS-X <= 1 AND WS-Y <= 1 THEN
                   MOVE 10 TO WS-RESULT
           ELSE 
               IF WS-X <= 5 AND WS-Y <= 5 THEN
                   MOVE 5 TO WS-RESULT
               ELSE
                   IF WS-X <= 10 AND WS-Y <= 10 THEN
                       MOVE 1 TO WS-RESULT
                   ELSE
                       MOVE 0 TO WS-RESULT
                   END-IF
               END-IF
           END-IF.
