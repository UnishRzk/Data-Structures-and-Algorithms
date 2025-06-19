package com.unish.searching.linearSearch;

public class Main {
    public static void main(String[] args) {

        int[] nums = {32,43,54,64,75,86,9867,42,54,65,765};
        int target = 86;

        // for the block that will return the index value of the array

//        int ans = linearSearch(nums,target);
//        if (ans == -1){
//            System.out.println("Target Element Not Found!");
//        }else {
//            System.out.println("Target element found at index: " + ans);
//        }


        // for the block that will return the target value

//        int ans = linearSearch2(nums,target);
//        if (ans == -1){
//            System.out.println("Target Element Not Found!");
//        } else {
//            System.out.println("Target element: "+ans+ " found..");
//        }


        // for the block that will return the boolean value

        boolean ans = linearSearch3(nums,target);

        if (ans){
            System.out.println("Target Element found");
        }else {
            System.out.println("Target Element not found");
        }

    }

    // Will return the index if found
    // Will return -1 in not found

    static int linearSearch(int[] arr, int target){
        for (int i = 0; i < arr.length; i++) {
            // check every element one by one for the target
            if (arr[i] == target){
                return i;
            }

        }
        return -1;
    }

    // this method will return the target value
    static int linearSearch2(int[] arr,int target){
        for (int val : arr){
            if (val == target){
                return val;
            }
        }
        return -1;
    }

    // this will return boolean values
    static boolean linearSearch3(int[] arr,int target){
        for (int val : arr){
            if (val == target){
                return true;
            }
        }
        return false;
    }


}
