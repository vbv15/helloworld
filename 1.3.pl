%1.3 Factorial of a number.


%rule

fact(X,Z):- X=<1,Z is 1,!. 
fact(X,Z):- Y is X-1,fact(Y,B), Z is X*B.