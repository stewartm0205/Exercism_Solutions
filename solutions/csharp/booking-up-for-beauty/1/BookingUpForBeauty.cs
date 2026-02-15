using System;

static class Appointment
{
    public static DateTime Schedule(string appointmentDateDescription)
    {
        return DateTime.Parse(appointmentDateDescription);
        //throw new NotImplementedException("Please implement the (static) Appointment.Schedule() method");
    }

    public static bool HasPassed(DateTime appointmentDate)
    {
        if (appointmentDate < DateTime.Now) return true;
        return false;
    }

    public static bool IsAfternoonAppointment(DateTime appointmentDate)
    {
        if (appointmentDate.Hour*100+appointmentDate.Minute >= 1200 && appointmentDate.Hour*100+appointmentDate.Minute < 1800) return true;
        return false;
    }

    public static string Description(DateTime appointmentDate)
    {
        return "You have an appointment on " +appointmentDate.ToString("M/d/yyyy h:mm:ss tt") + ".";
    }

    public static DateTime AnniversaryDate()
    {
        DateTime now = DateTime.Now;
        DateTime anni = new DateTime(now.Year, 9, 15);
        return anni;
        //throw new NotImplementedException("Please implement the (static) Appointment.AnniversaryDate() method");
    }
}
