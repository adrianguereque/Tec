%Función MatLab
%
clear clc
clc
syms x;
f=input('Digite la función a integrar =');
F=inline(char(f));
a=input('Desde = ');
b=input('Hasta = ');
F=int(f,a,b)


% Función 1

pi.*((-x+5)^2)
De =2
Hasta = 4

%(26*pi)/3

% Función 2
pi.*x^0
De = 4
Hasta = 6

%2*pi

% Función 3

pi.*(((sqrt(25-(x-11)^2))+1)^2);

Desde = 6;
Hasta = 11;


%(5*pi*(15*pi + 106))/6
