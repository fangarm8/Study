import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class SmartphoneList {
    private final List<Smartphone> smartphones;
    public SmartphoneList() {
        smartphones = new ArrayList<>();
    }
    public void addSmartphone(Smartphone smartphone) {
        smartphones.add(smartphone);
    }
    public void removeSmartphone(int id) {
        smartphones.removeIf(d -> d.getId() == id);
    }
    public void sortByPrice() {
        smartphones.sort(Comparator.comparingDouble(Gadget::getPrice));
    }
    public void displayAll() {
        smartphones.forEach(System.out::println);
    }
    public List<Smartphone> getSmartphones() {
        return smartphones;
    }
}
