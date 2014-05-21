
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;


public class Main {


  static class Pair{
    int d1, d2;
    @Override
      public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + d1;
        result = prime * result + d2;
        return result;
      }
    @Override
      public boolean equals(Object obj) {
        if (this == obj)
          return true;
        if (obj == null)
          return false;
        if (getClass() != obj.getClass())
          return false;
        Pair other = (Pair) obj;
        if (d1 != other.d1)
          return false;
        if (d2 != other.d2)
          return false;
        return true;
      }
    public Pair(int dd1, int dd2){
      d1 = dd1;
      d2 = dd2;
    }
  }


  static char[] text;
  static HashMap<Pair, Integer> map;

  public static void main(String args[]) throws IOException{
    BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
    text = rd.readLine().toCharArray();
    map = new HashMap<Pair, Integer>();
    map.put(new Pair(0,0), 1);
    int[] array = new int[3];
    Arrays.fill(array, 0);
    long count = 0;
    for(int i = 0; i < text.length; i++){
      char c = text[i];
      if (c == 'a' || c == 'b' || c=='c')
        array[c - 'a']++;
      int d1 = array[0] - array[1];
      int d2 = array[1] - array[2];
      Pair aux = new Pair(d1, d2);
      if (map.containsKey(aux)){
        int t = map.get(aux);
        count = count + t;
        map.put(aux, t + 1);
      }
      else
        map.put(aux, 1);
    }
    System.out.println(count);
  }

}
