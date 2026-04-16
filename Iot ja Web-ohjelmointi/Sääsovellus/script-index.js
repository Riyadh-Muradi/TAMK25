console.log("Index page loaded - Current weather");

const API_KEY = "6c98fda8f11aeccaf6d92c178e1209d9";
const CITY = "Tampere";

const getCurrentWeatherData = async (city) => {
  try {
    const response = await fetch(
      `https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${API_KEY}&units=metric`
    );

    if (!response.ok) {
      throw new Error("City not found");
    }

    const data = await response.json();
    return data;
  } catch (error) {
    console.error("Error fetching current data:", error);
    alert("Could not fetch current data. Please try again.");
  }
};

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
  document.getElementById("humidity").textContent = `Kosteus: ${humidity}%`;
  document.getElementById("wind-speed").textContent = `Tuuli: ${windSpeed} m/s`;
  document.getElementById("weather-description").textContent = weatherDescription;

  const now = new Date();
  const timeString = now.toLocaleTimeString("fi-FI");
  document.querySelector(".info").textContent = `Päivitetty: ${timeString}`;
  document.querySelector(".attribution").textContent = "Säädata: OpenWeatherMap API";
};

// Search form handler
document.addEventListener("DOMContentLoaded", () => {
  const searchForm = document.getElementById("search-form");
  if (searchForm) {
    searchForm.addEventListener("submit", (e) => {
      e.preventDefault();
      const cityInput = document.getElementById("city-input");
      const city = cityInput.value.trim();
      if (city) {
        loadWeather(city);
      }
    });
  }
  
  loadWeather(CITY);
});

const loadWeather = async (city) => {
  const data = await getCurrentWeatherData(city);
  if (data) {
    updateUI(data);
  }
};
