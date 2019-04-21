clear;
currentDir = pwd;
fileName = 'fftTest_256.csv';
testDir = [currentDir, '\..\data\' fileName];
data = csvread(testDir);

[m, n] = size(data);
N = data(1, 1);
for i = 2:(m-1)/4+1
    idx = (i-2)*4+1;
    input_vec = data(idx+1, :) + j*data(idx+2, :);
    output_fp = data(idx+3, :) + j*data(idx+4, :);
    output_mag_fp(i-1, :) = abs(output_fp);
    
    % Floating point values
%     output_float = fftc_lib.fftc(input_vec, N);
    output_float = fft(input_vec, N);
    output_mag_float(i-1, :) = abs(output_float);
    
%     error(i, :) = abs(output_mag_fp - output_mag_float)./output_mag_float;
end

for i = 1:(m-1)/4
    figure(i)
    plot(output_mag_fp(i, :), 'linewidth', 1.5), hold on
    plot(output_mag_float(i, :), '--', 'linewidth', 1.5), hold on
    xlabel('N')
    ylabel('Magnitude')
    legend('Floating Point', 'Fixed Point')
    grid on, grid minor
    hold off
end



