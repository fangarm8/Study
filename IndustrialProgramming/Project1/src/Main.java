import java.util.Scanner;
import java.util.Formatter;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Введите x: ");
        double x = in.nextDouble();
        System.out.println("Введите k:");
        int k = in.nextInt();

        Taylor cosh = new Taylor(x, k);
        double res = cosh.cosh();

        int IntRes = (int) res;

        Formatter formatter = new Formatter();
        formatter.format("Мой cosh(x): %+0" + Integer.valueOf(k + 1).toString() + "f%n", res);

        double res1 = Math.cosh(x);
        formatter.format("Встроенный cosh(x): %+0" + Integer.valueOf(k + 1).toString() + "f%n", res1);


        formatter.format("Восьмеричное представление округленного результата: %#o%n", IntRes);
        formatter.format("Шестнадцатеричное представление k: %#x%n", IntRes);
        System.out.println(formatter);

        in.close();
        formatter.close();
    }
}
