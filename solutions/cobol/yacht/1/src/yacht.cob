       IDENTIFICATION DIVISION.
       PROGRAM-ID. YACHT.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-RESULT PIC 99 VALUE 0.
       01 WS-CATEGORY PIC X(15).
       01 WS-DICE PIC 9(5).
       01 WS-DICE-TABLE REDEFINES WS-DICE.
           05 D PIC 9 OCCURS 5 TIMES.
       01 WS-DICE-COUNT-TABLE.
           05 DC PIC 9 OCCURS 6 TIMES.
       01 WS-COUNTERS.
           05 DI PIC 9.
       PROCEDURE DIVISION.
       YACHT.
       PERFORM VARYING DI FROM 1 BY 1 UNTIL DI > 6 
           MOVE 0 TO DC (DI)
       END-PERFORM.
       PERFORM VARYING DI FROM 1 BY 1 UNTIL DI > 5
           ADD 1 TO DC (D(DI))
       END-PERFORM.

           MOVE 0 TO WS-RESULT.    
       EVALUATE WS-CATEGORY
           WHEN 'ones'
               COMPUTE WS-RESULT = DC (1)
           WHEN 'twos'
               COMPUTE WS-RESULT = 2 * DC (2)
           WHEN 'threes'
               COMPUTE WS-RESULT = 3 * DC (3)
           WHEN 'fours'
               COMPUTE WS-RESULT = 4 * DC (4)
           WHEN 'fives'
               COMPUTE WS-RESULT = 5 * DC (5)
           WHEN 'sixes'
               COMPUTE WS-RESULT = 6 * DC (6)
           WHEN 'yacht'
              PERFORM VARYING DI FROM 1 BY 1 UNTIL DI > 6 
                 IF DC(DI) = 5 THEN
                    MOVE 50 TO WS-RESULT
                 END-IF
              END-PERFORM    
           WHEN 'four of a kind'
              PERFORM VARYING DI FROM 1 BY 1 UNTIL DI > 6
                 IF DC(DI) >= 4 THEN
                    COMPUTE WS-RESULT = 4 * DI
                 END-IF
              END-PERFORM    
           WHEN 'full house'
              PERFORM VARYING DI FROM 1 BY 1 UNTIL DI > 6
                  IF DC(DI) = 3 THEN
                      EXIT PERFORM
                  END-IF
              END-PERFORM
              IF DI < 7 THEN
                  COMPUTE WS-RESULT = 3 * DI
              END-IF
              PERFORM VARYING DI FROM 1 BY 1 UNTIL DI > 6
                  IF DC(DI) = 2 THEN
                      EXIT PERFORM
                  END-IF
              END-PERFORM    
              IF WS-RESULT > 0 AND DI < 7 THEN
                  COMPUTE WS-RESULT = WS-RESULT + 2 * DI
              END-IF
           WHEN 'little straight'
              PERFORM VARYING DI FROM 1 BY 1 UNTIL DI > 5 
                  IF DC(DI) = 0 THEN
                      EXIT PERFORM
                  END-IF
              END-PERFORM    
              IF DI = 6 THEN
                  MOVE 30 TO WS-RESULT
              END-IF
           WHEN 'big straight'
              PERFORM VARYING DI FROM 2 BY 1 UNTIL DI > 6 
                  IF DC(DI) = 0 THEN
                      EXIT PERFORM
                  END-IF
              END-PERFORM    
              IF DI = 7 THEN
                  MOVE 30 TO WS-RESULT
              END-IF
           WHEN 'choice' 
              PERFORM VARYING DI FROM 1 BY 1 UNTIL DI > 6
                  COMPUTE WS-RESULT = WS-RESULT + DI * DC(DI)
              END-PERFORM    
               
       END-EVALUATE.
