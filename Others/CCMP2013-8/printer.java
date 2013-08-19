import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class printer {
	
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
	
	static class point{
		double x,y,z;
		public point(double xx, double yy, double zz){
			x = xx;
			y = yy;
			z = zz;
		}
		point add(point o){
			return new point(x + o.x, y + o.y, z + o.z);
		}
		point sub(point o){
			return new point(x - o.x, y - o.y, z - o.z);
		}
		double dot(point o){
			return x * o.x + y * o.y + z * o.z;
		}
		point cross(point o){
			return new point(y * o.z - z * o.y, z * o.x - x * o.z, x * o.y - y * o.x );
		}
		double norm(){
			return Math.sqrt(this.dot(this));
		}
		point normalize(){
			return this.multbyscalar(1/this.norm());
		}
		point multbyscalar(double s){
			return new point(s * x, s * y, s * z);
		}
	}
	
	static class Face{
		point[] v;
		public Face(int tam){
			v = new point[tam];
		}
		point getnormal(){
			return v[1].sub(v[0]).cross(v[2].sub(v[0])).normalize();
		}
		double getarea(){
			double area = 0;
			point pivot = v[0];
			for(int i = 0; i < v.length; i++)
				area += v[i].sub(pivot).cross(v[(i + 1) % v.length].sub(pivot)).norm();
			return area/2.0;
		}
	}
	
	static point mean(Face[] p){
		point ret = new point(0, 0, 0);
		int amount = 0;
		for(int i = 0; i < p.length; i++)
			for(int j = 0; j < p[i].v.length; j++){
				ret = ret.add(p[i].v[j]);
				amount++;
			}
		return ret.multbyscalar(1.0/amount);
	}
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc = new Scanner();
		while(true){
			int N = sc.nextInt();
			if (N == 0) return;
			double area = 0;
			for(int p = 0; p < N; p++){
				int nfaces = sc.nextInt();
				Face[] fcs = new Face[nfaces];
				for(int i = 0; i < nfaces; i++){
					int nv = sc.nextInt();
					fcs[i] = new Face(nv);
					for(int j = 0; j < nv; j++)
						fcs[i].v[j] = new point(sc.nextDouble(), sc.nextDouble(), sc.nextDouble());
				}
				point mean = mean(fcs);
				for(int i = 0; i < nfaces; i++){
					Face cf = fcs[i];
					point P = mean.sub(cf.v[0]);
					area += cf.getarea() * (Math.abs(cf.getnormal().dot(P)));
				}
			}
			area = (area / 3);
			String cad = String.format("%.2f", area);
			System.out.println(cad);
		}
	}

}
