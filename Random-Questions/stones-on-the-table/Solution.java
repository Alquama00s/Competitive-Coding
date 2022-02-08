import java.io.*;
import java.util.regex.*;

//https://codeforces.com/problemset/problem/266/A
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        String in = br.readLine().strip();
        int count=0;
        Pattern pat = Pattern.compile("(R+)|(B+)|(G+)");
        var mat =pat.matcher(in);
        while (mat.find()) {
            count+=(mat.group().length()-1);
        }
        System.out.println(count);
    }
}