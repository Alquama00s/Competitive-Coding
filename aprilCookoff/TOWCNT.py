# -*- coding: utf-8 -*-
"""
Created on Mon Apr 20 22:12:39 2020

@author: ALQUAMA
"""
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
def check():
        global data,iin,fin,h,temp
        counter=0
        for i in range(len(data)):
            if data[i][1]<=fin and data[i][1]>=iin:
                if data[i][0]==0 and data[i][2]>=counter:
                    temp=temp+1
                    counter=data[i][2]
                if data[i][0]==1 and data[i][2]<=(h-counter):
                    temp=temp+1
        return 1
                

test=int(input())
data=[]
tempdata=[]
result=[]
while test:
    data=[]
    tempdata=[]
    result=[]
    temp=0
    iin=0
    fin=0
    h,n=map(int,input().split())
    while n:
        tempdata=intInput()
        data.append(tempdata)
        n=n-1
        
    for j in range(len(data)):
            if j==0 or j==n-1:
                temp=1
            else:
                temp=2
            if j+2<=n:
                for k in range(j+2,n):
                    iin=j+1
                    fin=n
                    if check()==1:
                        temp=temp+1
            if j-2>=0:
                for k in range(0,j-2):
                    iin=0
                    fin=j-1
                    if check()==1:
                        temp=temp+1
            result.append(temp)            
    for i in result:
        print(i,end=" ")
    test=test-1
            
                
                
                
            
        
        