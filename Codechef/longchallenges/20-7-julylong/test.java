import java.util.*;
import java.io.*;


class IO {
    /*function takes a BufferedReader as args and gives an int as output  */
    static int input(BufferedReader reader) throws IOException{
        int a=0;
        String c = reader.readLine();
        a =Integer.parseInt(c);
        return a;
    }
    /*----end---prototype:
     BufferedReader reader =  new BufferedReader(new InputStreamReader(System.in));
     int a=input(bf); */
    /*function takes BufferedReader as args and gives List<Integer> as output*/
    static List<Integer> intInput(BufferedReader reader) throws IOException{
        String input = reader.readLine();
        List<Integer> integer = new ArrayList<Integer>();
        String tempstring="";
        for (int i =0;i<input.length();i++){
            if(input.charAt(i) ==' '){
                integer.add(Integer.parseInt(tempstring));
                tempstring="";
            }
            else{
                tempstring=tempstring+(input.substring(i,i+1));
            }
        }
        integer.add(Integer.parseInt(tempstring));
        return integer;

    }
    /*---end---prototype:
    BufferedReader reader =  new BufferedReader(new InputStreamReader(System.in));
     List<Integer> no = new ArrayList<Integer>();no=intInput(bf) */

}
class Sort{
    public static void main(String[]args)throws IOException{
        BufferedReader reader =new BufferedReader(new InputStreamReader(System.in));
        List<Integer> foo=new ArrayList<Integer>();
        foo=IO.intInput(reader);
        long start=System.nanoTime();
        Collections.sort(foo);
        System.out.println(Collections.frequency(foo,foo.get(0)));
        for (int i=0;i<foo.size();i++)
            System.out.print(foo.get(i)+" ");
        long end=System.nanoTime();
        System.out.println((end-start)/(10E9));
    }
}