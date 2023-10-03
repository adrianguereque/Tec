%---Método de Jacobi
A=[5 -3 1;2 4 -1;2 -3 8];
b=[5 6 4]';
x=[1 1 1]';
tol=0.0001;
m=20;
metjacobi(A,b,x,tol,m)
%% ---Método de Gauss Seidel
A=[5 -3 1;2 4 -1;2 -3 8];
b=[5 6 4]';
x=[1 1 1]';
tol=0.0001;
m=20;
metgaussseidel(A,b,x,tol,m)
