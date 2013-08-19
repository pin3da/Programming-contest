import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeMap;


public class worms {
	
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
	
	static class SegmentTree{
		int[] array;
		boolean max;
		int NN;
		public SegmentTree(int tam, boolean m){
			NN = tam;
			max =  m;
			tam = (tam<<2) + 4;
			array = new int[tam];
		}
		
		int get(int node, int b, int e, int i, int j){
			if(i>e || j < b)
				return max? Integer.MIN_VALUE : Integer.MAX_VALUE;
			
			if(b >= i && e <= j)
					return array[node];
			
			int p1 = get(node<<1, b, (b+e)>>1, i, j);
			int p2 = get((node<<1)+1, ((b+e)>>1)+1 , e, i, j);
			
			if(max) return Math.max(p1, p2);
			else return Math.min(p1,p2);
			
		}
					
				
		int get(int l, int r){
			return get(1,0,NN -1, l,r);
		}
		
		void set(int node, int b, int e, int pos, int value){
			if(pos > e || pos < b)
				return;
			
			if(b==e){
				//System.out.println(node);
				array[node] = value;
				return;
			}
			
			set(node<<1, b, (b+e)>>1, pos, value);
			set((node<<1)+1, ((b+e)>>1)+1, e, pos,value);
			
			if(max) array[node] = Math.max(array[node<<1], array[(node<<1)+1]);
			else array[node] = Math.min(array[node<<1], array[(node<<1)+1]);
			
		}
		
		void set(int pos, int val){
			set(1,0,NN - 1 , pos,val);
		}
	}
	
	static int comparacion ;
	
	static class Node implements Comparable<Node>{
		int x;
		int radius;
		int indexoriginal;
		int index;
		public Node(int xx, int rr, int idx){
			x = xx;
			radius = rr;
			indexoriginal = idx;
			index = 0;
		}
		@Override
		public int compareTo(Node o) {
			if (comparacion == 0)
				return x - o.x;
			else
				return o.radius - radius;
		}
	}
	
	static Node[] array;
	static int[] izq,der;
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc = new Scanner();
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		while(true){
			int N = sc.nextInt();
			if ( N == 0) break;
			comparacion = 0;
			array = new Node[N];
			for(int i = 0; i< N; i++)
				array[i] = new Node(sc.nextInt(), sc.nextInt(), i);
			Arrays.sort(array);
			for(int i = 0;i < N; i++)
				array[i].index = i;
			izq = new int[N];
			der = new int[N];
			TreeMap<Integer,Integer> map = new TreeMap<Integer,Integer>();
			SegmentTree sleft = new SegmentTree(N,false);
			for(int i = 0; i < N; i++){
				map.put(array[i].x, i);
				sleft.set(i, i);
				int alcanzado = array[i].x - array[i].radius;
				int leftindex = map.ceilingKey(alcanzado);
				int value = sleft.get(map.get(leftindex), i);
				sleft.set(i, value);
				izq[i] = value;
			}
			map.clear();
			SegmentTree sright = new SegmentTree(N,true);
			for(int i = N - 1; i >= 0; i--){
				map.put(array[i].x, i);
				sright.set(i, i);
				int alcanzado = array[i].x + array[i].radius;
				int rightindex = map.floorKey(alcanzado);
				int value = sright.get(i,map.get(rightindex));
				sright.set(i, value);
				der[i] = value;
			}
			//
			comparacion = 1;
			Node[] copy = new Node[N];
			for(int i = 0; i < N; i++)
				copy[i] = array[i];
			Arrays.sort(copy);
			for(int j = 0; j < N; j++){
				int i = copy[j].index;
				int a = sleft.get(izq[i], i);
				int b = sright.get(izq[i], i);
				int c = sleft.get(i,der[i]);
				int d = sright.get(i,der[i]);
				int min = Math.min(Math.min(a, b), Math.min(c, d));
				int max = Math.max(Math.max(a, b), Math.max(c, d));
				sleft.set(i, min);
				sright.set(i, max);
				izq[i] = min;
				der[i] = max;
			}
			//
			boolean primero = true;
			int[] aux = new int[N];
			for(int i = 0; i < N; i++)
				aux[array[i].indexoriginal] = der[i] - izq[i] + 1; 
			for(int i = 0; i < N; i++){
				if (!primero)
					bw.write(" ");
				bw.write(aux[i]+"");
				primero = false;
			}
			bw.write("\n");
		}
		bw.flush();
	}

}