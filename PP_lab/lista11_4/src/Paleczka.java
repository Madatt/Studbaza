import java.util.concurrent.Semaphore;

public class Paleczka {
    private Semaphore lock = new Semaphore(1, true);

    public void podnies() {
        try {
            lock.acquire();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public void poloz() {
        lock.release();

    }
}
