import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        SmartphoneList smartphonelist = new SmartphoneList();
        Scanner scanner = new Scanner(System.in);
        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");

        // Чтение данных из файла при запуске
        List<Smartphone> loadedSmartphones = FileHandler.readFromFile("gadgets.txt");
        loadedSmartphones.forEach(smartphonelist::addSmartphone);

        while (true) {
            System.out.println("\nМеню:");
            System.out.println("1. Добавить смартфон");
            System.out.println("2. Редактировать смартфон");
            System.out.println("3. Удалить смартфон");
            System.out.println("4. Показать все смартфоны");
            System.out.println("5. Сортировать по цене");
            System.out.println("6. Записать данные в файл");
            System.out.println("7. Загрузить данные из файла");
            System.out.println("8. Запись в XML");
            System.out.println("9. Чтение из XML");
            System.out.println("10. Запись в JSON");
            System.out.println("11. Чтение из JSON");
            System.out.println("12. Выход");
            System.out.print("Выберите действие: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // очистка буфера после nextInt

            switch (choice) {
                case 1:
                    try {
                        System.out.print("Введите ID: ");
                        int id = scanner.nextInt();
                        scanner.nextLine(); // переход на следующую строку
                        System.out.print("Введите тип: ");
                        String type = scanner.nextLine();
                        System.out.print("Введите модель: ");
                        String model = scanner.nextLine();
                        System.out.print("Введите название процессора: ");
                        String cpu = scanner.nextLine();
                        System.out.print("Введите тактовую частоту процессора (Ghz): ");
                        double cpu_freq = scanner.nextDouble();
                        System.out.print("Введите количество оперативной памяти (Gb): ");
                        int ram_gb = scanner.nextInt();
                        scanner.nextLine();
                        System.out.print("Введите дату выпуска (yyyy-MM-dd): ");
                        Date releaseDate = dateFormat.parse(scanner.nextLine());
                        System.out.print("Введите цену: ");
                        double price = scanner.nextDouble();
                        scanner.nextLine(); // переход на следующую строку

                        Smartphone smartphone = new Smartphone(id, type, model, cpu, cpu_freq, ram_gb, releaseDate, price);
                        smartphonelist.addSmartphone(smartphone);
                        System.out.println("Смартфон добавлен.");
                    } catch (ParseException e) {
                        System.out.println("Ошибка: Неправильный формат даты.");
                    }
                    break;
                case 2:
                    System.out.print("Введите ID смартфона для редактирования: ");
                    int updateId = scanner.nextInt();
                    scanner.nextLine(); // переход на следующую строку
                    updateSmartphone(smartphonelist, updateId, scanner);
                    break;
                case 3:
                    System.out.print("Введите ID смартфона для удаления: ");
                    int deleteId = scanner.nextInt();
                    scanner.nextLine(); // переход на следующую строку
                    smartphonelist.removeSmartphone(deleteId);
                    System.out.println("Посудомоечная машина удалена.");
                    break;
                case 4:
                    System.out.println("Список всех сматрфонов:");
                    smartphonelist.displayAll();
                    break;
                case 5:
                    smartphonelist.sortByPrice();
                    System.out.println("Список отсортирован по цене.");
                    break;
                case 6:
                    FileHandler.writeToFile("gadgets.txt", smartphonelist.getSmartphones());
                    System.out.println("Данные записаны в файл.");
                    break;
                case 7:
                    smartphonelist.getSmartphones().clear(); // очистка текущих данных
                    List<Smartphone> newLoadedDishwashers = FileHandler.readFromFile("gadgets.txt");
                    newLoadedDishwashers.forEach(smartphonelist::addSmartphone);
                    System.out.println("Данные загружены из файла.");
                    break;
                case 12:
                    System.out.println("Выход из программы.");
                    scanner.close();
                    return;
                case 8:
                    XMLFileHandler.writeToFile("smartphones.xml", smartphonelist.getSmartphones());
                    System.out.println("Данные записаны в XML файл.");
                    break;
                case 9:
                    smartphonelist.getSmartphones().clear();
                    smartphonelist.getSmartphones().addAll(XMLFileHandler.readFromFile("smartphones.xml"));
                    System.out.println("Данные загружены из XML файла.");
                    break;
                /*case 10:
                    JSONFileHandler.writeToFile("smartphones.json", smartphonelist.getSmartphones());
                    System.out.println("Данные записаны в JSON файл.");
                    break;
                case 11:
                    SmartphoneList.getDishwashers().clear();
                    SmartphoneList.getDishwashers().addAll(JSONFileHandler.readFromFile("smartphones.json"));
                    System.out.println("Данные загружены из JSON файла.");
                    break;*/

                default:
                    System.out.println("Неверный выбор. Пожалуйста, выберите снова.");
            }
        }
    }

    private static void updateSmartphone(SmartphoneList smartphonelist, int id, Scanner scanner) {
        for (Smartphone smartphone : smartphonelist.getSmartphones()) {
            if (smartphone.getId() == id) {
                System.out.println("Введите новый тип:");
                smartphone.setType(scanner.nextLine());
                System.out.println("Введите новую модель:");
                smartphone.setModel(scanner.nextLine());
                System.out.println("Введите новый процессор:");
                smartphone.set_cpu(scanner.nextLine());
                System.out.println("Введите новую тактовую частоту:");
                smartphone.setCpu_freqency_ghz(scanner.nextDouble());
                System.out.println("Введите новый обхем памяти:");
                smartphone.setRam_gb(scanner.nextInt());
                System.out.println("Введите новую цену:");
                smartphone.setPrice(scanner.nextDouble());
                scanner.nextLine(); // Для перехода на следующую строку
                System.out.println("Обновлено: " + smartphone);
                return;
            }
        }
        System.out.println("Сматрфон с ID " + id + " не найдена.");
    }
}
