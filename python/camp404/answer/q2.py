def userAuthentication():
    password = input('Input Passwod\n')
    if (password == 'rezimaulana10'):
        return print('Anda berhasil login!\n')
    else:
        print('Password Salah\n')
        tryAgain()

def tryAgain():
    reEnter = input('Coba lagi? Y/T\n')
    if (reEnter == 'Y'):
        userAuthentication()
    elif (reEnter == 'T'):
        pass
    else:
        tryAgain()

userAuthentication()