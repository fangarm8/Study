import java.util.HashMap;
import java.util.Map;

public class SmartphoneMap {
    private Map<Integer, Smartphone> smartphoneMap;

    public SmartphoneMap() {
        smartphoneMap = new HashMap<>();
    }

    public void addSmartphone(Smartphone dishwasher) {
        smartphoneMap.put(dishwasher.getId(), dishwasher);
    }

    public void removeSmartphone(int id) {
        smartphoneMap.remove(id);
    }

    public void displayAll() {
        smartphoneMap.values().forEach(System.out::println);
    }

    public Map<Integer, Smartphone> getDishwasherMap() {
        return smartphoneMap;
    }
}
