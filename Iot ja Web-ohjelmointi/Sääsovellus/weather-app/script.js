console.log("Hello, World! Lets start building the weather app!");

const API_KEY = "6c98fda8f11aeccaf6d92c178e1209d9";
const CITY = "Tampere";

const updateUI = (data) => {
  const cityName = data.name;
  const temperature = data.main.temp;
  const feelsLike = data.main.feels_like;
  const humidity = data.main.humidity;
  const windSpeed = data.wind.speed;
  const weatherDescription = data.weather[0].description;

  document.getElementById("city-name").textContent = cityName;
  document.getElementById("temperature").textContent = `${temperature.toFixed(2)}°C`;
  document.getElementById("feels-like").textContent = `${feelsLike.toFixed(2)}°C`;
  document.getElementById("humidity").textContent = `Humidity: ${humidity}%`;
  document.getElementById("wind-speed").textContent = `Wind Speed: ${windSpeed} m/s`;
  document.getElementById("weather-description").textContent = weatherDescription;

  // Päivitetty-aikaleima
  const now = new Date();
  const timeString = now.toLocaleTimeString("fi-FI");
  document.querySelector(".info").textContent = `Päivitetty: ${timeString}`;

  // Päivitä datan lähde footeriin
  document.querySelector(".attribution").textContent = "Säädata: OpenWeatherMap API";
};

(async () =>{
  const response = await fetch(
    `https://api.openweathermap.org/data/2.5/weather?q=${CITY}&appid=${API_KEY}&units=metric`
  );
  const data = await response.json();
  console.log(`Weather data for ${CITY}:`, data);
  updateUI(data);
})();