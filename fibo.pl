%Print upto Nth fibonacci number..


%rule
fibo(N):-fib(0,1,1,N).
fib(X,Y,N,N):-write(X),!.
fib(X,Y,Z,N):-write(X),write(' '),T is Y+X,Z1 is Z+1,fib(Y,T,Z1,N).
