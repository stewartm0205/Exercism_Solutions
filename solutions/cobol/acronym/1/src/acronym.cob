       IDENTIFICATION DIVISION.
       PROGRAM-ID. acronym.
       ENVIRONMENT DIVISION.
       DATA DIVISION.

       WORKING-STORAGE SECTION.
       01 WS-ACRONYM               PIC X(80).
       01 WS-ACRONYM-TABLE REDEFINES WS-ACRONYM.
           05 WS-A PIC X OCCURS 80 TIMES.
       01 WS-RESULT                PIC X(20).
       01 WS-RESULT-TABLE REDEFINES WS-RESULT.
           05 WS-R PIC X OCCURS 20 TIMES.    
       01 WS-AI PIC 99.    
       01 WS-RI PIC 99.    
       01 WS-MODE PIC X.
               88 PROCESSING-LETTER VALUE "L".
               88 PROCESSING-DELIMITER VALUE "D".
               88 PROCESSING-UNKNOWN VALUE "U".

       PROCEDURE DIVISION.
       ABBREVIATE.
           DISPLAY WS-ACRONYM
           MOVE SPACES TO WS-RESULT
           MOVE 0 TO WS-RI
           MOVE "U" TO WS-MODE.
           PERFORM VARYING WS-AI FROM 1 BY 1 UNTIL WS-AI > 80
               IF (WS-A(WS-AI)>="A" AND WS-A(WS-AI)<="Z") OR
                   (WS-A(WS-AI)>="a" AND WS-A(WS-AI)<="z") OR
                   WS-A(WS-AI) = "'" THEN
                   IF PROCESSING-DELIMITER OR 
                       PROCESSING-UNKNOWN THEN
                      ADD 1 TO WS-RI
                      MOVE FUNCTION UPPER-CASE(WS-A(WS-AI)) TO 
                          WS-R(WS-RI)
                      MOVE "L" TO WS-MODE
                   END-IF
               ELSE
                   MOVE "D" TO WS-MODE
               END-IF    
           END-PERFORM.    
