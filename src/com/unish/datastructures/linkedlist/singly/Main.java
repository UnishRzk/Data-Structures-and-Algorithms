package com.unish.datastructures.linkedlist.singly;

public class Main {
    public static void main(String[] args) {
        CustomLinkedList linkedList = new CustomLinkedList();

        linkedList.insertFirst(54);
        linkedList.insertFirst(43);
        linkedList.insertFirst(76);
        linkedList.insertFirst(5443);
        linkedList.insertFirst(32);

        linkedList.insertLast(45);

        linkedList.insertAt(1,1);

        linkedList.deletefirst();
        linkedList.deleteLast();
        linkedList.deleteAt(2);

        linkedList.display();
    }


}
