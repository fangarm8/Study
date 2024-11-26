package org.example;

import java.io.*; // импортируем классы для работы с вводом-выводом
import java.util.List; // импортируем класс List для работы со списками

public class FileHandler {
    private String inputFileName; // имя входного файла
    private String outputFileName; // имя выходного файла

    // конструктор класса FileHandler
    public FileHandler(String inputFileName, String outputFileName) {
        this.inputFileName = inputFileName; // инициализация
        this.outputFileName = outputFileName;
    }

    // метод для чтения входных данных из файла
    public String[] readInputs() {
        try (BufferedReader reader = new BufferedReader(new FileReader(inputFileName))) {
            // чтение первой строки (лексемы)
            String lexemes = reader.readLine();
            // чтение второй строки (разделители)
            String delimiters = reader.readLine();
            // возвращаем массив строк, содержащий лексемы и разделители
            return new String[]{lexemes, delimiters};
        } catch (IOException e) {
            // обработка исключения при чтении файла
            e.printStackTrace();
            return null;
        }
    }

    // метод для записи результатов в файл
    public void writeOutputs(List<Double> numbers, List<String> times, String modifiedLexemes) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(outputFileName))) {
            // записываем вещественные числа в выходной файл
            writer.write("Вещественные числа (экспоненциальная форма): " + numbers.toString());
            writer.newLine();
            // записываем найденные временные метки
            writer.write("Время (ЧЧ:ММ): " + times.toString());
            writer.newLine();
            // записываем измененную строку
            writer.write("Измененная строка: " + modifiedLexemes);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
