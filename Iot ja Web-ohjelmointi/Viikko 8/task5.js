const calculate = (a, b, operation) => operation(a, b);

console.log("Yhteenlasku:", calculate(5, 5, (x, y) => x + y));
console.log("Vähennyslasku:", calculate(10, 4, (x, y) => x - y));