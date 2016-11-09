 
--> t=(0:0.01:5*%pi)';
 
--> 
 
--> tc=(2*%pi)/10;
 
--> fc=1/tc;
 
-->k=(squarewave(t));
 
-->y=k.*cos(2*%pi*fc*t);
 
-->plot(t,y)
 
-->plot(k,t)
 
