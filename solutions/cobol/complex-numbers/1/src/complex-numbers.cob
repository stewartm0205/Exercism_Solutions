       IDENTIFICATION DIVISION.
       PROGRAM-ID. COMPLEX-NUMBERS.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 Z1-RE          PIC S99999.
       01 Z1-IM          PIC S99999.
       01 Z2-RE          PIC S99999.
       01 Z2-IM          PIC S99999. 
       01 RESULT-RE      PIC S99999V9999.
       01 RESULT-IM      PIC S99999V9999.


       PROCEDURE DIVISION.

       C-REAL.
           MOVE Z1-RE TO RESULT-RE.
           MOVE 0 TO RESULT-IM.

 
       C-IMAGINARY.
           MOVE 0 TO RESULT-RE.
           MOVE Z1-IM TO RESULT-IM.


       C-ADD.
           ADD Z1-RE Z2-RE GIVING RESULT-RE
           ADD Z1-IM Z2-IM GIVING RESULT-IM.



       C-SUB.
           SUBTRACT Z2-RE FROM Z1-RE GIVING RESULT-RE
           SUBTRACT Z2-IM FROM Z1-IM GIVING RESULT-IM.


       C-MUL.
           COMPUTE RESULT-RE = (Z1-RE * Z2-RE - Z1-IM * Z2-IM) 
           COMPUTE RESULT-IM = (Z1-IM * Z2-RE + Z1-RE * Z2-IM). 
                               


       C-DIV.
           COMPUTE RESULT-RE = (Z1-RE * Z2-RE + Z1-IM * Z2-IM) /
                               (Z2-RE * Z2-RE + Z2-IM * Z2-IM)
           COMPUTE RESULT-IM = (Z1-IM * Z2-RE - Z1-RE * Z2-IM) /
                               (Z2-RE * Z2-RE + Z2-IM * Z2-IM).


       C-ABS.
           COMPUTE RESULT-RE = 
             FUNCTION SQRT(Z1-RE * Z1-RE + Z1-IM * Z1-IM).
           MOVE 0 TO RESULT-IM.


       C-CONJUGATE.
           MOVE Z1-RE TO RESULT-RE
           COMPUTE RESULT-IM = -1 * Z1-IM.


