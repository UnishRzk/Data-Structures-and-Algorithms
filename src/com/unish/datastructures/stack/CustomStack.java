package com.unish.datastructures.stack;

public class CustomStack {
    protected int[] data;
    public int top = -1;
    private static final int DEFAULT_SIZE = 10;

    public CustomStack() {
        this(DEFAULT_SIZE);
    }

    public CustomStack(int size) {
        this.data = new int[size];
    }

    public boolean Push(int value) throws StackException {

        if (isFull()){
            throw  new StackException("Stack Overflow");
        }

        top++;
        data[top] = value;
        return true;
    }

    public int Pop() throws StackException {
        if (isEmpty()){
            throw new StackException("Stack Underflow");
        }
        return data[top--];
    }


    public int peek() throws StackException {
        if (isEmpty()){
            throw new StackException("Stack Underflow");
        }
        return data[top];
    }

    public boolean isFull(){
        return top == data.length - 1;
    }

    public boolean isEmpty(){
        return top == -1;
    }

}
