import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class maps {
	
	static class Scanner{
		BufferedReader rd;
		StringTokenizer tk;
		public Scanner(){
			rd = new BufferedReader(new InputStreamReader(System.in));
			tk = null;
		}
		String next() throws IOException{
			while(tk == null || !tk.hasMoreTokens()){
				tk = new StringTokenizer(rd.readLine());
			}
			return tk.nextToken();
		}
		int nextInt() throws NumberFormatException, IOException{
			return Integer.valueOf(next());
		}
		double nextDouble() throws NumberFormatException, IOException{
			return Double.valueOf(next());
		}
	}
	
	static class point{
		double x,y;
		public point(double xx, double yy){
			x = xx;
			y = yy;
		}
		point add(point o){
			return new point(x + o.x, y + o.y);
		}
		point sub(point o){
			return new point(x - o.x, y - o.y);
		}
		point rotate(double the){
			the = (Math.PI / 180.0) * the;
			return new point(x * Math.cos(the) - y * Math.sin(the), x * Math.sin(the) + y * Math.cos(the));
		}
		point scale(double s){
			return new point(x * s, y * s);
		}
	}
	
	
	static double eps = 1e-8;
	
	static boolean thesame(point a, point b){
		if (Math.abs(a.x - b.x) < eps && Math.abs(a.y - b.y) < eps )
			return true;
		return false;
	}
	
	public static void main(String args[]) throws NumberFormatException, IOException
	{
		Scanner sc = new Scanner();
		while(true){
			int w = sc.nextInt();
			int h = sc.nextInt();
			int x = sc.nextInt();
			int y = sc.nextInt();
			int s = sc.nextInt();
			int r = sc.nextInt();
			if (w == 0 && h == 0 && x == 0 && y == 0 && s == 0 && r ==0)
				return;
			point ant_origin = new point(x, y);
			point ant_rotated = new point(x, y);
			point actual_origin, actual_rotated;
			while(true){
				actual_origin = ant_origin.scale(s / 100.0).rotate(r);
				actual_rotated = ant_rotated.add(actual_origin);
				if (thesame(ant_rotated, actual_rotated))
					break;
				ant_origin = actual_origin;
				ant_rotated = actual_rotated;
			}
			String res = String.format("%.2f %.2f", actual_rotated.x, actual_rotated.y);
			res = res.replace(",", ".");
			System.out.println(res);
		}
	}
}
