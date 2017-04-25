// http://codeforces.com/contest/381/problem/A

import java.io.*;
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
            int[] nums = new  int[n];
            for (int i = 0; i < n; ++i) 
                nums[i] = in.nextInt();
            int[] ans = new int [2];
            int left = 0, right = n - 1, t = 0;
            while (left <= right) {
                if (nums[left] > nums[right]) {
                    ans[t] += nums[left];
                    left++;
                } else {
                    ans[t] += nums[right];
                    right--;
                }
                t  = t ^ 1;
            }
            
            out.println(ans[0] + " " + ans[1]);
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

