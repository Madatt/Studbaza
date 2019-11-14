import java.util.List;

public interface IGraf<W, S> {
    List<W> wierzcholki();
    S krawedz(W w1, W w2);
    List<W> krawedzie(W w);
}