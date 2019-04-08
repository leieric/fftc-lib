clear



[A,B] = singleBfly(3+2j, 3+2j, 3    , 8)

function [A,B] = singleBfly(a, b, k, N)
    A = a + b*exp(1i*2*pi*k/N);
    B = a - b*exp(1i*2*pi*k/N);
end

% function output_vec = fftStage(input_vec, num_points, N)
%     i = 0, j=0;
%     Nover2 = num_points/2;
%     k_factor = N/num_points;
%     
%     for i=0:num_points:N-1
%        for j=0:Nover2-1 
%            [A,B] = singleBfly(input_vec(
%        end
%     end
% end