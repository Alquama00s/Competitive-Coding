import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

//https://leetcode.com/problems/longest-valid-parentheses/



public class Solution {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(longestValidParentheses(br.readLine().trim()));
    }
    public static int longestValidParentheses(String s) {
     Stack<Character> data = new Stack<>();
        int prev=0,curr=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='('){
                data.push('(');
            }else{
                if(data.size()>0 && data.peek()=='('){
                    data.pop();
                    curr++;
                    //if(data.isEmpty())prev=Math.max(prev,curr); 
                }else{
                    prev=Math.max(prev,curr);
                    curr=0;
                }
            }
        }
        //if(!data.isEmpty()) curr=0;
        return Math.max(prev,curr)*2;
    }
}