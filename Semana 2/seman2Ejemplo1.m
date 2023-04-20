clear; clc;
t=-3:0.1:3;
x=t.^2;
y=t+1;
plot(x,y)
grid on

% -----------------------

clear; clc;
t=-3:0.1:8*pi;
x=cos(t);
y=sin(t);
z=0.2*t;
plot3(x,y,z)
grid on

% ----------------------

clear; clc;
[u,v] = meshgrid(0:0.5:50);
x = cos(u).*(2+cos(v));
y = sin(u).*(2+cos(v));
z=sin(v);
surf(x,y,z) %surf en lugar de plot3 le da profundidad

% --------------------------

clear; clc;
t = -5:0.5:5;
x = t.^2 - 2*t;
y = t + 1;
plot (x,y)
grid on; 

% ------------------------

clear; clc;
t = -5:0.5:5;
x = t.^3 - 4*t;
y = t.^2-4;
plot(x,y)

% ---------------------------

clear; clc;
a = 1; b = 1;
[t,u] = meshgrid(0:0.1:2*pi);
x = a*cos(t).*cos(u);
y = b*cos(t).*sin(u);
z = (cos(t)).^2;

surf(x,y,z)


