% limites
a = 0;
b = 28;
c = 32;
d = 60;

% Crear un vector de valores de x para cada ecuación
x1 = linspace(a, b, b-a); %   28 puntos de 0 a 28
x2 = linspace(b+1, c, c-b); % 4 puntos de 29 a 32
x3 = linspace(c+1, d, d-c); % 28 puntos de 33 a 60

% Calcular los valores 
% correspondientes de y 
% para cada ecuación
y1 = 0.11 * x1 + 10; 
y2 = 0.75 * x2 - 8;
y3 = 0.19 * x3 + 9.97;

% Combinar los vectores de
% y de todas las ecuaciones
y_combined = [y1, y2, y3];

%gráfica
st=20;
for i=1:60
    PC=[ y_combined(i); 0; i; 0];
    graficar(st,PC);
end

%Multiplicación de matrices
function resultado = multiplicar(matriz1,matriz2)
    r1=size(matriz1,1);
    c1=size(matriz1,2);
    c2=size(matriz2,2);
    resultado=zeros(r1,c2);
    for i = 1:r1
        for j = 1:c2
            res = 0;
            for k = 1:c1
                res=res+matriz1(i,k)*matriz2(k,j);
            end
            resultado(i,j)=res;
        end
    end
end

%Rotación alrededor de x
function resultado = rotX(punto, angx)
    Rx = [[1,0,0,0];
    [0,cos(deg2rad(angx)),-sin(deg2rad(angx)),0];
    [0,sin(deg2rad(angx)),cos(deg2rad(angx)),0];
    [0,0,0,1]];
    resultado= multiplicar(Rx,punto);
end
%Rotación alrededor de y
function resultado = rotY(punto, angy)
    Ry = [[cos(deg2rad(angy)),0,sin(deg2rad(angy)),0];
    [0,1,0,0];
    [-sin(deg2rad(angy)),0,cos(deg2rad(angy)),0];
    [0,0,0,1]];
    resultado = multiplicar(Ry,punto);
end

%Rotación alrededor de z
function resultado = rotZ(punto, angz)
    Rz = [[cos(deg2rad(angz)),-sin(deg2rad(angz)),0,0];
    [sin(deg2rad(angz)),cos(deg2rad(angz)),0,0];
    [0,0,1,0];
    [0,0,0,1]];
    resultado = multiplicar(Rz,punto);
end
%Traslación
function resultado = tras(punto, x, y, z)
    T = [[1,0,0,x];
    [0,1,0,y];
    [0,0,1,z];
    [0,0,0,1]];
    resultado = multiplicar(T,punto);
end
%Graficar
function graficar(step,punto)
    ang=0;
    listX=zeros(step+1);
    listY=zeros(step+1);
    listZ=zeros(step+1);
    for s = 1:step+1
        res = rotZ(punto,ang);
        listX(s)=res(1,1);
        listY(s)=res(2,1);
        listZ(s)=res(3,1);
        ang = ang + 360/step;
    end
    %plot3(listX,listY,listZ,'b');
    surf(listX,listY,listZ);
    hold on
end
