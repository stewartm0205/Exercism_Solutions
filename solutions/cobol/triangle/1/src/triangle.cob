       IDENTIFICATION DIVISION.
       PROGRAM-ID. TRIANGLE.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
      *Incoming
       01 WS-SIDES PIC X(20).
       01 WS-PROPERTY PIC X(11).
       01 WS-NUMBERS.
           05 A-X PIC X(3).    
           05 B-X PIC X(3).    
           05 C-X PIC X(3).    
           05 A PIC 99V9.    
           05 B PIC 99V9.    
           05 C PIC 99V9.    
      *OUTGOING
       01 WS-RESULT PIC 9.
       PROCEDURE DIVISION.
       TRIANGLE.
           UNSTRING WS-SIDES DELIMITED BY ","
              INTO A-X, B-X, C-X
           MOVE A-X TO A
           MOVE B-X TO B
           MOVE C-X TO C
           MOVE 0 TO WS-RESULT
           IF A>0 AND B>0 AND C>0 AND
              A+B>=C AND B+C>=A AND A+C>=B 
           THEN
               EVALUATE WS-PROPERTY
                  WHEN  "equilateral"
                   IF A=B AND B=C THEN
                       MOVE 1 TO WS-RESULT
                   END-IF    
                 WHEN  "isosceles"    
                   IF A=B OR B=C OR A=C THEN
                       MOVE 1 TO WS-RESULT
                   END-IF    
                 WHEN  "scalene"
                   IF A=B OR B=C OR A=C THEN
                       MOVE 0 TO WS-RESULT
                   ELSE
                       MOVE 1 TO WS-RESULT
                   END-IF    
               END-EVALUATE        
           END-IF.

       
