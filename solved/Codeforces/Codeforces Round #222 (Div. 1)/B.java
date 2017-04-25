// http://codeforces.com/contest/377/problem/B

import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.util.TreeSet;


public class D {

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

    static class Bug implements Comparable<Bug>{
        int complexity, idx;
        public Bug(int c, int i){
            complexity = c;
            idx = i;
        }
        @Override
        public int compareTo(Bug o) {
            return o.complexity - complexity;
        }
    }

    static class Student implements Comparable<Student>{
        int habilidad, costo;
        boolean comprado;
        int amount;
        int idx;
        public Student(int h, int i, int c){
            habilidad  = h;
            costo = c;
            comprado = false;
            amount = 0;
            idx = i;
        }
        @Override
        public int compareTo(Student o) {
            if(this.comprado && o.comprado){
                return amount - o.amount;
            }
            if (this.comprado)
                return -1;
            if (o.comprado)
                return 1;
            if(costo == o.costo) return idx - o.idx;
            return costo - o.costo;
        }
        public String toString(){
            return String.format("(idx = %d, amount = %d, skill = %d)", idx, amount, habilidad);
        }
    }

    static class cmp implements Comparator<Student>{
        @Override
        public int compare(Student a, Student b) {
            return b.habilidad - a.habilidad;
        }
    }

    static boolean test(int t, int[] answer){
        if (t == 0)
            return false;
        for(int i = 0; i < N; i++){
            array[i].amount = 0;
            array[i].comprado = false;
        }
        int money = S;
        int pointerstudent = 0;
        TreeSet<Student> pq = new TreeSet<Student>();
        for(int i = 0; i < M; i+=t){
            while(pointerstudent < N && array[pointerstudent].habilidad >= bugs[i].complexity){
                pq.add(array[pointerstudent]);
                pointerstudent++;
            }
            Student paraasignar = pq.pollFirst();
            if (paraasignar == null)
                return false;
            if (!paraasignar.comprado)
                money -= paraasignar.costo;
            if (money < 0)
                return false;
            paraasignar.comprado = true;
            for(int j = 0; i +j < M && j < t; ++j)
                answer[bugs[i+j].idx] = paraasignar.idx;
            }
        return true;
    }

    static int N,M,S;
    static Student[] array;
    static Bug[] bugs;

    public static void main(String args[]) throws NumberFormatException, IOException{
        Scanner sc  =new Scanner();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        N = sc.nextInt();
        M = sc.nextInt();
        S = sc.nextInt();
        bugs = new Bug[M];
        for(int i = 0; i < M; i++)
            bugs[i] = new Bug(sc.nextInt(), i);
        array = new Student[N];
        for(int i = 0; i < N; i++)
            array[i] = new Student(sc.nextInt(), i,  0);
        for(int i = 0; i < N; i++)
            array[i].costo = sc.nextInt();
        Arrays.sort(array, new cmp());
        Arrays.sort(bugs);
        int[] ans = new int[M];
        if(!test(M, ans)){
            bw.write("NO\n");
            bw.flush();
            return;
        }
        int low = 1;
        int high = M;
        while( low < high){
            int mid = (low + high)/2;
            if (test(mid,ans)) high = mid;
            else low  = mid +1;
        }

        test(low, ans);

        bw.write("YES\n");
        for(int i = 0; i < M; i++)
            bw.write((ans[i] + 1) + " ");
        bw.write("\n");
        bw.flush();
        return;
    }

}