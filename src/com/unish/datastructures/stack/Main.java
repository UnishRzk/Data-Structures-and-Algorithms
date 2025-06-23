package com.unish.datastructures.stack;

public class Main {
    public static void main(String[] args) throws StackException {

//        CustomStack stack = new CustomStack();
        CustomStack stack = new DynamicStack();

        for (int i = 0; i < 11; i++) {
            stack.Push(i);
        }

        for (int i = 0; i < 5; i++) {
            System.out.println(stack.Pop());
        }

        System.out.println(stack.peek());
        System.out.println(stack.peek());
    }
}
