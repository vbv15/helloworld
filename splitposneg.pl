%Spilt list into two sub list

split([],[],[]):-!.
split([H1|T1],[H2|T2],N):- H1>=0,H2 is H1,split(T1,T2,N),!.
split([H1|T1],P,[H3|T3]):- H1<0,H3 is H1,split(T1,P,T3),!.