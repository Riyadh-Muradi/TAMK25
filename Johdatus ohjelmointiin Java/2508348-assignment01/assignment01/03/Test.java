import java.util.concurrent.TimeUnit;

void main() throws Exception {
    int passed = 0;
    int total = 0;

    total++;
    var output = run("Alice\n");
    if (output.contains("Hello, Alice!")) {
        IO.println("  PASS: output contains 'Hello, Alice!'");
        passed++;
    } else {
        IO.println("  FAIL: expected output to contain 'Hello, Alice!', got: " + output.trim());
    }

    total++;
    output = run("Bob\n");
    if (output.contains("Hello, Bob!")) {
        IO.println("  PASS: output contains 'Hello, Bob!'");
        passed++;
    } else {
        IO.println("  FAIL: expected output to contain 'Hello, Bob!', got: " + output.trim());
    }

    IO.println("Exercise 03: " + passed + "/" + total + " passed");
}

String run(String input) throws Exception {
    var pb = new ProcessBuilder("java", "Main.java");
    pb.redirectErrorStream(true);
    var process = pb.start();
    if (input != null) {
        process.getOutputStream().write(input.getBytes());
        process.getOutputStream().close();
    } else {
        process.getOutputStream().close();
    }
    var output = new String(process.getInputStream().readAllBytes());
    boolean exited = process.waitFor(10, TimeUnit.SECONDS);
    if (!exited) {
        process.destroyForcibly();
        return "";
    }
    return output;
}