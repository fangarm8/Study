package org.example;

import java.math.BigDecimal;
import java.math.RoundingMode;
import java.math.MathContext;

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

    public BigDecimal BigCosh() {
        BigDecimal res = new BigDecimal("1.0");
        BigDecimal eps = BigDecimal.ONE.divide(BigDecimal.TEN.pow(k, MathContext.DECIMAL128));
        BigDecimal div = new BigDecimal("1.0");
        for (int n = 1; ; n=n+2) {
            div = div.multiply(BigDecimal.valueOf(x)
                    .pow(2)
                    .divide(BigDecimal.valueOf(n).multiply(BigDecimal.valueOf(n+1)),10, RoundingMode.HALF_UP));
            res = res.add(div);
            if (div.abs().compareTo(eps) == -1) {
                res=res.setScale(k+1, RoundingMode.HALF_UP);
                return res;
            }
        }
    }
}
