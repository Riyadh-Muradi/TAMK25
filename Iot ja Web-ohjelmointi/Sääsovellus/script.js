console.log("Hello, World! Lets start building the weather app!");

const API_KEY = "6c98fda8f11aeccaf6d92c178e1209d9";
const CITY = "Tampere";

let tempChart; // Chart.js-käppyrä tähän muuttujaan: päivitetään jo haun yhteydessä

const getDataAndUpdateUI = async (city) => {
  console.log(`Fetching weather data for ${city}...`);

  const currentWeatherData = await getCurrentWeatherData(city); // Haetaan tämän hetkinen säädata
  updateUI(currentWeatherData); // Päivitetään UI:hin saatu data (tämän hetkinen sää)

  const forecastData = await getForeccastData(city); // Haetaan forecast-data
  drawChart(forecastData); // Piiretään kappyra forecast-dataststa
};

const getCurrentWeatherData = async (city) => {
  // Haetaan current-weather OpenWeatherMap API:sta
  // ja palautetaan se JSON-muodossa
  try {
    const response = await fetch(
      `https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${API_KEY}&units=metric`,
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

const getForeccastData = async (city) => {
  // Haetaan forecast-data OpenWeatherMap API:sta
  // ja palautetaan se JSON-muodossa
  try {
    const response = await fetch(
      `https://api.openweathermap.org/data/2.5/forecast?q=${city}&appid=${API_KEY}&units=metric`,
    );

    if (!response.ok) {
      throw new Error("City not found");
    }

    const data = await response.json();
    return data;
  } catch (error) {
    console.error("Error fetching forecast data:", error);
    alert("Could not fetch forecast data. Please try again.");
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
  document.getElementById("temperature").textContent =
    `${temperature.toFixed(2)}°C`;
  document.getElementById("feels-like").textContent =
    `${feelsLike.toFixed(2)}°C`;
  document.getElementById("humidity").textContent = `Humidity: ${humidity}%`;
  document.getElementById("wind-speed").textContent =
    `Wind Speed: ${windSpeed} m/s`;
  document.getElementById("weather-description").textContent =
    weatherDescription;

  // Päivitetty-aikaleima
  const now = new Date();
  const timeString = now.toLocaleTimeString("fi-FI");
  document.querySelector(".info").textContent = `Päivitetty: ${timeString}`;

  // Päivitä datan lähde footeriin
  document.querySelector(".attribution").textContent =
    "Säädata: OpenWeatherMap API";
};

function drawChart(data) {
  // Chart.js-käppyrä
  const ctx = document.getElementById("weather-chart");

  // X-akselin labelit (aika)
  const labels = data.list.map((item) => {
    const date = new Date(item.dt * 1000);
    const weekdays = ["Su", "Ma", "Ti", "Ke", "To", "Pe", "La"];

    return `${weekdays[date.getDay()]} ${date.getHours()}:00`;
  });

  // Y-akselin arvot (lämpötila-arvot)
  const temps = data.list.map((item) => item.main.temp);

  if (tempChart) {
    tempChart.destroy();
  }

  tempChart = new Chart(ctx, {
    type: "line",
    data: {
      labels: labels,
      datasets: [
        {
          label: "Lämpötila °C",
          data: temps,
          borderColor: "orange",
          backgroundColor: "rgba(255,165,0,0.2)",
          tension: 0.3,
        },
      ],
    },
  });
}

// Search form handler
document.addEventListener("DOMContentLoaded", () => {
  const searchForm = document.getElementById("search-form");
  if (searchForm) {
    searchForm.addEventListener("submit", (e) => {
      e.preventDefault();
      const cityInput = document.getElementById("city-input");
      const city = cityInput.value.trim();
      if (city) {
        getDataAndUpdateUI(city);
      }
    });
  }

  getDataAndUpdateUI(CITY);
});
