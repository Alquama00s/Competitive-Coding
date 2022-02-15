import java.util.Scanner;
import java.util.regex.Pattern;

//https://codeforces.com/problemset/problem/59/A
public class Solution{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String in = sc.next();
        Pattern pat = Pattern.compile("[A-Z]");
        var mat = pat.matcher(in);
        int capCount=0;
        while(mat.find()){
            capCount+=mat.group().length();
        }
        if(capCount>in.length()-capCount){
            System.out.println(in.toUpperCase());
        }else{
            System.out.println(in.toLowerCase());
        }
        sc.close();
    }
}