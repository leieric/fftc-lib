clear

N = 8;
t = (0:N-1)';
x = sin(t);

[A,B] = fftc_lib.singleBfly(3+2j, 3+2j, 3, N);

xout = fftc_lib.fftc(x, N)
xoutdft = fftc_lib.slow_dft(x,N)
xoutfft = fft(x)

error = mean(abs(xout - xoutfft))