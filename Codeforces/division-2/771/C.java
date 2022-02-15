import java.io.*;
import java.util.*;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t, n, max, temp;
        int[] data;
        ArrayList<Integer> max_lst = new ArrayList<>();
        t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            max = Integer.MIN_VALUE;

            max_lst.clear();
            n = Integer.parseInt(br.readLine().trim());
            data = Arrays.stream(br.readLine().trim().split(" ")).mapToInt(I -> Integer.parseInt(I)).toArray();
            for (int i = 0; i < data.length; i++) {
                if (data[i] > max) {
                    max_lst.add(data[i]);
                    max = data[i];
                } else {
                    temp = -(Collections.binarySearch(max_lst, data[i]) + 1);
                    while (max_lst.get(temp) != max) {
                        max_lst.remove(temp);
                    }
                }
            }
            System.out.println(max_lst.size());
        }
    }
}