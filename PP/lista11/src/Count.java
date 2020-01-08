import java.util.concurrent.Semaphore;

class Count extends Thread {
    private static IntCell2 n = new IntCell2();
    private static Semaphore semaphore = new Semaphore(1);

    @Override
    public void run() {
        int temp;
        for (int i = 0; i < 200000; i++) {
            try {
                semaphore.acquire();
                temp = n.getN();
                n.setN(temp + 1);
                semaphore.release();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Count p = new Count();
        Count q = new Count();
        p.start();
        q.start();
        try {
            p.join();
            q.join();
        } catch (InterruptedException e) {
        }
        System.out.println("The value of n is " + n.getN());
    }
}