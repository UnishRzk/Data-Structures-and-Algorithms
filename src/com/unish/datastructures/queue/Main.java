package com.unish.datastructures.queue;

public class Main {
    public static void main(String[] args) {
        CustomQueue queue = new CustomQueue();

        for (int i = 0; i < 8; i++) {
            queue.enqueue(i);
        }

        queue.display();

        System.out.println(queue.dequeue());
        queue.display();
    }
}
