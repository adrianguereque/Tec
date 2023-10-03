%actividad graficas
clear; clc;
t = -5:0.5:5;
x = t.^2 - 2*t;
y = t + 1;
plot (x,y)
grid on; 

% ------------------------

t = -5:0.5:5;
x = t.^3 - 4*t;
y = t.^2-4;
plot(x,y)

% ---------------------------

a = 1; b = 1;
[t,u] = meshgrid(0:0.1:2*pi);
x = a*cos(t).*cos(u);
y = b*cos(t).*sin(u);
z = (cos(t)).^2;

surf(x,y,z)


