gener(A,B):-A1 is A+1,gen1(A,B,A1).
gen1(A,B,X):-X<B,write(X),X1 is X+1,X1<B,write(,),gen1(A,B,X1),!.
