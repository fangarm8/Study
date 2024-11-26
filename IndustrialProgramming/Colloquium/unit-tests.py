import unittest
import main

class TestCalculateFactorials(unittest.TestCase):

    def test_factorials_normal(self):
        self.assertEqual(main.calculate_factorials(1), [1])
        self.assertEqual(main.calculate_factorials(3), [1, 2, 6])
        self.assertEqual(main.calculate_factorials(5), [1, 2, 6, 24, 120])

    def test_factorials_large(self):
        self.assertEqual(main.calculate_factorials(10), [1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800])

    def test_invalid_input_zero(self):
        with self.assertRaises(ValueError):
            main.calculate_factorials(0)

    def test_invalid_input_negative(self):
        with self.assertRaises(ValueError):
            main.calculate_factorials(-5)


if __name__ == '__main__':
    unittest.main()
