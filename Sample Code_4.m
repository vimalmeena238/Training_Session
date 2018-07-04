clear all; clc;
                            % Calculating the Most energy efficient direction to move for robotic arm with any number of DOF
data = readtable('DH.txt','Format','%s%s%s%s');
[dof,~] = size(data);
dof=dof-1;
fprintf('Degree of Freedom : %d',dof);
mat = data{1:dof+1,{'a','alpha','d','theta'}};
matd = str2double(mat);
[r,c] = find(isnan(matd));
siz = size(r); 

for i=1:siz(1)
    varii(i,1) = mat(r(i,1),c(i,1));
end
syms(varii(:,1));
syms a alpha d theta;
rad = pi()/180;
T =           [ cos(rad*theta) -sin(rad*theta) 0 a;
                sin(rad*theta)*cos(rad*alpha) cos(rad*theta)*cos(rad*alpha) -sin(rad*alpha) -d*sin(rad*alpha);
                sin(rad*theta)*sin(rad*alpha) cos(rad*theta)*sin(rad*alpha)  cos(rad*alpha)   d*cos(rad*alpha);
                 0                              0                  0         1];
f(a,alpha,d,theta) = T; 
Ton = eye(4);
link = sym('pos',[dof 3]);
for i=1:dof+1
    if (isnan(matd(i,1))) 
        x = mat(i,1);  
    else
        x = matd(i,1);
    end
    if (isnan(matd(i,2))) 
        y = mat(i,2);  
    else
        y = matd(i,2);
    end
    if (isnan(matd(i,3))) 
        z = mat(i,3);  
    else
        z = matd(i,3);
    end
    if (isnan(matd(i,4))) 
        w = mat(i,4);  
    else
        w = matd(i,4);
    end
    T_mat = f(x,y,z,w);
    Ton = Ton*T_mat;
        link(i,:) = Ton(1:3,4);

end
Ton = simplify(Ton);
EE_Cord = sym('cord',[3 1]);
EE_Cord = link(i,:)';
Jacobian = sym('J',[3 dof]);


x=1;

for i=1:siz(1)
    if c(i,1)>2
    vari(x,1) = mat(r(i,1),c(i,1));
    x=x+1;
    end
end
for i=1:3
    for j=1:dof
        Dif = diff(EE_Cord(i,1),vari(j,1));
        Jacobian(i,j) = Dif;
    end
end

thetas = readtable('theta.txt');
[ntheta,~] = size(thetas);
theta_mat = thetas{1:ntheta,vari};
for i=1:ntheta
    v_val = theta_mat(i,:);
   ee_cord = double(subs(EE_Cord,vari,v_val'));
   J = double(subs(Jacobian,vari,v_val'));
       J=J*J';
[U,S,V] = svd(J);

Linkrefcord = double(subs(link, vari,zeros(siz)));
Linkcord = double(subs(link,vari,v_val'));
plot3([Linkcord(:,1) Linkrefcord(:,1)],[Linkcord(:,2) Linkrefcord(:,2)],[Linkcord(:,3) Linkrefcord(:,3)],'o');
hold on;
line([Linkcord(:,1) Linkrefcord(:,1)],[Linkcord(:,2) Linkrefcord(:,2)],[Linkcord(:,3) Linkrefcord(:,3)]);
hold on;
sigma = diag(S);
[X,Y,Z]= ellipsoid(ee_cord(1),ee_cord(2),ee_cord(3),200*sigma(1),200*sigma(2),200*sigma(3));
Ss = surfl(X,Y,Z);
ang = atan2d(U(2,1),U(1,1));
rotate(Ss,[0 0 1],ang,[ee_cord(1) ee_cord(2) ee_cord(3)]);
V
hold on;
end

