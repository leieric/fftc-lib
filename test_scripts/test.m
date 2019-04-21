clear

N = 128;
% t = (0:N-1)';
% x = sin(t);



[A,B] = fftc_lib.singleBfly(3+1i, 5+1i, 50, N)

% tic
% for i=1:500
%     xout = fftc_lib.fftc(x, N);
% end
% timeFFT = toc
% tic
% for i=1:500
%     xoutdft = fftc_lib.slow_dft(x,N);
% end
% timeDFT = toc
% xoutfft = fft(x);
% 
% error = mean(abs(xout - xoutfft))