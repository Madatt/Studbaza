class IntCell {
    private int n = 0;
    private boolean busy = true;

    public synchronized int  getN() throws InterruptedException {
        while(!busy)
        {
            wait();
        }

        busy = false;
        notifyAll();
        return n;
    }

    public synchronized void setN(int n) throws InterruptedException {

        while(busy)
        {
            wait();
        }

        busy = true;
        notifyAll();

        this.n = n;
    }
}
