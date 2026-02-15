using System;

class RemoteControlCar
{
    int speed;
    int batteryDrain;
    int distanceDriven;
    int batteryDrained;
    public RemoteControlCar (int speed, int batteryDrain){

        this.speed = speed;
        this.batteryDrain = batteryDrain;
        this.distanceDriven = 0;
        this.batteryDrained = 0;

    }

    public bool BatteryDrained()
    {
        return batteryDrained + batteryDrain > 100;
    }

    public int DistanceDriven()
    {
        return distanceDriven;
    }

    public void Drive()
    {
        batteryDrained += batteryDrain;
        if (batteryDrained <= 100) {
            distanceDriven += speed;
        }
    }

    public static RemoteControlCar Nitro()
    {
        return new RemoteControlCar(50, 4);
    }
}

class RaceTrack
{
    int distance;
    // TODO: define the constructor for the 'RaceTrack' class
    public RaceTrack (int distance) {
        this.distance = distance;

    }

    public bool TryFinishTrack(RemoteControlCar car)
    {

        while (!car.BatteryDrained() && car.DistanceDriven()<distance) {
            car.Drive();
        }
        return car.DistanceDriven()==distance;
    }
}
