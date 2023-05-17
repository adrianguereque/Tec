clear;
clc;
% Valor de las cargas
q1 = 1 * 10^-6;
q2 = -2    * 10^-6;

xq1 = -4;
yq1 = 0;
xq2 = 4;
yq2 = 0;

% Definir las constantes de Coulomb 
k = 9e9; % N m^2 / C^2

% Definir el rango de posiciones donde se calculará el campo eléctrico
[x,y] = meshgrid(-5:0.1:5);

% Inicializar las componentes del campo eléctrico
[Ex,Ey] = meshgrid(-5:0.1:5);

% Calcular el campo eléctrico en cada punto del rango

for i = 1:length(x)
    for j = 1:length(x)
        r1 = sqrt((x(i, j)-xq1)^2 + (y(i, j)-yq1)^2); % Distancia a la carga 1
        r2 = sqrt((x(i, j)-xq2)^2 + (y(i, j)-yq2)^2); % Distancia a la carga 2
        E1 = k*q1/r1^2; % Magnitud del campo eléctrico de la carga positiva
        E2 = k*q2/r2^2; % Magnitud del campo eléctrico de la carga negativa
        theta1 = atan2((y(i, j)-yq1),(x(i, j)-xq1)); % Ángulo entre el vector y el eje x
        theta2 = atan2((y(i, j)-yq2),(x(i, j)-xq2)); % Ángulo entre el vector y el eje x
        
            Ex(i,j)=E1*cos(theta1) + E2*cos(theta2);
            Ey(i,j)=E1*sin(theta1) + E2*sin(theta2);
       
    end
end

streamslice(x, y, Ex, Ey, 2)
hold on 

r = 0.2; % radio de los círculos
theta = linspace(0,2*pi,100); % valores de theta para dibujar el círculo
hold on
plot(xq1 + r*cos(theta), yq1 + r*sin(theta),'k','LineWidth',1);
plot(xq2 + r*cos(theta), yq2 + r*sin(theta),'k','LineWidth',1);

% Rellenar los círculos de color
fill(xq1 + r*cos(theta), yq1 + r*sin(theta),'r');
fill(xq2 + r*cos(theta), yq2 + r*sin(theta),'b');

hold on
xlim([-5 5])
ylim([-5 5])
