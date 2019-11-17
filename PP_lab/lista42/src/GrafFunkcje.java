import java.util.*;

class GrafFunkcje {
    private static <W, S> boolean drogaPom(Graf<W, S> graf, W w1, W w2, List<W> stos, Set<W> odw) {
        odw.add(w1);
        stos.add(w1);
        if (w1.equals(w2)) return true;

        for (W n : graf.krawedzie(w1)) {
            if (!odw.contains(n)) {
                if (drogaPom(graf, n, w2, stos, odw)) return true;
            }
        }
        stos.remove(stos.size() - 1);
        return false;

    }

    public static <W, S> List<S> droga(Graf<W, S> graf, W w1, W w2) {
        Set<W> odwiedzone = new HashSet<>();
        List<W> stos = new ArrayList<>();
        List<S> stos2 = new ArrayList<>();

        if (!drogaPom(graf, w1, w2, stos, odwiedzone)) return null;
        for (int i = stos.size() - 1; i >= 1; i--) {
            stos2.add(graf.krawedz(stos.get(i - 1), stos.get(i)));
        }

        return stos2;
    }

    private static <W, S> void skladowePom(Graf<W, S> graf, W w1, int cn, HashMap<W, Integer> c) {
        Set<W> odwiedzone = new HashSet<>();
        List<W> stos = new ArrayList<>();
        stos.add(w1);
        odwiedzone.add(w1);
        c.replace(w1, cn);

        while (!stos.isEmpty()) {
            W tp = stos.remove(stos.size() - 1);
            if (!tp.equals(w1) && droga(graf, w1, tp) != null) c.replace(tp, cn);
            for (W sas : graf.krawedzie(tp)) {
                if (!odwiedzone.contains(sas)) {
                    stos.add(sas);
                    odwiedzone.add(sas);
                }
            }
        }
    }

    public static <W, S> HashMap<W, Integer> skladowe(Graf<W, S> graf) {
        HashMap<W, Integer> c = new HashMap<>();
        for(W w : graf.wierzcholki())
            c.put(w, 0);
        int cn = 0;
        int n = graf.wierzcholki().size();
        for(W w : graf.wierzcholki())
        {
            if(c.get(w) > 0) continue;

            cn += 1;
            skladowePom(graf, w, cn, c);
        }

        return c;
    }

}
