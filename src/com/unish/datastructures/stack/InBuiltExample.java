package com.unish.datastructures.stack;

import java.util.Stack;

public class InBuiltExample {
    public static void main(String[] args) {

        // Internally it is an array
        // It extends vector class

        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i <6; i++) {
            stack.push(i);
        }

        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
//        System.out.println(stack.pop());
//        System.out.println(stack.pop());
//        System.out.println(stack.pop());

//        System.out.println(stack.pop());

        System.out.println(stack.peek());
        System.out.println(stack.peek());

    }
}
