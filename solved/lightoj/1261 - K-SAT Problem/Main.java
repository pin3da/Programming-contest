
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String []args) throws IOException {
        Scanner in = new Scanner(System.in);
        OutputWriter out = new OutputWriter(System.out);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }

}

class Task{
    public void solve(Scanner in, OutputWriter out) throws IOException {
        int tc = in.nextInt();
        for(int cn = 1; cn <= tc; ++cn ){
            int n = in.nextInt() , m = in.nextInt(), k = in.nextInt();
            boolean [][][] mask = new boolean[n][2][33];
            for(int i = 0; i< n; ++i){
                for(int j = 0; j < k; ++j){
                    int tmp = in.nextInt();
                    int check = (tmp > 0)?0:1;
                    int pos =  Math.abs(tmp);
                    mask[i][check][pos] = true;
                }
            }
            int p = in.nextInt();
            boolean []visited = new boolean[m+1];
            for(int i = 0; i < p; ++i)
                visited[in.nextInt()] = true;


            boolean ans = true;
            for(int i = 0; i< n; ++i){
                boolean ok = false;
                for(int j = 1; j <= m && !ok; ++j )
                    if((mask[i][0][j] && visited[j]) || (mask[i][1][j] && !visited[j])) ok = true;
                ans = ans && ok;

            }
            out.print(String.format("Case %d: ",cn));
            if(ans)
                out.print("Yes\n");
            else
                out.print("No\n");
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

}

class OutputWriter{
    BufferedWriter writer;

    public OutputWriter(OutputStream stream){
        writer = new BufferedWriter(new OutputStreamWriter(stream));
    }

    public void print(String s) throws IOException {
        writer.write(s);
    }

    public  void close() throws IOException {
        writer.close();
    }

}
