# -*- coding: utf-8 -*-
"""
Created on Sat Jun 13 20:28:47 2020

@author: ALQUAMA
"""
def degdiv(js):
    count=0
    while(js%2==0):
        js=js/2
        count=count+1
    return (count)
t1=100
t2=100000
if(degdiv(t1)>degdiv(t2)):
    print("ok")
print(degdiv(t1))
print(degdiv(t2))