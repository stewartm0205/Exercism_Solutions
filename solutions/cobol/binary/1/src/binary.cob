       IDENTIFICATION DIVISION.
       PROGRAM-ID. BINARY.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-BINARY                PIC X(60).
       01 WS-BINARY-TABLE REDEFINES WS-BINARY.
           05 B PIC X OCCURS 60 TIMES.    
       01 WS-RESULT                PIC 9999.
       01 WS-ERROR                 PIC X(60). 
       01 BL PIC 9(3).      
       01 BI PIC 9(3).      
       PROCEDURE DIVISION.
       
       DECIMAL.
           MOVE SPACES TO WS-ERROR
           MOVE 0 TO BL
           PERFORM VARYING BI FROM 1 BY 1 UNTIL BI>60
               IF B(BI)='0' OR B(BI)='1' OR B(BI) = SPACES THEN
                 IF B(BI)='0' OR B(BI)='1' THEN
                     ADD 1 TO BL
                 END-IF    
               ELSE 
                   IF B(BI) >= '2' AND B(BI) <= '9' THEN
                     MOVE "error: a number containing non-binary "
                     & "digits is invalid" TO WS-ERROR
                   ELSE  
                     MOVE "error: a number containing non-binary "
                     & "characters is invalid" TO WS-ERROR
                   END-IF  
               END-IF
           END-PERFORM
           MOVE 0 TO WS-RESULT.
           IF WS-ERROR = SPACES THEN
               PERFORM VARYING BI FROM 1 BY 1 UNTIL BI>BL
                 IF B(BI) = '1' THEN
                     COMPUTE WS-RESULT = WS-RESULT + 
                       2 ** (BL - BI)
                 END-IF
               END-PERFORM    
           END-IF.   
 
