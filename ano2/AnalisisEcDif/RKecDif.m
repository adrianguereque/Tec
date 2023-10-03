f0 = 209000;  
Cs = 35;      
Vd = 18.7e9;  
Cd0 = 0;      
t_final = 365 * 24 * 3600;  
delta_t = 3600;  

t_values = [0];
Cd_values = [Cd0];

t = 0;
Cd = Cd0;
while t < t_final
    dCd_dt = (f0 * Cs - f0 * Cd) / Vd;
    Cd = Cd + dCd_dt * delta_t;
    t = t + delta_t;
    t_values = [t_values, t];
    Cd_values = [Cd_values, Cd];
end

figure;
plot(t_values, Cd_values);
xlabel('Tiempo (s)');
ylabel('Concentración de Sal (kg/m^3)');
title('Evolución de la Concentración de Sal en el Lago del Cráter');