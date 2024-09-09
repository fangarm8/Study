public class Taylor {
    private final double x;
    private final int k;

    public Taylor(double num1, int num2) {
        this.x = num1;
        this.k = num2;
    }

    public double cosh() {
        double eps = 1;
        for (int i = 0; i < this.k; i++) {
            eps/=10;
        }
        double ak = 1;
        double sum = ak;
        int n = 1;
        while (Math.abs(ak) > eps) {
            double y = (this.x*this.x)/(n*(n+1));
            ak *= y;
            sum += ak;
            n+=2;
        }
        return sum;
    }
}
