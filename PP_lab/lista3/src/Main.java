import java.util.ArrayList;
import java.util.Arrays;

public class Main {

    public static <T> T[] duplicate(T[] l1, int[] l2) {
        ArrayList<T> res = new ArrayList<>();
        int c = 0;
        for (T e : l1) {
            if (c < l2.length) {
                for (int i = 0; i < l2[c]; i++) {
                    res.add(e);
                }
                c++;
            }
        }
        return (T[]) res.toArray();
    }


    public static void main(String[] args) {
        Integer[] l1 = {1, 2, 3, 4, 5};
        int[] l2 = {5, 4, -3, 1, 4};

        System.out.println(Arrays.toString(duplicate(l1, l2)));
    }
}
