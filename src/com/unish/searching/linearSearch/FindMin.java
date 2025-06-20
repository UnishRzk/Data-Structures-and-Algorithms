package com.unish.searching.linearSearch;

public class FindMin {
    public static void main(String[] args) {
        int[] arr = {32,54,65,76,21,65,76,87,97,65,54,43};

        System.out.println("The Minimum number is: " + min(arr));

    }

    static int min(int[] arr){
        int min = arr[0];
        for (int j : arr) {
            if (min > j) {
                min = j;
            }
        }
        return min;
    }
}
