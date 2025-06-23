package com.unish.datastructures.queue;

public class CircularQueue{
    private static final int DEFAULT_SIZE = 10;
    protected int[] data;

    int end =  0;
    int front = 0;
    private int size = 0;


    public CircularQueue() {
        this(DEFAULT_SIZE);
    }

    public CircularQueue(int size) {
        this.data = new int[size];
    }

    public void enqueue(int val) throws QueueException{
        if (isFull()){
            throw new QueueException("Queue is Full");
        }
        data[end++] = val;
        end = end % data.length;
        size++;
    }

    public int dequeue() throws QueueException{
        if (isEmpty()){
            throw new QueueException("Queue is Empty");
        }

        int remove = data[front];
        front = (front+1) % data.length;
        size--;
        return remove;
    }

    public int peek() throws QueueException{
        if (isEmpty()){
            throw new QueueException("Queue is Empty");
        }
        return data[front];
    }

        public void display(){
            for (int i = front; i < end; i++) {
                System.out.print(data[i] + "<- ");
            }
            System.out.println("END");
        }


    public boolean isFull(){
        return size == data.length;
    }

    public boolean isEmpty(){
        return size == 0;
    }

}
