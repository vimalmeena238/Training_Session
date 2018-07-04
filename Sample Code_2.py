import numpy as np
import sys
import os, os.path
import cv2
import csv
import time
from numpy import linalg as LA
start_time = time.time()
imageDir = 'H:\\UGP\\Face_Rec\\Database\\s16\\9.pgm'
X = np.loadtxt('H:\\UGP\\Final_Code\\Optvec.txt')
Sm_img = np.array(cv2.imread(imageDir,0))
fmatrix = np.transpose(np.dot(Sm_img,X))
FSD  = fmatrix.reshape(560,1)
Rname = []
Fvecn = np.zeros((160,560))
ind = 0
with open('H:\\UGP\\Final_Code\\fvector.csv') as f:
    reaer= csv.reader(f)
    for row in reaer:
        name = row[1]
        Fv = row[2:]
        Rname.append(name)
        col = 0
        for column in Fv:
            Fvecn[ind,col] = float(column.translate(None,"[],"))
            col = col + 1
            continue
        ind = ind + 1
        continue

Fvecdiff = np.zeros((160,1))
r=0
for row in Fvecn:
    Fvecdiff[r] = LA.norm(Fvecn[r,:]-np.transpose(FSD))
    r = r+1
    continue
 
print np.argmin(Fvecdiff)
#print Fvecdiff
print Rname[np.argmin(Fvecdiff)]    
print("--- %s seconds ---" % (time.time() - start_time))
