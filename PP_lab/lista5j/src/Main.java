public class Main {
    public static void main(String[] args) throws IllegalAccessException {
        Debug.fields(new Test());
        System.out.println();
        Debug.fields(new Test2());
    }
}
