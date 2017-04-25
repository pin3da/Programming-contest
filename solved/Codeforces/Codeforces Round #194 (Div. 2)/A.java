// http://codeforces.com/contest/334/problem/A

import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Manuel Pineda
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n  = in.nextInt();

        int a = 1, b = n*n;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j< n/2; ++j){
                out.print(a++ +  " " + b-- + " ");
            }
            out.println();
        }

    }
}

