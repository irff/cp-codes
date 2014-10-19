import java.io.*;
import java.util.*;

public class TimSar {
	static String[] m = new String[600];
	static Boolean[][] vis = new Boolean[510][510];
	static PriorityQueue<Korban> gawan = new PriorityQueue<Korban>();
	static int bar, kol, counter = 0;
	static HashMap korbans = new HashMap();

	public static void main(String args[]) {

		Scanner sc = new Scanner(System.in);

		bar = sc.nextInt();
		kol = sc.nextInt();
		sc.nextLine();


		int awalx = 0, awaly = 0;

		for(int i = 0;  i < bar; i++) {
			m[i] = sc.nextLine();
			for(int j = 0; j < kol; j++) {
				if(m[i].charAt(j) == '#') {
					vis[i][j] = true;
				} else {
					vis[i][j] = false;
				}

				if(m[i].charAt(j) == 'S') {
					awalx = i;
					awaly = j;
				}
			}
		}

		while(sc.hasNextLine()) {
			String s = sc.nextLine();
			StringTokenizer st = new StringTokenizer(s);
			
			ArrayList<String> a = new ArrayList<String>();

			while(st.hasMoreElements()) {
				String now = st.nextElement().toString();
				//System.out.println(now);
				a.add(now);
			}
			int len = a.size();
			int kondisi = 0;
			
			int umur = countUmur(a.get(2));
			String nama = a.get(1);
			String posisi = a.get(0);
			//Kondisi = Baik
			if(len == 3) {
				kondisi = 3;
			} else
			//Kondisi = Panik
			if(len == 4) {
				kondisi = 2;
			} else {
				// Kondisi = Luka Berat
				if(a.get(4).charAt(0) == 'B') {
					kondisi = 0;
				} else
				// Kondisi = Luka Ringan
				{
					kondisi = 1;
				}
			}
			Korban k = new Korban(nama, 0, umur, kondisi);
			
			Daftar d = (Daftar) korbans.get(posisi);
			if(d != null) {
				d.addKorban(k);
				korbans.put(posisi, d);
			} else {
				korbans.put(posisi, new Daftar(k));
			}
		}
		dfs(awalx, awaly);
		System.out.println("PENCARIAN SELESAI");

		while(true) {
			Korban k = gawan.poll();
			if(k == null) break;
			System.out.println("Korban " + k.getNama() + " telah diselamatkan");
		}
		//Daftar x = (Daftar) korbans.get("1,6");
		//System.out.println(x.toString());

	}

	public static void dfs(int a, int b) {
		if(a >= 0 && a < bar && b >= 0 && b < kol && !vis[a][b]) {
			vis[a][b] = true;
			
			counter++;

			if(m[a].charAt(b) == 'W') {
				String pos = a + "," + b;
				Daftar x = (Daftar) korbans.get(pos);
				ArrayList<Korban> y = x.getKorbans();
				int len = y.size();
				for(int i = 0; i < len; i++) {
					Korban z = y.get(i);
					z.setNemu(counter);
					gawan.add(z);
				}
			}
			evakuasi(a,b);
			
			if(a > 0 && !vis[a-1][b]) {
				dfs(a-1, b);
				evakuasi(a,b);
			}
			
			if(b < kol-1 && !vis[a][b+1]) {
				dfs(a, b+1);
				evakuasi(a,b);
			}
			
			if(a < bar-1 && !vis[a+1][b]) {
				dfs(a+1, b);
				evakuasi(a,b);
			}

			if(b > 0 && !vis[a][b-1]) {
				dfs(a, b-1);
				evakuasi(a,b);
			}
		}
	}

	public static void evakuasi(int a, int b) {
		if(m[a].charAt(b) == 'E') {
			Korban top = gawan.poll();
			if(top != null) {
				System.out.println("Korban " + top.getNama() + " diselamatkan di evac point " + a + "," + b);
			}
		}		
	}

	public static int countUmur(String s) {
		int len = s.length(),
			dashpost = 0;

		boolean dash = false,
				less = false,
				equal = false,
				more = false;

		for(int i = 0; i < len; i++) {
			if(s.charAt(i) == '-') {
				dash = true;
				dashpost = i;
			} else if(s.charAt(i) == '<') less = true;
			else if(s.charAt(i) == '=') equal = true;
			else if(s.charAt(i) == '>') more = true;
		}
		long kiri = 0, kanan = 0;
		//U
		if(!dash && !less && !equal && !more) {
			kiri = Integer.parseInt(s);
			kanan = Integer.parseInt(s);
		} else
		// <U
		if(!dash && less && !equal && !more) {
			kiri = Integer.parseInt(s.substring(1,len)) - 1;
			kanan = kiri;
		} else
		// <=U
		if(!dash && less && equal && !more) {
			kiri = Integer.parseInt(s.substring(2,len));
			kanan = kiri;
		} else
		// >U
		if(!dash && !less && !equal && more) {
			kiri =  Integer.parseInt(s.substring(1,len)) + 1;
			kanan = kiri;
		} else
		//>=U
		if(!dash && !less && equal && more) {
			kiri = Integer.parseInt(s.substring(2,len));
			kanan = kiri;
		} else {
			kiri = Integer.parseInt(s.substring(0,dashpost));
			kanan = Integer.parseInt(s.substring(dashpost+1,len));
		}
		//Balita
		if(kiri < 5 && kanan < 5) return 0;
		//Anak-anak
		if(kiri >= 5 && kiri <= 12 && kanan >= 5 && kanan <= 12) return 1;
		//Lansia
		if(kiri > 64 && kanan > 64) return 2;
		//Remaja
		if(kiri >= 13 && kiri <= 19 && kanan >= 13 && kanan <= 19) return 3;
		//Dewasa
		if(kiri >= 20 && kiri <= 64 && kanan >= 20 && kanan <= 64) return 4;

		return -9999;
	}
}

class Daftar {
	ArrayList<Korban> k = new ArrayList<Korban>();
	public Daftar(Korban korban) {
		k.add(korban);
	}

	public void addKorban(Korban korban) {
		k.add(korban);
	}

	public ArrayList<Korban> getKorbans() {
		return k;
	}

	public String toString() {
		int len = k.size();
		String out = "";
		for(int i = 0; i < len; i++) {
			out = out + k.get(i).toString() + "\n";
		}
		return out;
	}
}

//belum di cek bener apa nggak
class Korban implements Comparable<Korban> {
	int nemu, umur, kondisi;
	String nama;

	public Korban(String nama, int nemu, int umur, int kondisi) {
		this.nama = nama;
		this.nemu = nemu;
		this.umur = umur;
		this.kondisi = kondisi;
	}

	public int getNemu() {
		return nemu;
	}

	public void setNemu(int nemu) {
		this.nemu = nemu;
	}

	public String getNama() {
		return nama;
	}

	public void setNama(String nama) {
		this.nama = nama;
	}

	public int getUmur() {
		return umur;
	}

	public void setUmur(int umur) {
		this.umur = umur;
	}

	public int getKondisi() {
		return kondisi;
	}

	public void setKondisi(int kondisi) {
		this.kondisi = kondisi;
	}

	public int compareTo(Korban b) {
		Korban a = this;
		if(a.getKondisi() == b.getKondisi()) {
			if(a.getUmur() == b.getUmur()) {
				if(a.getNemu() == b.getNemu()) {
					return a.getNama().toLowerCase().compareTo(b.getNama().toLowerCase());
				}
				return a.getNemu() - b.getNemu();
			}
			return a.getUmur() - b.getUmur();
		}

		return a.getKondisi() - b.getKondisi();
	}

	public String toString() {
		return this.getNama() +"-"+this.getUmur()+"-"+this.getKondisi();
	}
}