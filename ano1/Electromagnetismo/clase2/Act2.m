%% Ejercicio 1
f=@(x,y) -y+sin(x);
y0 = -0.1;
t0 = 4;
tf = 6;
h=0.1;
[x,y]=RK4(f,t0,tf,y0,h);
plot(x,y,'-b')
E=1.5*exp(-x)+0.5*sin(x)-0.5*cos(x);
hold on
plot(x,E,'-r')
legend('Aproximacion','Exacta')
title('Metodo de Runge-Kutta 4to orden')
xlabel('x')
ylabel('y')
hold off
x = x';
y=y';
E=E';
Diferencia = E-y;
T = table(x,y,E,Diferencia);
disp(T);
%writetable(T,'Ejercicio1.xlsx')

%% Ejercicio 2
f=@(x,y)y.*tan(x)+x;
y0 = 10;
t0 = 0;
tf = 3;
h = 0.1;
[x,y]=RK4(f,t0,tf,y0,h);
plot(x,y,'-b')
E=x.*tan(x)+12.*sec(x)+1;
hold on
plot(x,E,'-r')
legend('Aproximacion','Exacta')
title('Metodo de Runge-Kutta 4to orden')
xlabel('x')
ylabel('y')
hold off
x = x';
y=y';
E=E';
Diferencia = E-y;
T = table(x,y,E,Diferencia);
disp(T);
%writetable(T,'Ejercicio2.xlsx')

%% Ejercicio 3
f=@(x,y)(3.*x./y)-x.*y;
y0 = 2;
t0 = 0;
tf = 2.5;
h = 0.1;
[x,y]=RK4(f,t0,tf,y0,h);
plot(x,y,'-b')
E=sqrt(3+exp(-x.^2));
hold on
plot(x,E,'hexagram')
legend('Aproximacion','Exacta')
title('Metodo de Runge-Kutta 4to orden')
xlabel('x')
ylabel('y')
hold off
x = x';
y=y';
E=E';
Diferencia = E-y;
T = table(x,y,E,Diferencia);
disp(T);
%writetable(T,'Ejercicio3.xlsx')

%% Ejercicio 4
f=@(x,y)y.*cos(x);
y0 = 1;
t0 = 0;
tf = 4;
h = 0.1;
[x,y]=RK4(f,t0,tf,y0,h);
plot(x,y,'-b')
E=exp(sin(x));
hold on
plot(x,E,'hexagram')
legend('Aproximacion','Exacta')
title('Metodo de Runge-Kutta 4to orden')
xlabel('x')
ylabel('y')
hold off
x = x';
y=y';
E=E';
Diferencia = E-y;
T = table(x,y,E,Diferencia);
disp(T);
%writetable(T,'Ejercicio4.xlsx')

%% Ejercicio 5
f=@(x,y)y+2.*x - x.^2;
y0 = 1;
t0 = 1;
tf = 4;
h = 1;
[x,y]=RK4(f,t0,tf,y0,h);
plot(x,y,'-b')
E=exp(sin(x));
hold on
plot(x,E,'hexagram')
legend('Aproximacion','Exacta')
title('Metodo de Runge-Kutta 4to orden')
xlabel('x')
ylabel('y')
hold off
x = x';
y=y';
E=E';
Diferencia = E-y;
T = table(x,y,E,Diferencia);
disp(T);
%writetable(T,'Ejercicio4.xlsx')
