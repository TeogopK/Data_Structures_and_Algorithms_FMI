# Complete the mergeLists function below.


#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#
def mergeLists(list1, list2):
    if not list1:
        return list2

    if not list2:
        return list1

    merged_head = SinglyLinkedListNode(0)
    if list1.data <= list2.data:
        merged_head = list1
        list1 = list1.next
    else:
        merged_head = list2
        list2 = list2.next

    merged_iter = merged_head
    while list1 and list2:
        if list1.data <= list2.data:
            merged_iter.next = list1
            list1 = list1.next
        else:
            merged_iter.next = list2
            list2 = list2.next
        merged_iter = merged_iter.next

    if list1:
        merged_iter.next = list1

    if list2:
        merged_iter.next = list2

    return merged_head
