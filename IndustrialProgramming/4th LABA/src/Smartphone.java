import java.util.Date;

public class Smartphone extends Gadget {
    public Smartphone(int id, String type, String model, String cpu, double freq, int ram_gb, Date releaseDate, double price) {
        this.id = id;
        this.type = type;
        this.model = model;
        this.cpu = cpu;
        this.cpu_freqency_ghz = freq;
        this.ram_gb = ram_gb;
        this.releaseDate = releaseDate;
        this.price = price;
    }

    @Override
    public String toString() {
        return "Dishwasher [ID=" + id + ", Type=" + type + ", Model=" + model +
                ", CPU=" + cpu + ", Frequency=" + cpu_freqency_ghz +
                "Ghz, RAM=" + ram_gb + "Gb, Release Date=" + releaseDate + ", Price=" + price + "]";
    }
}
