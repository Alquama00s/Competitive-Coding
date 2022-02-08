import java.io.*;
import java.util.regex.*;

//https://codeforces.com/problemset/problem/118/A
public class Solution{
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String in = br.readLine().strip().toLowerCase();
        in=in.replaceAll("[aeiouy]", "");
        in=in.replaceAll("", ".");
        System.out.println(in.substring(0,in.length()-1));
    }
}