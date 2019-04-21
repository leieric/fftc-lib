clear;
currentDir = pwd;
filename = [currentDir, '\..\data\test_3_128.csv'];
data = csvread(filename);

[m, n] = size(data);
k = data(1, 1);
N = data(1, 2);
for i = 2:m
    a = data(i, 1) + j*data(i, 2);
    b = data(i, 3) + j*data(i, 4);
    A = data(i, 5) + j*data(i, 6);
    B = data(i, 7) + j*data(i, 8);
    
    % Floating point values
    [A_float, B_float] = fftc_lib.singleBfly(a, b, k, N);
    A_float_mag = abs(A_float);
    B_float_mag = abs(B_float);
    
    error(i, 1) = (A_float_mag - abs(A))/A_float_mag;
    error(i, 2) = (B_float_mag - abs(B))/B_float_mag;
end

figure(1)
plot(error)



