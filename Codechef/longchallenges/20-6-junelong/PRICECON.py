# cook your dish here
# -*- coding: utf-8 -*-
"""
Created on Fri Jun 12 19:46:03 2020

@author: ALQUAMA
"""
from bisect import bisect 
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
    n,k=map(int,input().split())
    data=intInput()
    data.sort()
    noItems=len(data)-bisect(data,k)
    netcostPrice=sum(i for i in data if i>k)
    print(netcostPrice-(k*noItems))
    t=t-1