public class QuickFindUF {
    private int[] id;    // id[i] = component identifier of i
    //private int count;   // number of component

    public QuickFindUF(int n) {
        id = new int[n];
        for (int i = 0; i < n; i++)
            id[i] = i;
    }

    public boolean connected(int p, int q) {
        return id[p] == id[q];
    }

    public void union(int p, int q) {
        int pID = id[p];   // needed for correctness
        int qID = id[q];   // to reduce the number of array accesses
        for (int i = 0; i < id.length; i++)
            if (id[i] == pID) id[i] = qID;
    }

    public static void main(String[] args) {
        int n = StdIn.readInt();
        QuickFindUF uf = new QuickFindUF(n);
        while (!StdIn.isEmpty()) {
            int p = StdIn.readInt();
            int q = StdIn.readInt();
            if (uf.find(p) == uf.find(q)) continue;
            uf.union(p, q);
            StdOut.println(p + " " + q);
        }
        StdOut.println(uf.count() + " components");
    }

}
