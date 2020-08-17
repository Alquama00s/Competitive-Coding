# -*- coding: utf-8 -*-
"""
Created on Wed Jun 17 21:44:02 2020

@author: ALQUAMA
"""

# -*- coding: utf-8 -*-
"""
Created on Sun Jun 14 18:26:15 2020

@author: ALQUAMA
"""
import collections
#spaced separeted integers
def intInput():
    integers=[]
    tempstring=""
    string=input()
    for i in string:
        tempstring=tempstring+i
        if i==' ':
            integers.append(int(tempstring))
            tempstring=""
    integers.append(int(tempstring))
    tempstring=""
    return (integers)
#---end-----------prototype:t=intInput()
def mult(iin,out):
    global attempt
    attempt[0]=3
    c=1
    for j in range(3):
        attempt[c]=3
        if(iin[j]!=iin[j+1]):
            m=(out[j]-out[j+1])/(iin[j]-iin[j+1])
            a=(iin[j]*out[j+1]-iin[j+1]*out[j])/(iin[j]-iin[j+1])
            print(m) #qc
            print(a) #qc
            if(((iin[j+2]*m+a)==out[j+2])or (iin[j+2]==out[j+2]) or (iin[j+2]+a==out[j+2]) or (iin[j+2]*m==out[j+2]) )and(m-int(m))==0 and(a-int(a))==0:
                attempt[c]=2
                print(iin[j+2],out[j+2])
            if(m==1):
                attempt[c]-=1
            if(a==0):
                attempt[c]-=1
        print(attempt[c]) #qc
        print("--------") #qc
        c+=1
t=int(input())
while t:
    attempt=[0,0,0,0]
    datain=intInput()
    dataout=intInput()
    datain.append(datain[0])
    dataout.append(dataout[0])
    datain.append(datain[1])
    dataout.append(dataout[1])
    mult(datain,dataout)
    attempt.sort()
    print(attempt[0])
    t=t-1