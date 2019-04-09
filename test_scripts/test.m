clear

t = (0:7)';
x = sin(t);

[A,B] = fftc_lib.singleBfly(3+2j, 3+2j, 3, 8);

xout = fftc_lib.fftc(x, 8)
fft(x)