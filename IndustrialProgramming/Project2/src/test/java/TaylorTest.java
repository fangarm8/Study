import junit.framework.TestCase;
import org.example.Taylor;
import org.junit.Test;

import java.math.BigDecimal;

public class TaylorTest extends TestCase {
    @Test
    public void testCosh() {
        Taylor test_obj = new Taylor(5, 4);
        double eps = 1;
        for (int i = 0; i < 4; i++) {
            eps/=10;
        }
        double res = test_obj.cosh();
        assertEquals(res, Math.cosh(5), eps);
    }

    public void testNegativeCosh() {
        Taylor test_obj = new Taylor(-10, 4);
        double eps = 1;
        for (int i = 0; i < 4; i++) {
            eps/=10;
        }
        double res = test_obj.cosh();
        assertEquals(res, Math.cosh(-10), eps);
    }

    public void testBigCosh() {
        Taylor test_obj = new Taylor(5, 4);
        BigDecimal res = test_obj.BigCosh();
        assertEquals(String.format("%.5f", res), String.format("%.5f", Math.cosh(5)));
    }

    public void testNegativeBigCosh() {
        Taylor test_obj = new Taylor(-10, 4);
        BigDecimal res = test_obj.BigCosh();
        assertEquals(String.format("%.5f", res), String.format("%.5f", Math.cosh(-10)));
    }
}
