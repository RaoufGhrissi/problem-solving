import java.util.*;

public class Scheduler {
    static class BIT {
        int[] tree;
        int n;

        public BIT(int n) {
            this.n = n;
            tree = new int[n];
        }

        void update(int x, int val) {
            while (x < n) {
                tree[x] += val;
                x += x & -x;
            }
        }

        int get(int x) {
            int res = 0;
            while (x > 0) {
                res += tree[x];
                x -= x & -x;
            }
            return res;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(), m = sc.nextInt(), q = sc.nextInt();
        BIT[][] bits = new BIT[m][m];

        for (int emp1 = 0; emp1 < m; emp1++) {
            for (int emp2 = emp1 + 1; emp2 < m; emp2++) {
                bits[emp1][emp2] = new BIT(n * 14 + 1);
                for (int week = 0; week < n; week++) {
                    for (int day = 0; day < 7; day++) {
                        for (int shift = 1; shift <= 2; shift++) {
                            int val = day < 5 ? 4 : 0;
                            bits[emp1][emp2].update(week * 14 + 2 * day + shift, val);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < q; i++) {
            int type = sc.nextInt();
            if (type == 1) {
                int e = sc.nextInt() - 1, day = sc.nextInt() - 1;
                for (int e2 = 0; e2 < m; e2++) {
                    if (e != e2) {
                        int x = Math.min(e, e2), y = Math.max(e, e2);
                        for (int shift = 1; shift <= 2; shift++) {
                            int r = day * 2 + shift;
                            int l = r > 1 ? bits[x][y].get(r - 1) : 0;
                            if (bits[x][y].get(r) - l == 4)
                                bits[x][y].update(r, -4);
                        }
                    }
                }
            } else if (type == 2) {
                int e = sc.nextInt() - 1, day = sc.nextInt() - 1, half = sc.nextInt();
                for (int e2 = 0; e2 < m; e2++) {
                    if (e != e2) {
                        int x = Math.min(e, e2), y = Math.max(e, e2);
                        int r = day * 2 + half;
                        int l = r > 1 ? bits[x][y].get(r - 1) : 0;
                        if (bits[x][y].get(r) - l == 4)
                            bits[x][y].update(r, -4);
                    }
                }
            } else {
                int e1 = sc.nextInt() - 1, e2 = sc.nextInt() - 1, day = sc.nextInt() - 1, time = sc.nextInt();
                int x = Math.min(e1, e2), y = Math.max(e1, e2);
                int s = 2 * day + 1, e = n * 14;
                int l = s > 1 ? bits[x][y].get(s - 1) : 0;

                if (bits[x][y].get(e) - l < time) {
                    System.out.println(-1);
                    continue;
                }

                while (s < e) {
                    int mid = (s + e) / 2;
                    int cnt = bits[x][y].get(mid) - l;
                    if (cnt < time) s = mid + 1;
                    else e = mid;
                }

                System.out.println((s % 2 == 1) ? s / 2 + 1 : s / 2);
            }
        }
    }
}
