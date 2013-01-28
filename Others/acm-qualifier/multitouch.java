import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class multitouch
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

		double x, y;
		
		public Punto(double x2, double y2) 
		{
			x = x2;
			y = y2;
		}
		
		double normaSq()
		{
			return x * x + y * y;
		}
		
		double norma()
		{
			return Math.sqrt(x * x + y * y);
		}
		
		Punto resta(Punto otro)
		{
			return new Punto(x - otro.x, y - otro.y);
		}
		
		double dot(Punto a){
			return x*a.x + y*a.y;
		}
		
		double angle(Punto a){
			return Math.acos(this.dot(a)/(this.norma() * a.norma()));
		}
		
		double cross(Punto a){
			return x*a.y - a.x*y;
		}
	}
	
	static void floodFill(char[][] imagen, int x, int y, ArrayList <Punto> puntos)
	{
		if(x >= 0 && x < 15 && y >= 0 && y < 30)
		{
			if(imagen[x][y] == 'X')
			{
				imagen[x][y] = '.';
				puntos.add(new Punto(x, y));
				floodFill(imagen, x + 1, y, puntos);
				floodFill(imagen, x - 1, y, puntos);
				floodFill(imagen, x, y + 1, puntos);
				floodFill(imagen, x, y - 1, puntos);
			}
		}
	}

	private static void fill(ArrayList<Punto> grid, char[][] imagen) 
	{
		for(int i = 0; i < imagen.length; i++)
			for(int j = 0; j < imagen[i].length; j++)
			{
				if(imagen[i][j] == 'X')
				{
					ArrayList <Punto> estos = new ArrayList <Punto> ();
					floodFill(imagen, i, j, estos);
					grid.add(average(estos.toArray(new Punto[0])));
				}
			}
	}
	
	private static Punto average(Punto[] estos) 
	{
		double sumaX = 0;
		double sumaY = 0;
		for(Punto p : estos)
		{
			sumaX += p.x;
			sumaY += p.y;
		}
		sumaX /= estos.length;
		sumaY /= estos.length;
		return new Punto(sumaX, sumaY);
	}
	
	static Punto[] mejorPermutacion;
	static double mejorMetrica;
	
	static void permutar(Punto[] gridI, Punto[] gridF, Punto[] permutacion, boolean[] visitados, int n)
	{
		if(n == permutacion.length)
		{
			if(mejorPermutacion == null)
			{
				mejorPermutacion = permutacion.clone();
				mejorMetrica = metrica(gridI, permutacion);
			}
			else
			{
				double metrica = metrica(gridI, permutacion);
				if(metrica < mejorMetrica)
				{
					mejorMetrica = metrica;
					mejorPermutacion = permutacion.clone();
				}
			}
		}
		else
		{
			for(int i = 0; i < visitados.length; i++)
			{
				if(visitados[i])
					continue;
				visitados[i] = true;
				permutacion[n] = gridF[i];
				permutar(gridI, gridF, permutacion, visitados, n + 1);
				visitados[i] = false;
			}
		}
	}

	static double metrica(Punto[] gridI, Punto[] permutacion) 
	{
		double res = 0;
		for(int i = 0; i < gridI.length; i++)
			res += gridI[i].resta(permutacion[i]).normaSq();
		return res;
	}

	private static void corresponder(Punto[] gridI, Punto[] gridF) 
	{
		mejorPermutacion = null;
		permutar(gridI, gridF, new Punto[gridI.length], new boolean[gridI.length], 0);
		for(int i = 0; i < gridF.length; i++)
			gridF[i] = mejorPermutacion[i];
	}
	


	private static double pan(Punto[] gridI, Punto[] gridF) 
	{
		Punto a = average(gridI);
		Punto b = average(gridF);
		return Math.sqrt(a.resta(b).normaSq());
	}
	
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner();
		while(true)
		{
			
			char[][] imagen1 = new char[15][];
			char[][] imagen2 = new char[15][];
			for(int i = 0; i < 15; i++)
			{
				String linea = sc.nextLine();
				if(linea == null)
					return;
				linea = linea.trim();
				imagen1[i] = linea.substring(0, 30).toCharArray();
				imagen2[i] = linea.substring(31, 31 + 30).toCharArray();
			}
			ArrayList <Punto> gridIA = new ArrayList <Punto> ();
			ArrayList <Punto> gridFA = new ArrayList <Punto> ();
			fill(gridIA, imagen1);
			fill(gridFA, imagen2);
			Punto[] gridI = gridIA.toArray(new Punto[0]);
			Punto[] gridF = gridFA.toArray(new Punto[0]);
			corresponder(gridI, gridF);
			double panDistance = pan(gridI, gridF);
			double zoomDistance = zoom(gridI, gridF);
			double rotationDistance = rot(gridI, gridF);
			if(panDistance > zoomDistance && panDistance > rotationDistance)
				System.out.println(gridI.length + " pan");
			else if(zoomDistance > rotationDistance)
				System.out.println(gridI.length + " zoom " + (gripSpread(gridI) > gripSpread(gridF) ? "in" : "out"));
			else
				System.out.println(gridI.length + " rotate " + (gripRotation(gridI, gridF) > 0 ? "counter-clockwise" : "clockwise"));
		}
	}

	
	static double eps=1e-8;
	
	private static double gripRotation(Punto[] gridI, Punto[] gridF) {
		Punto cI = average(gridI);
		Punto cF = average(gridF);
		double acum = 0;
		for(int i = 0; i < gridI.length; i++)
		{
			Punto a = gridI[i].resta(cI);
			Punto b = gridF[i].resta(cF);
			if (a.norma()<eps || b.norma()<eps || a.angle(b)<eps)
				continue;
			if (Math.abs(a.cross(b))<eps){
				acum+=Math.PI;
				continue;
			}
			if (a.cross(b)>0)
				acum+=a.angle(b);
			else
				acum+= -a.angle(b);
		}
		return acum/gridI.length;
	}

	private static double rot(Punto[] gridI, Punto[] gridF) {
		
		return Math.abs(gripRotation(gridI, gridF)) * gripSpread(gridI);
	}

	private static double zoom(Punto[] gridI, Punto[] gridF)
	{
		return Math.abs(gripSpread(gridI) - gripSpread(gridF));
	}

	private static double gripSpread(Punto[] grid) 
	{
		Punto centro = average(grid);
		double acum = 0;
		for(int i = 0; i < grid.length; i++)
			acum += Math.sqrt(grid[i].resta(centro).normaSq());
		return acum / grid.length;
	}
}
