/*import org.json.JSONArray;
import JAR.JSONObject;

import java.io.FileWriter;
import java.io.FileReader;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import static com.sun.tools.jdeprscan.Main.LoadMode.JAR;

public class JSONFileHandler {
    private static final SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");

    public static void writeToFile(String filename, List<Dishwasher> dishwashers) {
        JSONArray jsonArray = new JSONArray();

        for (Dishwasher dishwasher : dishwashers) {
            JSONObject jsonObject = new JSONObject();
            jsonObject.put("ID", dishwasher.getId());
            jsonObject.put("Type", dishwasher.getType());
            jsonObject.put("Model", dishwasher.getModel());
            jsonObject.put("EnginePower", dishwasher.getEnginePower());
            jsonObject.put("MaxSpeed", dishwasher.getMaxSpeed());
            jsonObject.put("ReleaseDate", dateFormat.format(dishwasher.getReleaseDate()));
            jsonObject.put("Price", dishwasher.getPrice());

            jsonArray.put(jsonObject);
        }

        try (FileWriter file = new FileWriter(filename)) {
            file.write(jsonArray.toString(4));
            System.out.println("JSON data written to " + filename);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static List<Dishwasher> readFromFile(String filename) {
        List<Dishwasher> dishwashers = new ArrayList<>();

        try (FileReader reader = new FileReader(filename)) {
            StringBuilder jsonBuilder = new StringBuilder();
            int i;
            while ((i = reader.read()) != -1) {
                jsonBuilder.append((char) i);
            }

            JSONArray jsonArray = new JSONArray(jsonBuilder.toString());

            for (int j = 0; j < jsonArray.length(); j++) {
                JSONObject jsonObject = jsonArray.getJSONObject(j);

                int id = jsonObject.getInt("ID");
                String type = jsonObject.getString("Type");
                String model = jsonObject.getString("Model");
                double enginePower = jsonObject.getDouble("EnginePower");
                double maxSpeed = jsonObject.getDouble("MaxSpeed");
                Date releaseDate = dateFormat.parse(jsonObject.getString("ReleaseDate"));
                double price = jsonObject.getDouble("Price");

                dishwashers.add(new Dishwasher(id, type, model, enginePower, maxSpeed, releaseDate, price));
            }
            System.out.println("JSON data read from " + filename);

        } catch (IOException | ParseException e) {
            e.printStackTrace();
        }

        return dishwashers;
    }
}
*/