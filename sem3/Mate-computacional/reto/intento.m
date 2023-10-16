% Definir el número de puntos deseados para cada ecuación
num_puntos1 = 28; % Para y = 0.11x + 10 (0 a 28)
num_puntos2 = 4;  % Para y = 0.75x - 8 (29 a 32)
num_puntos3 = 28; % Para y = 0.19x + 9.97 (33 a 60)

% Crear un vector de valores de x para cada ecuación
x1 = linspace(0, 28, num_puntos1);
x2 = linspace(29, 32, num_puntos2);
x3 = linspace(33, 60, num_puntos3);

% Calcular los valores correspondientes de y para cada ecuación
y1 = 0.11 * x1 + 10;
y2 = 0.75 * x2 - 8;
y3 = 0.19 * x3 + 9.97;

% Combinar los vectores de y de todas las ecuaciones
y_combined = [y1, y2, y3]

% Ahora, 'y_combined' contiene todos los valores de y para las tres ecuaciones en el rango especificado
