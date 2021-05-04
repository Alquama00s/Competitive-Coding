import java.util.*;
import java.io.*;

//chefnswps
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
class Swapstress{
    static void print(List a){
        for (int i=0;i<a.size();i++)
            System.out.print(a.get(i)+" ");
        System.out.println("");
    }
    static ArrayList<Integer> randInputArray(int n,int range){
        Random r=new Random();
        ArrayList<Integer> arr=new ArrayList<Integer>();
        for (int i=0;i<n;i++){
            arr.add(r.nextInt(range));
        }
        return arr;
    }
    public static void main(String[]args)throws IOException{
        BufferedReader reader =new BufferedReader(new InputStreamReader(System.in));
        List<Integer> a=new ArrayList<Integer>();
        List<Integer> b=new ArrayList<Integer>();
        List<Integer> ca=new ArrayList<Integer>();
        List<Integer> cb=new ArrayList<Integer>();
        List<Integer> da=new ArrayList<Integer>();
        List<Integer> db=new ArrayList<Integer>();
        List<Integer> indexa=new ArrayList<Integer>();
        //List<Integer> indexb=new ArrayList<Integer>();
        List<Integer> unduplia=new ArrayList<Integer>();
        List<Integer> unduplib=new ArrayList<Integer>();
        int t,n,ads,bds;
        int no;
        boolean cant;
        Random rand = new Random();
        //Set<Integer> union;
        //Set<Integer> inter;
        //t=IO.input(reader);
        int ans,ansst=0;
        int noOf,k,j,temp;
        no=0;
        while (true){
            no++;
            a.clear();
            b.clear();
            n=rand.nextInt(200000)+1;
            a=randInputArray(n,1000000000);
            a=new ArrayList<Integer>(new HashSet(a));
            print(a);
            b.addAll(a);
            noOf=rand.nextInt(n);
            indexa.clear();
            //indexb.clear();
            ansst=0;
            for (int i=0;i<noOf || a.equals(b);i++){
                    k = rand.nextInt(a.size());
                    //while (indexa.contains(k));

                    //do
                        j = rand.nextInt(b.size());
                    //while (k == j || indexb.contains(j));
                    if(!indexa.contains(a.get(k)) && !indexa.contains(b.get(j)) && a.get(k)!=b.get(j)) {
                        indexa.add(b.get(j));
                        indexa.add(a.get(k));
                        temp = a.get(k);
                        a.set(k, b.get(j));
                        b.set(j, temp);
                        ansst++;
                    }
            }

            da.clear();
            db.clear();
            da.addAll(a);
            db.addAll(b);
            for(int i=0;i<a.size();i++){
                db.remove(a.get(i));
            }
            for(int i=0;i<b.size();i++){
                da.remove(b.get(i));
            }
            unduplia.clear();
            unduplib.clear();
            unduplia=new ArrayList<Integer>(new HashSet(da));
            unduplib=new ArrayList<Integer>(new HashSet(db));
            /*diff.clear();
            diff.addAll(db);
            diff.addAll(da);*/
            //print(diff);
            ca.clear();
            cb.clear();
            for (int i=0;i<unduplia.size();i++){
                ca.add(Collections.frequency(da,unduplia.get(i)));
            }
            for (int i=0;i<unduplib.size();i++){
                cb.add(Collections.frequency(db,unduplib.get(i)));
            }
            cant=false;
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
            }
            if(da.size()+db.size()==0)
                ans=0;
            else if(cant==true)
                ans=-1;
            else {
                if(ads!=bds)
                    ans=-1;
                else
                    ans=ads/2;
            }
            if(ans==ansst){
                System.out.println(no);
                System.out.println("OK");
                System.out.println(ans);
                System.out.println(ansst);
                System.out.println("--------details----------");
                print(a);
                print(b);
                System.out.println("------------------");
            }else{
                System.out.println(no);
                System.out.println("error");
                System.out.println(ans);
                System.out.println(ansst);
                System.out.println("--------details----------");
                print(a);
                print(b);
                print(indexa);
                System.out.println("------------------");
                break;
            }
            //print(da);
            //print(ca);
            //print(diff);
            //System.out.println(ads);
            //print(db);
            //print(cb);
            //System.out.println(bds+"---------------------------------");
        }
    }
}