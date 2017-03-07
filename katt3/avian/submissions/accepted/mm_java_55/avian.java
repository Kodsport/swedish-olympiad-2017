import java.util.*;
public class avian {
    public static String[] encode(int C, int K, int N, String X) {
        String[] ret = new String[K];
        if(K == 4 && C == 3) {
            ret[0] = X.substring(0,N);
            ret[1] = X.substring(N, 2*N);
            ret[2] = X.substring(2*N);
            ret[3] = xor(ret[0], ret[1], ret[2]);
        } else if(K == 4 && C == 2){
            ret[0] = X.substring(0,N);
            ret[1] = X.substring(N);
            ret[2] = xor(ret[0], ret[1]);
            String a1 = ret[0].substring(0,N/2);
            String a2 = ret[0].substring(N/2);
            String b1 = ret[1].substring(0,N/2);
            String b2 = ret[1].substring(N/2);
            ret[3] = xor(a1,b1,b2) + xor(a2,a1,b2);
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
        if(K == 4 && C == 3) {
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

        } else if(K == 4 && C == 2) {
            String[] ret = new String[4];
            for(int i = 0; i<4; i++) if(indexOf(i, I) != -1) ret[i] = Y[indexOf(i, I)];
            if(ret[0] == null && ret[1] == null) {
                String a = xor(ret[2], ret[3]);
                String b2 = a.substring(0,N/2);
                String a1 = a.substring(N/2);
                String b1 = xor(ret[2].substring(0,N/2), a1);
                String a2 = xor(ret[2].substring(N/2), b2);
                ret[0] = a1+a2;
                ret[1] = b1+b2;
            } else if((ret[0] == null || ret[1] == null) && ret[3] == null) {
                if(ret[0] == null) ret[0] = xor(ret[1], ret[2]);
                else ret[1] = xor(ret[0], ret[2]);
            } else if(ret[0] == null && ret[2] == null) {
                String b1 = ret[1].substring(0,N/2);
                String b2 = ret[1].substring(N/2);
                String a1 = xor(ret[3].substring(0,N/2), b1, b2);
                String a2 = xor(ret[3].substring(N/2), a1, b2);
                ret[0] = a1 + a2;
            } else if(ret[1] == null && ret[2] == null){
                String a1 = ret[0].substring(0,N/2);
                String a2 = ret[0].substring(N/2);
                String b2 = xor(ret[3].substring(N/2), a1, a2);
                String b1 = xor(ret[3].substring(0, N/2), b2, a1);
                ret[1] = b1 + b2;
            }
            return ret[0] + ret[1];
        }
        return "";
    }
}

