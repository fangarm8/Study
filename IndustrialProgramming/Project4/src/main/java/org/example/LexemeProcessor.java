package org.example;

import java.util.List; // Импортируем класс List для работы со списками

public class LexemeProcessor {
    public static void main(String[] args) {
        // Указание имен входного и выходного файлов
        String inputFileName = "input.txt";
        String outputFileName = "output.txt";

        // Создаем объект FileHandler для работы с файлами
        FileHandler fileHandler = new FileHandler(inputFileName, outputFileName);
        // Читаем входные данные из файла
        String[] inputs = fileHandler.readInputs();

        // Проверяем, что данные успешно прочитаны и их количество равно 2
        if (inputs != null && inputs.length == 2) {
            String lexemes = inputs[0]; // Первая строка - лексемы
            String delimiters = inputs[1]; // Вторая строка - разделители

            // Создаем объект LexemeUtility для обработки лексем
            LexemeUtility utility = new LexemeUtility();
            // Разбиваем лексемы на токены по заданным разделителям
            String[] tokens = utility.splitLexemes(lexemes, delimiters);
            // Извлекаем вещественные числа в экспоненциальной форме
            List<Double> numbers = utility.extractDoubleNumber(tokens);
            // Извлекаем временные метки в формате ЧЧ:ММ
            List<String> times = utility.extractTimeFormats(tokens);

            // Добавляем случайное число в список найденных чисел
            inputs[0] = utility.addRandomNumber(inputs[0], numbers);
            inputs[0] = utility.eraseSmallestLexems(inputs[0]);
            // Записываем результаты в выходной файл
            fileHandler.writeOutputs(numbers, times, inputs[0]);
        }
    }
}