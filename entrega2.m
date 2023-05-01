clear;
clc;
% valor de las cargas
q1 = 5 * 10^-6;
q2 = -5 * 10^-6;

d1 = 1; %distancia entre las cargas positivas en el eje y
d2 = 1; %distancia entre las cargas negativas

xq1 = -2; 
yq1 = -1*d1:d1:1*d1; 
xq2 = 2;
yq2 = -2*d2:d2:2*d2;

% Definir las constantes de Coulomb 
k = 9e9; % N m^2 / C^2

% Definir el rango de posiciones donde se calculará el campo eléctrico
[x,y] = meshgrid(-5:0.1:5);

% Inicializar las componentes del campo eléctrico
[Ex,Ey] = meshgrid(-5:0.1:5);

% Calcular el campo eléctrico en cada punto del rango
for i = 1:length(x)
    for j = 1:length(x)
        Ex(i,j) = 0;
        Ey(i,j) = 0;
        for l = 1:length(yq1)
            r1 = sqrt((x(i, j)-xq1)^2 + (y(i, j)-yq1(l))^2); % Distancia a la carga 1
            E1 = k*q1/r1^2; % Magnitud del campo eléctrico de la carga positiva
            theta1 = atan2((y(i, j)-yq1(l)),(x(i, j)-xq1)); % Ángulo entre el vector y el eje x
            

            r2 = sqrt((x(i, j)-xq2)^2 + (y(i, j)-yq2(l))^2); % Distancia a la carga 2
            E2 = k*q2/r2^2; % Magnitud del campo eléctrico de la carga negativa
            theta2 = atan2((y(i, j)-yq2(l)),(x(i, j)-xq2)); % Ángulo entre el vector y el eje x

            Ex(i,j)=Ex(i,j) + E1*cos(theta1) + E2*cos(theta2);
            Ey(i,j)=Ey(i,j) + E1*sin(theta1) + E2*sin(theta2);
        end
    end
end
streamslice(x, y, Ex, Ey, 2)
hold on
%Agregar los graficos de las cargas positivas
r=0.3;
for x = xq1
    for y = yq1
        xi = x;
        yi = y;
        th = 0:pi/50:2*pi;
        xunit = r * cos(th) + xi;
        yunit = r * sin(th) + yi;
        fill(xunit, yunit, 'g');
        text(xi, yi, '+', 'HorizontalAlignment', 'center', 'Color', 'k');
        hold on; 
    end
end
%Agregar los graficos de las cargas negativas
for x = xq2
    for y = yq2
        xi = x;
        yi = y;
        th = 0:pi/50:2*pi;
        xunit = r * cos(th) + xi;
        yunit = r * sin(th) + yi;
        fill(xunit, yunit, 'b');
        text(xi, yi, '-', 'HorizontalAlignment', 'center', 'Color', 'w');
        hold on; 
    end
end