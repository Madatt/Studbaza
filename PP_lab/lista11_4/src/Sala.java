import java.util.concurrent.Semaphore;

public class Sala {
    private Paleczka[] paleczka = new Paleczka[5];
    private Filozof[] filozof = new Filozof[5];
    private Semaphore odzwierny = new Semaphore(4, true);
    private int n;

    Sala(int n) {
        this.n = n;
        for(int i = 0; i < n; i++) {
            paleczka[i] = new Paleczka();
        }

        for(int i = 0; i < n; i++) {
            filozof[i] = new Filozof(this, i);
            filozof[i].start();
        }
    }

    public static void main(String[] args) {
        Sala sala = new Sala(5);
    }

    public Paleczka getPaleczka(int i) {
        return paleczka[i];
    }

    public Semaphore getOdzwierny() {
        return odzwierny;
    }

    public int getN() {
        return n;
    }
}
