import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class hittingtargets 
{
	static class Scanner
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");
		
		String nextLine()
		{
			try
			{
				return br.readLine();
			}
			catch(Exception e)
			{
				throw(new RuntimeException(e));
			}
		}
		
		String next()
		{
			while(!st.hasMoreTokens())
			{
				String linea = nextLine();
				if(linea == null)
					return linea;
				st = new StringTokenizer(linea);
			}
			return st.nextToken();
		}
		
		Integer nextInteger()
		{
			String line = next();
			if(line == null)
				return null;
			return Integer.parseInt(line);
		}
		
		int nextInt()
		{
			return Integer.parseInt(next());
		}
	}
	
	static class Punto
	{
		public Punto(int a, int b) {
			x=a;
			y=b;
		}

		int x, y;
	}
	
	static class Rectangulo
	{
		Punto a;
		Punto b;
		
		public Rectangulo(Punto aa, Punto bb) {
			a=aa;
			b=bb;
		}

		boolean inside(Punto c)
		{
			if(c.x >= a.x && c.x <= b.x && c.y>=a.y && c.y<=b.y)
				return true;
			return false;
		}
	}
	
	
	static class Circulo
	{
		Punto a;
		int radio;
		
		public Circulo(Punto aa, int bb) {
			a=aa;
			radio=bb;
		}

		boolean inside(Punto c)
		{
			int sqdist=(c.x - a.x)*(c.x - a.x) + (c.y - a.y)*(c.y - a.y);
			return (sqdist<=radio*radio);
		}
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner();
		while(true){
			LinkedList<Rectangulo> rects=new LinkedList<Rectangulo>();
			LinkedList<Circulo> circs=new LinkedList<Circulo>();
			Integer m=sc.nextInteger();
			if (m==null)
				return;
			for(int i=0;i<m;i++){
				String cad=sc.next();
				if (cad.charAt(0)=='r'){
					Rectangulo tmp=new Rectangulo(new Punto(sc.nextInt(),sc.nextInt()),new Punto(sc.nextInt(),sc.nextInt()));
					rects.add(tmp);
				}
				else{
					Circulo tmp=new Circulo(new Punto(sc.nextInt(),sc.nextInt()),sc.nextInt());
					circs.add(tmp);
				}
			}
			int n=sc.nextInt();
			for(int i=0;i<n;i++){
				Punto pt=new Punto(sc.nextInt(),sc.nextInt());
				int times=0;
				for(Rectangulo re: rects)
					times+=(re.inside(pt))?1:0;
				for(Circulo ci: circs)
					times+=(ci.inside(pt))?1:0;
				System.out.println(times);
			}
		}
	}

}
