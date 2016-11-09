 
 ac=4;
 
 fc=1500;
 
 fm=100;
 
 b=1.5;
 
 ta=1/fm;
 
 t=0:ta/99:2*ta;
 
 y=ac*cos(2*%pi*fc*t+b*sin(2*%pi*fm*t));
 
 plot(t,y);
 
 t=0:ta/99:5*ta;
 
 fc=20000;
 
 y=ac*cos(2*%pi*fc*t+b*sin(2*%pi*fm*t));
 
 plot(t,y);
 
 fc=5000;
 
 y=ac*cos(2*%pi*fc*t+b*sin(2*%pi*fm*t));
 
 plot(t,y);
 
 plot(t,y);
 
 z=ac*cos(2*%pi*fm*t);
 
 plot(t,z);
 
