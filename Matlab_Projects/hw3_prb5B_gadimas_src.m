%Gabriel Dimas

[x,y] = meshgrid(-10:1:10, -10:1:10);


m=y.*(3-(x.*y));
L = sqrt(1+m.^2);

quiver(x,y,1./L,m./L)