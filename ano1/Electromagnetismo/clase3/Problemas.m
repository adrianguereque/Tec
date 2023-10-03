%% Problema 1
Matriz = readmatrix('valores.csv');
x=Matriz(:,1);
y=Matriz(:,2);
plot(x,y,'.','MarkerSize',20)
[m,b]=Min2(x,y);
f=m*x+b;
hold on
plot(x,f)
str = "m = "+m+", b = "+b;
title(str)
xlabel('x')
ylabel('y')

%% Problema 2
Matriz = readmatrix('PuntosXY.csv');
x=Matriz(1,:);
y=Matriz(2,:);
plot(x,y,'.','MarkerSize',20)
[m,b]=Min2(x,y);
f=m*x+b;
hold on
plot(x,f)
str = "m = "+m+", b = "+b;
title(str)
xlabel('x')
ylabel('y')

%%
x=[5 3 1 -2];
y=[6 5 3 1];
plot(x,y,'.','MarkerSize',20)
[m,b]=Min2(x,y);
f=m*x+b;
hold on
plot(x,f)
str = "m = "+m+", b = "+b;
title(str)
xlabel('x')
ylabel('y')

C = polyfit(x,y,3)
polyval(C,x)