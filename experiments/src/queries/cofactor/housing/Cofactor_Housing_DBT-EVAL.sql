CREATE TABLE HOUSE(postcode float, h2 float, h3 float, h4 float, h5 float, h6 float, h7 float, h8 float, h9 float, h10 float, h11 float)
FROM FILE './datasets/housing/House.tbl' LINE DELIMITED CSV(delimiter := '|');

CREATE TABLE SHOP(postcode float, s2 float, s3 float, s4 float, s5 float, s6 float)
FROM FILE './datasets/housing/Shop.tbl' LINE DELIMITED CSV(delimiter := '|');

CREATE TABLE INSTITUTION(postcode float, i2 float, i3 float)
FROM FILE './datasets/housing/Institution.tbl' LINE DELIMITED CSV(delimiter := '|');

CREATE TABLE RESTAURANT(postcode float, r2 float, r3 float)
FROM FILE './datasets/housing/Restaurant.tbl' LINE DELIMITED CSV(delimiter := '|');

CREATE TABLE DEMOGRAPHICS(postcode float, d2 float, d3 float, d4 float, d5 float)
FROM FILE './datasets/housing/Demographics.tbl' LINE DELIMITED CSV(delimiter := '|');

CREATE TABLE TRANSPORT(postcode float, t2 float, t3 float, t4 float)
FROM FILE './datasets/housing/Transport.tbl' LINE DELIMITED CSV(delimiter := '|');

SELECT SUM(HOUSE.postcode*HOUSE.postcode), SUM(HOUSE.postcode*h2), SUM(HOUSE.postcode*h3), SUM(HOUSE.postcode*h4), SUM(HOUSE.postcode*h5), SUM(HOUSE.postcode*h6), SUM(HOUSE.postcode*h7), SUM(HOUSE.postcode*h8), SUM(HOUSE.postcode*h9), SUM(HOUSE.postcode*h10), SUM(HOUSE.postcode*h11), SUM(HOUSE.postcode*s2), SUM(HOUSE.postcode*s3), SUM(HOUSE.postcode*s4), SUM(HOUSE.postcode*s5), SUM(HOUSE.postcode*s6), SUM(HOUSE.postcode*i2), SUM(HOUSE.postcode*i3), SUM(HOUSE.postcode*r2), SUM(HOUSE.postcode*r3), SUM(HOUSE.postcode*d2), SUM(HOUSE.postcode*d3), SUM(HOUSE.postcode*d4), SUM(HOUSE.postcode*d5), SUM(HOUSE.postcode*t2), SUM(HOUSE.postcode*t3), SUM(HOUSE.postcode*t4), SUM(h2*h2), SUM(h2*h3), SUM(h2*h4), SUM(h2*h5), SUM(h2*h6), SUM(h2*h7), SUM(h2*h8), SUM(h2*h9), SUM(h2*h10), SUM(h2*h11), SUM(h2*s2), SUM(h2*s3), SUM(h2*s4), SUM(h2*s5), SUM(h2*s6), SUM(h2*i2), SUM(h2*i3), SUM(h2*r2), SUM(h2*r3), SUM(h2*d2), SUM(h2*d3), SUM(h2*d4), SUM(h2*d5), SUM(h2*t2), SUM(h2*t3), SUM(h2*t4), SUM(h3*h3), SUM(h3*h4), SUM(h3*h5), SUM(h3*h6), SUM(h3*h7), SUM(h3*h8), SUM(h3*h9), SUM(h3*h10), SUM(h3*h11), SUM(h3*s2), SUM(h3*s3), SUM(h3*s4), SUM(h3*s5), SUM(h3*s6), SUM(h3*i2), SUM(h3*i3), SUM(h3*r2), SUM(h3*r3), SUM(h3*d2), SUM(h3*d3), SUM(h3*d4), SUM(h3*d5), SUM(h3*t2), SUM(h3*t3), SUM(h3*t4), SUM(h4*h4), SUM(h4*h5), SUM(h4*h6), SUM(h4*h7), SUM(h4*h8), SUM(h4*h9), SUM(h4*h10), SUM(h4*h11), SUM(h4*s2), SUM(h4*s3), SUM(h4*s4), SUM(h4*s5), SUM(h4*s6), SUM(h4*i2), SUM(h4*i3), SUM(h4*r2), SUM(h4*r3), SUM(h4*d2), SUM(h4*d3), SUM(h4*d4), SUM(h4*d5), SUM(h4*t2), SUM(h4*t3), SUM(h4*t4), SUM(h5*h5), SUM(h5*h6), SUM(h5*h7), SUM(h5*h8), SUM(h5*h9), SUM(h5*h10), SUM(h5*h11), SUM(h5*s2), SUM(h5*s3), SUM(h5*s4), SUM(h5*s5), SUM(h5*s6), SUM(h5*i2), SUM(h5*i3), SUM(h5*r2), SUM(h5*r3), SUM(h5*d2), SUM(h5*d3), SUM(h5*d4), SUM(h5*d5), SUM(h5*t2), SUM(h5*t3), SUM(h5*t4), SUM(h6*h6), SUM(h6*h7), SUM(h6*h8), SUM(h6*h9), SUM(h6*h10), SUM(h6*h11), SUM(h6*s2), SUM(h6*s3), SUM(h6*s4), SUM(h6*s5), SUM(h6*s6), SUM(h6*i2), SUM(h6*i3), SUM(h6*r2), SUM(h6*r3), SUM(h6*d2), SUM(h6*d3), SUM(h6*d4), SUM(h6*d5), SUM(h6*t2), SUM(h6*t3), SUM(h6*t4), SUM(h7*h7), SUM(h7*h8), SUM(h7*h9), SUM(h7*h10), SUM(h7*h11), SUM(h7*s2), SUM(h7*s3), SUM(h7*s4), SUM(h7*s5), SUM(h7*s6), SUM(h7*i2), SUM(h7*i3), SUM(h7*r2), SUM(h7*r3), SUM(h7*d2), SUM(h7*d3), SUM(h7*d4), SUM(h7*d5), SUM(h7*t2), SUM(h7*t3), SUM(h7*t4), SUM(h8*h8), SUM(h8*h9), SUM(h8*h10), SUM(h8*h11), SUM(h8*s2), SUM(h8*s3), SUM(h8*s4), SUM(h8*s5), SUM(h8*s6), SUM(h8*i2), SUM(h8*i3), SUM(h8*r2), SUM(h8*r3), SUM(h8*d2), SUM(h8*d3), SUM(h8*d4), SUM(h8*d5), SUM(h8*t2), SUM(h8*t3), SUM(h8*t4), SUM(h9*h9), SUM(h9*h10), SUM(h9*h11), SUM(h9*s2), SUM(h9*s3), SUM(h9*s4), SUM(h9*s5), SUM(h9*s6), SUM(h9*i2), SUM(h9*i3), SUM(h9*r2), SUM(h9*r3), SUM(h9*d2), SUM(h9*d3), SUM(h9*d4), SUM(h9*d5), SUM(h9*t2), SUM(h9*t3), SUM(h9*t4), SUM(h10*h10), SUM(h10*h11), SUM(h10*s2), SUM(h10*s3), SUM(h10*s4), SUM(h10*s5), SUM(h10*s6), SUM(h10*i2), SUM(h10*i3), SUM(h10*r2), SUM(h10*r3), SUM(h10*d2), SUM(h10*d3), SUM(h10*d4), SUM(h10*d5), SUM(h10*t2), SUM(h10*t3), SUM(h10*t4), SUM(h11*h11), SUM(h11*s2), SUM(h11*s3), SUM(h11*s4), SUM(h11*s5), SUM(h11*s6), SUM(h11*i2), SUM(h11*i3), SUM(h11*r2), SUM(h11*r3), SUM(h11*d2), SUM(h11*d3), SUM(h11*d4), SUM(h11*d5), SUM(h11*t2), SUM(h11*t3), SUM(h11*t4), SUM(s2*s2), SUM(s2*s3), SUM(s2*s4), SUM(s2*s5), SUM(s2*s6), SUM(s2*i2), SUM(s2*i3), SUM(s2*r2), SUM(s2*r3), SUM(s2*d2), SUM(s2*d3), SUM(s2*d4), SUM(s2*d5), SUM(s2*t2), SUM(s2*t3), SUM(s2*t4), SUM(s3*s3), SUM(s3*s4), SUM(s3*s5), SUM(s3*s6), SUM(s3*i2), SUM(s3*i3), SUM(s3*r2), SUM(s3*r3), SUM(s3*d2), SUM(s3*d3), SUM(s3*d4), SUM(s3*d5), SUM(s3*t2), SUM(s3*t3), SUM(s3*t4), SUM(s4*s4), SUM(s4*s5), SUM(s4*s6), SUM(s4*i2), SUM(s4*i3), SUM(s4*r2), SUM(s4*r3), SUM(s4*d2), SUM(s4*d3), SUM(s4*d4), SUM(s4*d5), SUM(s4*t2), SUM(s4*t3), SUM(s4*t4), SUM(s5*s5), SUM(s5*s6), SUM(s5*i2), SUM(s5*i3), SUM(s5*r2), SUM(s5*r3), SUM(s5*d2), SUM(s5*d3), SUM(s5*d4), SUM(s5*d5), SUM(s5*t2), SUM(s5*t3), SUM(s5*t4), SUM(s6*s6), SUM(s6*i2), SUM(s6*i3), SUM(s6*r2), SUM(s6*r3), SUM(s6*d2), SUM(s6*d3), SUM(s6*d4), SUM(s6*d5), SUM(s6*t2), SUM(s6*t3), SUM(s6*t4), SUM(i2*i2), SUM(i2*i3), SUM(i2*r2), SUM(i2*r3), SUM(i2*d2), SUM(i2*d3), SUM(i2*d4), SUM(i2*d5), SUM(i2*t2), SUM(i2*t3), SUM(i2*t4), SUM(i3*i3), SUM(i3*r2), SUM(i3*r3), SUM(i3*d2), SUM(i3*d3), SUM(i3*d4), SUM(i3*d5), SUM(i3*t2), SUM(i3*t3), SUM(i3*t4), SUM(r2*r2), SUM(r2*r3), SUM(r2*d2), SUM(r2*d3), SUM(r2*d4), SUM(r2*d5), SUM(r2*t2), SUM(r2*t3), SUM(r2*t4), SUM(r3*r3), SUM(r3*d2), SUM(r3*d3), SUM(r3*d4), SUM(r3*d5), SUM(r3*t2), SUM(r3*t3), SUM(r3*t4), SUM(d2*d2), SUM(d2*d3), SUM(d2*d4), SUM(d2*d5), SUM(d2*t2), SUM(d2*t3), SUM(d2*t4), SUM(d3*d3), SUM(d3*d4), SUM(d3*d5), SUM(d3*t2), SUM(d3*t3), SUM(d3*t4), SUM(d4*d4), SUM(d4*d5), SUM(d4*t2), SUM(d4*t3), SUM(d4*t4), SUM(d5*d5), SUM(d5*t2), SUM(d5*t3), SUM(d5*t4), SUM(t2*t2), SUM(t2*t3), SUM(t2*t4), SUM(t3*t3), SUM(t3*t4), SUM(t4*t4)
FROM HOUSE NATURAL JOIN SHOP NATURAL JOIN INSTITUTION NATURAL JOIN RESTAURANT NATURAL JOIN DEMOGRAPHICS NATURAL JOIN TRANSPORT;