function [m,b] = Min2(x,y)
    sumxy=sum(x.*y);
    sumx=sum(x);
    sumy=sum(y);
    sumx2=sum(x.^2);
    n=numel(x);
    m=(sumxy-sumx.*sumy/n)/(sumx2-(sumx.^2)/n);
    b=(sumy/n) - m.*sumx/n;
end