%Delete all occurence of number

delete1(X,[],[]):-!.
delete1(X,[X|T],L2):-delete1(X,T,L2),!.
delete1(X,[H1|T1],[H1|T2]):-delete1(X,T1,T2).
