
import java.io.*;
import java.util.*;

public class one {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        Set<Integer> x = new HashSet<Integer>();
        Set<Integer> y = new HashSet<Integer>();
        int n;
        int[] points;

        while (t-- > 0) {
            x.clear();
            y.clear();
            n = Integer.parseInt(br.readLine().trim());
            for (int i = 0; i < n; i++) {
                points = Arrays.stream(br.readLine().trim().split(" ")).mapToInt(in -> Integer.parseInt(in)).toArray();
                x.add(points[0]);
                y.add(points[1]);
            }

            System.out.println(x.size() + y.size());
        }
    }
}