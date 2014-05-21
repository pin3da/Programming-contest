
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeSet;


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


  static class Event implements Comparable<Event>{
    double t;
    boolean type;
    int id;
    public Event(double tt, boolean tipo, int idx){
      t = tt;
      type = tipo;
      id = idx;
    }
    @Override
      public int compareTo(Event o) {
        if (id == o.id)
          return (type?-1:1);
        if (Math.abs(t - o.t)< eps){
          if (!type)
            return -1;
          else
            return 1;
        }
        return Double.compare(t, o.t);
      }
  }

  static double eps = 1e-9;
  static int N;
  static LinkedList<Event> l;

  public static void main(String args[]) throws NumberFormatException, IOException{
    Scanner sc = new Scanner();
    int T = sc.nextInt();
    for(int c = 0; c < T; c++){
      N = sc.nextInt();
      l = new LinkedList<Event>();
      for(int i = 0; i < N; i++){
        int a = sc.nextInt();
        int b = sc.nextInt();
        l.add(new Event(a - 0.5, true, i));
        l.add(new Event(b + 0.5, false, i));
      }
      Collections.sort(l);
      double until = -100;
      int total = 0;
      int abiertos = 0;
      int pedazos = 0;
      for(Event e: l){
        if (!e.type){
          total += e.t - until;
          until = e.t;
          abiertos--;
        }
        else{
          if (abiertos > 0)
            total += e.t - until;
          else
            pedazos++;
          until = e.t;
          abiertos++;
        }
      }

      //			Collections.sort(l, Collections.reverseOrder());
      //			abiertos = 0;
      //			for(Event e: l){
      //				if (!e.type){
      //					if (abiertos == 0)
      //						pedazos++;
      //					abiertos++;
      //				}
      //				else{
      //					abiertos--;
      //				}
      //			}
      System.out.println(Math.round(total));
    }
  }

}
