#/usr/bin/python
import time
startTime = time.time()

#myList = [23,7,32,99,4,15,11,20] #array
myList = [100,93,81,73,62,55,41,33]

#function
def insertionSort(_myList):
    for index in range(1,len(_myList)):
        activeValue = _myList[index]
        position = index
        while position>0 and _myList[position-1]>activeValue:
            _myList[position]=_myList[position-1]
            position = position-1
            print(_myList)
        _myList[position] = activeValue



#call function
insertionSort(myList)
print('Sorted Array in Ascending Order:')
print(myList)
print('Process finished in %s seconds!'% (time.time() - startTime))