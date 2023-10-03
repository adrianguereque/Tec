function [x,y] = RK2(f,y0,t0,tf,h)
x = t0:h:tf;
y = zeros(1,length(x));
y(1) = y0;

for i=1:length(x)-1
    k1 = h* f(x(i),y(i));
    k2 = h*f(x(i)+h/2,y(i)+k1/2);
    y(i+1) = y(i)+k2;

end

end