 
Startup execution:
  loading initial environment
 
-->ac=40;
 
-->fc=2000;
 
-->fm=100;
 
-->b=2;
 
-->ta=1/fc;
 
-->t=1/fc;
 
-->t=0:ta/996:2*ta;
 
-->am=40;
 
-->y=ac*cos(2*%pi*fc*t+b*sin(2*%pi*fm*t));
 
-->plot(t,y);
 
