# cook your dish here
# -*- coding: utf-8 -*-
"""
Created on Sat Jun 13 16:19:35 2020

@author: ALQUAMA
"""
def degdiv(js):
    count=0
    while(js%2==0):
        js=js/2
        count=count+1
    return (count)
t=int(input())
while t:
    digts=0
    count=0
    ts=int(input())
    digts=degdiv(ts)+1
    if(ts%2!=0):
        count=(ts-1)/2
    else:
        count=(ts-(ts%(2**digts)))/(2**digts)
    print(int(count))
    t=t-1