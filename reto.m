% Constants
k = 9e9; % Coulomb's constant
arrow_scale = 0.5; % scale factor for arrow length (adjust as needed)
arrow_width = 2; % width of the arrow (adjust as needed)

% Create a grid of points
[x, y] = meshgrid(-5:5);

% Add charges
num_charges = 3; % number of charges
q = [1e-9, -2e-9, 3e-9]; % charge values in Coulombs
xq = [2, -2, 0]; % x-coordinates of charges
yq = [0, 0, 3]; % y-coordinates of charges

% Initialize the electric field components
Ex = zeros(size(x));
Ey = zeros(size(y));

% Calculate the electric field at each point on the grid due to each charge
for i = 1:num_charges
    r = sqrt((x-xq(i)).^2 + (y-yq(i)).^2); % distance from charge i
    Ex = Ex + k*q(i)*(x-xq(i))./r.^3; % x-component of electric field due to charge i
    Ey = Ey + k*q(i)*(y-yq(i))./r.^3; % y-component of electric field due to charge i
end

% Plot the electric field as vectors
quiver(x, y, Ex, Ey, arrow_scale, 'LineWidth', 1.5, 'MaxHeadSize', 0.5) % plot the vectors without scaling and with longer arrows
hold on

% Plot each charge as a circle and draw arrows pointing to or away from each charge
for i = 1:num_charges
    % plot each charge as a circle
    plot(xq(i), yq(i), 'o', 'MarkerSize', 10, 'LineWidth', 2)
    
    % calculate the direction of the arrow based on the sign of the charge
    if q(i) > 0
        dir = [1 0]; % arrow points to the right for positive charges
    else
        dir = [-1 0]; % arrow points to the left for negative charges
    end
    
    % calculate the start and end points of the arrow
    arrow_start = [xq(i), yq(i)];
    arrow_end = arrow_start + dir * arrow_scale * 2; % multiply by 2 to make the arrows longer
    
    % plot the arrow
    quiver(arrow_start(1), arrow_start(2), arrow_end(1)-arrow_start(1), arrow_end(2)-arrow_start(2), ...
        'LineWidth', arrow_width, 'MaxHeadSize', 0.5, 'Color', 'r');
end

% Set the axis limits and show the grid
xlim([-6 6])
ylim([-6 6])
grid on


