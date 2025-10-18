using System;

class BIT {
    int[] tree;
    int n;

    public BIT(int size) {
        n = size;
        tree = new int[n];
    }

    public void Update(int x, int val) {
        while (x < n) {
            tree[x] += val;
            x += x & -x;
        }
    }

    public int Get(int x) {
        int res = 0;
        while (x > 0) {
            res += tree[x];
            x -= x & -x;
        }
        return res;
    }
}

class Program {
    static void Main() {
        string[] parts = Console.ReadLine().Split();
        int n = int.Parse(parts[0]), m = int.Parse(parts[1]), q = int.Parse(parts[2]);

        BIT[,] bits = new BIT[m, m];

        for (int emp1 = 0; emp1 < m; emp1++) {
            for (int emp2 = emp1 + 1; emp2 < m; emp2++) {
                bits[emp1, emp2] = new BIT(n * 14 + 1);
                for (int week = 0; week < n; week++) {
                    for (int day = 0; day < 7; day++) {
                        for (int shift = 1; shift <= 2; shift++) {
                            int c = day < 5 ? 4 : 0;
                            bits[emp1, emp2].Update(week * 14 + 2 * day + shift, c);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < q; i++) {
            string[] query = Console.ReadLine().Split();
            int type = int.Parse(query[0]);

            if (type == 1) {
                int e = int.Parse(query[1]) - 1;
                int day = int.Parse(query[2]) - 1;
                for (int e2 = 0; e2 < m; e2++) {
                    if (e != e2) {
                        int x = Math.Min(e, e2);
                        int y = Math.Max(e, e2);
                        for (int shift = 1; shift <= 2; shift++) {
                            int r = day * 2 + shift;
                            int l = r > 1 ? bits[x, y].Get(r - 1) : 0;
                            if (bits[x, y].Get(r) - l == 4)
                                bits[x, y].Update(r, -4);
                        }
                    }
                }
            } else if (type == 2) {
                int e = int.Parse(query[1]) - 1;
                int day = int.Parse(query[2]) - 1;
                int half = int.Parse(query[3]);
                for (int e2 = 0; e2 < m; e2++) {
                    if (e != e2) {
                        int x = Math.Min(e, e2);
                        int y = Math.Max(e, e2);
                        int r = day * 2 + half;
                        int l = r > 1 ? bits[x, y].Get(r - 1) : 0;
                        if (bits[x, y].Get(r) - l == 4)
                            bits[x, y].Update(r, -4);
                    }
                }
            } else {
                int e1 = int.Parse(query[1]) - 1;
                int e2 = int.Parse(query[2]) - 1;
                int day = int.Parse(query[3]) - 1;
                int time = int.Parse(query[4]);
                int x = Math.Min(e1, e2), y = Math.Max(e1, e2);
                int s = 2 * day + 1, e = n * 14;
                int l = s > 1 ? bits[x, y].Get(s - 1) : 0;

                if (bits[x, y].Get(e) - l < time) {
                    Console.WriteLine(-1);
                    continue;
                }

                while (s < e) {
                    int mid = (s + e) / 2;
                    int cnt = bits[x, y].Get(mid) - l;
                    if (cnt < time) s = mid + 1;
                    else e = mid;
                }

                int res = (s % 2 == 1) ? s / 2 + 1 : s / 2;
                Console.WriteLine(res);
            }
        }
    }
}
