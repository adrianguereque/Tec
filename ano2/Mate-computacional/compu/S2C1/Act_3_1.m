%Adrian Guereque de la Garza a01722394
%Act 3.1 matrices
%% parte 1
A = [3,-1,4,2];
B = [6,0,-1,4];
C = [-2,3,1,5];
a = A + C
b = -2.*B
c = C - B - 2.*A

%% parte 2
A = [1,-1,2;3,4,5;0,1,-1];
B = [0,2,1;3,0,5;7,-6,0];
C = [0,0,2;3,1,0;0,-2,4];
a = A - 2.*B
b = 4.*C - 2.*B + 3.*A
c = C - A - B
d = 3.*A - C

%% parte 3
A = [1;-2;4];
B = [0;-3;7];
C = [4;-1;5];
D = [6,0,-5;6,2,7];
a = (2.*A).*(3.*B);
b = (A - C).*(3.*B - 4.*A);
c = D*(3.*A - 5.*B + C) 

%% parte 4
A = [2,4,6;4,5,6;3,1,-2];
a = inv(A) % Diferentes maneras
a2 = adjoint(A)./ det(A)
a3 = A^-1

