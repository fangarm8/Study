import math
from typing import List

def calculate_factorials(n: int) -> List[int]:
    if n <= 0:
        raise ValueError("Input must be a natural number greater than zero.")

    factorials = []
    for i in range(1, n + 1):
        factorials.append(math.factorial(i))

    return factorials
