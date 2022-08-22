#/usr/bin/python
import time
startTime = time.time()

myList = [100,93,81,73,62,55,41,33] #array
myListLen = len(myList) #array length

#function
def selectionSort(_myList, _myListLen):
    for step in range(_myListLen):
        min_idx = step
        for i in range(step + 1, _myListLen):
            print(_myList)
            # to sort in descending order, change > to < in this line
            # select the minimum element in each loop
            if _myList[i] < _myList[min_idx]:
                min_idx = i
        # put min at the correct position
        (_myList[step], _myList[min_idx]) = (_myList[min_idx], _myList[step])

#call function
selectionSort(myList, myListLen)
print('Sorted Array in Ascending Order:')
print(myList)
print('Process finished in %s seconds!'% (time.time() - startTime))