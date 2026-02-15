class SpaceAge {
    double ageInSecs;

    SpaceAge(double seconds) {
        ageInSecs = seconds;
    }

    double getSeconds() {
        return(ageInSecs);
    }

    double onEarth() {
        return(ageInSecs/31557600);
    }

    double onMercury() {
        return((ageInSecs/31557600)/0.2408467);
    }

    double onVenus() {
        return((ageInSecs/31557600)/0.61519726);
    }

    double onMars() {
        return((ageInSecs/31557600)/1.8808158);
    }

    double onJupiter() {
        return((ageInSecs/31557600)/11.862615);
    }

    double onSaturn() {
        return((ageInSecs/31557600)/29.447498);
    }

    double onUranus() {
        return((ageInSecs/31557600)/84.01684);
    }

    double onNeptune() {
        return((ageInSecs/31557600)/164.79132 );
    }

}