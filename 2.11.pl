%Merging two ordered lists.
merge([],L,L).
merge(L,[],L).
merge([],[],[]).
merge([H1|T1],[H2|T2],[H3|X]):-H1=<H2, H3 is H1, merge(T1,[H2|T2],X);H1>H2, H3 is H2, merge([H1|T1],T2,X).
