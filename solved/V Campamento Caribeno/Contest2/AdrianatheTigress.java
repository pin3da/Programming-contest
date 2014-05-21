
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;


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

  static char[] text;

  public static void main(String args[]) throws IOException{
    Scanner sc = new Scanner();
    text = sc.next().toCharArray();
    char letra = sc.next().charAt(0);
    int peso = sc.nextInt();
    ArrayList<Integer> gaps = new ArrayList<Integer>();
    int i = 0;
    while(i < text.length){
      if (text[i] != letra){
        i++;
        continue;
      }
      int ni = i;
      while(ni < text.length && text[ni] == letra)
        ni++;
      gaps.add(ni - i);
      i = ni;
    }
    int words = sc.nextInt();
    ArrayList<Integer> available = new ArrayList<Integer>();
    for(int j = 0; j < words; j++)
      available.add(sc.next().length());
    Collections.sort(gaps, Collections.reverseOrder());
    Collections.sort(available, Collections.reverseOrder());
    //System.out.println(gaps);
    //System.out.println(available);
    int uno = 0;
    int dos = 0;
    int costo = 0;
    while(uno < available.size() && dos < gaps.size()){
      while(uno < available.size() && available.get(uno) > gaps.get(dos))
        uno++;
      if (uno == available.size())
        break;
      costo += gaps.get(dos) - available.get(uno);
      uno++;
      dos++;
    }
    while(dos < gaps.size()){
      costo += gaps.get(dos);
      dos++;
    }
    System.out.println(costo * peso);
  }

}
