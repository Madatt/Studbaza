public class Main {
    public static void main(String[] args) throws FullException, EmptyException {
        QueueCyclic<Integer> queue = new QueueCyclic<>(3);
        queue.enqueue(3);
        System.out.println(queue.first());
        queue.enqueue(2);
        System.out.println(queue.first());
        queue.enqueue(1);

        System.out.println(queue.first());
        queue.dequeue();
        System.out.println(queue.first());
        queue.dequeue();
        System.out.println(queue.first());
        queue.dequeue();

        queue.enqueue(3);
        System.out.println(queue.first());
        queue.enqueue(2);
        System.out.println(queue.first());
        queue.enqueue(1);
    }
}
