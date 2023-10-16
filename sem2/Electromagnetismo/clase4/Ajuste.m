function [E,E2] = Ajuste(x,y,x2,y2,n)
    p=polyfit(x,y,n);
    yy=polyval(p,x);
    hold on
    plot(x,yy,'-k')
    E = mse(y-yy);
    plot(x2,y2,'.m','MarkerSize',15)
    yy2=polyval(p,x2);
    plot(x2,yy2,'-g')
    E2 = mse(y2-yy2);
end