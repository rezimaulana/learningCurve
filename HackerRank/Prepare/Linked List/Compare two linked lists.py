#!/bin/python3

import os
import sys

class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_node(self, node_data):
        node = SinglyLinkedListNode(node_data)

        if not self.head:
            self.head = node
        else:
            self.tail.next = node


        self.tail = node

def print_singly_linked_list(node, sep, fptr):
    while node:
        fptr.write(str(node.data))

        node = node.next

        if node:
            fptr.write(sep)

# Complete the compare_lists function below.

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#
def compare_lists(llist1, llist2):
    head1=llist1
    head2=llist2
    arr1=[]
    arr2=[]
    while head1:
        arr1.append(head1.data)
        head1=head1.next
    while head2:
        arr2.append(head2.data)
        head2=head2.next
    if len(arr1)!=len(arr2):
        return 0
    else:
        for i in range(len(arr1)):
            if arr1[i]==arr2[i]:
                return 1
            else:
                return 0

if __name__ == '__main__':