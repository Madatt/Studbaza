public class Main {
    public static void main(String[] args) throws FullException {
        QueueCyclic<Integer> queue = new QueueCyclic<>(3);
        queue.enqueue(3);
        queue.enqueue(3);
        queue.enqueue(3);
        queue.enqueue(3);
    }
}
