import java.io.*;

public class Java_Calculate {
    public static void main(String[] args) {
        try {
            FileReader fr = new FileReader("1000MBFile.txt");
            FileWriter fw = new FileWriter("Uppercase.txt");

            long start = System.nanoTime();  // Start timing

            int ch;
            while ((ch = fr.read()) != -1) {
                fw.write(Character.toUpperCase((char) ch));
            }

            long end = System.nanoTime();  // End timing

            fr.close();
            fw.close();

            double timeTaken = (end - start) / 1e9;
            System.out.println("File converted to uppercase successfully.");
            System.out.println("Time taken: " + timeTaken + " seconds");
        } catch (IOException e) {
            System.out.println("File error: " + e.getMessage());
        }
    }
}
