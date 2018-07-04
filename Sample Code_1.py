import numpy as np
import sys
import os, os.path
import cv2
import csv
from numpy import linalg as LA

#imageDir = '/home/mike/Desktop/Database/'
imageDir = 'H:\UGP\Face_Rec\Database\\'

#Calculating average image of all samles
Avg_img = np.zeros((112,92))
# number of samples
M = 0         
for FP in sorted(os.listdir(imageDir)):
    num = 0
    for IP in sorted(os.listdir(imageDir+FP)):
        img = np.array(cv2.imread(imageDir+FP+'\\'+IP,0))
        Avg_img = Avg_img + img
        if num== 4:
           break
        num=num+1
        M = M+1
        continue
    continue
Avg_img = Avg_img/M
# Calculating image covariance matrix
G_l = np.zeros((92,92))
for FP in sorted(os.listdir(imageDir)):
    num = 0
    for IP in sorted(os.listdir(imageDir+FP)) :
        img = np.array(cv2.imread(imageDir+FP+'\\'+IP,0))
        meandiff = img-Avg_img
        G_l = G_l + np.dot(np.transpose(meandiff), meandiff)
        if num==4:
           break
        num=num+1
        continue
    continue
G_l = G_l/M
print M,num
w, v = LA.eig((G_l))
wn = np.array(w)
vn = np.array(v)
opv = vn[:,:5]

np.savetxt('Optvec.txt',opv)
zp =0
for FP in sorted(os.listdir(imageDir)):
    num = 0
    
    for IP in sorted(os.listdir(imageDir+FP)) :
        img = np.array(cv2.imread(imageDir+FP+'\\'+IP,0))
        fmatrix = np.transpose(np.dot(img,opv))
        FSD  = fmatrix.reshape(560,1).tolist()
        l_vector = []
        l_vector = list([zp])
        if num==4:
           break
        num=num+1
        zp=zp+1
        l_vector.append(FP)
        l_vector.extend(FSD)
        with open('fvector.csv', 'a') as csvfile:
             writer = csv.writer(csvfile)
             writer.writerow(l_vector)
        #print IP,index
        continue
    continue
print sorted(os.listdir(imageDir+FP)) 

