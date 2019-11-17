import java.lang.reflect.Array;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args){
        ArrayList<Integer> wierz = new ArrayList<>();
        ArrayList<Integer> pw = new ArrayList<>();
        ArrayList<Integer> dr = new ArrayList<>();
        ArrayList<String> lb = new ArrayList<>();

        wierz.add(1);
        wierz.add(2);
        wierz.add(3);
        wierz.add(4);
        wierz.add(5);
        wierz.add(6);
        wierz.add(7);

        pw.add(1);
        dr.add(2);
        lb.add("Jeden");

        pw.add(4);
        dr.add(3);
        lb.add("Dwa");

        pw.add(2);
        dr.add(4);
        lb.add("Pomiedzy");

        pw.add(5);
        dr.add(6);
        lb.add("Kot");

        pw.add(5);
        dr.add(7);
        lb.add("Pies");


        Graf<Integer, String> graf = new Graf<>(wierz, pw, dr, lb);
        System.out.println(graf.wierzcholki().toString());
        System.out.println(graf.krawedz(1, 2));
        System.out.println(graf.krawedz(1, 3));
        System.out.println(graf.krawedzie(1));
        System.out.println(graf.krawedzie(2));
        System.out.println(graf.krawedzie(3));
        System.out.println(graf.krawedzie(4));
        System.out.println(graf.krawedzie(5));
        System.out.println(graf.krawedzie(6));
        System.out.println(graf.krawedzie(7));

        System.out.println(GrafFunkcje.droga(graf, 1, 3).toString());
        System.out.println(GrafFunkcje.skladowe(graf).toString());
    }
}
