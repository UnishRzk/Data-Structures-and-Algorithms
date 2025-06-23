package com.unish.datastructures.queue;

public class CustomQueue {

    private static final int DEFAULT_SIZE = 10;
    protected int[] data;
    int end =  0;


    public CustomQueue() {
        this(DEFAULT_SIZE);
    }

    public CustomQueue(int size) {
        this.data = new int[size];
    }

    public void enqueue(int val) throws QueueException{
        if (isFull()){
            throw new QueueException("Queue is Full");
        }
        data[end++] = val;
    }

    public int dequeue() throws QueueException{
        if (isEmpty()){
            throw new QueueException("Queue is Empty");
        }
        int removed = data[0];

        for (int i = 1; i <= end; i++) {
            data[i-1] = data[i];
        }
        end--;
        return removed;
    }

    public int peek() throws QueueException{
        if (isEmpty()){
            throw new QueueException("Queue is Empty");
        }
        return data[0];
    }

    public void display(){
        for (int i = 0; i < end; i++) {
            System.out.print(data[i] + "<- ");
        }
        System.out.println("END");
    }

    public boolean isFull(){
       return end == data.length;
    }

    public boolean isEmpty(){
        return end == 0;
    }
}
