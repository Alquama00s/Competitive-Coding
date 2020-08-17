import java.util.*;
import java.io.*;


class sell {
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
    //end of lib func
    public static void main(String[] args) throws IOException{
        int n=0,t=0,profit=0;
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        t=input(in);
        while(t>0){
            List<Integer> p =new ArrayList<Integer>();
            profit=0;
            n=input(in);
            p= intInput(in);
            Collection.sort(p);
            Collection.reverse(p);
            for(int i; i<p.size();i++){
                profit=(p.get(i)-i);
            }
            profit=profit%1000000007;
            System.out.println(profit);
            t--;
        }



    }

}