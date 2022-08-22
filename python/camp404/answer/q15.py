import time
startTime = time.time()

myList = [1,5,10,15,20,25,30,2,6,8,9] #array
search = int(input('Input number to search!\n')) #data to search

#function
def searchNumber(_myList, _search):
    counter = 0
    while counter != len(_myList):
        if _myList[counter] == _search:
            result = counter
        counter += 1
    return result

#call function
try:
    searchResult = searchNumber(myList, search)
    if search in myList:
        print('Number %s in index %s\n'% (search,searchResult))
except:
    print('Number not found!\n')
print('Process finished in %s seconds!'% (time.time() - startTime))