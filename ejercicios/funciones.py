def swap(array,j,i):
    temporal=[]     
    temporal.append(array[i])    
    array[i]=array[j]
    array[j]=temporal[0] 
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
    min_in=(aumento) #indice
    i=(1+aumento) 
    if aumento==largo-1:
        return -1,-1
    for i in range(i,largo,1):
        if min>list[i]:
           min=list[i]
           min_in=i 
    if min_in==aumento:
        aumento=aumento+1
        return valor_minimo_smart(list,largo,aumento)     
    return min_in, aumento
def entrada_repeat (void_list,num):
    while(True):
        try:
            num=int(input('write a number,:'))
            void_list.append(num)
        except EOFError:
             return void_list
             break       
def binarisearchr(num,array,lim_inf,lim_sup,mid):
    mid=int((lim_inf+lim_sup)/2)
    if (array[mid]==num):
        return mid
    elif(lim_inf==mid or lim_sup==mid):
        return -1
    elif (num<array[mid]):
        lim_sup=(mid-1)
        return binarisearchr(num,array,lim_inf,lim_sup,mid) #POR LA IZQUIERDA 
    elif (num>array[mid]):
        lim_inf=(mid+1)
        return binarisearchr(num,array,lim_inf,lim_sup,mid) #POR LA DERECHA
def entrada_0 (void_list,num):
    while(True):
        try:
            num=int(input('write a number other than 0,:'))
            if num !=0: 
                void_list.append(num)
            else:
                print('write other number')
        except EOFError:
             return void_list
             break   



        
           