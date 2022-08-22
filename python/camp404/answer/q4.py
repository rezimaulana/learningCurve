def inputUser():
    in1 = int(input('Bilangan Pertama\n'))
    in2 = int(input('Bilangan Kedua\n'))
    in3 = int(input('Bilangan Ketiga\n'))
    arr = []
    arr.append(in1)
    arr.append(in2)
    arr.append(in3)
    arr.sort(reverse=True)
    print(arr)
    
inputUser()