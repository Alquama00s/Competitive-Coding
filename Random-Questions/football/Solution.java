import java.util.*;
import java.io.*;
import java.util.regex.*;

//https://codeforces.com/problemset/problem/96/A
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String in = br.readLine().trim();
        Pattern pat = Pattern.compile("(0000000)|(1111111)");
        if(pat.matcher(in).find()){
            System.out.println("YES");
        }else{
            System.out.println("NO"); 
        }
    }
}