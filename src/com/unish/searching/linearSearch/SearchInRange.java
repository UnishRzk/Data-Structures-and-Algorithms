package com.unish.searching.linearSearch;

public class SearchInRange {
    public static void main(String[] args) {

        int[] arr = {32,54,65,76,21,65,76,87,97,65,54,43};
        int target = 87;
        if (linearSearch(arr, target, 4, 9)) {
            System.out.println("Target Element Found");
        }else{
            System.out.println("Target Element not Found");
        }
    }

    static boolean linearSearch(int[] arr, int target, int start, int end) {
        if (arr.length == 0){
            System.out.println("The Array is Empty");
        }
        for (int i = start; i < end ; i++) {
            if (arr[i] == target){
                return true;
            }
        }
        return false;
    }

}
