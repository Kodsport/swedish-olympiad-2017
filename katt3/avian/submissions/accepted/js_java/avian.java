import java.util.*;

public class avian {
	
	public static String[] encode(int C, int K, int N, String X) {
		StringBuilder[] encoding = new StringBuilder[4];
		for (int i = 0; i < 4; i++) encoding[i] = new StringBuilder();
		for (int i = 0; i < N; i++) {
			char[] sub = X.substring(i * 3, i * 3 + 3).toCharArray();
			encoding[0].append(sub[0]);
			encoding[1].append(sub[1]);
			encoding[2].append(sub[2]);
			encoding[3].append((char)(sub[0] ^ sub[1] ^ sub[2]));
		}
		String[] enc = new String[4];
		for (int i = 0; i < 4; i++) enc[i] = encoding[i].toString();
		return enc;
	}

	public static String decode(int C, int K, int N, String[] Y, int[] I) {
		StringBuilder ret = new StringBuilder();
		for (int i = 0; i < N; i++) {
			char x = 0;
			char[] add = new char[3];
			for (int j = 0; j < 3; j++) {
				if (I[j] < 3) {
					add[I[j]] = Y[j].charAt(i);
				}
				x ^= Y[j].charAt(i);
			}
			for (int j = 0; j < 3; j++) {
				if (add[j] == 0) add[j] = x;
			}
			ret.append(add);
		}
		return ret.toString();
	}
}

