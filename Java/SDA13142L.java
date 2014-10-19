import java.io.*;
import java.util.*;

public class SDA13142L {
	public static void main(String args[]) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			int nPulau		= Integer.parseInt(br.readLine());
			String p[]		= new String[20];
			String mucuh[]	= new String[20];
			Long b[]		= new Long[20];

			Boolean wisgelut = false;

			for(int i = 0; i < nPulau; i++) {
				p[i] = br.readLine();
				mucuh[i] = "";
				b[i] = new Long(0);
			}
			
			if(nPulau == 0) {
				System.out.println("Tidak ada pulau yang dikunjungi Luffy");
			}

			int nMusuh = Integer.parseInt(br.readLine());
			for(int i = 0; i < nMusuh; i++) {
				StringTokenizer s = new StringTokenizer(br.readLine());

				String nama = s.nextToken(" ");

				String pulau = s.nextToken(" ");

				long bounty = Long.parseLong(s.nextToken());
				//System.out.println(nama + "-" + pulau + "-" + bounty);

				Boolean gelut = false;

				for(int j = 0; j < nPulau; j++) {
					if(p[j].equals(pulau)) {
						//System.out.println("yeah " + j);
						if(mucuh[j].length() > 0) {
							mucuh[j] += " ";
						}
						mucuh[j] += nama;
						if(b[j] < bounty) {
							b[j] = bounty;
						}
						gelut = true;
						break;
					}
				}
				if(!wisgelut && gelut) wisgelut = gelut;
				if(!gelut) {
					System.out.println("Luffy tidak akan pergi ke " + pulau + " sehingga tidak akan menghadapi " + nama);
				}
			}
			if(!wisgelut) {
				System.out.println("Tidak ada musuh yang dihadapi Luffy");
			} else {
				for(int i = 0; i < nPulau; i++) {
					if(mucuh[i].length() > 0) {
						System.out.println(p[i] + " " + mucuh[i] + " " + b[i]);
					}
				}
			}

		} catch (IOException io) {

		}
	}
}