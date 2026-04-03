       IDENTIFICATION DIVISION.
       PROGRAM-ID. reverse-string.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-STRING PIC X(64).
       01 WS-STRING-TABLE REDEFINES WS-STRING.
           05 SS PIC X OCCURS 64 TIMES.     
       01 WS-T-STR PIC X(64).
       01 WS-T-STR-TABLE REDEFINES WS-T-STR.
           05 TS PIC X OCCURS 64 TIMES.     
       01 WS-I PIC  9(2).
       01 WS-J PIC 9(2).

       PROCEDURE DIVISION.
       REVERSE-STRING.
           MOVE SPACE TO WS-T-STR
           PERFORM VARYING WS-I FROM 64 BY -1
               UNTIL WS-I = 1 OR SS ( WS-I ) NOT = SPACE
           END-PERFORM
           MOVE 1 TO WS-J
           PERFORM VARYING WS-I FROM WS-I BY -1
               UNTIL WS-I < 1 
               MOVE SS (WS-I) TO TS (WS-J)
               ADD 1 TO WS-J 
           END-PERFORM
           MOVE WS-T-STR TO WS-STRING        

STRING* Reverse a string and display result
       
       DISPLAY WS-STRING.
