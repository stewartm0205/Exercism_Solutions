       IDENTIFICATION DIVISION.
       PROGRAM-ID. DIAMOND.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-INPUTVARS. 
           05 WS-LETTER            PIC X.
           05 WS-ROWS              PIC 99.
       01 WS-OUTPUTTABLE.
           05 WS-TABLEROW    OCCURS 1 TO 61 DEPENDING ON WS-ROWS.
               10 WS-LINE           PIC X(60).
       01 WS-DETAIL-LINE PIC X(60).
       01 WS-DL-TABLE REDEFINES WS-DETAIL-LINE.
           05 WS-DL PIC X OCCURS 60 TIMES.    

       01 WS-COUNTERS.
           05 WS-L PIC S999.
           05 WS-N PIC S99. 
           05 WS-R PIC S99. 
           05 WS-MAX-C PIC S999.
           05 WS-MID-C PIC S999.
           05 WS-FRNT-C PIC S999.
           05 WS-END-C PIC S999.
       PROCEDURE DIVISION.
       
       DIAMOND. 
           COMPUTE WS-L = FUNCTION ORD(WS-LETTER) - 65
           COMPUTE WS-MAX-C = 2 * WS-L + 1
           COMPUTE WS-MID-C = WS-L 
           COMPUTE WS-ROWS = 2 * WS-L - 1
           PERFORM VARYING WS-R FROM 1 BY 1 UNTIL WS-R > WS-ROWS
               MOVE SPACES TO WS-DETAIL-LINE
               IF WS-R = 1 OR WS-R = WS-ROWS THEN
                  MOVE "A" TO WS-DL(WS-MID-C)     
               ELSE 
                   IF WS-R <= WS-L THEN
                     COMPUTE WS-FRNT-C = WS-MID-C - WS-R + 1
                     COMPUTE WS-END-C = WS-MID-C + WS-R - 1
                     MOVE FUNCTION CHAR(65 + WS-R) TO 
                        WS-DL(WS-FRNT-C)
                     MOVE FUNCTION CHAR(65 + WS-R) TO 
                        WS-DL(WS-END-C)
                  ELSE
                      COMPUTE WS-FRNT-C = WS-R - WS-MID-C + 1
                                          
                     COMPUTE WS-END-C = WS-MID-C + 
                                           (WS-MAX-C - WS-R - 2)
                     MOVE FUNCTION CHAR(65 + WS-ROWS - WS-R + 1) TO 
                        WS-DL(WS-FRNT-C)
                     MOVE FUNCTION CHAR(65 + WS-ROWS - WS-R + 1) TO
                        WS-DL(WS-END-C)
                  END-IF
               END-IF  
               MOVE WS-DETAIL-LINE TO WS-TABLEROW(WS-R) 
           END-PERFORM.

