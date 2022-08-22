#/usr/bin/python
import time
startTime = time.time()

#myList = [23,7,32,99,4,15,11,20] #array
myList = [100,93,81,73,62,55,41,33]

#function
def mergeSort(_myList):
    if len(_myList) > 1:
        mid = len(_myList) // 2
        left = _myList[:mid]
        right = _myList[mid:]

        #recusive call on each half
        mergeSort(left)
        mergeSort(right)

        #two iterators for traversing the two halves
        i = 0
        j = 0

        #iterator for the main list
        k = 0

        while i < len(left) and j <len(right):
            if left[i] <= right[j]:
                #the value from the left half has been used
                _myList[k] = left[i]
                #move the iterator forward
                i += 1
            else:
                _myList[k] = left[i]
                j += 1
                #move to the next slot
        while j < len(right):
            _myList[k]=right[j]
            j += 1
            k += 1


#call function
mergeSort(myList)
print('Sorted Array in Ascending Order:')
print(myList)
print('Process finished in %s seconds!'% (time.time() - startTime))