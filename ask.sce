 t=(0:0.01:5*%pi)';
 
 tc=(2*%pi)/10;
 
 fc=1/tc;
 
 plot(t,cos(2*%pi*fc*t))
 
  k=(squarewave(t)+1)*(1/2);
 
y=k.*cos(2*%pi*fc*t);
 
plot(t,y)
