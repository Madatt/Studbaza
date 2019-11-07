import java.util.ArrayList;
import java.util.Arrays;

public class Main {

    public static int[] duplicate(int[] l1, int[] l2)
    {
        int size = 0;
        int tmp = Math.min(l1.length, l2.length);
        for(int i = 0; i < tmp; i++)
            if(l2[i] > 0) size += l2[i];

        int[] res = new int[size];

        int c = 0;
        for(int i = 0; i < tmp; i++) {
            for(int j = 0; j < l2[i]; j++) {
                res[c++] = l1[i];
            }
        }

        return res;
    }


    public static void main(String[] args) {
        int[] l1 = {1, 2, 3, 4, 5};
        int[] l2 = {5, 4, -3, 1, 4};
        int[] l3 = {-3, 1, 4};
        int[] l4 = {5, 12, 22, 1, 4, 3, 7};
        int[] l5 = {1, 1};
        int[] l6 = {5};
        int[] l7 = {1, 2, 3};
        int[] l8 = {};

        System.out.println(Arrays.toString(duplicate(l1, l2)));
        System.out.println(Arrays.toString(duplicate(l3, l4)));
        System.out.println(Arrays.toString(duplicate(l5, l6)));
        System.out.println(Arrays.toString(duplicate(l7, l8)));
    }

}

    /*public static <T> T[] duplicate(T[] l1, int[] l2) {
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
    }*/