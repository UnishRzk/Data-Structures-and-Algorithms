package com.unish.searching.linearSearch;

public class SearchIn2DArray {
    public static void main(String[] args) {
        int[][] arr = {
                {21, 32, 43},
                {4, 6, 7}, 
                {1, 76, 87},
                {54,763,897,54}
        };
        int target = 763;

        if (search(arr,target)){
            System.out.println("Target Element has Been found");
        }else {
            System.out.println("Target Element not Found");
        }

//        System.out.println("The Max Value is "+ Max(arr));
        
    }
    
    static boolean search(int[][] arr, int target){
        if (arr.length == 0){
            System.out.println("Array is Empty");
        }

        for (int[] ints : arr) {
            for (int anInt : ints) {
                if (anInt == target) {
                    return true;
                }
            }
        }
        return false;
    }

    static int Max(int[][] arr){
        int max = Integer.MIN_VALUE;

        for (int[] ints : arr) {
            for (int anInt : ints) {
                if (anInt > max) {
                    max = anInt;
                }
            }
        }
        return max;
    }

    
}
