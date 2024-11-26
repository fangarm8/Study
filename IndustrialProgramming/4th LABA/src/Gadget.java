import java.util.Date;

public abstract class Gadget {
    protected int id;
    protected String type;
    protected String model;
    protected String cpu;
    protected double cpu_freqency_ghz;
    protected int ram_gb;
    protected Date releaseDate;
    protected double price;

    public abstract String toString();
    public int getId() { return id; }
    public void setId(int id) { this.id = id; }

    public String getType() { return type; }
    public void setType(String type) { this.type = type; }

    public String getModel() { return model; }
    public void setModel(String model) { this.model = model; }

    public String getCpu() { return cpu; }
    public void set_cpu(String cpu) { this.cpu = cpu; }

    public double getCpu_freqency_ghz() { return cpu_freqency_ghz; }
    public void setCpu_freqency_ghz(double freqency_ghz) { this.cpu_freqency_ghz = freqency_ghz; }

    public int getRam_gb() { return ram_gb; }
    public void setRam_gb(int gb) { ram_gb = gb; }

    public Date getReleaseDate() { return releaseDate; }
    public void setReleaseDate(Date releaseDate) { this.releaseDate = releaseDate; }

    public double getPrice() { return price; }
    public void setPrice(double price) { this.price = price; }
}
