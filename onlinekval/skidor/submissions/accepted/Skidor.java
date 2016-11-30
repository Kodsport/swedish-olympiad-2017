import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.TreeSet;
public class Skidor {
    private static class Pair {
        int min;
        int max;
        public Pair(int min, int max) {
            this.min = min; this.max = max;
        }
    }
    private static class Tuple implements Comparable<Tuple> {
        int val;
        int id;
        public Tuple(int val, int id) {
            this.val = val; this.id = id;
        }
        public int compareTo(Tuple t) {
            if(val != t.val) return val - t.val;
            return id - t.id;
        }
    }
    public static void main(String args[]) {
        Sc sc = new Sc(System.in);
        int R = sc.nI();
        int C = sc.nI();
        int L = sc.nI();
        int[][] map = new int[R][C];
        for(int i = 0; i<R; i++) {
            for(int j = 0; j<C; j++) {
                map[i][j] = sc.nI();
            }
        }

        Pair[][] rows = new Pair[R][C-L+1];
        for(int i = 0; i<R; i++) {
            TreeSet<Tuple> que = new TreeSet<>();
            for(int j = 0; j<L; j++) {
                que.add(new Tuple(map[i][j],j));
            }
            rows[i][0] = new Pair(que.first().val, que.last().val);
            for(int j = L; j<C; j++) {
                que.remove(new Tuple(map[i][j-L],j-L));
                que.add(new Tuple(map[i][j], j));
                rows[i][j-L+1] = new Pair(que.first().val, que.last().val);
            }
        }

        Pair[][] cols = new Pair[R-L+1][C-L+1];
        for(int j = 0; j<C-L+1; j++) {
            TreeSet<Tuple> que = new TreeSet<>();
            for(int i = 0; i<L; i++) {
                que.add(new Tuple(rows[i][j].max, i));
                que.add(new Tuple(rows[i][j].min, -i-1));
            }
            cols[0][j] = new Pair(que.first().val, que.last().val);
            for(int i = L; i<R; i++) {
                que.remove(new Tuple(rows[i-L][j].max, i-L));
                que.remove(new Tuple(rows[i-L][j].min, -(i-L)-1));
                que.add(new Tuple(rows[i][j].max, i));
                que.add(new Tuple(rows[i][j].min, -i-1));
                cols[i-L+1][j] = new Pair(que.first().val, que.last().val);
            }
        }

        int x = -1;
        int y = -1;
        int mindiff = Integer.MAX_VALUE;
        for(int i = 0; i<R-L+1; i++) {
            for(int j = 0; j<C-L+1; j++) {
                if(cols[i][j].min != -1) {
                    int diff = cols[i][j].max - cols[i][j].min;
                    if(diff<mindiff) {
                        mindiff = diff;
                        x = i;
                        y = j;
                    }
                }
            }
        }
        System.out.println(x + " " + y);

    }
}
class Sc {
    public Sc(InputStream i) {
        r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasM() {
        return peekToken() != null;
    }

    public int nI() {
        return Integer.parseInt(nextToken());
    }

    public double nD() { 
        return Double.parseDouble(nextToken());
    }

    public long nL() {
        return Long.parseLong(nextToken());
    }

    public String n() {
        return nextToken();
    }

    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
        if (token == null) 
            try {
                while (st == null || !st.hasMoreTokens()) {
                    line = r.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
                token = st.nextToken();
            } catch (IOException e) { }
        return token;
    }

    private String nextToken() {
        String ans = peekToken();
        token = null;
        return ans;
    }
}