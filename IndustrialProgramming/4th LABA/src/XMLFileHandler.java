import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.OutputKeys;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import java.io.File;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class XMLFileHandler {
    private static final SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");

    public static void writeToFile(String filename, List<Smartphone> smartphones) {
        try {
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();
            Document doc = builder.newDocument();

            Element root = doc.createElement("Smartphones");
            doc.appendChild(root);

            for (Smartphone smartphone : smartphones) {
                Element smartphoneElement = doc.createElement("Smartphone");

                smartphoneElement.appendChild(createElement(doc, "ID", String.valueOf(smartphone.getId())));
                smartphoneElement.appendChild(createElement(doc, "Type", smartphone.getType()));
                smartphoneElement.appendChild(createElement(doc, "Model", smartphone.getModel()));
                smartphoneElement.appendChild(createElement(doc, "CPU", String.valueOf(smartphone.getCpu())));
                smartphoneElement.appendChild(createElement(doc, "CPU_Freq", String.valueOf(smartphone.getCpu_freqency_ghz())));
                smartphoneElement.appendChild(createElement(doc, "Ram", String.valueOf(smartphone.getRam_gb())));
                smartphoneElement.appendChild(createElement(doc, "ReleaseDate", dateFormat.format(smartphone.getReleaseDate())));
                smartphoneElement.appendChild(createElement(doc, "Price", String.valueOf(smartphone.getPrice())));

                root.appendChild(smartphoneElement);
            }

            TransformerFactory transformerFactory = TransformerFactory.newInstance();
            Transformer transformer = transformerFactory.newTransformer();
            transformer.setOutputProperty(OutputKeys.INDENT, "yes");
            DOMSource domSource = new DOMSource(doc);
            StreamResult streamResult = new StreamResult(new File(filename));

            transformer.transform(domSource, streamResult);
            System.out.println("XML data written to " + filename);

        } catch (ParserConfigurationException | TransformerException e) {
            e.printStackTrace();
        }
    }

    public static List<Smartphone> readFromFile(String filename) {
        List<Smartphone> smartphones = new ArrayList<>();
        try {
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();
            Document doc = builder.parse(new File(filename));

            NodeList nodeList = doc.getElementsByTagName("Smartphone");

            for (int i = 0; i < nodeList.getLength(); i++) {
                Node node = nodeList.item(i);
                if (node.getNodeType() == Node.ELEMENT_NODE) {
                    Element element = (Element) node;

                    int id = Integer.parseInt(element.getElementsByTagName("ID").item(0).getTextContent());
                    String type = element.getElementsByTagName("Type").item(0).getTextContent();
                    String model = element.getElementsByTagName("Model").item(0).getTextContent();
                    String cpu = element.getElementsByTagName("CPU").item(0).getTextContent();
                    double cpu_freq = Double.parseDouble(element.getElementsByTagName("CPU_Freq").item(0).getTextContent());
                    int ram_gb = Integer.parseInt(element.getElementsByTagName("Ram").item(0).getTextContent());
                    Date releaseDate = dateFormat.parse(element.getElementsByTagName("ReleaseDate").item(0).getTextContent());
                    double price = Double.parseDouble(element.getElementsByTagName("Price").item(0).getTextContent());

                    smartphones.add(new Smartphone(id, type, model, cpu, cpu_freq, ram_gb, releaseDate, price));
                }
            }
            System.out.println("XML data read from " + filename);

        } catch (Exception e) {
            e.printStackTrace();
        }
        return smartphones;
    }

    private static Element createElement(Document doc, String name, String value) {
        Element element = doc.createElement(name);
        element.appendChild(doc.createTextNode(value));
        return element;
    }
}
