class Car {
  constructor(brand, year) {
    this.brand = brand;
    this.year = year;
  }
  info() {
    console.log(`Merkki: ${this.brand}, Vuosi: ${this.year}`);
  }
}
const auto1 = new Car("Toyota", 2015);
auto1.info();