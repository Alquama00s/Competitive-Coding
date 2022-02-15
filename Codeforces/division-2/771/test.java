import java.util.ArrayList;
import java.util.Collections;

public class test {
    public static void main(String[] args) {
        ArrayList<Integer> max_lst = new ArrayList<>();

        for (int i = 0; i < 10; i++) {
            max_lst.add(i);
        }
        for (int i = 0; i < 10; i++) {
            max_lst.add(i+11);
        }
        System.out.println(-(Collections.binarySearch(max_lst ,10)+1));
    }
}
