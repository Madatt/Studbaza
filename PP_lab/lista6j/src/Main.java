public class Main {
    public static void main(String[] args) {
        Dollar dollar1 = new Dollar(3);
        Exchange exchange = new Exchange(0.5f, 2);
        Franc franc = exchange.dollarToFranc(dollar1);
        System.out.println(franc.getValue());
        Dollar dollar2 = exchange.francToDollar(franc);
        System.out.println(dollar2.getValue());

        Exchange exchange2 = new Exchange(0.5f, 2);
        System.out.println(exchange2.dollarToFrancRatio());
        System.out.println(exchange2.francToDollarRatio());
    }
}
