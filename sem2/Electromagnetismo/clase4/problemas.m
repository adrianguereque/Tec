%% Problema 1
Matriz = readmatrix("PuntosEntrenaCurva1.csv");
x=Matriz(1,:);
y=Matriz(2,:);

Matriz2 = readmatrix("PuntosPruebaCurva1.csv");
x2=Matriz2(1,:);
y2=Matriz2(2,:);
plot(x,y,'.','MarkerSize',15)
hold on
for i=1:5
    [E(i),E2(i)] = Ajuste(x,y,x2,y2,i);
    Eprom(i)=(E(i)+E2(i))/2;
end
min(Eprom)

%% Problema 2
Matriz = readmatrix("PuntosEntrenaCurva2.csv");
x=Matriz(1,:);
y=Matriz(2,:);

Matriz2 = readmatrix("PuntosPruebaCurva2.csv");
x2=Matriz2(1,:);
y2=Matriz2(2,:);
plot(x,y,'.','MarkerSize',15)
for i=1:5
    [E(i),E2(i)] = Ajuste(x,y,x2,y2,i);
    Eprom(i)=(E(i)+E2(i))/2;
end
min(Eprom)

