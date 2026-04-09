       IDENTIFICATION DIVISION.
       PROGRAM-ID. SPACE-AGE.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-INPUT                 PIC 9(30).
       01 WS-WHICH-PLANET          PIC X(30).
       01 WS-RESULT                PIC 9(4)V99.
       01 WS-ERROR                 PIC X(30).
       
       PROCEDURE DIVISION.
       
       ROUNDS-TO.
           MOVE SPACES TO WS-ERROR           
           EVALUATE WS-WHICH-PLANET 
               WHEN "Earth"
                   COMPUTE WS-RESULT ROUNDED =
                       WS-INPUT / 31557600
               WHEN "Mercury"
                   COMPUTE WS-RESULT ROUNDED = 
                       WS-INPUT / (0.2408467 * 31557600)
               WHEN "Venus"
                   COMPUTE WS-RESULT ROUNDED = 
                       WS-INPUT / (0.61519726 * 31557600)
               WHEN "Mars"
                   COMPUTE WS-RESULT ROUNDED = 
                      WS-INPUT / (1.8808158  * 31557600)
               WHEN "Jupiter"
                   COMPUTE WS-RESULT ROUNDED = 
                       WS-INPUT / (11.862615 * 31557600)
               WHEN "Saturn"
                   COMPUTE WS-RESULT ROUNDED = 
                       WS-INPUT / (29.447498 * 31557600)
               WHEN "Uranus"
                   COMPUTE WS-RESULT ROUNDED = 
                       WS-INPUT / (84.016846 * 31557600)
               WHEN "Neptune"
                   COMPUTE WS-RESULT ROUNDED = 
                       WS-INPUT / (164.79132 * 31557600)
               WHEN OTHER 
                 MOVE "not a planet" TO WS-ERROR
           END-EVALUATE.
