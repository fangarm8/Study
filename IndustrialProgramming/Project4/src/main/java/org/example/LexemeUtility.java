package org.example;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class LexemeUtility {
    // метод для разделения строк по заданным разделителям
    public String[] splitLexemes(String str, String delimiters) {
        return str.split("[" + Pattern.quote(delimiters) + "]+");
        //чтобы воспринимались как обычные символы в регулярном выражении
        //+ один и более символов
    }
    public List<Double> extractDoubleNumber(String[] tokens) {
        List<Double> numbers = new ArrayList<>();
        Pattern numberPattern = Pattern.compile("\\d+\\.\\d+");
        for (String token : tokens) {
            Matcher numberMatcher = numberPattern.matcher(token);
            if (numberMatcher.matches()) {
                numbers.add(Double.parseDouble(token));
            }
        }
        return numbers;
    }
    // Поиск времени (ЧЧ:ММ)
    public List<String> extractTimeFormats(String[] tokens) {
        List<String> times = new ArrayList<>();
        for (String token : tokens) {
            if (isTimeFormat(token)) { //проверяем подходит ли по форату времени
                times.add(token); //добавляем
            }
        }
        return times;
    }
    /*"[+-]?": Опциональный знак (+ или -) в начале числа.
\\d*: Ноль или более цифр перед десятичной точкой
\\.?:  десятичная точка.
\\d+: Одна или более цифр после десятичной точки
([eE][+-]?\\d+)?: часть для экспоненциальной нотации:
[eE]: Буква e или E.
[+-]?: (+ или -) для экспоненты.
\\d+: Одна или более цифр, представляющих экспоненту.*/


    // Проверка на формат времени (ЧЧ-ММ)
    private boolean isTimeFormat(String str) {
        return str.matches("(0[0-9]|1[0-9]|2[0-3])-[0-5][0-9]");
    }
/*(0[0-9]|1[0-9]|2[0-3]): Часы:
0[0-9]: Часы от 00 до 09.
1[0-9]: Часы от 10 до 19.
2[0-3]: Часы от 20 до 23.
:: Двоеточие, разделяющее часы и минуты.
[0-5][0-9]: Минуты:
[0-5]: Первая цифра минут от 0 до 5.
[0-9]: Вторая цифра минут от 0 до 9.*/

    // Добавление случайного числа
    public String addRandomNumber(String inputString, List<Double> numbers) {
        Random random = new Random();
        double randomNumber = random.nextDouble() * 100;
        if (!numbers.isEmpty()) {
            int index = inputString.indexOf(numbers.get(0).toString()) + numbers.get(0).toString().length();
            inputString = new StringBuilder(inputString).insert(index, " " + randomNumber).toString();
        } else {
            int middle = inputString.length() / 2;
            inputString = new StringBuilder(inputString).insert(middle, " " + randomNumber).toString();
        }
        return inputString;
    }

    public String eraseSmallestLexems(String str) {
        Pattern pattern = Pattern.compile(".*-$");
        Matcher matcher = pattern.matcher(str);

        String shortestSubstring = null;

        // Ищем самую короткую подстроку
        while (matcher.find()) {
            String match = matcher.group();
            if (shortestSubstring == null || match.length() < shortestSubstring.length()) {
                shortestSubstring = match;
            }
        }

        // Если найдена самая короткая подстрока, удаляем её из строки
        if (shortestSubstring != null) {
            str = str.replaceFirst(Pattern.quote(shortestSubstring), "");
        }
        return str;
    }
}