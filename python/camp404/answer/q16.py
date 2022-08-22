import time
startTime = time.time()

myList = [2,4,9,8,1,3,5,6,3] #array
search = int(input('Input number to search!\n')) #data to search

#function
def searchNumber(_myList, _search):
    found = False #condition that number is not found yet
    _myList.sort() #binary search to sort
    firstIndex = 0
    lastIndex = len(_myList)-1
    while firstIndex <= lastIndex and not found:
        middleIndex = (firstIndex + lastIndex) // 2
        if _myList[middleIndex] == _search:
            found = True
        else:
            if _search < _myList[middleIndex]:
                lastIndex = middleIndex -1
            else:
                firstIndex = middleIndex + 1
    return found

#call function
searchResult = searchNumber(myList, search)
if searchResult:
    print('Number %s is found!\n'% search)
else:
    print('Number %s not found!\n'% search)
print('Process finished in %s seconds!'% (time.time() - startTime))