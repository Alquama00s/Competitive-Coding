import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//https://codeforces.com/problemset/problem/339/A
public class Solution{
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String in = br.readLine().strip();
        String signs = in.replaceAll("[123]", "");
        int[] nums=Arrays.stream(in.split("[+-]")).mapToInt(i->Integer.parseInt((i))).toArray();
        Arrays.sort(nums);
        String ans="";
        for (int j = 0; j < nums.length-1; j++) {
            ans+=String.valueOf(nums[j])+signs.charAt(j);
        }
        ans+=nums[nums.length-1];
        System.out.println(ans);
    }
}