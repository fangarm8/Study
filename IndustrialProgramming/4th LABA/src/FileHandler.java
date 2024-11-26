import java.io.*;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class FileHandler {
    public static void writeToFile(String filePath, List<Smartphone> smartphones) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filePath))) {
            for (Smartphone smartphone : smartphones) {
                bw.write(smartphone.getId() + "," + smartphone.getType() + "," + smartphone.getModel() + "," +
                        smartphone.getCpu() + "," + smartphone.getCpu_freqency_ghz() + "," + smartphone.getRam_gb() + "," +
                        new SimpleDateFormat("yyyy-MM-dd").format(smartphone.getReleaseDate()) + "," +
                        smartphone.getPrice());
                bw.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static List<Smartphone> readFromFile(String filePath) {
        List<Smartphone> list = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                int id = Integer.parseInt(parts[0]);
                String type = parts[1];
                String model = parts[2];
                String cpu = parts[3];
                double cpu_freq = Double.parseDouble(parts[4]);
                int ram_gb = Integer.parseInt(parts[5]);
                Date releaseDate = new SimpleDateFormat("yyyy-MM-dd").parse(parts[6]);
                double price = Double.parseDouble(parts[7]);
                list.add(new Smartphone(id, type, model, cpu, cpu_freq, ram_gb, releaseDate, price));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return list;
    }
}
