%Remove nth item in the list

remove(0,[H|T],X):-X = "No such element",!.
remove(Pos,[],X):-Pos >=1,write('No such element.'),!.
remove(1,[H|T],T):-!.	
remove(P,[H|T],[H|T1]):-P1 is P-1,remove(P1,T,T1).
