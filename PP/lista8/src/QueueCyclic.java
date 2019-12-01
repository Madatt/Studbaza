import java.util.ArrayList;

public class QueueCyclic<E> implements MyQueue<E> {
    private int f;
    private int r;
    private ArrayList<E> array;
    public QueueCyclic(int n) {
        array = new ArrayList<>(n);
        for(int i = 0; i < n; i++)
            array.set(i, null);
    }

    @Override
    public void enqueue(E x) throws FullException {
        if(isFull()) throw new FullException();
        array.set(r, x);
        r = (r + 1) % array.size();
    }

    @Override
    public void dequeue() {
        if(isEmpty()) return;
        r = (f + 1) % array.size();
    }

    @Override
    public E first() throws EmptyException {
        if(isEmpty()) throw new EmptyException();
        if(array.get(f) == null) throw new EmptyException();
        else return array.get(f);
    }

    @Override
    public boolean isEmpty() {
        return r == f;
    }

    @Override
    public boolean isFull() {
        return ((r - f == -1) || (r - f == array.size() - 1));
    }
}
