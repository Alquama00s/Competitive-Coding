import java.util.*;

//https://codeforces.com/problemset/problem/617/A
public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println((int)Math.ceil((double) n / 5));
        sc.close();
    }
}