import java.util.Random;
import java.util.concurrent.Semaphore;

public class Filozof extends Thread {
    private int numer;
    private Sala sala;
    private Random random = new Random();

    Filozof(Sala sala, int numer) {
        this.sala = sala;
        this.numer = numer;
    }

    @Override
    public void run() {
        try {
            while(true) {
                medytuj();
                jedz();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public void jedz() throws InterruptedException {
        sala.getOdzwierny().acquire();

        sala.getPaleczka(numer).podnies();
        sala.getPaleczka((numer + 1) % sala.getN()).podnies();

        System.out.println("Filozof " + numer + " je...");
        sleep(random.nextInt(10000));
        System.out.println("Filozof " + numer + " skonczyl jesc...");

        sala.getPaleczka(numer).poloz();
        sala.getPaleczka((numer + 1) % sala.getN()).poloz();
        sala.getOdzwierny().release();
    }

    public void medytuj() throws InterruptedException {
        System.out.println("Filozof " + numer + " medytuje...");
        sleep(random.nextInt(10000));
        System.out.println("Filozof " + numer + " skonczyl medytowac...");
    }
}
