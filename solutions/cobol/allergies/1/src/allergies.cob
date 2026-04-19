       IDENTIFICATION DIVISION.
       PROGRAM-ID. allergies.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-SCORE       PIC 999.
       01 WS-ITEM        PIC X(12).
       01 WS-RESULT      PIC A.
       01 WS-RESULT-LIST PIC X(108).
       01 WS-TRL PIC X(108).
       01 WS-TRL-R REDEFINES WS-TRL.
           05 COMMA-SLOT PIC X.
           05 THE-REST PIC X(107).
       01 WS-I PIC 99.
       01 WS-R PIC 9.    
       01 WS-ALLERGENS-NAMES-DATA.
           05 FILLER PIC X(12) VALUE "eggs".
           05 FILLER PIC X(12) VALUE "peanuts".
           05 FILLER PIC X(12) VALUE "shellfish".
           05 FILLER PIC X(12) VALUE "strawberries".
           05 FILLER PIC X(12) VALUE "tomatoes".
           05 FILLER PIC X(12) VALUE "chocolate".
           05 FILLER PIC X(12) VALUE "pollen".
           05 FILLER PIC X(12) VALUE "cats".
       01 WS-ALLERGENS-TABLE REDEFINES WS-ALLERGENS-NAMES-DATA.     
           05 WS-ALLERGENS-NAMES PIC X(12) OCCURS 8 TIMES.
       PROCEDURE DIVISION.
       ALLERGIC-TO.
           MOVE "N" TO WS-RESULT
           PERFORM VARYING WS-I FROM 1 BY 1 UNTIL WS-I > 8
               DIVIDE WS-SCORE BY 2
               GIVING WS-SCORE REMAINDER WS-R
               IF WS-R = 1 AND 
                   WS-ITEM = WS-ALLERGENS-NAMES(WS-I) THEN
                    MOVE "Y" TO WS-RESULT
               END-IF    
       END-PERFORM.    

      * Code this paragraph
           CONTINUE.

       LIST-ALLERGENS.
           MOVE SPACE TO WS-TRL.
           PERFORM VARYING WS-I FROM 1 BY 1 UNTIL WS-I > 8
               DIVIDE WS-SCORE BY 2
               GIVING WS-SCORE REMAINDER WS-R
               IF WS-R = 1 THEN
                    STRING WS-TRL DELIMITED BY SPACE 
                       "," DELIMITED BY SPACE
                       WS-ALLERGENS-NAMES(WS-I) INTO WS-TRL
                    END-STRING 
               END-IF    
              
           END-PERFORM.    
           MOVE THE-REST TO WS-RESULT-LIST.
           CONTINUE.
