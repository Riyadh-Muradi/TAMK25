// NOTE: Hardcoding API keys in client-side code is NOT recommended for production.
const API_KEY = "6c98fda8f11aeccaf6d92c178e1209d9";
const CITY = "Tampere";

(async () => {
    try {
        const response = await fetch(
            `https://api.openweathermap.org/data/2.5/weather?q=${CITY}&appid=${API_KEY}&units=metric&lang=fi`
        );
        const data = await response.json();
        console.log(`Weather data for ${CITY}:`, data);
    } catch (err) {
        console.error('Fetch error:', err);
    }
})();