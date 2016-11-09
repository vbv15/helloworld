%4.1

evenlength([]):-!.
oddlength([H]):-!.

evenlength([H|T]):-oddlength(T).

oddlength([H|T]):-evenlength(T).


