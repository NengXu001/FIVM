CREATE STREAM R(A int, B int) FROM FILE 'examples/data/simple/r.dat' LINE DELIMITED CSV();

CREATE STREAM S(B int, C int) FROM FILE 'examples/data/simple/s.dat' LINE DELIMITED CSV();

CREATE STREAM T(C int, D int) FROM FILE 'examples/data/simple/t.dat' LINE DELIMITED CSV();

SELECT 
  t1.*, 
  t2.*
FROM 
  S, 
  T t1, 
  T t2
WHERE 
  t1.D = t2.C 
    OR 
  2 = (S.B*t1.D)
;
