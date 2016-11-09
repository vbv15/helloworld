%3.2 Max of 2 numbers.


%rule

max(X,Y,M):- X>Y,M is X.
max(X,Y,M):- Y>=X,M is Y.