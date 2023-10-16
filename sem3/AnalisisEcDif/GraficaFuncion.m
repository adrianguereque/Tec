% Define the x values (time) over a suitable range
x = 0:1000:1000000;  % Adjust the range as needed

% Calculate the corresponding values of y
y = 9.11e14 - 9.11e14 * exp(-1.12e-5 * x);

% Create the plot
plot(x, y, 'b', 'LineWidth', 2);
xlabel('Tiempo (s)');
ylabel('Cantidad de sal (g)');
title('Grafica de y = 9.11e14 - 9.11e14 * e^{-1.12e-5x}');
grid on;

% Display the plot
% Define the time values (t) over a suitable range
t = 0:1000:1000000;  % Adjust the range as needed

% Calculate the corresponding values of C(t)
C = 50 - 50 * exp(-1.12e-5 * t);

% Create the plot
plot(t, C, 'b', 'LineWidth', 2);
xlabel('Tiempo (s)');
ylabel('Concentracion de sal (g/L)');
title('C(t) = 50 - 50 * e^{-1.12e-5t}');
grid on;

% Display the plot

