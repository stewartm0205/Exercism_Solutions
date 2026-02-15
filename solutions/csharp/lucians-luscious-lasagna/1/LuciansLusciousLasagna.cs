class Lasagna
{
    // TODO: define the 'ExpectedMinutesInOven()' method
    public int ExpectedMinutesInOven() {
        return 40;
    }

    // TODO: define the 'RemainingMinutesInOven()' method
        public int RemainingMinutesInOven(int actualMinute) {
        return ExpectedMinutesInOven() - actualMinute;
    }

    // TODO: define the 'PreparationTimeInMinutes()' method
        public int PreparationTimeInMinutes (int layers)
        {
            return 2 * layers;
        }
    // TODO: define the 'ElapsedTimeInMinutes()' method
    public int ElapsedTimeInMinutes(int layers, int actualMinute) {
        return PreparationTimeInMinutes(layers) + actualMinute;
    }
}
