       IDENTIFICATION DIVISION.
       PROGRAM-ID. ROBOT-SIMULATOR.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-X-COORD               PIC S999.
       01 WS-Y-COORD               PIC S999.
       01 WS-DIRECTION             PIC X(20).
       01 WS-INSTRUCTIONS          PIC X(60).
       01 WS-INS-TABLE REDEFINES WS-INSTRUCTIONS.
           05 INS PIC X OCCURS 60.
       01 II PIC 99.    
       PROCEDURE DIVISION.
       
       CREATE-ROBOT.


       MOVE-ROBOT.
           PERFORM VARYING II FROM 1 BY 1 UNTIL INS(II) = SPACES
               EVALUATE INS(II)
                   WHEN 'A'
                       EVALUATE WS-DIRECTION
                           WHEN 'north'
                               ADD 1 TO WS-Y-COORD
                           WHEN 'south'
                               SUBTRACT 1 FROM WS-Y-COORD
                           WHEN 'west'
                               SUBTRACT 1 FROM WS-X-COORD
                           WHEN 'east'
                               ADD 1 TO WS-X-COORD
                       end-evaluate
                   WHEN 'L'
                       EVALUATE WS-DIRECTION
                           WHEN 'north'
                               MOVE 'west' TO WS-DIRECTION
                           WHEN 'south'
                               MOVE 'east' TO WS-DIRECTION
                           WHEN 'west'
                               MOVE 'south' TO WS-DIRECTION
                           WHEN 'east'
                               MOVE 'north' TO WS-DIRECTION
                       END-EVALUATE
                  when 'R'
                       EVALUATE WS-DIRECTION
                           WHEN 'north'
                               MOVE 'east' TO WS-DIRECTION
                           WHEN 'south'
                               MOVE 'west' TO WS-DIRECTION
                           WHEN 'west'
                               MOVE 'north' TO WS-DIRECTION
                           WHEN 'east'
                               MOVE 'south' TO WS-DIRECTION
                       END-EVALUATE
              END-EVALUATE        
           end-perform.    
