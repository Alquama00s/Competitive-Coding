import java.io.*;
//https://codeforces.com/problemset/problem/1/A
public class Solution{
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[];
        input=br.readLine().trim().split(" ");
        int l=Integer.parseInt(input[0]),b=Integer.parseInt(input[1]),s=Integer.parseInt(input[2]);
        l= (int)Math.ceil((double)l/s);
        b= (int)Math.ceil((double)b/s);
        System.out.println((long)l*b);
        

    }
}