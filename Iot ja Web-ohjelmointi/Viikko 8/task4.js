const counter = {
  value: 0,
  increment() { this.value++; },
  decrement() { this.value--; },
  show() { console.log(`Arvo: ${this.value}`); }
};

counter.increment();
counter.increment();
counter.show();