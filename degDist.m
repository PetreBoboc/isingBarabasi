dataX = dlmread('ddx.txt', ' ', 0, 0);
dataY = dlmread('ddy.txt', ' ', 0, 0);

figure
plot(dataX, dataY, "*")
xlabel('k')
ylabel('P(k)')

figure
loglog(dataX, dataY, "*")
xlabel('k')
ylabel('P(k)')
