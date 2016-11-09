%2.10

sumn(1,1).
sumn(N,R):-not(N=<1),N1 is N-1,sumn(N1,R1),R is N+R1.
