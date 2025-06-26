package com.unish.datastructures.linkedlist.singly;

public class CustomLinkedList {

    private Node head;
    private Node tail;

    private int size;

    public CustomLinkedList() {
        this.size=0;
    }

    public void insertFirst(int val){
        Node node = new Node(val);
        node.next = head;
        head = node;

        if (tail== null){
            tail = head;
        }

        size+=1;
    }

    public void insertLast(int val){
        Node node = new Node(val);

        if (tail == null){
            insertFirst(val);
            return;
        }

        tail.next = node;
        tail = node;
        size+=1;
    }

    public void insertAt(int val,int index){
        if (index == 0){
            insertFirst(val);
            return;
        }
        if (index == size){
            insertLast(val);
            return;
        }

        Node temp = head;

        for (int i = 1; i < index; i++) {
            temp = temp.next;
        }
        Node node = new Node(val);

        node.next = temp.next;
        temp.next = node;
        size++;
    }

    public void deletefirst(){
        head = head.next;
        if (head == null){
            tail = null;
        }
        size--;
    }


    public void deleteLast(){
        Node temp = head;

        for (int i = 1; i < size; i++) {
            temp = temp.next;
        }

        tail = temp.next;
        temp = temp.next;
        temp = null;
    }

    public  void  deleteAt(int index){
        Node prev = head;

        for (int i = 1; i < index; i++) {
            prev = prev.next;
        }

        Node del = prev.next;

        prev.next = del.next;

    }


    public void display(){
        Node temp = head;

        while (temp != null){
            System.out.print(temp.value+ " -> ");
            temp = temp.next;
        }
        System.out.println("[END]");
    }

    private class Node{
        private int value;
        private Node next;

        public Node(int value) {
            this.value = value;
        }

        public Node(int value, Node next) {
            this.value = value;
            this.next = next;
        }

        @Override
        public String toString() {
            return "[" +
                      value +
                    "]";
        }
    }
}
