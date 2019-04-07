clear



[A,B] = singleBfly(3, 3, 1, 8)

function [A,B] = singleBfly(a, b, k, N)
    A = a + b*exp(1i*2*pi*k/N);
    B = a - b*exp(1i*2*pi*k/N);

end