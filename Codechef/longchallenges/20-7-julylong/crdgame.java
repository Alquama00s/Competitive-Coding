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
    static List<Long> intInput(BufferedReader reader) throws IOException{
        String input = reader.readLine();
        List<Long> integer = new ArrayList<Long>();
        String tempstring="";
        for (int i =0;i<input.length();i++){
            if(input.charAt(i) ==' '){
                integer.add(Long.parseLong(tempstring));
                tempstring="";
            }
            else{
                tempstring=tempstring+(input.substring(i,i+1));
            }
        }
        integer.add(Long.parseLong(tempstring));
        return integer;

    }
    /*---end---prototype:
    BufferedReader reader =  new BufferedReader(new InputStreamReader(System.in));
     List<Integer> no = new ArrayList<Integer>();no=intInput(bf) */

}
class Game{
    static int winner(Long c,Long m){
        int chef=0,morty=0;
        for(chef=0;c>0;chef+=c%10,c/=10);
        for(morty=0;m>0;morty+=m%10,m/=10);
        if(chef>morty)
            return 0;
        else if(morty>chef)
            return 1;
        else
            return 2;

    }
    public static void main(String[]args)throws IOException{
        int t,n,chef,morty;
        int win;
        List<Long> data = new ArrayList<Long>();
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        t=IO.input(reader);
        while(t>0){
            chef=0;
            morty=0;
            n= IO.input(reader);
            while(n>0){
                data=IO.intInput(reader);
                win=winner(data.get(0),data.get(1));
                if(win==0)
                    chef+=1;
                else if(win==1)
                    morty+=1;
                else{
                    chef+=1;
                    morty+=1;
                }
                n--;
            }
            if(chef>morty)
                System.out.println("0 "+chef);
            else if(morty>chef)
                System.out.println("1 "+morty);
            else
                System.out.println("2 "+chef);
            t--;

        }
    }
}