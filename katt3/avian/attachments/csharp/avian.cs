using System.Text;

public class avian {

	public static string[] Encode(int C, int K, int N, string X) {
		string[] ret = new string[K];
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < N; i++) {
			sb.Append("0");
		}
		ret[0] = sb.ToString();
		for (int i = 1; i < K; i++) ret[i] = ret[0];
		return ret;
	}

	public static string Decode(int C, int K, int N, string[] Y, int[] I) {
		StringBuilder ret = new StringBuilder();
		for (int i = 0; i < C*N; i++) {
			ret.Append("0");
		}
		return ret.ToString();
	}
}

