FUNCTION PI(N,A,ACC,TERM,PI)
  PI:4  ACC:1/RADIX()^N  A:1
  LOOP
    TERM: 8/(16*A^2-1)
    PI: PI-TERM
    WHEN TERM<ACC, PRINT("ANSWER IS ") PI EXIT
    PRINT("ITERATION #") PRTMATH(I)
    PRINT("  VALUE =") PRTMATH(PI) NEWLINE()
    A: A+1
  ENDLOOP
ENDFUN $
                                                                                                              