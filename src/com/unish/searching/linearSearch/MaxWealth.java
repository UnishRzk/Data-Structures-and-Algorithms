package com.unish.searching.linearSearch;

//https://leetcode.com/problems/richest-customer-wealth/description/

public class MaxWealth {
    public static void main(String[] args) {

        int[][]  accounts  = {{1,2,3},{3,2,1,3}};

        System.out.println(maximumWealth(accounts));
    }

    static public int maximumWealth(int[][] accounts) {

        int ans = Integer.MIN_VALUE;
        for (int[] account : accounts) {
            int sum = 0;
            for (int i : account) {
                sum += i;
            }
            ans = Math.max(ans,sum);

        }
        return ans;
    }
}
