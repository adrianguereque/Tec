function metgaussseidel(A,b,x,tol,m)
n= length(x);
for k=1:m
    w=x;
    for i=1:n
        s=A(i,1:i-1)*x(1:i-1)+A(i,i+1:n)*x(i+1:n);
        x(i)=(b(i)-s)/A(i,i);
    end
    if norm(x-w,inf)<tol
        return
    end
    fprintf('\n la solución del sistema en la iteración %4.0f\n',k)
    for i=1:n
      fprintf(' x(%1.0f)=%6.8f\n',i,x(i))
    end
end