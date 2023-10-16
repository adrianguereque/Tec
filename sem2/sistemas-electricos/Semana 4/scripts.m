
biseccion(0,1,0.01,x-cos(x))
biseccion(1,2,0.01,x*exp(x))
biseccion(1.2,2.2,0.01,x*log10(x))
biseccion(-4,-3,0.01, exp(0.3*x)-x^2)
biseccion(1,2,0.01,2*cos(x)-sqrt(x)/2)

newtonRaphson(0,15,0.01,x-cos(x))
newtonRaphson(1,15,0.01,x*exp(x))
newtonRaphson(1.2,15,0.01,x*log10(x))
newtonRaphson(-4,15,0.01, exp(0.3*x)-x^2)
newtonRaphson(1,15,0.01,2*cos(x)-sqrt(x)/2)