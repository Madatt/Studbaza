import java.lang.reflect.Field;

public class Debug {
    static void fields(Object obj) throws IllegalAccessException {
        for(Field f : obj.getClass().getDeclaredFields())
        {
            f.setAccessible(true);
            System.out.println("Pole: " + f.getName() + " => " + f.getType().getSimpleName() + ", " + f.get(obj));
        }
    }
}
