#!/bin/python3

import math
import os
import random
import re
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

# Complete the mergeLists function below.

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#
def mergeLists(head1, head2):
    p1=head1
    p2=head2
    node=SinglyLinkedList()
    while p1 and p2:
        if p1.data<=p2.data:
            node.insert_node(p1.data)
            p1=p1.next
        else:
            node.insert_node(p2.data)
            p2=p2.next
    while p1:
        node.insert_node(p1.data)
        p1=p1.next
    while p2:
        node.insert_node(p2.data)
        p2=p2.next   
    return node.head

if __name__ == '__main__':