import java.util.*;
public class avian {
    public static String[] encode(int C, int K, int N, String X) {
        String[] ret = new String[K];
        if(K == 4 && C == 3) {
            ret[0] = X.substring(0,N);
            ret[1] = X.substring(N, 2*N);
            ret[2] = X.substring(2*N);
            ret[3] = xor(ret[0], ret[1], ret[2]);
        } 
        return ret;
    }
    private static String xor(String a, String b) {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i<a.length(); i++) {
            sb.append(a.charAt(i) == b.charAt(i)?"0":"1");
        }
        return sb.toString();
    }
    private static String xor(String a, String b, String c) {
        return xor(xor(a,b),c);
    }

    private static int indexOf(int x, int[] I) {
        for(int i = 0; i<I.length; i++) {
            if(I[i] == x) return i;
        }
        return -1;
    }
    public static String decode(int C, int K, int N, String[] Y, int[] I) {
        String[] ret = new String[3];
        for(int i = 0; i<3; i++) if(indexOf(i, I) != -1) {
            ret[i] = Y[indexOf(i, I)];
        }
        if(indexOf(3, I) != -1) {
            for(int i = 0; i<3; i++) {
                if(ret[i] == null) ret[i] = xor(Y[0], Y[1], Y[2]);
            }
        }
        return ret[0] + ret[1] + ret[2];

    }
}

