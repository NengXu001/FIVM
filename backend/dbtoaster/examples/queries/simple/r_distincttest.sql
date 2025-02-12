CREATE STREAM R(A int, B int) 
  FROM FILE 'examples/data/simple/r.dat' LINE DELIMITED csv;

SELECT * FROM R;
SELECT COUNT(*) FROM R;
SELECT COUNT(DISTINCT) FROM R;
SELECT COUNT(DISTINCT B) FROM R;
SELECT COUNT(DISTINCT B) FROM R GROUP BY A;
