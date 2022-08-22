score = int(input('Masukan Score\n'))
match score:
    case 1000:
        print('Raja Ular')
    case 500:
        print('Jagoan Ular')
    case _:
        print('Ular Tangguh')
