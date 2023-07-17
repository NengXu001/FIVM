IMPORT DTREE FROM FILE 'path-Q20.txt';

CREATE DISTRIBUTED TYPE RingFactorizedRelation
FROM FILE 'ring/RingFactorizedRelation.hpp'
WITH PARAMETER SCHEMA (dynamic_min);

CREATE STREAM R1 (
	A1 	 INT, 
	A2 	 INT) 
FROM FILE './datasets/snap/R1.csv' 
LINE DELIMITED CSV (delimiter := '|');

CREATE STREAM R2 (
	A2 	 INT, 
	A3 	 INT) 
FROM FILE './datasets/snap/R2.csv' 
LINE DELIMITED CSV (delimiter := '|');

CREATE STREAM R3 (
	A3 	 INT, 
	A4 	 INT) 
FROM FILE './datasets/snap/R3.csv' 
LINE DELIMITED CSV (delimiter := '|');

CREATE STREAM R4 (
	A4 	 INT, 
	A5 	 INT) 
FROM FILE './datasets/snap/R4.csv' 
LINE DELIMITED CSV (delimiter := '|');

CREATE STREAM R5 (
	A5 	 INT, 
	A6 	 INT) 
FROM FILE './datasets/snap/R5.csv' 
LINE DELIMITED CSV (delimiter := '|');

CREATE STREAM R6 (
	A6 	 INT, 
	A7 	 INT) 
FROM FILE './datasets/snap/R6.csv' 
LINE DELIMITED CSV (delimiter := '|');

CREATE STREAM R7 (
	A7 	 INT, 
	A8 	 INT) 
FROM FILE './datasets/snap/R7.csv' 
LINE DELIMITED CSV (delimiter := '|');

CREATE STREAM R8 (
	A8 	 INT, 
	A9 	 INT) 
FROM FILE './datasets/snap/R8.csv' 
LINE DELIMITED CSV (delimiter := '|');

CREATE STREAM R9 (
	A9 	 INT, 
	A10 	 INT) 
FROM FILE './datasets/snap/R9.csv' 
LINE DELIMITED CSV (delimiter := '|');

CREATE STREAM R10 (
	A10 	 INT, 
	A11 	 INT) 
FROM FILE './datasets/snap/R10.csv' 
LINE DELIMITED CSV (delimiter := '|');

CREATE STREAM R11 (
	A11 	 INT, 
	A12 	 INT) 
FROM FILE './datasets/snap/R11.csv' 
LINE DELIMITED CSV (delimiter := '|');

CREATE STREAM R12 (
	A12 	 INT, 
	A13 	 INT) 
FROM FILE './datasets/snap/R12.csv' 
LINE DELIMITED CSV (delimiter := '|');

CREATE STREAM R13 (
	A13 	 INT, 
	A14 	 INT) 
FROM FILE './datasets/snap/R13.csv' 
LINE DELIMITED CSV (delimiter := '|');

CREATE STREAM R14 (
	A14 	 INT, 
	A15 	 INT) 
FROM FILE './datasets/snap/R14.csv' 
LINE DELIMITED CSV (delimiter := '|');

CREATE STREAM R15 (
	A15 	 INT, 
	A16 	 INT) 
FROM FILE './datasets/snap/R15.csv' 
LINE DELIMITED CSV (delimiter := '|');

CREATE STREAM R16 (
	A16 	 INT, 
	A17 	 INT) 
FROM FILE './datasets/snap/R16.csv' 
LINE DELIMITED CSV (delimiter := '|');

CREATE STREAM R17 (
	A17 	 INT, 
	A18 	 INT) 
FROM FILE './datasets/snap/R17.csv' 
LINE DELIMITED CSV (delimiter := '|');

CREATE STREAM R18 (
	A18 	 INT, 
	A19 	 INT) 
FROM FILE './datasets/snap/R18.csv' 
LINE DELIMITED CSV (delimiter := '|');

CREATE STREAM R19 (
	A19 	 INT, 
	A20 	 INT) 
FROM FILE './datasets/snap/R19.csv' 
LINE DELIMITED CSV (delimiter := '|');

CREATE STREAM R20 (
	A20 	 INT, 
	A21 	 INT) 
FROM FILE './datasets/snap/R20.csv' 
LINE DELIMITED CSV (delimiter := '|');


SELECT SUM(
	[lift<0>: RingFactorizedRelation<[0, INT]>](A11) *
	[lift<1>: RingFactorizedRelation<[1, INT]>](A6) *
	[lift<2>: RingFactorizedRelation<[2, INT]>](A3) *
	[lift<3>: RingFactorizedRelation<[3, INT]>](A2) *
	[lift<4>: RingFactorizedRelation<[4, INT]>](A1) *
	[lift<5>: RingFactorizedRelation<[5, INT]>](A5) *
	[lift<6>: RingFactorizedRelation<[6, INT]>](A4) *
	[lift<7>: RingFactorizedRelation<[7, INT]>](A9) *
	[lift<8>: RingFactorizedRelation<[8, INT]>](A8) *
	[lift<9>: RingFactorizedRelation<[9, INT]>](A7) *
	[lift<10>: RingFactorizedRelation<[10, INT]>](A10) *
	[lift<11>: RingFactorizedRelation<[11, INT]>](A17) *
	[lift<12>: RingFactorizedRelation<[12, INT]>](A14) *
	[lift<13>: RingFactorizedRelation<[13, INT]>](A13) *
	[lift<14>: RingFactorizedRelation<[14, INT]>](A12) *
	[lift<15>: RingFactorizedRelation<[15, INT]>](A16) *
	[lift<16>: RingFactorizedRelation<[16, INT]>](A15) *
	[lift<17>: RingFactorizedRelation<[17, INT]>](A20) *
	[lift<18>: RingFactorizedRelation<[18, INT]>](A19) *
	[lift<19>: RingFactorizedRelation<[19, INT]>](A18) *
	[lift<20>: RingFactorizedRelation<[20, INT]>](A21) 
)
FROM R1 NATURAL JOIN R2 NATURAL JOIN R3 NATURAL JOIN R4 NATURAL JOIN R5 NATURAL JOIN R6 NATURAL JOIN R7 NATURAL JOIN R8 NATURAL JOIN R9 NATURAL JOIN R10 NATURAL JOIN R11 NATURAL JOIN R12 NATURAL JOIN R13 NATURAL JOIN R14 NATURAL JOIN R15 NATURAL JOIN R16 NATURAL JOIN R17 NATURAL JOIN R18 NATURAL JOIN R19 NATURAL JOIN R20;


