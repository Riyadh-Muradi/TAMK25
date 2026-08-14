import java.nio.file.Files;
import java.nio.file.Path;

void main() {
    int passed = 0;
    int total = 0;

    total++;
    boolean found = Files.exists(Path.of("screenshot.png"))
            || Files.exists(Path.of("screenshot.jpg"))
            || Files.exists(Path.of("screenshot.jpeg"));
    if (found) {
        IO.println("  PASS: screenshot file found");
        passed++;
    } else {
        IO.println("  FAIL: screenshot.png or screenshot.jpg not found");
    }

    IO.println("Exercise 01: " + passed + "/" + total + " passed");
}