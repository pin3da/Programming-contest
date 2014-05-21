
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeMap;


public class Main {

  static class Scanner{
    BufferedReader rd;
    StringTokenizer tk;
    public Scanner(){
      rd = new BufferedReader(new InputStreamReader(System.in));
    }
    String next() throws IOException{
      while(tk == null || !tk.hasMoreTokens())
        tk = new StringTokenizer(rd.readLine());
      return tk.nextToken();
    }
    int nextInt() throws NumberFormatException, IOException{
      return Integer.valueOf(next());
    }
  }


  static int gcd(int a, int b){
    if(b == 0)
      return a;
    return gcd(b, a % b);
  }

  static int N;
  static int[] array;

  public static void main(String args[]) throws NumberFormatException, IOException{
    Scanner sc = new Scanner();
    N = sc.nextInt();
    array = new int[N];
    int max = 0;
    for(int i = 0; i <N; i++){
      array[i] = sc.nextInt();
      max = Math.max(max, array[i]);
    }
    int Q = sc.nextInt();
    TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
    for(int g = 1; g <= max; g++){
      int nuevo = -1;
      int tam = 0;
      for(int i = 0; i < N; i++){
        if (array[i] % g == 0){
          tam++;
          if (nuevo < 0)
            nuevo = array[i];
          else
            nuevo = gcd(nuevo, array[i]);
        }
      }
      if (nuevo < 0)
        continue;
      if (map.containsKey(nuevo))
        map.put(nuevo, Math.max(tam, map.get(nuevo)));
      else
        map.put(nuevo, tam);
    }
    for(int q = 0; q < Q; q++){
      int K = sc.nextInt();
      Integer u = map.ceilingKey(K);
      if (u == null)
        System.out.println("0");
      else{
        int uu = u;
        System.out.println(map.get(uu));
      }
    }
  }

}
