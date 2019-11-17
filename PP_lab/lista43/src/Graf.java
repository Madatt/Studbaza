import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Graf<W, S> implements IGraf<W, S>  {
    public Graf(HashMap<W,  HashMap<W, S>> krawedzieArg) {
        krawedzieMap = krawedzieArg;
        wierzcholkiArr = new ArrayList<>(krawedzieMap.keySet());
    }

    public Graf(List<W> wierzcholkiList, List<W> pr, List<W> dr, List<S> lb) {
        wierzcholkiArr = new ArrayList<>(wierzcholkiList);
        krawedzieMap = new HashMap<>();
        for(W w : wierzcholkiArr)
            krawedzieMap.put(w, new HashMap<>());

        for(int i = 0; i < pr.size(); i++)
            krawedzieMap.get(pr.get(i)).put(dr.get(i), lb.get(i));
    }

    @Override
    public List<W> wierzcholki() {
        return wierzcholkiArr;
    }

    @Override
    public S krawedz(W w1, W w2) {
        HashMap<W, S> h = krawedzieMap.get(w1);
        if(h == null)
            return null;
        return h.get(w2);
    }

    @Override
    public List<W> krawedzie(W w) {
        HashMap<W, S> h = krawedzieMap.get(w);
        if(h == null)
            return new ArrayList<>();
        return new ArrayList<>(h.keySet());
    }

    private HashMap<W,  HashMap<W, S>> krawedzieMap;
    private List<W> wierzcholkiArr;


}
