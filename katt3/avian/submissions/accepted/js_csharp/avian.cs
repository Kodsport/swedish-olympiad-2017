using System.Text;

public class avian {

	public static string[] Encode(int C, int K, int N, string X) {
		StringBuilder[] encoding = new StringBuilder[4];
		for (int i = 0; i < 4; i++) encoding[i] = new StringBuilder();
		for (int i = 0; i < N; i++) {
			char[] sub = X.Substring(i * 3, 3).ToCharArray();
			encoding[0].Append(sub[0]);
			encoding[1].Append(sub[1]);
			encoding[2].Append(sub[2]);
			encoding[3].Append((char)(sub[0] ^ sub[1] ^ sub[2]));
		}
		string[] enc = new string[4];
		for (int i = 0; i < 4; i++) enc[i] = encoding[i].ToString();
		return enc;
	}

	public static string Decode(int C, int K, int N, string[] Y, int[] I) {
		StringBuilder ret = new StringBuilder();
		for (int i = 0; i < N; i++) {
			char x = (char)0;
			char[] add = new char[3];
			for (int j = 0; j < 3; j++) {
				if (I[j] < 3) {
					add[I[j]] = Y[j][i];
				}
				x ^= Y[j][i];
			}
			for (int j = 0; j < 3; j++) {
				if (add[j] == 0) add[j] = x;
			}
			ret.Append(add);
		}
		return ret.ToString();
	}
}

