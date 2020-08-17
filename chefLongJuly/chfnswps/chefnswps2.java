import java.util.*;
import java.io.*;
//v4

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
class Swap{
    static void print(List<Integer> a){
        for (int i=0;i<a.size();i++)
            System.out.print(a.get(i)+" ");
        System.out.println("");
    }
    public static void main(String[]args)throws IOException{
        BufferedReader reader =new BufferedReader(new InputStreamReader(System.in));
        List<Integer> a=new ArrayList<Integer>();
        List<Integer> b=new ArrayList<Integer>();
        //List<Integer> ca=new ArrayList<Integer>();
        //List<Integer> cb=new ArrayList<Integer>();
        List<Integer> da=new ArrayList<Integer>();
        List<Integer> db=new ArrayList<Integer>();
        //List<Integer> diff=new ArrayList<Integer>();
        List<Integer> unduplia=new ArrayList<Integer>();
        List<Integer> unduplib=new ArrayList<Integer>();
        int t,n;
        boolean cant;
        HashSet<Integer> daa = new HashSet<Integer>();
        HashSet<Integer> dbb = new HashSet<Integer>();
        //Set<Integer> union;
        //Set<Integer> inter;
        t=IO.input(reader);
        while (t-->0){
            n=IO.input(reader);
            a=IO.intInput(reader);
            b=IO.intInput(reader);
            //long start=System.nanoTime();
            da.clear();
            db.clear();
            da.addAll(a);
            db.addAll(b);
            for(int i=0;i<a.size();i++){
                db.remove(a.get(i));
                da.remove(b.get(i));
            }
            /*for(int i=0;i<b.size();i++){
                da.remove(b.get(i));
            }*/
            unduplia.clear();
            unduplib.clear();
            daa=new HashSet<Integer>(a);
            dbb=new HashSet<Integer>(b);
            unduplia=new ArrayList<Integer>(daa);
            unduplib=new ArrayList<Integer>(dbb);
            /*diff.clear();
            diff.addAll(db);
            diff.addAll(da);*/
            //print(diff);
            //ca.clear();
            //cb.clear();
            cant=false;
            for (int i=0;i<unduplia.size();i++){
                    if(Collections.frequency(da,unduplia.get(i))%2!=0)
                        {//System.out.println(Collections.frequency(da,unduplia.get(i)));
                            cant=true;
                        break;}
            }
            for (int i=0;i<unduplib.size()||cant==true;i++){
                if(Collections.frequency(db,unduplib.get(i))%2!=0){
                    //System.out.println(Collections.frequency(da,unduplia.get(i)));
                    cant=true;
                    break;
                }
            }
            /*cant=false;
            ads=0;
            for (int i=0;i<ca.size();i++){
                if(ca.get(i)%2!=0) {
                    cant = true;
                    break;
                }else
                    ads=ads+ca.get(i);
            }
            bds=0;
            for (int i=0;i<cb.size();i++){
                if(cb.get(i)%2!=0 || cant==true) {
                    cant = true;
                    break;
                }else
                    bds=bds+cb.get(i);
            }*/
            Collections.sort(a);
            Collections.sort(b);
            if(a.equals(b))
                System.out.println(0);
            else if(cant==true) {
                //System.out.println("cantcase");
                System.out.println(-1);
            }
            else {
                if(da.size()!=db.size()) {
                    //System.out.println("sizecase");
                    System.out.println(-1);
                }
                else{
                    int ans=0;
                    //int anst=0;
                    //int ansa=0;
                    int swapr;
                    //Collections.sort(a);
                    //Collections.sort(b);
                    swapr=Math.min(a.get(0),b.get(0));
                    Collections.sort(da);
                    Collections.sort(db,Collections.reverseOrder());
                    for(int i=0;i<da.size();i+=2){
                        if(2*swapr<Math.min(da.get(i),db.get(i)))
                            ans=ans+(2*swapr);
                        else
                            ans=ans+Math.min(da.get(i),db.get(i));

                    }
                    System.out.println(ans);

                }

            }
            //print(da);
            //print(ca);
            //print(diff);
            //System.out.println(ads);
            //print(db);
            //print(unduplia);
            //print(unduplib);
            //print(cb);
            //System.out.println(bds+"---------------------------------");
            //long end=System.nanoTime();
            //System.out.println((end-start)/10E9);
        }
    }
}