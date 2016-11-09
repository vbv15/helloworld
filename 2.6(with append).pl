%Add an element to the tail of list,with append.
	
add_to_tail(X,L):-append(L,[X],R), write(R).
