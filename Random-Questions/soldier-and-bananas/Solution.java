import java.util.*;
import java.io.*;

//https://codeforces.com/problemset/problem/546/A
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // k n w
        int[] in = Arrays.stream(br.readLine().trim().split(" ")).mapToInt(i -> Integer.parseInt(i)).toArray();
        //total amt req - amt he has
        int borrow = Math.max((in[0] * in[2] * (in[2] + 1) / 2) - in[1], 0);
        System.out.println(borrow);
    }
}