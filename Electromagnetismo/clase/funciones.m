%Ejercicio 1
f = @(t,x)t./sqrt(1+t.^2);
y0 = 10;
t0 = 0;
tf = 3.5;
h = 0.1;
[x,y] = RK2(f,y0,t0,tf,h);
[xa,xb] = Euler(f,y0,t0,tf,h);
plot(x,y,'r.')
hold on
plot(xa,xb)
hold off

%Ejercicio 2
f = @(x,y)sin(y);
y0 = 1;
t0 = 0;
tf = 3;
h = 0.1;
[x,y] = RK2(f,y0,t0,tf,h);
[xa,xb] = Euler(f,y0,t0,tf,h);
plot(x,y,'r.')
hold on
plot(xa,xb)
hold off

%Ejercicio 3
f = @(t,y)20+7.*sin(2.*t);
y0 = 15;
t0 = 0;
tf = 2.8;
h = 0.1;
[x,y] = RK2(f,y0,t0,tf,h);
[xa,xb] = Euler(f,y0,t0,tf,h);
plot(x,y,'r.')
hold on
plot(xa,xb)
hold off

%Ejercicio 4
f = @(x,y)3.*y+ - 4.*exp(-x);
y0 = 1;
t0 = 0;
tf = 3;
h = 0.1;
[x,y] = RK2(f,y0,t0,tf,h);
[xa,xb] = Euler(f,y0,t0,tf,h);
plot(x,y,'r.')
hold on
plot(xa,xb)
hold on
f2 = @(x)exp(-x);
y3 = f2(x);
plot(x,y3,'o')
ylim([-2.5 1])
xlim([0 2])
hold off

%Ejercicio 5
f = @(t,y)0.7.*y - (t.^2) + 1;
y0 = 1;
t0 = 1;
tf = 2;
h = 0.1;
[x,y] = RK2(f,y0,t0,tf,h);
[xa,xb] = Euler(f,y0,t0,tf,h);
plot(x,y,'r.')
hold on
plot(xa,xb)
hold on
f2 = @(t)1.42857.*t.^2 + 4.08163.*t - 4.42583.*exp(0.7.*t) + 4.40233;
y3 = f2(x);
plot(x,y3,'o')
ylim([0.3 1.2])
xlim([1 2])
hold off