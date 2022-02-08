import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

//https://codeforces.com/problemset/problem/1324/B
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().strip());
        ArrayList<Integer> in;
        boolean flag;
        while (n-- > 0) {
            flag = false;
            br.readLine();
            in = (ArrayList<Integer>) Arrays.stream(br.readLine().strip().split(" ")).mapToInt(i->Integer.parseInt(i)).boxed().collect(Collectors.toList());
            if (in.size() > 2) {
                for (int i = 0; i < in.size(); i++) {
                    if (in.lastIndexOf(in.get(i)) > i+1) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag)
                System.out.println("YES");
            else
                System.out.println("NO");

        }
    }
}