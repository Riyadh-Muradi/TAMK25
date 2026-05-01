const students = [
  { name: "Antti", grade: 4 },
  { name: "Beata", grade: 2 },
  { name: "Anniina", grade: 5 }
];

const filterStudents = (list, condition) => list.filter(condition);

console.log("Arvosana > 3:", filterStudents(students, s => s.grade > 3));
console.log("A-alkuiset:", filterStudents(students, s => s.name.startsWith("A")));