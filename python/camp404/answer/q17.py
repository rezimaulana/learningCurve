#/usr/bin/python
import time
startTime = time.time()

#myList = [23,7,32,99,4,15,11,20] #array
myList = [100,93,81,73,62,55,41,33]

#function
def bubbleSort(_myList):
    for step in range(len(_myList)-1, 0, -1): #array length, startIndex, lastIndex    
        for i in range(step):
            if _myList[i]>_myList[i+1]:
                temp = _myList[i]
                _myList[i] = _myList[i+1]
                _myList[i+1] = temp



#call function
bubbleSort(myList)
print('Sorted Array in Ascending Order:')
print(myList)
print('Process finished in %s seconds!'% (time.time() - startTime))