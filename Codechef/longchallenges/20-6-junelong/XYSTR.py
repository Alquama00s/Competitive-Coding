# cook your dish here
# -*- coding: utf-8 -*-
"""
Created on Fri Jun 12 20:11:51 2020

@author: ALQUAMA
"""
def process():
    global string,count
    i=0
    while i<(len(string)-1):
        if(string[i]=='x'):
            if(string[i+1]=='y'):
                count=count+1
                i=i+2
            else:
                i=i+1
                
        elif(string[i]=='y'):
            if(string[i+1]=='x' ):
                count=count+1
                i=i+2
            else:
                i=i+1
                
    
    
t=int(input())
while t:
    count=0
    string=""
    string=input()
    process()
    print(count)
    t=t-1