package com.unish.searching.linearSearch;

// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/

public class EvenDigits {
    public static void main(String[] args) {
        int[] arr = {43,65,32,635,6,85,312,45,7645,7,52,523,4,76};

        System.out.println("Total number of Even digits are: "+ findNumbers(arr));
    }

    static int findNumbers(int[] nums){
        int count = 0;
        for (int a : nums){
            if (digits(a) % 2 ==0 ){
                count++;
            }
        }
        return count;
    }

    static int digits2(int a){
        int count = 0;

        if (a < 0){
            a *= -1;
        }
        while (a>0){
            a =a/10;
            count++;
        }
        return count;
    }


    // faster
    static int digits(int a){
        if (a < 0){
            a *= -1;
        }
        return (int)(Math.log10(a) + 1);
    }

}
