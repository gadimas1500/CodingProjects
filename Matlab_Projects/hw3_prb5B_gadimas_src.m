%Gabriel Dimas

[x,y] = meshgrid(-10:1:10, -10:1:10);


m=y.*(3-(x.*y));
L = sqrt(1+m.^2);
x1 = [0:0.1:10];
y1 = -1.*(3*log(x1)+100);
y3 = -1.*(3*log(x1)+1);



quiver(x,y,1./L,m./L)
plot(x1, y1)
plot(x1, y2)
plot(x1, y3)

