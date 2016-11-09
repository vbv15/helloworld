%1.4 Nth fibonacci number..


%rule

fibo(1,0):- !.
fibo(2,1):- !.
fibo(X,Y):- A is X-1,B is X-2,fibo(A,C),fibo(B,D), Y is C+D.
