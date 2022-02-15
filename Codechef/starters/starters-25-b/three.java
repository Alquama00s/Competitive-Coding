import java.io.*;
import java.util.*;

public class three {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        long[] temp;
        // int x,m;
        while (t-- > 0) {
            temp = Arrays.stream(br.readLine().trim().split(" ")).mapToLong(i -> Long.parseLong(i)).toArray();
            //System.out.println(1 + (int)Math.ceil((double) Math.log(temp[0]) / Math.log(2)));
            temp[1] -= (1 + (int)Math.ceil((double) Math.log(temp[0]) / Math.log(2)));

            System.out.println(Math.max(temp[1] + 1, 0));
        }
    }
}
