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
            String a = half(ret[0], ret[1]);
            ret[3] = xor(ret[0], shiftL(a), ret[1]);
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
    private static String shiftR(String a) {
        return a.substring(1) + a.charAt(0);
    }
    private static String shiftL(String a) {
        return a.charAt(a.length() - 1) + a.substring(0,a.length() - 1);
    }
    private static String half(String a, String b) {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i<a.length(); i++) {
            sb.append(i%2 == 0?a.charAt(i):b.charAt(i));
        }
        return sb.toString();
    }

    private static String halfXor(String a, String b) {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i<a.length(); i++) {
            if(i%2 == 0) sb.append(a.charAt(i));
            else sb.append(a.charAt(i) == b.charAt(i)?"0":"1");
        }
        return sb.toString();
    }
    private static String halfXor2(String a, String b) {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i<a.length(); i++) {
            if(i%2 == 1) sb.append(a.charAt(i));
            else sb.append(a.charAt(i) == b.charAt(i)?"0":"1");
        }
        return sb.toString();
    }
    private static String resolveA(String ab, String b) {
        String x = xor(ab, b);
        String bsh = shiftL(b);
        String aa = halfXor2(x, bsh);
        //remove double aa's.
        return halfXor(aa, shiftL(aa));
    }
    private static String resolveB(String ab, String a) {
        String x = xor(ab, a);
        String ash = shiftL(a);
        String bb = halfXor(x, ash);
        //remove double aa's.
        String s = halfXor2(bb, shiftL(bb));
        if (s.length() % 2 == 0) return s;
        char cor = (char)((s.charAt(0) ^ ab.charAt(ab.length() - 1)) + '0');
        return cor + s.substring(1);
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
                ret[0] = halfXor(shiftR(a), ret[2]);
                ret[1] = xor(ret[0], ret[2]);
            } else if((ret[0] == null || ret[1] == null) && ret[3] == null) {
                if(ret[0] == null) ret[0] = xor(ret[1], ret[2]);
                else ret[1] = xor(ret[0], ret[2]);
            } else if(ret[0] == null && ret[2] == null) {
                ret[0] = resolveA(ret[3], ret[1]);
            } else if(ret[1] == null && ret[2] == null){
                ret[1] = resolveB(ret[3], ret[0]);
            }
            return ret[0] + ret[1];
        }
        return "";
    }
}
