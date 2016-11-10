function[y]=ampdemod(Em,Ec,fm,fc,fs)
    t = 0:1/fs:1;
    m=0.9;
    Vm = Em*sin(2*%pi*fm*t);
    Vc = Ec*sin(2*%pi*fc*t);
    x = Ec*(1+m*sin(2*%pi*fm*t)).*(sin(2*%pi*fc*t));
    xdem = x.*Vc;
    H = iir(7,'lp','butt',[fc/fs,0.5],[.01,.01]);
    num = coeff(H(2));
    den = coeff(H(3));
    num = num(length(num):-1:1);
    den = den(length(den):-1:1);
    y = filter(num,den,xdem);
    subplot(4,1,1)
    plot(Vm,'r')
    xtitle('Modulating Signal','Time','Amplitude');
    subplot(4,1,2)
    plot(Vc,'b')
    xtitle('Carrier Signal','Time','Amplitude');
    disp(m);
    subplot(4,1,3)
    plot(x,'g')
    xtitle('Amplitude Modulated Signal','Time','Amplitude');
    subplot(4,1,4)
    plot(y,'k');
    xtitle('AM Demodulated Signal','Time','Amplitude');
endfunction 

ampdemod(8,10,2,10,1000);
