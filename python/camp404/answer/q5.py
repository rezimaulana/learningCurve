def weatherCheck():
    temp = int(input('Input Suhu'))
    if (temp <= 26):
        print('Cuaca Berawan\n')
    elif (temp > 26):
        print('Cuaca Cerah\n')

weatherCheck()