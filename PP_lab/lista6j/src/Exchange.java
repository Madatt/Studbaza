public class Exchange {
    private float fTD = 1.f;
    private float dTF = 1.f;

    public Exchange(float dTF, float fTD) {
        this.fTD = fTD;
        this.dTF = dTF;
    }

    public float dollarToFrancRatio(){
        return dTF;
    }

    public float francToDollarRatio() {
        return fTD;
    }

    public Franc dollarToFranc(Dollar dollar) {
        return new Franc(dollar.getValue() * fTD);
    }

    public Dollar francToDollar(Franc franc) {
        return new Dollar(franc.getValue() * dTF);
    }
}
