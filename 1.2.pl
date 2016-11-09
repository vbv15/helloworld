%1.2 Max of 2 numbers.


%rule

max(X,Y,Z):- X>Y, Z is X.
max(X,Y,Z):- Y>=X, Z is Y.