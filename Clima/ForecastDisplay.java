public class ForecastDisplay implements Observer, DisplayElement {
    private float currenPressure = 29.92f;
    private float lastPressure;
    private WeatherData weatherData;

    public ForecastDisplay(WeatherData weatherData) {
        this.weatherData = weatherData;
        weatherData.registerObserver(this);
    }

    public void update(float temp, float humidity, float pressure) {
        lastPressure = currenPressure;
        currenPressure = pressure;
        display();
    }

    public void display() {
        System.out.println("Forecast: ");
        if (currenPressure > lastPressure) {
            System.out.println("Improving weather on the way");
        } else if (currenPressure == lastPressure) {
            System.out.println("More of the same");
        } else if (currenPressure < lastPressure) {
            System.out.println("Watch out for cooler, rainy weather");
        }
    }
}