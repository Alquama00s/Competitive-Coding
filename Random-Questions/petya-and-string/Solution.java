import java.io.*;

//https://codeforces.com/problemset/problem/112/A
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String in1 = br.readLine().strip();
        String in2 = br.readLine().strip();
        int ans=in1.compareToIgnoreCase(in2);
        ans = (ans==0)?ans:ans/Math.abs(ans);
        System.out.println(ans);

    }
}