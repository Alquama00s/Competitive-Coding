import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

//https://codeforces.com/problemset/problem/236/A
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String in = br.readLine().strip();
        Set<Character> set = new HashSet<>();
        for (int i=0;i<in.length();i++) {
            set.add(in.charAt(i));
        }
        
        if (set.size() % 2 == 0)
            System.out.println("CHAT WITH HER!");
        else
            System.out.println("IGNORE HIM!");
    }
}