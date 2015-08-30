import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class primes {

    public static void main(String []args) throws IOException {
        Scanner in = new Scanner(System.in);
        OutputWriter out = new OutputWriter(System.out);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }

}

class Task{
    public void solve(Scanner in, OutputWriter out) throws IOException{
        String t = in.next();
        BigInteger tt = new BigInteger(t);
        if (tt.isProbablePrime(40)) {
            for (int i = 0; i < t.length(); i++) {
                char k = t.charAt(i);
                if (k == '3' || k == '4' || k == '7') {
                    out.print("no\n");
                    return;
                }
            }
            t = t.replace('6', 'x');
            t = t.replace('9', '6');
            t = t.replace('x', '9');
            t = new StringBuilder(t).reverse().toString();
            BigInteger t2 = new BigInteger(t);
            if (t2.isProbablePrime(40)) {
                out.print("yes\n");
            } else {
                out.print("no\n");
            }
        } else {
            out.print("no\n");
        }
    }
}

class Scanner{
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

class OutputWriter{
    BufferedWriter writer;

    public OutputWriter(OutputStream stream){
        writer = new BufferedWriter(new OutputStreamWriter(stream));
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

