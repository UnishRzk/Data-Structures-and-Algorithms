package com.unish.datastructures.queue;

public class Main {
    public static void main(String[] args) {
//        CustomQueue queue = new CustomQueue();
        CircularQueue queue = new CircularQueue(5);

        for (int i = 0; i < 4; i++) {
            queue.enqueue(i);
        }

        queue.display();

        System.out.println(queue.dequeue());
        queue.display();
    }
}
