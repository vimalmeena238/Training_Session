                                % Non Local Means Algorithm
function im = NL_mean(im1)
h = waitbar(0,'Please wait...'); % Initialize Wait bar
if size(im1,3)==3                
    im1 = rgb2gray(im1);         % Convert RGB to gray scale
end
z=0;
if z==0                  % If z = 0 then add gaussian noise
    J = imnoise(im1,'gaussian',0,0.01);
end 
                         
[m,n] = size(J);
im = zeros(m,n,'double');     % Output of the NL_Mean 
J = double(J);                % Noisy image
im1 = double(im1);            % Convert uint8 to double 
im1 = padarray(im1,[21,21]);  % Add padding of 21x21 matrix
J = padarray(J,[21,21]);      % Add padding of 21x21 matrix
im = padarray(im,[21,21]);    % Add padding of 21x21 matrix
 B = im2col(J,[5,5],'sliding');  % Convert 2D matrix to 1D column
 
 % Gaussian distribution in 2D matrix of 5x5
 G = zeros(5,5);
    G_sum = 0;            
    sig = 1;                 % standard deviation of distribution 
    for i=1:5
        for j=1:5
            G(i,j)=exp(-((i-3)^2+(j-3)^2)/(2*((sig)^2)))/(2*pi*(sig)^2);
            G_sum = G_sum+G(i,j);
        end
    end
 Gg = im2col(G,[5,5]);       % Convert 2D matrix to 1D column for speeding up algorithm
 [mm,~] = size(J);          
for i=22:m+21                % Because of padding start the iteration from (21,21)
    steps = m+1;             % Number of steps for wait bar
    waitbar((i-21) / steps) 
    for j=22:n+21            
       wpq =0;              
       W_sum =0;
       sum_wpq = 0;
       N = double(B(:,(j-3)*(mm-4)+i-2));
       l=0;
       N_d = zeros(25,441); 
       jj = zeros(1,441);
      for p=i-10:i+10
            for q=j-10:j+10
                l=l+1;
                N_d(:,l) = N-B(:,(q-3)*(mm-4)+p-2); % Difference between 5x5 windows in the image
                jj(1,l) = J(p,q);    % All the intensity values of pixels in 5x5 window around pixel J(p,q)
            end
      end
      N_d = N_d.*N_d;
      wpq = sum(N_d.*Gg)/G_sum;      % Euclidean norm
      sum_wpq = sum(exp(-wpq/200));   % SUm of all the weights
      W_sum =sum(exp(-wpq/200).*jj);  % Weighted Intensity of pixel J(p,q)
       
        im(i,j)=W_sum/sum_wpq;       % Average Intensity stored at location (i,j)
    end
end
      close(h)                       % Close Wait bar
im = im(21:end-22,21:end-22);        % Remove padding of output image
end

                    
