// http://codeforces.com/contest/96/problem/A

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Codeforces {
    static class Scanner{

        BufferedReader br=null;
        StringTokenizer tk=null;
        public Scanner(){
            br=new BufferedReader(new InputStreamReader(System.in));
        }
        public String next() throws IOException{
            while(tk==null || !tk.hasMoreTokens())
                tk=new StringTokenizer(br.readLine());
            return tk.nextToken();
        }
        public int nextInt() throws NumberFormatException, IOException{
            return Integer.valueOf(next());
        }
        public double nextDouble() throws NumberFormatException, IOException{
            return Double.valueOf(next());
        }
    }
    
    public static void main(String args[]) throws IOException{
        Scanner sc =  new Scanner();
        String cad = sc.next();
        
        if(cad.contains("1111111") || cad.contains("0000000"))System.out.println("YES");
        else System.out.println("NO");
    }
}
