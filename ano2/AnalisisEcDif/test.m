% Define the time span for the simulation
tspan = [0, 500000];  % Adjust the time span as needed

% Define the initial salt concentration (A0)
A0 = 0;  % Initial salt concentration (assuming freshwater initially)

% Define the differential equation function
dAdt = @(t, A) 50 - (A * 2.09e8) / (1.87e13);

% Use ODE solver to solve the differential equation
[t, A] = ode45(dAdt, tspan, A0);

% Create the plot
plot(t, A, 'b', 'LineWidth', 2);
xlabel('Time (t)');
ylabel('Salt Concentration (A)');
title('Salt Concentration in Freshwater Lake Over Time');
grid on;

% Display the plot
