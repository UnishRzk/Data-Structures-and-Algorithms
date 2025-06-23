package com.unish.datastructures.queue;

public class DynamicQueue extends CircularQueue {

    public DynamicQueue() {
        super();
    }

    public DynamicQueue(int size) {
        super(size);
    }

    @Override
    public boolean enqueue(int val) throws QueueException {
        if (this.isFull()) {
            int[] temp = new int[data.length * 2];
            for (int i = 0; i < size; i++) {
                temp[i] = data[(front + i) % data.length];
            }
            front = 0;
            end = size;
            data = temp;
        }
        return super.enqueue(val);
    }
}
