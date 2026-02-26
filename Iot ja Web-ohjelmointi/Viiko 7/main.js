const state = {
  counter: 0,
};

const elements = {
  counter: document.getElementById("counter"),
  decrease: document.getElementById("decrease"),
  increase: document.getElementById("increase"),
  decrease10: document.getElementById("decrease10"),
  increase10: document.getElementById("increase10"),
  reset: document.getElementById("reset"),
  random: document.getElementById("random"),
};

const updateColor = () => {
  const isEven = state.counter % 2 === 0;
  elements.counter.style.color = isEven ? "red" : "green";
};

const updateDisplay = () => {
  elements.counter.textContent = state.counter;
  updateColor();
};

const setCounter = (value) => {
  state.counter = Math.max(0, value);
  updateDisplay();
};

const incrementCounter = (amount) => {
  setCounter(state.counter + amount);
};

const handleIncrease = () => incrementCounter(1);
const handleDecrease = () => incrementCounter(-1);
const handleIncrease10 = () => incrementCounter(10);
const handleDecrease10 = () => incrementCounter(-10);
const handleReset = () => setCounter(0);

const handleRandom = () => {
  const randomValue = Math.floor(Math.random() * 101);
  setCounter(randomValue);
};

const initEventListeners = () => {
  elements.increase.addEventListener("click", handleIncrease);
  elements.decrease.addEventListener("click", handleDecrease);
  elements.increase10.addEventListener("click", handleIncrease10);
  elements.decrease10.addEventListener("click", handleDecrease10);
  elements.reset.addEventListener("click", handleReset);
  elements.random.addEventListener("click", handleRandom);
};

const init = () => {
  updateColor();
  initEventListeners();
};

init();
