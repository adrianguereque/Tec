% Funcion yeti
clear clc
clc
syms x;
f1=0.11*x+10;
a1=0;
b1=28;
F1=int(f1,a1,b1);

f2=0.75*x-8;
a2=28;
b2=32;
F2=int(f2,a2,b2);

f3=0.19*x+9.97;
a3=32;
b3=60;
F3=int(f3,a3,b3);

% se suma y se quitan las fracciones vpa()
VolumenTot=vpa(F1+F2+F3)



