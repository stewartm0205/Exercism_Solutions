       IDENTIFICATION DIVISION.
       PROGRAM-ID. MATCHING-BRACKETS.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-INPUT                 PIC X(100).
       01 WS-INPUT-TABLE REDEFINES WS-INPUT.
           05 WS-IC PIC X OCCURS 100 TIMES.
           
       01 WS-RESULT                PIC 9.
       01 WS-I PIC 999.    
       01 WS-BRACKET-STACK PIC X(100).
       01 WS-BRACKET-TABLE REDEFINES WS-BRACKET-STACK.
           05 WS-BS PIC X OCCURS 100 TIMES.
       01 WS-BS-I PIC 999.

       PROCEDURE DIVISION.

       ISPAIRED.
           DISPLAY WS-INPUT
           MOVE SPACES TO WS-BRACKET-STACK.
           MOVE 0 TO WS-BS-I.
           PERFORM VARYING WS-I FROM 1 BY 1 UNTIL WS-I > 100
               IF (WS-IC(WS-I)="]" AND WS-BS(WS-BS-I)="[") OR 
                      (WS-IC(WS-I)="}" AND WS-BS(WS-BS-I)="{") OR 
                      (WS-IC(WS-I)=")" AND WS-BS(WS-BS-I)="(") THEN
                      SUBTRACT 1 FROM WS-BS-I
               ELSE 
                  IF WS-IC(WS-I) = "[" OR WS-IC(WS-I) = "{" OR
                      WS-IC(WS-I) = "(" OR WS-IC(WS-I) = "]" OR 
                      WS-IC(WS-I) = "}" OR WS-IC(WS-I) = ")" THEN
                     ADD 1 TO WS-BS-I
                     MOVE WS-IC(WS-I) TO WS-BS(WS-BS-I)
                  END-IF    
               END-IF    
           END-PERFORM    
           IF WS-BS-I = 0 THEN
               MOVE 1 TO WS-RESULT
           ELSE 
               MOVE 0 TO WS-RESULT
           END-IF.    
