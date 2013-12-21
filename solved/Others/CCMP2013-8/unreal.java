
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.util.TreeSet;


public class unreal {
	
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
	
	
	static boolean comparacion = true;
	
	static class Event implements Comparable<Event>{
		double x;
		double y1,y2;
		boolean type;
		int id;
		public Event(double xx,double yy1, double yy2, boolean t,int idd){
			x = xx;
			y1 = yy1;
			y2 = yy2;
			type = t;
			id = idd;
		}
		@Override
		public int compareTo(Event o) {
			if (comparacion)
				return Double.compare(x, o.x);
			else{
				if (Math.abs(y1 - o.y1)< eps)
					return this.id - o.id;
				return Double.compare(y1, o.y1);
			}
		}
	}
	
	static double eps = 1e-8;
	
	static double compute_area(TreeSet<Event> l, double anterior,double actual){
		double area = 0.0;
		if (l.size() == 0) return area;
		Event ant = l.first();
		for(Event e:  l){
			if (e.y2 > ant.y2 + eps){
				area += Math.min(e.y1, ant.y2) - ant.y1;
				ant = e;
			}
		}
		area += ant.y2 - ant.y1;
		return (actual - anterior) * area;
	}
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc = new Scanner();
		while(true){
			comparacion = true;
			int N = sc.nextInt();
			if(N == 0) return;
			LinkedList<Event> lista = new LinkedList<Event>();
			for(int i = 0; i < N ; i++){
				double x1 = sc.nextDouble();
				double y1 = sc.nextDouble();
				double x2 = sc.nextDouble();
				double y2 = sc.nextDouble();
				lista.add(new Event(x1,y1,y2,true,i));
				lista.add(new Event(x2,y1,y2,false,i));
			}
			Collections.sort(lista);
			comparacion = false;
			double ant = lista.getFirst().x;
			double area = 0.0;
			TreeSet<Event> DS = new TreeSet<Event>();
			for(Event e: lista){
				area += compute_area(DS, ant, e.x);
				if (!e.type)
					DS.remove(e);
				else
					DS.add(e);
				ant = e.x;
			}
			String cad = String.format("%.2f", area);
			cad = cad.replace(",", ".");
			System.out.println(cad);
		}
	}

}
