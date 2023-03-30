% Constants
k = 9e9; % Coulomb's constant

% Create a grid of points
[x, y] = meshgrid(-5:5);

% Initialize the electric field components
Ex = zeros(size(x));
Ey = zeros(size(y));

% Add charges
num_charges = 3; % number of charges
q = [1e-9, -2e-9, 3e-9]; % charge values in Coulombs
xq = [2, -2, 0]; % x-coordinates of charges
yq = [0, 0, 3]; % y-coordinates of charges

% Calculate the electric field at each point on the grid due to each charge
for i = 1:num_charges
    r = sqrt((x-xq(i)).^2 + (y-yq(i)).^2); % distance from charge i
    Ex = Ex + k*q(i)*(x-xq(i))./r.^3; % x-component of electric field due to charge i
    Ey = Ey + k*q(i)*(y-yq(i))./r.^3; % y-component of electric field due to charge i
end

% Plot the electric field as vectors
quiver(x, y, Ex, Ey) % plot the vectors
hold on
for i = 1:num_charges
    plot(xq(i), yq(i), 'o', 'MarkerSize', 10, 'LineWidth', 2) % plot each charge as a circle
end
xlim([-6 6]) % set the x-axis limits
ylim([-6 6]) % set the y-axis limits
grid on % show the grid
