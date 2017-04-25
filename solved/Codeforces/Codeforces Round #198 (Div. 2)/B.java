// http://codeforces.com/contest/340/problem/B

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Bdiv2 {
    
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
    
    static class Point{
        int x,y;
        public Point(int xx, int yy){
            x = xx;
            y = yy;
        }
        Point sub(Point o){
            return new Point(x - o.x, y - o.y);
        }
        int cross(Point o){
            return x * o.y - y * o.x;
        }
    }
    
    static int N;
    static Point[] array;
    
    static int compute(Point base, Point o){
        if (o == null)
            return 0;
        return Math.abs(base.cross(o));
    }
    
    public static void main(String args[]) throws NumberFormatException, IOException{
        Scanner sc = new Scanner();
        N = sc.nextInt();
        array = new Point[N];
        for(int i = 0; i < N; i++)
            array[i] = new Point(sc.nextInt(), sc.nextInt());
        int max = 0;
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                Point v = array[j].sub(array[i]);
                Point p= array[i];
                Point izq = null,der = null;
                for(int k = 0; k < N; k++){
                    if (i == k || j == k)
                        continue;
                    Point res = array[k].sub(p); 
                    if (res.cross(v) < 0){
                        if (compute(v, res) > compute(v, izq))
                            izq = res;
                    }
                    else{
                        if (compute(v, res) > compute(v, der))
                            der = res;
                    }
                }
                if (izq != null && der != null)
                    max = Math.max(max, compute(v, izq) + compute(v, der));
            }
        }
        System.out.println(max / 2.0);  
    }

}
