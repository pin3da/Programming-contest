// http://codeforces.com/contest/381/problem/B

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A {

    public static void main(String []args) throws IOException {
        Scanner in = new Scanner(System.in);
        OutputWriter out = new OutputWriter(System.out);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }

    static class Task{
        public void solve(Scanner in, OutputWriter out) throws IOException{
            int n = in.nextInt();
            int [] times = new int [5001];
            Arrays.fill(times, 0);
            for (int i = 0 ; i < n ; ++ i) 
                times[in.nextInt()]++;
            
            int last = 0;
            ArrayList<Integer> ans = new ArrayList<Integer>();
            for (int i = 0; i < 5001; ++i) {
                if (times[i] > 0) {
                    ans.add(i);
                    last = i;
                    times[i]--;
                }
            }
            for (int i = last - 1; i >= 0; --i) 
                if (times[i] > 0) 
                    ans.add(i);

            out.println(ans.size() + " ");
            boolean primero = true;
            for (int i : ans) {
                if (!primero)
                    out.print(' ');
                primero = false;
                out.print(i + "");
            }
                
        }
    }

    static class Scanner{
        public BufferedReader reader;
        public StringTokenizer st;

        public Scanner(InputStream stream){
            reader = new BufferedReader(new InputStreamReader(stream));
            st = null;
        }

        public String next(){
            while(st == null || !st.hasMoreTokens()){
                try{
                    String line  = reader.readLine();
                    if(line == null) return null;
                    st =  new StringTokenizer(line);
                }catch (Exception e){
                    throw (new RuntimeException());
                }
            }
            return st.nextToken();
        }

        public int nextInt(){
            return Integer.parseInt(next());
        }
        public long nextLong(){
            return Long.parseLong(next());
        }
        public double nextDouble(){
            return Double.parseDouble(next());
        }
    }

    static class OutputWriter{
        BufferedWriter writer;

        public OutputWriter(OutputStream stream){
            writer = new BufferedWriter(new OutputStreamWriter(stream));
        }

        public void println(int j) throws IOException {
            print(j + "\n");
        }

        public void println(String j) throws IOException {
            print(j + "\n");
        }

        public void print(int i) throws IOException {
            writer.write(i);
        }

        public void print(String s) throws IOException {
            writer.write(s);
        }

        public void print(char []c) throws IOException {
            writer.write(c);
        }
        public  void close() throws IOException {
            writer.close();
        }
    }
}

