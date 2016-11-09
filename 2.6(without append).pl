%Add an element to the tail of list,with append.
	
a(X,[],[X]):-!.
a(X,[H|T],[H|Z]):-a(X,T,Z).
