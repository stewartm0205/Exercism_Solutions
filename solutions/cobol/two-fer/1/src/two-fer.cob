       IDENTIFICATION DIVISION.
       PROGRAM-ID. two-fer.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-NAME PIC X(16).
       01 WS-RESULT PIC X(64).
       
       PROCEDURE DIVISION.
       TWO-FER.
           IF WS-NAME = SPACE THEN
               MOVE "One for you, one for me." TO WS-RESULT
           ELSE    
               STRING "One for " DELIMITED BY SIZE
                   WS-NAME DELIMITED BY SPACE
                   ", one for me." INTO WS-RESULT
               END-STRING
           END-IF.
