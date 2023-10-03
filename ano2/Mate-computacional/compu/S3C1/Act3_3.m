%% 1
A=[3 -1 -1;-1 3 1;2 1 4];
b=[1 3 7]';
x=[0 0 0]';
tol=0.0001;
m=20;
metjacobi(A,b,x,tol,m)
metgaussseidel(A,b,x,tol,m)

%% 2
A=[3 -0.1 -0.2;0.1 7 -0.3;0.3 -0.2 10];
b=[7.85 -19.3 71.4]';
x=[0 0 0]';
tol=0.0001;
m=20;
metjacobi(A,b,x,tol,m)
metgaussseidel(A,b,x,tol,m)

%% 3
A=[2 -5 3;-3 1 9;8 -4 -3];
b=[-1 9 14]';
x=[0 0 0]';
tol=0.0001;
m=20;
metjacobi(A,b,x,tol,m)
metgaussseidel(A,b,x,tol,m)

%% 4
A=[5 2 -3;2 10 -8;3 8 13];
b=[1 4 7]';
x=[0 0 0]';
tol=0.0001;
m=20;
metjacobi(A,b,x,tol,m)
metgaussseidel(A,b,x,tol,m)