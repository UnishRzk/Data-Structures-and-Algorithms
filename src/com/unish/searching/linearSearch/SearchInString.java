package com.unish.searching.linearSearch;

public class SearchInString {
    public static void main(String[] args) {
        String str = "Unish";
        char target = 's';

        if (search(str, target)){
            System.out.println("Character Found");
        }else {
            System.out.println("Target not Found!");
        }

    }


    public static boolean search(String s, char target){
        if(s.isEmpty()){
            return false;
        }

        for(char c : s.toCharArray()){
            if (c == target){
                return true;
            }
        }

        return false;
    }

}
