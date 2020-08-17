# -*- coding: utf-8 -*-
"""
Created on Sat Jun 13 15:50:08 2020

@author: ALQUAMA
"""

def process():
    global string,data
    revenu=[0,0,0]
    for i in data:
        if i==1:
            revenu[0]=revenu[0]+1
        elif i==2: 
            if revenu[0]>0:
                revenu[0]=revenu[0]-1
                revenu[1]=revenu[1]+1
            else:
                string="NO"
                break
        elif i==3:
            if revenu[1]>0:
                revenu[1]=revenu[1]-1
                revenu[2]=revenu[2]+1
            elif revenu[0]>1:
                revenu[0]=revenu[0]-2
                revenu[2]=revenu[2]+1
            else:
                string="NO"
                break
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
t=int(input())
while t:
    string="YES"
    n=input()
    data=intInput()
    data=[x/5 for x in data]
    process()
    print(string)
    t=t-1