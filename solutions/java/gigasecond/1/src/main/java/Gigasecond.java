import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.temporal.TemporalUnit;

class Gigasecond {
    long gigaSeconds = 1000000000;
    LocalDateTime gigaDateTime;

    Gigasecond(LocalDate birthDate) {
        gigaDateTime = birthDate.atStartOfDay();
        gigaDateTime = gigaDateTime.plusSeconds(gigaSeconds);
    }

    Gigasecond(LocalDateTime birthDateTime) {
        gigaDateTime = birthDateTime;
        gigaDateTime = gigaDateTime.plusSeconds(gigaSeconds);
    }

    LocalDateTime getDate() {
        return(gigaDateTime);
    }


}