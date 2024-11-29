def find_password(sequence, required_chars, max_len):
    if max_len > len(sequence):
        return "-1"

    char_set = set(required_chars)
    char_set_cpy = char_set.copy()

    for i in range(len(sequence) - max_len, -1, -1):
        substring = sequence[i:i + max_len]
        valid = True
        for c in substring:
            if c in char_set_cpy:
                char_set_cpy.remove(c)
            if c not in char_set:
                valid = False
                break

        if char_set_cpy:
            valid = False
        if valid:
            return substring
        char_set_cpy = char_set.copy()

    return "-1"

# Ввод данных
sequence = input()  # Строка символов
required_chars = input()  # Набор требуемых символов
max_len = int(input())  # Максимальная длина пароля

# Вызов функции
result = find_password(sequence, required_chars, max_len)
print(result)