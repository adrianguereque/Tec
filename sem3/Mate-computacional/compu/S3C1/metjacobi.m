function metjacobi(A,b,x,tol,m)
n=length(x);
for k=1:m
    w=x;
    for i=1:n
        s=A(i,1:i-1)*w(1:i-1)+A(i,i+1:n)*w(i+1:n);
        x(i)=(b(i)-s)/A(i,i);
    end
    if norm(w-x,inf)<tol
       return
    end
    fprintf('\n la solucion del sistema en la iteracion %4.0f\n',k)
    for i=1:n
        fprintf(' x(%1.0f)=%6.8f\n',i,x(i))
    end
end
