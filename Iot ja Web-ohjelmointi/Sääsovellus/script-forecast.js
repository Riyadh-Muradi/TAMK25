console.log("Forecast page loaded!");

const API_KEY = "6c98fda8f11aeccaf6d92c178e1209d9";
const CITY = "Tampere";

let tempChart;

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

const getForeccastData = async (city) => {
  try {
    const response = await fetch(
      `https://api.openweathermap.org/data/2.5/forecast?q=${city}&appid=${API_KEY}&units=metric`
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

function drawChart(data) {
  const ctx = document.getElementById("weather-chart");

  const labels = data.list.map((item) => {
    const date = new Date(item.dt * 1000);
    const weekdays = ["Su", "Ma", "Ti", "Ke", "To", "Pe", "La"];

    return `${weekdays[date.getDay()]} ${date.getHours()}:00`;
  });

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

  const now = new Date();
  const timeString = now.toLocaleTimeString("fi-FI");
  document.querySelector(".info").textContent = `Päivitetty: ${timeString}`;
  document.querySelector(".attribution").textContent = "Säädata: OpenWeatherMap API";
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
        loadForecast(city);
      }
    });
  }
  
  loadForecast(CITY);
});

const loadForecast = async (city) => {
  const forecastData = await getForeccastData(city);
  if (forecastData) {
    drawChart(forecastData);
  }
};
