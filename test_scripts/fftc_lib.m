classdef fftc_lib
    methods(Static)
        
        function [A,B] = singleBfly(a, b, k, N)
            A = a + b*exp(-1i*2*pi*k/N);
            B = a - b*exp(-1i*2*pi*k/N);
        end

        function output_vec = fftStage(input_vec, num_points, N)
            output_vec = input_vec;
            Nover2 = num_points/2;
            k_factor = N/num_points;
            for i=0:num_points:N-1
               for j=0:Nover2-1 
                   [output_vec(j+i+1),output_vec(j+i+Nover2+1)] = fftc_lib.singleBfly(input_vec(j+i+1), input_vec(j+i+Nover2+1), j*k_factor, N);
               end
            end
        end

        function output_vec = fftc(input_vec, N)
            output_vec = bitrevorder(input_vec);
            num_stages = log2(N);
            num_points = 2;
            for i=0:num_stages-1
               output_vec = fftc_lib.fftStage(output_vec, num_points, N);
               num_points = num_points * 2;
            end
        end
        
        function output_vec = slow_dft(input_vec, N)
            output_vec = zeros(N,1);
            for k=1:N
               for n=1:N
                   output_vec(k) = output_vec(k) + input_vec(n)*exp(-1i*2*pi*(k-1)*(n-1)/N);
               end
            end
        end
        
    end
end

