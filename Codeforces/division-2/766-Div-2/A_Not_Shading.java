import java.util.ArrayList;
import java.util.Scanner;

public class A_Not_Shading {
    static ArrayList<String> data = new ArrayList<String>();
    static int t, n, m, r, c;

    static boolean checkCol() {
        boolean res = false;
        for (int i = 0; i < n; i++) {
            if (data.get(i).charAt(c) == 'B') {
                res = true;
                break;
            }
        }
        return res;
    }

    static boolean checkAll() {
        boolean res = false;
        for (int i = 0; i < n; i++) {
            if (data.get(i).contains("B")) {
                res = true;
                break;
            }
        }
        return res;
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        t = scanner.nextInt();
        while (t-- > 0) {
            data.clear();
            n = scanner.nextInt();

            m = scanner.nextInt();

            r = scanner.nextInt();

            c = scanner.nextInt();

            scanner.nextLine();
            r -= 1;
            c -= 1;
            for (int i = 0; i < n; i++) {
                data.add(scanner.nextLine());
            }
            
            if (data.get(r).charAt(c) == 'B') {
                System.out.println(0);
            } else if (data.get(r).contains("B") || checkCol()) {
                System.out.println(1);
            } else if (checkAll()) {
                System.out.println(2);
            } else {
                System.out.println(-1);
            }

        }
        scanner.close();
    }
}