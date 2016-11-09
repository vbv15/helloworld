t=(0:0.01:5*%pi)';
 
-  
 
-  tc=(2*%pi)/10;
 
-  
 
-  fc=1/tc;
 
-  
 
- tl=t/20;
 
- u=cos(2*%pi*fc*tl);
 
- ta=8*t;
 
- k=(squarewave(ta)+1)*(1/2);
 
- y=k.*u;
 plot(t,y)
