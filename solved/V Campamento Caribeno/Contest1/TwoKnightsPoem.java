
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Scanner;


public class Main {


  static class state {
    int idx;
    int x1,y1;
    int x2, y2;
    @Override
    public int hashCode() {
      final int prime = 31;
      int result = 1;
      result = prime * result + idx;
      result = prime * result + x1;
      result = prime * result + x2;
      result = prime * result + y1;
      result = prime * result + y2;
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
      state other = (state) obj;
      if (idx != other.idx)
        return false;
      if (x1 != other.x1)
        return false;
      if (x2 != other.x2)
        return false;
      if (y1 != other.y1)
        return false;
      if (y2 != other.y2)
        return false;
      return true;
    }
    public state(int a, int b, int c, int d, int e) {
      idx = a;
      x1= b;
      y1 = c;
      x2 = d;
      y2 = e;
    }
  }

  static boolean isshift(int x, int y){
    if (x < 3)
      return false;
    if ( y < 2)
      return true;
    if (y > 7)
      return true;
    return false;
  }


  static boolean dp(state s){
    //System.out.println(s.idx + " " + s.x1 + " " + s.y1 + " " + s.x2 + " " + s.y2);
    if (dp.containsKey(s))
      return dp.get(s);
    if ( s.idx == t.length){
      dp.put(s, true);
      return true;
    }
    //		if (s.x2 == 3 && s.y2 == 8){
    //			System.out.println("debug");
    //		}
    char letra = t[s.idx];
    boolean flag = false;
    for(int i = -2; i < 3 && !flag; i++)
      for(int j = -2; j < 3 && !flag; j++){
        int tmp = Math.abs(i) + Math.abs(j);
        if (tmp == 3){
          int nx1 = s.x1 + i;
          int ny1 = s.y1 + j;
          if (nx1 < 0 || nx1 > 3 || ny1 < 0 || ny1 > 9)
            continue;
          if (nx1 == s.x2 && ny1 == s.y2)
            continue;
          if (nx1 < 3){
            char typed = min[nx1][ny1];
            if (isshift(s.x2, s.y2))
              typed = may[nx1][ny1];
            if (typed == letra){
              state ns = new state(s.idx + 1, nx1, ny1, s.x2, s.y2);
              flag = flag || dp(ns);
            }
          }
          else if (ny1 >= 2 && ny1 <= 7){
            char typed = ' ';
            if (typed == letra){
              state ns = new state(s.idx + 1, nx1, ny1, s.x2, s.y2);
              flag = flag || dp(ns);
            }
          }
          else
            flag = flag || dp(new state(s.idx, nx1, ny1, s.x2, s.y2));
        }
      }


    for(int i = -2; i < 3 && !flag; i++)
      for(int j = -2; j < 3 && !flag; j++){
        int tmp = Math.abs(i) + Math.abs(j);
        if (tmp != 3)
          continue;
        int nx2 = s.x2 + i;
        int ny2 = s.y2 + j;
        if (nx2 < 0 || nx2 > 3 || ny2 < 0 || ny2 > 9)
          continue;
        if (nx2 == s.x1 && ny2 == s.y1)
          continue;
        if (nx2 < 3){
          char typed = min[nx2][ny2];
          if (isshift(s.x1, s.y1))
            typed = may[nx2][ny2];
          if (typed == letra){
            state ns = new state(s.idx + 1, s.x1, s.y1, nx2, ny2);
            flag = flag || dp(ns);
          }
        }
        else if (ny2 >= 2 && ny2 <= 7){
          char typed = ' ';
          if (typed == letra){
            state ns = new state(s.idx + 1, s.x1, s.y1, nx2, ny2);
            flag = flag || dp(ns);
          }
        }
        else
          flag = flag || dp(new state(s.idx, s.x1, s.y1, nx2, ny2));
      }


    dp.put(s, flag);
    return flag;
  }


  static String mayusculas = "QWERTYUIOPASDFGHJKL:ZXCVBNM<>?";
  static String minusculas = "qwertyuiopasdfghjkl;zxcvbnm,./";
  static char[][] may;
  static char[][] min;

  static HashMap<state, Boolean> dp;
  static char[] t;


  public static void main(String args[]) throws IOException{
    BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
    may = new char[3][10];
    min = new char[3][10];
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 10; j++){
        may[i][j] = mayusculas.charAt(i * 10 + j);
        min[i][j] = minusculas.charAt(i * 10 + j);
      }
    while(true){
      String cad = rd.readLine();
      cad = cad.trim();
      if (cad.equals("*"))
        break;
      t = cad.toCharArray();
      dp = new HashMap<state, Boolean>();
      state s = new state(0, 3, 0, 3 , 9);
      if (dp(s))
        System.out.println("1");
      else
        System.out.println("0");
    }

  }

}
