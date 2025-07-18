package com.unish.datastructures.stack;

public class DynamicStack extends CustomStack{

    public DynamicStack() {
        super();
    }

    public DynamicStack(int size) {
        super(size);
    }

    @Override
    public boolean Push(int value) throws StackException {
        if (this.isFull()){
            int[] temp = new int[data.length*2];

            for (int i = 0; i < data.length; i++) {
                temp[i] = data[i];
            }
            data = temp;
        }

        return super.Push(value);
    }
}
