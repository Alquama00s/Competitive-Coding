# -*- coding: utf-8 -*-
"""
Created on Mon Apr 20 21:19:51 2020

@author: ALQUAMA
"""


t=int(input())
while t:
    n,q=map(int,input().split())
    final=0
    total=0
    temp=0
    while q:
        f,d=map(int,input().split())
        temp=final-f
        if temp<0:
            temp=temp*(-1)
        total=total+temp
        temp=d-f
        if temp<0:
            temp=temp*(-1)
        total=total+temp
        final=d
        q=q-1
    print(total)    
    t=t-1
    