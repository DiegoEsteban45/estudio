def swap(array,min,i):
    temporal=[]     
    temporal.append(array[i])    
    array[i]=array[min]
    array[min]=temporal[0] 
def valor_minimo(list,largo,aumento):    
    min_i=(aumento)
    min=list[0+aumento]   
    for i in range((1+aumento),largo,1):
        if min>list[i]:
           min=list[i]
           min_i=i
    return min_i
def entrada (void_list,num):
    while(True):
        try:
            num=int(input('write a number,:'))
            if num not in void_list: 
                void_list.append(num)
            else:
                print('write other number')
        except EOFError:
             return void_list
             break
def valor_minimo_smart(list,largo,aumento):  
    min=list[aumento]    
    min_i=(aumento)
    i=(1+aumento) 
    if min==list[largo-1]:
        return -1
    for i in range(i,largo,1):
        if aumento == largo-2 and i==largo-1:
            return -1
            break
        if min>list[i]:
           min=list[i]
           min_i=i 
        elif min_i==aumento and i==largo-1:
            aumento=aumento+1    
            i=(1+aumento)  
    return min_i
