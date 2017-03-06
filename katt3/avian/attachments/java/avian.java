import java.util.*;

public class avian {

	public static String[] encode(int C, int K, int N, String X) {
		String[] ret = new String[K];
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < N; i++) {
			sb.append("0");
		}
		ret[0] = sb.toString();
		for (int i = 1; i < K; i++) ret[i] = ret[0];
		return ret;
	}

	public static String decode(int C, int K, int N, String[] Y, int[] I) {
		StringBuilder ret = new StringBuilder();
		for (int i = 0; i < C*N; i++) {
			ret.append("0");
		}
		return ret.toString();
	}
}

