const products = [
  { name: "Diar", price: 5 },
  { name: "Arttu", price: 2 },
  { name: "Aarlo", price: 1.5 }
];

function printProducts(prods) {
  prods.forEach(p => console.log(`${p.name}: ${p.price}€`));
}
printProducts(products);