// http://codeforces.com/contest/374/problem/B

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class B {
    
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
    
    
    static char[] ss;
    static int [] s;
    
    public static void main(String args[]) throws NumberFormatException, IOException{
        Scanner sc = new Scanner();
        ss = sc.next().toCharArray();
        s = new int[ss.length];
        for(int i = 0; i < ss.length; i++) 
            s[i] = ss[i] - '0';
        int count = 1;
        long ans = 1;
        for(int i = 1; i < s.length; i++){
            if (s[i - 1] + s[i] == 9)
                count++;
            else{
                if (count % 2 == 1){
                    long t = (count / 2) + 1;
                    ans *= t;
                }
                count = 1;
            }
        }
        if (count % 2 == 1){
            long t = (count / 2) + 1;
            ans *= t;
        }
        System.out.println(ans);
    }

}
