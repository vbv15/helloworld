 
t=(0:0.01:5*%pi)';
 
tc=(2*%pi)/10;
 
fc=1/tc;
 
k=(squarewave(t)+1)*(1/2);
 
y=k.*cos(2*%pi*fc*t);

k1=((-1)*squarewave(t)+1)*(1/2);
 
ta=(2*%pi)/2;
 
fa=1/ta;
 
y1=k1.*cos(2*%pi*fa*t);
p=y+y1;
 
plot(t,p);
