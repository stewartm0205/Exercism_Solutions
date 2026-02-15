package main.java;
import java.util.List;

public class BinarySearch<E extends Comparable<E>> {
    List<E> c;

    public BinarySearch (List<E> c) {
        this.c = c;
    }

    public long indexOf(E e) {

        int l = c.size() - 1;
        int i = l / 2;
        int b = 0;
        int t = l - 1;
        if (c.isEmpty()) { return -1;}
        if (e.compareTo(c.get(0)) < 0 || e.compareTo(c.get(l)) > 0) {
            return -1;
        }
        while (1 == 1) {
            if (c.get(i).equals(e)) {
                return (long) i;
            } else if (i < l && e.compareTo(c.get(i)) > 0 && e.compareTo(c.get(i + 1)) < 0) {
                return -1;
            } else if (e.compareTo(c.get(i)) > 0) {
                b = i;
                i = i + (t - i) / 2;
                if (i == b) i++;
            } else if (i > 0 && e.compareTo(c.get(i)) < 0 && e.compareTo(c.get(i - 1)) > 0) {
                return -1;
            } else if (e.compareTo(c.get(i)) < 0) {
                t = i;
                i = i - (i - b) / 2;
                if (i == t) i--;
            } else {
                return -1;
            }
        }
    }
}
