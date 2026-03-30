       IDENTIFICATION DIVISION.
       PROGRAM-ID. LEAP.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-YEAR  pic 9(4).
       01 WS-RESULT  pic 9(1).
       01 WS-REMAINDER  pic 9(3).
       01 WS-QUOTIENT  pic 9(4).
       PROCEDURE DIVISION.
       LEAP.
      * Enter solution here
         DIVIDE WS-YEAR BY 4 GIVING WS-QUOTIENT REMAINDER WS-REMAINDER.
         move 0 to ws-result.
         if ws-remainder = 0 
                DIVIDE WS-YEAR BY 100 GIVING WS-QUOTIENT 
                     REMAINDER WS-REMAINDER
                if ws-remainder = 0 
                        DIVIDE WS-YEAR BY 400 GIVING WS-QUOTIENT 
                                REMAINDER WS-REMAINDER
                        if ws-remainder = 0 
                                move 1 to ws-result
                        end-if
                else
                        move 1 to ws-result
                end-if               
         end-if
         CONTINUE.
       LEAP-EXIT.
         EXIT.
