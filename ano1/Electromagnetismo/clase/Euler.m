function [x,y] = Euler(f,y0,a,b,h)
    x = a:h:b;
    n = length(x);
    y = zeros(1,n);
    y(1) = y0;
   
for i = 1:n-1
    y(i+1) = y(i) + f(x(i),y(i))*h;
end

end