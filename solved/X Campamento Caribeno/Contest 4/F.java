import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;


public class F {

	public static void main(String []arg) throws IOException  {
		Scanner sc = new Scanner(System.in);
		Task solver = new Task();
		solver.solve(sc);

	}
}
class Task{
	public void solve(Scanner in) {
		int a = in.nextInt();
		BigInteger it = new BigInteger(in.nextBiginteger(), a);
		int b = in.nextInt();
		String ans = it.toString(b);
		System.out.print(ans);
	}
}

class Scanner {
	public BufferedReader reader;
	public StringTokenizer st;

	public Scanner(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		st = null;
	}

	public String next(){
		while(st == null || !st.hasMoreTokens()) {
			try{
				String line = reader.readLine();
				if(line == null) return null;
				st = new StringTokenizer(line);
			}catch (Exception e) {
				throw (new RuntimeException());
			}
		}
		return st.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public String nextBiginteger() {
		return next();
	}
}

