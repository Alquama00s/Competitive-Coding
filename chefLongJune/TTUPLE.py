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
t=int(input())
while t:
    datain=intInput()
    dataout=intInput()
    if(datain==dataout):
        attempt=0
    else:
        sub=[]
        div=[]
        attempt=3
        stat=0
        obj=zip(dataout,datain)
        for out,iin in obj:
            sub.append(out-iin)
            if iin!=0:
                div.append(out/iin)
            else:
                div.append(0)
        a=[item for item, count in collections.Counter(div).items() if count > 1]
        stat=2
        if(len(a)==0):
            a=[item for item, count in collections.Counter(sub).items() if count > 1]
            stat=1
        elif(a[0]-int(a[0]))>0 or a[0]==0:
            a=[item for item, count in collections.Counter(sub).items() if count > 1]
            stat=1
        if (len(a)!=0):
            if (stat==1 and sub.count(a[0])==3)or(stat==2 and div.count(a[0])==3):
                attempt=1
            else:
                sub.sort()
                div.sort()
                attempt=2
                if(stat==1 and sub[0]==0)or(stat==2 and div[0]==1):
                    attempt=1
    if (attempt==3):
        eo=[]
        temp=[]
        obj=zip(dataout,datain)
        if(datain[0]!=datain[1]):
            eo.append((dataout[0]-dataout[1])/(datain[0]-datain[1]))
        if(datain[1]!=datain[2]):
            eo.append((dataout[1]-dataout[2])/(datain[1]-datain[2]))
        if(datain[0]!=datain[2]):
            eo.append((dataout[0]-dataout[2])/(datain[0]-datain[2]))
        for i in eo:
            for out,iin in obj:
                temp.append(out-(iin*i))
                print(temp)
            if (temp.count(temp[0])==3) and (temp[0]>0):
                attempt=2
                print("ecase")
    print(attempt)
    t=t-1