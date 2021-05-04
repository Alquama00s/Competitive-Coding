# -*- coding: utf-8 -*-
"""
Created on Thu Jun 18 11:19:55 2020

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
#check how many elemebts of in out are equal
def check_eq(iin,out):
    global index
    count=0
    for i in range(3):
        if(iin[i]==out[i]):
            index.append(i)
            count+=1
    return count
def seg():
    global eql,answer
    if(eql==3):
        answer=0
    elif(eql==2):
        answer=1
    elif(eql==1):
        one()
    else:
        zero()
def one():
    global answer,index,datain,dataout
    datain=datain[:3]
    dataout=dataout[:3]
    datain.pop(index[0])
    dataout.pop(index[0])
    answer=2
    if((datain[0]-dataout[0])==(datain[1]-dataout[1])):
        answer-=1
        return None
    elif(datain[0]!=0 and datain[1]!=0):
        div=dataout[0]/datain[0]
        if(div-int(div)==0) and (div==(dataout[1]/datain[1])):
            answer-=1
def zero():
    #print("in") #qc
    global answer,index,datain,dataout,sub,div
    answer=3
    #print(sub,div) #qc
    if(sub.count(sub[0])==3) or (((div[0]-int(div[0]))==0) and((div.count(div[0]))==3) and div[0]!=0):
        answer=1
        return None
    else:
        thirdcheck(datain,dataout)
    #print("out") #qc
def thirdcheck(iin,out):
    #print("jara1")#qc
    global answer,sub,div
    attempt=[0,0,0,0]
    attempt[0]=3
    c=1
    #case1,2,3
    for j in range(3):
        attempt[c]=3
        if(iin[j]!=iin[j+1]):
            m=(out[j]-out[j+1])/(iin[j]-iin[j+1])
            a=(iin[j]*out[j+1]-iin[j+1]*out[j])/(iin[j]-iin[j+1])
            #print(m) #qc
            #print(a) #qc
            if(((iin[j+2]*m+a)==out[j+2]) or (iin[j+2]+a==out[j+2]) or (iin[j+2]*m==out[j+2]) )and(m-int(m))==0 and(a-int(a))==0:
                attempt[c]=2
                #print(iin[j+2],out[j+2])
        #print(attempt) #qc
        #print("--------") #qc
        c+=1
    attempt.sort()
    answer=attempt[0]
    #case4,5
    if(answer==3):
        for i in range(3):
            if(sub.count(sub[i])==2) or (div.count(div[i])==2) and (div[i]-int(div[i])==0):
                answer=2
                return None
    #case6,7,8
    if(answer==3):
        #print("jara")#qc
        em=[]
        ea=[]
        for j in range(3):
            em=[]
            ea=[]
            ea.append(out[j]-iin[j])
            ea.append(out[j+1]-iin[j+1]) 
            if(iin[j]!=0)and(out[j]%iin[j]==0):
                em.append(out[j]/iin[j])
            if(iin[j+1]!=0)and(out[j+1]%iin[j+1]==0):
                em.append(out[j+1]/iin[j+1])
                #print(em) #qc
                #print(ea) #qc
                #print(iin[j+2],out[j+2])#qc
            if((iin[j+2]+ea[0]+ea[1])==out[j+2]):
                #print("2a")#qc
                answer=2
                return None
            else:
                if(len(em)==2):
                    if(iin[j+2]*em[0]*em[1]==out[j+2]):
                        #print("2m")#qc
                        answer=2
                        return None
                for i in range(len(em)):
                    for k in range(2):
                        if(((iin[j+2]*em[i])+ea[k])==out[j+2])or(((iin[j+2]+ea[k])*em[i])==out[j+2]):
                            #print("1a1m")#qc
                            answer=2
                            return None
                            
t=int(input())
while t:
    answer=0
    index=[]
    sub=[]
    div=[]
    datain=intInput()
    dataout=intInput()
    for i in range(3):
      sub.append(dataout[i]-datain[i])
      if datain[i]!=0:
          div.append(dataout[i]/datain[i])
      else:
          div.append(0)
    eql=check_eq(datain,dataout)
    datain.append(datain[0])
    dataout.append(dataout[0])
    datain.append(datain[1])
    dataout.append(dataout[1])
    seg()
    #print(eql,index)
    print(answer)
    t=t-1