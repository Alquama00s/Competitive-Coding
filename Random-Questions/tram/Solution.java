import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.*;
import java.util.*;

//https://codeforces.com/problemset/problem/116/A
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, curr = 0, max = 0;
        int[] in;
        n = Integer.parseInt(br.readLine().trim());
        while (n-- > 0) {
            in = Arrays.stream(br.readLine().trim().split(" ")).mapToInt(i -> Integer.parseInt(i)).toArray();
            curr += in[1] - in[0];
            max = Math.max(max, curr);
        }
        System.out.println(max);
    }
}